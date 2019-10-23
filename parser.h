#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>

using namespace std;

// read a JSON file
ifstream i("airports.json");
nlohmann::json j;
i >> j;

// write prettified JSON to another file
ofstream o("pretty.json");
o << std::setw(4) << j << std::endl;



#endif //GRAPHS_ASDASD_PARSER_H
