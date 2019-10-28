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

void graph::printNode(int key) {
    Node* temporal = findNode(key);
    cout<<temporal->Name<<"-"<<temporal->Id<<endl;
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

/*
bool graph::connexo() {
#define N 100000

}
// To keep correct and reverse direction
    vector<int> gr1[N], gr2[N];

    bool vis1[N], vis2[N];

// Function to add edges
    void Add_edge(int u, int v)
    {
        gr1[u].push_back(v);
        gr2[v].push_back(u);
    }

// DFS function
    void dfs1(int x)
    {
        vis1[x] = true;

        for (auto i : gr1[x])
            if (!vis1[i])
                dfs1(i);
    }

// DFS function
    void dfs2(int x)
    {
        vis2[x] = true;

        for (auto i : gr2[x])
            if (!vis2[i])
                dfs2(i);
    }

    bool Is_Connected(int n)
    {
        // Call for correct direction
        memset(vis1, false, sizeof vis1);
        dfs1(1);

        // Call for reverse direction
        memset(vis2, false, sizeof vis2);
        dfs2(1);

        for (int i = 1; i <= n; i++) {

            // If any vertex it not visited in any direction
            // Then graph is not connected
            if (!vis1[i] and !vis2[i])
                return false;
        }

        // If graph is connected
        return true;
    }
}
 */

/*
bool graph::is_bipartite(graph G,int n){
    vector<bool> discovered;
    vector<int> color={0};
    discovered={true};
cout<<"hola";

for (int i = 0; i <= G.LA.size(); ++i) {

        for (int j = 0; j < G.LA[i].size(); ++j) {
            if (discovered[j] == false) {
                discovered[n] = true;
                color[n] = !color[j];

                if (!is_bipartite(G, n)) {
                    return false;
                }
            } else if (color[j] == color[n]) {
                return false;
            }

        }
}
    return true;
}

string graph::Kruskal() {


    if(is_directed){
        throw invalid_argument("no es dirigido");
    }


}*/