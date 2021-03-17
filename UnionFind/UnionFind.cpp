#include "UnionFind.h"

UnionFind::UnionFind(int cap) {
    par.resize(cap);
    for(int i=0; i<cap; i++)
        par[i] = i;
}

int UnionFind::find(int x) {
    return (par[x] == x)? x : (par[x] = find(par[x]));
}

void UnionFind::unite(int a, int b) {
    int x = find(a);
    int y = find(b);

    if(x == y)
        return;

    if(x > y)
    {
        swap(x, y);
        swap(a, b);
    }

    par[a] = x;
    par[b] = x;
}