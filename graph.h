//
// Created by alonso on 23/10/19.
//

#ifndef GRAPHS_ASDASD_GRAPH_H
#define GRAPHS_ASDASD_GRAPH_H

#include <vector>

using namespace std;

template <typename T>
struct Node;

template  <typename T>
struct Edge{
    double pond;
    Node<T>* origin;
    Node<T>* end;
};

template  <typename T>
struct Node{
    T value;
    vector<Edge<T>*> nexts;
};


class graph {

};


#endif //GRAPHS_ASDASD_GRAPH_H
