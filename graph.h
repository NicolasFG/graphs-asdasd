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
    vector<Edge*> nexts;

    double pond = 0;
};

class graph {
private:
    unsigned int nodes,edges;
    bool is_directed;
    vector<vector<Node*>> LA;

public:
    explicit graph(bool isdirected);

    void createNodes(int _id, const string& _name, double _la, double _lo);
    void createNodes(int _id, const string&  _name, double _la, double _lo, double _pond);
    void createConection(int origin, int end);
    void createConection(int origin, int end, double pond);

    double calculateDensity();
    static string denseOrDispersed(double densidad, double cota);

    double calculatedistance(int key1, int key2);
    void printNode(int key);
    Node* findNode(int key);
    Edge* findArista(int key1, int key2);
    bool connexo();
};



#endif //GRAPHS_ASDASD_GRAPH_H
