#include <bits/stdc++.h>

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
using namespace std;
class Graph {

public:
    explicit Graph(int size);
    void addEdge(int a, int b);
    void buildGraph(list<pair<int, int>> & edges);
    void WeisfeilerLehman(); // Implements the algorithm
    bool operator== (Graph & that); //Compares if the two graphs are isomorphic (after running the algorithm)

private:
    int capacity;
    struct nodeInfo {
        std::size_t curHash;
        std::size_t nextHash;
        nodeInfo() : curHash(0), nextHash(0) {};
    };
    vector<list<int>> gr;
    vector<nodeInfo> info;
};

#endif //UNTITLED_GRAPH_H
