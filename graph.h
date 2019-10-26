//
// Created by alonso on 23/10/19.
//

#ifndef GRAPHS_ASDASD_GRAPH_H
#define GRAPHS_ASDASD_GRAPH_H

#include <vector>

using namespace std;


struct Node;

struct Edge{
    double pond = 0;
    Node* origin = nullptr;
    Node* end = nullptr;
};


struct Node{
    int Id;
    string Name;
    double Lat,Long;
    vector<int> nexts;

    double pond = 0;
};

class graph {
private:
    unsigned int nodes;
    bool is_directed;
    vector<vector<Node*>> LA;
public:
    explicit graph(bool directed);

    void createNodes(int _id, const string& _name, double _la, double _lo);
    void createNodes(int _id, const string& _name, double _la, double _lo, double _pond);
    void createConection(int origin, int end);
    void createConection(int origin, int end, double pond);

    void printNode(int key);
    Node* findNode(int key);
};



#endif //GRAPHS_ASDASD_GRAPH_H
