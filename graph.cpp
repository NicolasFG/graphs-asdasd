#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
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
    for (auto & i : LA){
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

void graph::printNode(int key) {
    Node* temporal = findNode(key);
    if(temporal){
        cout
                << "Nombre : " << temporal->Name
                << " - ID: " << temporal->Id
                << endl;
    } else {
        cout << "No se encontró lo que buscaba. " << endl;
    }
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

int graph::getNodeIdByName(const string &Name) {
    for (auto i : LA) {
        if (i[0]->Name == Name){
            return i[0]->Id;
        }
    }
    return 0;
}

void graph::printArista(int OriginKey, int EndKey) {
    Edge* temporal = findArista(OriginKey, EndKey);
    if(temporal){
        cout
                << "Origen : " << temporal->origin->Name
                << " - Destino : " << temporal->end->Name
                << " - Distancia : " << temporal->pond
                << endl;
    }

    else {
        cout << "No se encontró lo que buscaba. " << endl;
    }
}

void graph::removeConnection(int OriginKey, int EndKey) {
    auto temp = findArista(OriginKey, EndKey);
    for (auto i : LA){
        if(i[0]->Id == OriginKey){
            auto it1 = i[0]->nexts.begin();
            for (auto x : i[0]->nexts){
                if(x == temp){
                    i[0]->nexts.erase(it1);
                }
                ++it1;
            }
            auto it2 = i.begin();
            for(auto y : i){
                if (y->Id == EndKey){
                    i.erase(it2);
                }
                ++it2;
            }
        }
    }
    delete temp;
}

void graph::removeNode(int _id) {
    auto temp = findNode(_id);
    //Borrar todos los edges que salen del NODO
    for (auto i : temp->nexts){
        removeConnection(i->origin->Id, i->end->Id);
    }
    //Borrar todos los edges que llegan al NODO y su rastro en la lista de adyacencia LA
    for (auto j : LA){
        auto it1 = j.begin();
        for (auto k : j) {
            if (k== temp){
                auto it2 = j[0]->nexts.begin();
                for(auto m : j[0]->nexts){
                    if (m->end == temp){
                        j[0]->nexts.erase(it2);
                        break;
                    }
                    ++it2;
                }
                j.erase(it1);
                break;
            }
            ++it1;
        }
    }

    //Borrar el nodo de la lista de adyacencia
    auto itSupremo = LA.begin();
    for (auto n : LA){
        if(n[0] == temp){
            n.clear();
            LA.erase(itSupremo);
            break;
        }
        ++itSupremo;
    }

    //Borrar el nodo
    delete temp;
}

void graph::printLA(){
    for (auto & x : LA){
        cout << x.size() << " = ";
        for (auto & y : x){
            cout << y->Name << " - " << y->Id << " | ";
        }
        cout << endl;
    }
}

vector<Edge*> graph::filledges(){
    vector<Edge*> compilado;
    for (auto & i : LA) {
        for (auto & j : i) {
            for (auto next : j->nexts) {
                compilado.push_back(next);
            }
        }
    }
}
unsigned int graph::getNodes() {
    return nodes;
}


vector<bool> graph::fillvectordiscovered(graph G,vector<bool> vector) {
    for (int i = 0; i <= G.LA.size(); ++i) {

        for (int j = 0; j <G.LA.size(); ++j) {
            vector.push_back(false);
        }
        }
    return vector;}


bool graph::is_bipartite(graph G,int n,vector<bool> &discovered,vector <int> &color){


    for (int i = 0; i <= G.LA.size(); ++i) {

        for (int j = 1; j < G.LA[i].size(); ++j) {
            if (discovered[j] == false) {
                discovered[j] = true;
                color[n] = !color[j];
               bool a=is_bipartite(G,j,discovered,color);
               if(!a){
                   return false;
               }
            } else return color[j] != color[n];

        }
    }
    return true;
}


string graph::getKruskal() {

    if (is_directed) {
        cout << "kruskal no funciona para dirigidos" << endl;
    } else {
        vector<double> pesos;
        vector<Edge *> aristas;
        aristas = filledges();

        for (int i = 0; i <= LA.size(); ++i) {

            for (int j = 0; j < LA[i].size(); ++j) {
                pesos.push_back(aristas[j]->pond);
                cout << pesos[j] << endl;
            }
        }

        sort(pesos.begin(), pesos.end());

        for (int i = 0; i <= LA.size(); ++i) {

            for (int j = 0; j < LA.size(); ++j) {
                if (pesos[i] == aristas[j]->pond) {
                    aristas[i] = aristas[j];
                }
            }
        }
        for (int k = 1; k < 10; ++k) {

            cout << "Paso " << k << ": (" << aristas[k]->origin->Name << "," << aristas[k]->end->Name << ")" << endl;

        }


    }

}



//Pruebas Prim
int graph::minKey(vector<int> key, vector<bool> mstSet){
    int min =  2147483647;
    //Deberia ser int, pero como lo igualo a i, que es un unsigned long por lo que es el iterador del vector
    auto min_index = 0;
    for (unsigned long i = 0; i < LA.size(); ++i) {
        if (!mstSet[i] and key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void graph::printMST(const vector<int>& parent){
    cout<<"Edge \tWeight\n";
    for (unsigned long i = 1; i < LA.size(); i++){
        cout<<parent[i]<<" - "<<LA[i][parent[i]]->Id<<" \t"<<findArista(parent[i],LA[i][parent[i]]->Id)->pond<<" \n";
    }
}

void graph::primMST(){
    vector<int> parent;
    vector<int> key;
    vector<bool> mstSet;

    for (unsigned long i = 0; i < LA.size(); ++i){
        key.push_back(2147483647);
        mstSet.push_back(false);
    }
    key[0] = 0;
    parent.push_back(-1);

    for (unsigned long j = 0; j < LA.size() - 1; ++j){
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (unsigned long k = 1; k < LA[u].size()-1; ++k) {
            int temp1=LA[u][0]->Id;
            int temp2=LA[u][k]->Id;
            double temp3=findArista(temp1,temp2)->pond;

            if (temp3!=0 && !mstSet[k] and temp3 < key[k]){
                parent.push_back(LA[u][0]->Id);
                key.push_back(temp3);
            }
        }
    }
    printMST(parent);
}

