#include <string>
#include <iostream>
#include <cmath>
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

double deg2rad(double deg) {
    return deg * (M_PI/180);
}

double graph::calculatedistance(int key1, int key2) {
    int R = 6371;
    auto x = findNode(key1);
    auto y = findNode(key2);
    double diflat = deg2rad(x->Lat-y->Lat);
    double diflong = deg2rad(x->Long-y->Long);
    double z =
            sin(diflat/2)*sin(diflat/2)+
            cos(deg2rad(y->Lat))*cos(deg2rad(x->Lat))*
            sin(diflong/2)*sin(diflong/2);
    double c= 2*atan2(sqrt(z),sqrt(1-z));
    double d= R*c;
    return d;
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
    Node* x = findNode(key);
    cout<<x->Name<<endl;
}

Node* graph::findNode(int key) {
    for (auto & i : LA) {
        cout<<i[0]->Id<<endl;
        if (i[0]->Id == key){
            return i[0];
        }
    }
    return nullptr;
}