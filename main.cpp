#include <iostream>
#include "parser.h"
#include "graph.h"

using namespace std;

void trials(){
    graph G(true);

    G.createNodes(0, "S", 120.0, 20);
    G.createNodes(1, "A", 120.0, 20);
    G.createNodes(2, "B", 50.0, 30);
    G.createNodes(3, "C", 140.0, 110);
    G.createNodes(4, "D", 60.0, 130);
    G.createNodes(5, "E", 60.0, 130);
    //G.createNodes(5, "F", 60.0, 130);
    //G.createNodes(6, "G", 60.0, 130);
    //G.createNodes(7, "H", 60.0, 130);
    //G.createNodes(8, "I", 60.0, 130);
    //G.createNodes(9, "J", 60.0, 130);

    G.createConection(0,1, 10);
    G.createConection(0,5, 8);
    G.createConection(1,3, 2);
    G.createConection(2,1, 1);
    G.createConection(3,2, -2);
    G.createConection(4,3, -1);
    G.createConection(4,1, -4);
    G.createConection(5,4, 1);
    /*G.createConection(1,6, 2);
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
    */
    G.printBF(0);

}


int main(){
    //fillin();
    createjsonnodes();
    //trials();

    return 0;
}

