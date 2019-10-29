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
    unsigned int nodes,edges{};
    bool is_directed;
    Edge* edge;
     vector<vector<Node*>> LA;

public:
    explicit graph(bool isdirected);

    void createNodes(int _id, const string& _name, double _la, double _lo);
    void createNodes(int _id, const string&  _name, double _la, double _lo, double _pond);
    void createConection(int origin, int end);
    void createConection(int origin, int end, double pond);
    void removeNode(int _id);

    void removeConnection(int OriginKey, int EndKey);
    unsigned int getNodes();


    Node* findNode(int key);
    Edge* findArista(int OriginKey, int EndKey);

    double calculateDensity();
    static string denseOrDispersed(double densidad, double cota);
    bool isConexo();
    bool isFuertementeConexo();
    static bool is_bipartite(graph G,int n,vector<bool>& discovered,vector<int>& color);
    static vector<bool> fillvectordiscovered(graph G,vector<bool> vector);
    vector<Edge*> filledges();


    string getKruskal();


    int getNodeIdByName(const string& Name);
    double calculatedistance(int key1, int key2);
    void printNode(int key);
    void printArista(int OriginKey, int EndKey);
    void printLA();


    int minKey(vector<int> key, vector<bool> mstSet);
    void printMST(const vector<int>& parent);
    void primMST();





};



#endif //GRAPHS_ASDASD_GRAPH_H
