#include <iostream>
#include "parser.h"
#include "graph.h"

using namespace std;

void trials(){
    graph G(false);

    G.createNodes(0, "LA", 120.0, 20);
    G.createNodes(1, "Lima", 50.0, 30);
    G.createNodes(2, "Paris", 140.0, 110);
    G.createNodes(3, "Ethiopia", 60.0, 130);

    G.createConection(0,1, 1);
    G.createConection(1,2, 1);
    G.createConection(2,3, 1);
    G.createConection(3,0, 1);
    G.printLA();
   // G.printNode(0);
    G.removeNode(0);
    //G.printNode(0);
    //G.printArista(0,1);
    //G.printArista(3,0);

    vector<bool> discovered;
    vector<int> color(G.getNodes());
    color[0]=0;

   discovered= G.fillvectordiscovered(G,discovered);

    bool a= graph::is_bipartite(G,0,discovered,color);

    if(a){
        cout<<" es bipartido";
    }

    else{
        cout<< " no es bipartido ";
    }
cout<<endl;
    G.getKruskal();



}



int main(){
    //fillin();
   // createjsonnodes();
    trials();


    return 0;
}
