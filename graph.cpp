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
    auxEdge->origin->nexts.push_back(auxEdge);
    if (!is_directed){
        for (auto i : LA){
            if (i[0] == auxEdge->end){
                i.push_back(auxEdge->origin);
            }
        }
        auxEdge->end->nexts.push_back(auxEdge);
    }
    edges++;
}

void graph::createConection(int origin, int end, double pond) {
    auto auxEdge = new Edge;
    auxEdge->origin = findNode(origin);
    auxEdge->end = findNode(end);
    auxEdge->pond = pond;
    for (auto i : LA){
        if (i[0] == auxEdge->origin){
            i.push_back(auxEdge->end);
        }
    }
    auxEdge->origin->nexts.push_back(auxEdge);
    if (!is_directed){
        for (auto i : LA){
            if (i[0] == auxEdge->end){
                i.push_back(auxEdge->origin);
            }
        }
        auxEdge->end->nexts.push_back(auxEdge);
    }
    edges++;
}

void graph::printNode(int key) {
    Node* temporal = findNode(key);
    if(temporal){
        cout
        << "Nombre : " << temporal->Name
        << " - ID: " << temporal->Id
        << endl;
    } else {
        cout << "No se encontró lo que buscaba. " << endl;
    }
}

Node* graph::findNode(int key) {
    for (auto i : LA) {
        if (i[0]->Id == key){
            return i[0];
        }
    }
    return nullptr;
}

Edge* graph::findArista(int key1, int key2) {
    for (auto i : LA) {
        if (i[0]->Id == key1){
            vector <Edge*> tempRecorrido = i[0]->nexts;
            for (auto & y : tempRecorrido){
                if(y->end->Id==key2){
                    return y;
                }
            }
            return nullptr;
        }
    }
    return nullptr;
}

double graph::calculateDensity() {
    double densidad = static_cast<double>(edges)/ (nodes * (nodes - 1));
    if (!is_directed) {
        densidad *= 2;
    }
    return densidad;
}

string graph::denseOrDispersed(double densidad, double cota){
    if(densidad >= cota){
        return "Es denso";
    }
    return "Es disperso";
}

int graph::getNodeIdByName(const string &Name) {
    for (auto i : LA) {
        if (i[0]->Name == Name){
            return i[0]->Id;
        }
    }
    return 0;
}

void graph::printArista(int OriginKey, int EndKey) {
    Edge* temporal = findArista(OriginKey, EndKey);
    if(temporal){
        cout
        << "Origen : " << temporal->origin->Name
        << " - Destino : " << temporal->end->Id
        << "Distancia : " << temporal->pond
        << endl;
    } else {
        cout << "No se encontró lo que buscaba. " << endl;
    }
}

void graph::removeConnection(int OriginKey, int EndKey) {
    for (auto i : LA){
        if(i[0]->Id == OriginKey){
            auto it = i[0]->nexts.begin();
            for (auto x : i[0]->nexts){
                if(x->end->Id == EndKey){
                    i[0]->nexts.erase(it);
                }
                ++it;
            }
        }
    }
}


