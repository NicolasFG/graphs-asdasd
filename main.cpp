#include <iostream>
#include "parser.h"
#include "graph.h"

using namespace std;

void trials(){
    graph G(true);

    G.createNodes(0, "LA", 120.0, 20);
    G.createNodes(1, "Lima", 50.0, 30);
    G.createNodes(2, "Paris", 140.0, 110);
    G.createNodes(3, "Ethiopia", 60.0, 130);

    G.createConection(0,1);

    G.printArista(0,1);

    G.removeConnection(0,1);

    G.printArista(0,1);



}

int main(){
    //fillin();
    //createjsonnodes();
    trials();

    return 0;
}