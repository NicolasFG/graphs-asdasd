#ifndef GRAPHS_ASDASD_PARSER_H
#define GRAPHS_ASDASD_PARSER_H

#include <iostream>
#include "json.hpp"
#include <fstream>

using namespace std;

int main(){
    //string filename="/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/json.hpp";

    ifstream filename("/Users/jonathanprieto/Documents/GitHub/graphs-asdasd/json.hpp");
    nlohmann::json j = nlohmann::json::parse(filename);
    cout << j <<endl;

    // file_input(filename);
    //nlohmann::json airports;
    //file_input >> airports;
    //cout<<airports<<endl;
}

#endif //GRAPHS_ASDASD_PARSER_H
