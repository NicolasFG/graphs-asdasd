#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include <cstdlib>
#include "json.hpp"
#include <fstream>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

bool isNumber(string s)
{
    char simbolo=s.at(0);

    if (simbolo=='-'){
        return true;
    }

    for (int i = 0; i < s.length(); ++i){
        return isdigit(s[i]) != 0;
    }
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
    //ifstream filename("/home/alonso/Documentos/Ciclo_4/Alg&DataStructure/graphs-asdasd/airports.json");
    ifstream filename("/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/airports.json");
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

#endif //GRAPHS_ASDASD_PARSER_H
