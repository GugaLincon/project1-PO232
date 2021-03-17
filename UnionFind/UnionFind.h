#include "bits/stdc++.h"

#ifndef UNTITLED_UNIONFIND_H
#define UNTITLED_UNIONFIND_H

using namespace std;

class UnionFind {
public:
    UnionFind(int cap);

    int find(int x);
    void unite(int a, int b);
private:
    vector<int> par;
};

#endif //UNTITLED_UNIONFIND_H
