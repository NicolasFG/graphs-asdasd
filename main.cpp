#include <iostream>
#include "parser.h"
using namespace std;

int main(){
    nlohmann::json jvalues = nlohmann::json::parse(filename);
    for (int i = 0; i < sizearray(jvalues); ++i) {
       cout<<parse(i,jvalues)<<endl;
    }
}