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
    G.createNodes(4, "London", 180.0, 110);
    G.createNodes(5, "Moscow", 150.0, 160);

    G.createConection(0,5, 1);
    G.createConection(1,0, 1);
    G.createConection(1,4, 1);
    G.createConection(2,1, 1);
    G.createConection(2,3, 1);
    G.createConection(3,0, 1);
    G.createConection(3,4, 1);
    G.printLA();
    if(G.isConexo()) cout << "Es Conexo";
    else cout << "No es conexo";


}

int main(){
    //fillin();
    createjsonnodes();
    //trials();

    return 0;
}