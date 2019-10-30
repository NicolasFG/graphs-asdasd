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

    void createNodes(int _id, const string& _name, double _la, double _lo); //TERMINADO
    void createNodes(int _id, const string&  _name, double _la, double _lo, double _pond); //TERMINADO
    void createConection(int origin, int end); //TERMINADO
    void createConection(int origin, int end, double pond); //TERMINADO
    void removeNode(int _id); //TERMINADO
    void removeConnection(int OriginKey, int EndKey); //TERMINADO

    Node* findNode(int key); //TERMINADO
    Edge* findArista(int OriginKey, int EndKey); //TERMINADO

    double calculateDensity();   //TERMINADO
    string denseOrDispersed(double cota); //TERMINADO
    bool isConexo();
    bool isFuertementeConexo();
    bool is_bipartite(graph G,int n);

    string getPrim();
    string getKruskal();

    int getNodeIdByName(const string& Name);
    double calculatedistance(int key1, int key2);
    void printNode(int key);
    void printArista(int OriginKey, int EndKey);
    void printLA();


};



#endif //GRAPHS_ASDASD_GRAPH_H
