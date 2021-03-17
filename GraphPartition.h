#include "Graph.h"
#include "UnionFind/UnionFind.h"

#ifndef UNTITLED_GRAPHPARTITION_H
#define UNTITLED_GRAPHPARTITION_H

class GraphPartition {
public:
    GraphPartition(int cap);
    void createPartition(const Graph * g);
    bool operator!= (GraphPartition & that);
    UnionFind uf;
    void reset();
private:
    int cap;
    unordered_map<std::size_t, int> mp;
};

#endif //UNTITLED_GRAPHPARTITION_H
