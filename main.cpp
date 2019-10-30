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

    G.createConection(0,1, 12);
    G.createConection(0,4, 5.7);
    G.createConection(1,2, 2);
    G.createConection(1,3, 8);
    G.createConection(2,6, 10);
    G.createConection(3,4, 4);
    G.createConection(4,6, 6);
    G.createConection(5,7, 9);
    G.createConection(6,7, 5);

    if (G.isConexo()) cout << "Es conexo" << endl<< endl;
    else cout << "No es conexo" << endl<< endl;
    G.printLA();
    cout << endl;
    G.printAristasByNode();
    cout << endl;
    G.primMST(3);
    G.getKruskal();
    


}


int main(){
    //fillin();
    //createjsonnodes();
    trials();

    return 0;
}
