#include "Graph.h"

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
    //TODO: Finish this algorithm
    //The starting hash is the degree of the vertex, as suggested by the professor references
    for(int i=0; i<capacity; i++)
    {
        info[i].curHash = gr[i].size();
        cout << info[i].nextHash << endl;
    }

    // Iteratively calculate new hash for the set of neighbors
    while(true /* TODO: Create the condition function */)
    {
        hash<size_t> hashFunc = hash<size_t>();
        for(int i=0; i<capacity; i++)
        {
            for(int & e : gr[i])
            {
                info[i].nextHash = (info[i].nextHash == 0)?
                        hashFunc(info[e].curHash) : (info[i].nextHash^hashFunc(info[e].curHash));
            }
        }
        for(int i=0; i<capacity; i++)
        {
            swap(info[i].curHash, info[i].nextHash);
            info[i].nextHash = 0;
        }
    }

}

bool Graph::operator==(Graph &that) {
    //TODO
    return false;
}