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