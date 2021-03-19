#include "Parser.h"
#include "Graph.h"

void checkIsomorphism(string & s1, string & s2)
{
    unique_ptr<Parser> p = make_unique<Parser>("../" + s1 + ".dat");
    int size;
    p->readEdgesFromFile(&size);
    Graph gr1 = Graph(size);
    gr1.buildGraph(p->getEdges());
    p.reset();
    gr1.WeisfeilerLehman();

    p = make_unique<Parser>("../" + s2 + ".dat");
    p->readEdgesFromFile(&size);
    Graph gr2 = Graph(size);
    gr2.buildGraph(p->getEdges());
    p.reset();
    gr2.WeisfeilerLehman();

    cout << s1 << " and " << s2 << " are ";
    if(gr1 == gr2)
        cout << "inconclusive" << endl;
    else
        cout << "not isomorphic" << endl;
}

int main() {
    for(int i=1; i<6; i+=2)
    {
        string s1 = "g" + to_string(i);
        string s2 = "g" + to_string(i+1);
        checkIsomorphism(s1, s2);
    }

    return 0;
}
