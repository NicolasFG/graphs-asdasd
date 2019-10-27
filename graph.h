#ifndef GRAPHS_ASDASD_GRAPH_H
#define GRAPHS_ASDASD_GRAPH_H

#include <vector>

using namespace std;


struct Node;


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


class graph {
private:
    bool is_directed;

    unsigned int nodes;
    vector<vector<Node*>> LA;
public:
    graph(bool isdirected);

    void createNodes(int _id, const string& _name, double _la, double _lo);
    void createNodes(int _id, const string&  _name, double _la, double _lo, double _pond);
    void createConection(int origin, int end);
    void createConection(int origin, int end, double pond);

    Node* findNode(int key);
    void printNode(int key);
};



#endif //GRAPHS_ASDASD_GRAPH_H
