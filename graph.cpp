#include <string>
#include <iostream>
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

void graph::calculatedistance(int key1, int key2) {
    auto x = findNode(key1);
    auto y = findNode(key2);
    cout<<x->Name<<endl;
    cout<<y->Name<<endl;
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
    cout<<x->Name<<endl;
}

Node* graph::findNode(int key) {
    for (auto i : LA) {
        cout<<i[0]->Id<<endl;
        cout<<typeid(i[0]).name()<<endl;
        if (i[0]->Id == key){
            cout<<i[0]->Name<<endl;
            return i[0];

        }
    }
    return nullptr;
}