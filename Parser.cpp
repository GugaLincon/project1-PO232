#include "Parser.h"

Parser::Parser(string fileName) {
    file.open(fileName);
}

Parser::~Parser() {
    file.close();
}

void Parser::readEdgesFromFile(int *maxSize) {
    *maxSize = 0;
    string line;

    // Read first lines
    getline(file, line);
    getline(file, line);

    // Get
    int firstEdge = 0, secondEdge = 0;
    int status;
    while (getline(file, line)) {
        status = sscanf(line.data(), "%d -> %d", &firstEdge, &secondEdge);
        if(status == 2) {
            edges.emplace_back(firstEdge, secondEdge);
            *maxSize = max(*maxSize, max(firstEdge+1, secondEdge+1));
        }
    }
}

list<pair<int, int>> & Parser::getEdges() {
    return edges;
}
