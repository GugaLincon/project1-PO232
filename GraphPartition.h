#include "Graph.h"
#include "UnionFind/UnionFind.h"

#ifndef UNTITLED_GRAPHPARTITION_H
#define UNTITLED_GRAPHPARTITION_H

class GraphPartition {
public:
    GraphPartition(int cap);
    void createPartition(Graph & g);
    bool operator== (GraphPartition & that);
    UnionFind uf;
private:
    unordered_map<std::size_t, int> mp;
};

#endif //UNTITLED_GRAPHPARTITION_H
