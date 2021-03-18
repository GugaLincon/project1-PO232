#include "Parser.h"
#include "Graph.h"

int main() {
    unique_ptr<Parser> p = make_unique<Parser>("../g5.dat");
    int size;
    p->readEdgesFromFile(&size);
    Graph gr1 = Graph(size);
    gr1.buildGraph(p->getEdges());
    p.reset();
    gr1.WeisfeilerLehman();

    p = make_unique<Parser>("../g6.dat");
    p->readEdgesFromFile(&size);
    Graph gr2 = Graph(size);
    gr2.buildGraph(p->getEdges());
    p.reset();
    gr2.WeisfeilerLehman();

    if(gr1 == gr2)
        cout << "Isomorphic" << endl;
    else
        cout << "Non-isomorphic" << endl;


    return 0;
}
