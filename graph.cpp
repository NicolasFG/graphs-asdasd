//
// Created by alonso on 23/10/19.
//

#include <string>
#include <iostream>
#include <utility>
#include "graph.h"

graph::graph(bool directed) {
    nodes = 0;
    is_directed = directed;
}


void graph::createNodes(int _id, const string& _name, double _la, double _lo) {
    Node* auxNode = new Node;
    auxNode->Id = _id;
    auxNode->Name = _name;
    auxNode->Lat = _la;
    auxNode->Long = _lo;
    vector<Node*> aux;
    aux.push_back(auxNode);
    LA.push_back(aux);
    nodes++;
}

void graph::createNodes(int _id, const string& _name, double _la, double _lo, double _pond) {
    Node* auxNode = new Node;
    auxNode->Id = _id;
    auxNode->Name = _name;
    auxNode->Lat = _la;
    auxNode->Long = _lo;
    auxNode->pond = _pond;
    vector<Node*> aux;
    aux.push_back(auxNode);
    LA.push_back(aux);
    nodes++;
}

//

void graph::createConection(int origin, int end) {
    auto auxEdge = new Edge;
    auxEdge->origin = findNode(origin);
    auxEdge->end = findNode(end);
    for (auto i : LA){
        if (i[0] == auxEdge->origin){
            i.push_back(auxEdge->end);
        }
    }

}

void graph::printNode(int key) {
    auto x = findNode(key);
    cout << x->Name;
}

Node* graph::findNode(int key) {
    for (auto& i : LA) {
        if (i[0]->Id == key){
            return i[0];
        }
    }
    return nullptr;
}