#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;

ifstream filename("/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/airports.json");
//ifstream filename("/home/alonso/Documentos/Ciclo_4/Alg&DataStructure/graphs-asdasd/airports.json");

auto parse(int i,const nlohmann::json& jvalues){
    return jvalues[i];
}

int sizearray(nlohmann::json jvalues){
    int size=jvalues.size();
    return size;
}

void print(){
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    cout<<jvalues.size()<<endl;
}

#endif //GRAPHS_ASDASD_PARSER_H
