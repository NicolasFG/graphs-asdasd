#include <iostream>
#include "parser.h"
#include "graph.h"

using namespace std;

void trials(){
    graph G(false);

    G.createNodes(0, "A", 120.0, 20);
    G.createNodes(1, "B", 50.0, 30);
    G.createNodes(2, "C", 140.0, 110);
    G.createNodes(3, "D", 60.0, 130);
    G.createNodes(4, "E", 60.0, 130);
    G.createNodes(5, "F", 60.0, 130);
    G.createNodes(6, "G", 60.0, 130);
    G.createNodes(7, "H", 60.0, 130);
    G.createNodes(8, "I", 60.0, 130);
    G.createNodes(9, "J", 60.0, 130);

    G.createConection(0,2, 4);
    G.createConection(0,3, 13);
    G.createConection(0,4, 13);
    G.createConection(0,7, 5);
    G.createConection(0,8, 11);
    G.createConection(1,9, 15);
    G.createConection(1,7, 29);
    G.createConection(1,4, 24);
    G.createConection(1,6, 2);
    G.createConection(2,3, 39);
    G.createConection(2,8, 37);
    G.createConection(2,5, 9);
    G.createConection(3,9, 15);
    G.createConection(3,7, 5);
    G.createConection(4,7, 19);
    G.createConection(4,6, 2);
    G.createConection(4,8, 26);
    G.createConection(5,8, 7);
    G.createConection(6,8, 39);
    G.createConection(7,9, 15);

    if (G.isConexo()) cout << "Es conexo" << endl<< endl;
    else cout << "No es conexo" << endl<< endl;


    if (G.is_bipartite()) cout << "Es bipartito" << endl<< endl;
    else cout << "No es bipartito" << endl<< endl;
    //G.printLA();

    cout << endl;
    G.printAristasByNode();
    cout << endl;
    G.primMST(0);
    G.getKruskal();



}


int main(){
    //fillin();
    createjsonnodes();
    //trials();

    return 0;
}

