#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include <cstdlib>
#include "graph.h"
#include "json.hpp"
#include <fstream>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

bool isNumber(string coordinates)
{
    char simbolo=coordinates.at(0);
    if (simbolo=='-'){
        return true;
    }
    else{
        for (char i : coordinates){
            return isdigit(i) != 0;
        }
    }
    return false;
}

auto parse(int i,const nlohmann::json& jvalues){
    return jvalues[i];
}

int sizearray(const nlohmann::json& jvalues){
    int size=jvalues.size();
    return size;
}

string getairportname(nlohmann::json linea){
    string nombre=linea.at("Name");
    return nombre;
}

int getairportid(nlohmann::json linea){
    string idletras=linea.at("Id");
    int id=stoi(idletras);
    return id;
}

double getairportlatitude(nlohmann::json linea){
    string latitudeletras=linea.at("Latitude");
    if(isNumber(latitudeletras)){
        double latitude=stod(latitudeletras);
        return latitude;
    }
    else{
        return 0;
    }
}

double getairportlongitude(nlohmann::json linea){
    string longitudletras=linea.at("Longitude");
    if(isNumber(longitudletras)) {
        double longitude = stod(longitudletras);
        return longitude;
    }
    else{
        return 0;
    }
}

vector<int>  getairportdestinations(nlohmann::json linea){
    auto destinationsletras=linea.at("destinations");
    int sizearray=destinationsletras.size();
    vector<int> destinations;
    for (int i = 0; i < sizearray; ++i) {
        string temp=destinationsletras[i];
        destinations.push_back(stoi(temp));
    }
    return destinations;
}

void fillin(){
    ifstream filename("../airports.json");
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    for (int i = 0; i < sizearray(jvalues); ++i) {
        cout<<parse(i,jvalues)<<endl;
        cout<<getairportname(parse(i,jvalues))<<endl;
        cout<<getairportid(parse(i,jvalues))<<endl;
        cout<<getairportlatitude(parse(i,jvalues))<<endl;
        cout<<getairportlongitude(parse(i,jvalues))<<endl;
        //Aqui se esta botando un vector donde estan todos los destinos asi que ya estan todo y como enteros, con un .size sacas puedes hacer un for y sacar todos
        cout<<getairportdestinations(parse(i,jvalues))[0]<<endl;
    }
}

void createjsonnodes(){
    ifstream filename("../airports.json");
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    for (int i = 0; i < sizearray(jvalues); ++i) {
        graph G = graph(true);
        G.createNodes(getairportid(parse(i,jvalues)),getairportname(parse(i,jvalues)), getairportlatitude(parse(i,jvalues)), getairportlongitude(parse(i,jvalues)));
        G.printNode(getairportid(parse(i,jvalues)));
    }
}

#endif //GRAPHS_ASDASD_PARSER_H
