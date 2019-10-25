//
// Created by alonso on 23/10/19.
//

#ifndef GRAPHS_ASDASD_GRAPH_H
#define GRAPHS_ASDASD_GRAPH_H

#include <vector>

using namespace std;


struct Node;

template  <typename T>
struct Edge{
    double pond;
    Node* origin;
    Node* end;
};


struct Node{
    int Id;
    string Name;
    double Lat,Long;
    vector<int> nexts;

    double pond;
};

template <typename T>
class graph {
private:
    unsigned int nodes;
    vector<vector<Node*>> LA;
public:
    graph();

    void createNodes(int _id, string _name, double _la, double _lo);
    void createNodes(int _id, string _name, double _la, double _lo, double _pond);
    void createConection(string* origin, string* end);
    void createConection(string* origin, string* end, double pond);
};



#endif //GRAPHS_ASDASD_GRAPH_H
