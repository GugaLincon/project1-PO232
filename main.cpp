#include "Parser.h"
#include "Graph.h"

int main() {
    unique_ptr<Parser> p = make_unique<Parser>("../g.dat");
    int size;
    p->readEdgesFromFile(&size);
    Graph gr = Graph(size);
    gr.buildGraph(p->getEdges());
    p.reset();

    return 0;
}
