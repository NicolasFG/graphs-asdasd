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
    G.createNodes(4, "London", 60.0, 130);
    G.createNodes(5, "Spain", 60.0, 130);
    G.createNodes(6, "Moscow", 60.0, 130);
    G.createNodes(7, "DF", 60.0, 130);
    G.createNodes(8, "NY", 60.0, 130);

    G.createConection(0,1, 1);
    G.createConection(0,2, 1);
    G.createConection(1,3, 1);
    G.createConection(1,4, 1);
    G.createConection(2,5, 1);
    G.createConection(2,6, 1);
    G.createConection(4,7, 1);
    G.createConection(7,8, 1);

    if(G.is_bipartite()) cout << "Es bipartito";
    else cout << "No es bipartito";


}

int main(){
    //fillin();
    //createjsonnodes();
    trials();

    return 0;
}