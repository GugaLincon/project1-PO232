#include "graphvizParser.cpp"

int main() {
    int v;
    vector<int> a[5000];
    v = parseGraphviz("../g.dat", a);

    return 0;
}
