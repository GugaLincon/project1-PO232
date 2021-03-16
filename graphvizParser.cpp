#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Creates a graph from a text file with Graphviz formatting.
 * @param dataFile the path to the file.
 * @return a graph.
 */
vector<list<int>> parseGraphviz(const string& filePath) {
    ifstream dataFile(filePath);

    string line;
    while (getline(dataFile, line)) {
        std::cout << line;
    }

    dataFile.close();
}