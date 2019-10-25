#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>
//
using namespace std;

void parse (){
    //string filename="/home/alonso/Documentos/Ciclo_4/Alg&DataStructure/graphs-asdasd/airports.json";

    ifstream filename("/home/alonso/Documentos/Ciclo_4/Alg&DataStructure/graphs-asdasd/airports.json");
    //ifstream filename("/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/airports.json");
    nlohmann::json j = nlohmann::json::parse(filename);
    cout << j <<endl;

    //ifstream file_input(filename);
    //nlohmann::json airports;
    //file_input >> airports;
    //cout<<airports[1]<<endl;
}

#endif //GRAPHS_ASDASD_PARSER_H
