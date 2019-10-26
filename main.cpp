#include <iostream>
#include "parser.h"
#include "graph.h"

using namespace std;

int main(){
    //fillin();
    graph G = graph(true);
    G.createNodes(0,"LAX", 120.0, 120.0);
    G.printNode(0);

}