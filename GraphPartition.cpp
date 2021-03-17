#include "GraphPartition.h"

GraphPartition::GraphPartition(int cap) : uf(cap), cap(cap) {}

void GraphPartition::createPartition(const Graph *g) {

    for(int i=0; i<cap; i++)
    {
        if(mp.find(g->info[i].curHash) == mp.end())
        {
            mp[g->info[i].curHash] = i;
        }
        else
        {
            uf.unite(i, mp[g->info[i].curHash]);
        }
    }
}

bool GraphPartition::operator!=(GraphPartition &that) {

    for(int i=0; i<cap; i++)
    {
        if(this->uf.find(i) != that.uf.find(i))
            return true;
    }
    return false;
}

void GraphPartition::reset() {
    uf.reset();
    mp.clear();
}