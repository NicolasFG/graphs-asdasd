#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>

using namespace std;

int main(){
    string filename="airports.json";
    ifstream file_input(filename);
    nlohmann::json airports;
    file_input >> airports;
}

#endif //GRAPHS_ASDASD_PARSER_H
