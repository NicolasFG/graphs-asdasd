#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;

ifstream filename("/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/airports.json");
//ifstream filename("/home/alonso/Documentos/Ciclo_4/Alg&DataStructure/graphs-asdasd/airports.json");

string parse(int i){
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    return jvalues[i];
}

int sizearray(){
    int sizearray;
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    return sizearray=jvalues.size();
}

#endif //GRAPHS_ASDASD_PARSER_H
