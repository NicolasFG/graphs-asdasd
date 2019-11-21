#ifndef GRAPHS_ASDASD_GRAPH_H
#define GRAPHS_ASDASD_GRAPH_H

#include <vector>
#include <map>

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
    void removeNode(int _id);

    void removeConnection(int OriginKey, int EndKey);
    unsigned int getNodes();


    Node* findNode(int key); //TERMINADO
    Edge* findArista(int OriginKey, int EndKey); //TERMINADO

    double calculateDensity();   //TERMINADO
    string denseOrDispersed(double cota); //TERMINADO
    bool isConexo(); //TERMINADO MEJORABLE
    bool isFuertementeConexo();
    bool is_bipartite();
    void fillvectordiscovered(map<Node*, bool*> & key);
    vector<Edge*> filledges();

    void getKruskal();// TERMINADO

    int getNodeIdByName(const string& Name);
    double calculatedistance(int key1, int key2);
    void printNode(int key);
    void printArista(int OriginKey, int EndKey);
    void printLA();
    bool CheckBoucle(Edge *arista);
    void printAristasByNode();
    int minKey(vector<int> key, vector<bool> mstSet);
    static void printMST( const vector<Edge*>& parent);
    void primMST(int key);//TERMINADO
    void dijkstra(int OriginKey);
    int minDistance(int dist[], bool sptSet[]);
    int printSolution(int dist[]);

    static void aux_bipartite(Node* N, bool prevColor, map<Node*,bool> &checked, int &contador);

    ~graph();


};



#endif //GRAPHS_ASDASD_GRAPH_H
