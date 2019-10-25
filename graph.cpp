//
// Created by alonso on 23/10/19.
//

#include <string>
#include <iostream>
#include "graph.h"


graph::graph() {
    nodes = 0;
}



void graph::createNodes(int _id, string _name, double _la, double _lo) {
    auto auxNode = new Node;
    auxNode->Id = _id;
    auxNode->Name = _name;
    auxNode->Lat = _la;
    auxNode->Long = _lo;
    LA[nodes][0] = auxNode;
    nodes++;
}


void graph::createNodes(int _id, string _name, double _la, double _lo, double _pond) {
    auto auxNode = new Node;
    auxNode->Id = _id;
    auxNode->Name = _name;
    auxNode->Lat = _la;
    auxNode->Long = _lo;
    auxNode->pond = _pond;
    LA[nodes][0] = auxNode;
    nodes++;
}



void graph::createConection(string* origin, string* end,double pond) {
    auto auxEdge = new Edge;
}


void graph::printNodes() {

    for (int i = 0; i < LA.size() ; i++){
        cout << LA[i][0]->Name << " ";
    }
}