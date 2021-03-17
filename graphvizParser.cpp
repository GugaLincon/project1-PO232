#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Creates a graph from a text file with Graphviz formatting. Graphs are labelled strictly as
 * positive integers, where the max vertex is the number of vertices.
 *
 * @param dataFile the path to the file.
 * @param graph the array where the graph will be stored.
 * @return a tuple with the number of vertices of the graph and the graph itself.
 */
int parseGraphviz(const string& filePath, vector<int> * graph) {
    const int MAXN = 5000;
    int vertexNumber = 0;
    ifstream dataFile(filePath);
    string line;

    // Read first lines
    getline(dataFile, line);
    getline(dataFile, line);

    // Get
    int firstEdge = 0, secondEdge = 0;
    while (getline(dataFile, line)) {
        istringstream iss(line);
        char trash[4];
        if(!(iss >> firstEdge >> trash >> secondEdge)) { break; }
        graph[firstEdge].push_back(secondEdge);
        graph[secondEdge].push_back(firstEdge);
        vertexNumber = max(vertexNumber, max(firstEdge, secondEdge));
    }

    dataFile.close();
    return vertexNumber;
}
