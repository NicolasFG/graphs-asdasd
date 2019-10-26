//
// Created by alonso on 23/10/19.
//

#include <string>
#include "graph.h"

template<typename T>
graph<T>::graph() {
    nodes = 0;
}


template <typename T>
void graph<T>::createNodes(int _id, string _name, double _la, double _lo) {
    auto auxNode = new Node;
    auxNode->Id = _id;
    auxNode->Name = _name;
    auxNode->Lat = _la;
    auxNode->Long = _lo;
    LA[nodes][0] = auxNode;
    nodes++;
}
template <typename T>
void graph<T>::createNodes(int _id, string _name, double _la, double _lo, double _pond) {
    auto auxNode = new Node;
    auxNode->Id = _id;
    auxNode->Name = _name;
    auxNode->Lat = _la;
    auxNode->Long = _lo;
    auxNode->pond = _pond;
    LA[nodes][0] = auxNode;
    nodes++;
}




template<typename T>
void graph<T>::createConection(string* origin, string* end,double pond) {
    auto auxEdge = new Edge<T>;
}