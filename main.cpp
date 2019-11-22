#include <iostream>
#include "parser.h"
#include "graph.h"

using namespace std;

void trials(){
    graph G(true);

    G.createNodes(100, "A", 120.0, 20);
    G.createNodes(200, "B", 50.0, 30);
    G.createNodes(300, "C", 140.0, 110);
    G.createNodes(400, "D", 60.0, 130);
    G.createNodes(500, "E", 60.0, 130);
    G.createNodes(600, "F", 60.0, 130);
    G.createNodes(700, "G", 60.0, 130);
    G.createNodes(800, "H", 60.0, 130);
    G.createNodes(900, "I", 60.0, 130);
    G.createNodes(1000, "J", 60.0, 130);

    G.createConection(100,200, 100);
    G.createConection(300,100, 200);
    G.createConection(200,300, 100);
    G.createConection(400,100, 300);
    G.createConection(300,500, 200);
    G.createConection(100,500, 400);
    G.createConection(100,400, 300);
    G.createConection(400,700, 300);
    G.createConection(700,800, 100);
    G.createConection(800,900, 100);
    G.createConection(200,600, 400);
    G.createConection(500,700, 200);
    G.createConection(800,1000, 200);

    G.printSolution(G.dijkstra(200));

    cout<<"Following is Depth First Traversal: "<<endl;
    G.DFS(100);

    cout<<"Following is Breadth First Traversal: "<<endl;
    G.BFS(100);

}

int main(){
    //fillin();
    //createjsonnodes();
    trials();

    return 0;
}

