#include "Graph.h"
#include "GraphPartition.h"

Graph::Graph(int size) {
    gr.resize(size);
    info.resize(size);
    capacity = size;
}

void Graph::addEdge(int a, int b) {
    gr[a].push_back(b);
    gr[b].push_back(a);
}

void Graph::buildGraph(list<pair<int, int>> & edges) {
    for(auto p : edges)
    {
        addEdge(p.first, p.second);
    }
}

void Graph::WeisfeilerLehman() {
    //The starting hash is the degree of the vertex, as suggested by the professor references
    for(int i=0; i<capacity; i++)
    {
        info[i].curHash = gr[i].size();
    }

    unique_ptr<GraphPartition> cur = make_unique<GraphPartition>(capacity);
    unique_ptr<GraphPartition> old = make_unique<GraphPartition>(capacity);
    cur->createPartition(this);

    // Iteratively calculate new hash for the set of neighbors
    int j =0;
    do
    {
        hash<string> hashFunc = hash<string>();
        for(int i=0; i<capacity; i++)
        {
            for(int & e : gr[i])
            {
                //cout << "cur: " << info[e].curHash << " new: " << hashFunc(to_string(info[e].curHash)) << endl;
                info[i].nextHash = (!info[i].nextHash)?
                        hashFunc(to_string(info[e].curHash)) : (info[i].nextHash^hashFunc(to_string(info[e].curHash)));
            }
        }
        for(int i=0; i<capacity; i++)
        {
            swap(info[i].curHash, info[i].nextHash);
            info[i].nextHash = 0;
        }
        cur.swap(old);
        cur->reset();
        cur->createPartition(this);
        j++;
    } while((*cur) != (*old) && j < 100);

}

bool Graph::operator==(Graph &that) {
    if(capacity != that.capacity)
        return false;
    unordered_map<std::size_t, int> mp;
    for(int i=0; i<capacity; i++)
    {
        mp[info[i].curHash]++;
    }

    for(int i=0; i<capacity; i++)
    {
        if(mp.find(that.info[i].curHash) == mp.end())
            return false;
        mp[that.info[i].curHash]--;
        if(mp[that.info[i].curHash] == 0)
            mp.erase(that.info[i].curHash);
    }

    return mp.empty();
}