#include <bits/stdc++.h>
#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

using namespace std;

class Parser {
public:
    Parser(string fileName);
    ~Parser();

    void readEdgesFromFile(int *maxSize);
    list<pair<int, int>> &getEdges();

private:
    list<pair<int, int>> edges;
    ifstream file;
};

#endif //UNTITLED_PARSER_H
