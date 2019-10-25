#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;

auto parse(int i,const nlohmann::json& jvalues){
    return jvalues[i];
}

int sizearray(const nlohmann::json& jvalues){
    int size=jvalues.size();
    return size;
}

void fillin(){
    //ifstream filename("/home/alonso/Documentos/Ciclo_4/Alg&DataStructure/graphs-asdasd/airports.json");
    ifstream filename("/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/airports.json");
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    for (int i = 0; i < sizearray(jvalues); ++i) {
        cout<<parse(i,jvalues)<<endl;
    }
}

#endif //GRAPHS_ASDASD_PARSER_H
