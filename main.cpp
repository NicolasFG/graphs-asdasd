#include <iostream>
#include "parser.h"
using namespace std;

int main(){
    for (int i = 0; i < sizearray(); ++i) {
        cout<<parse(i)<<endl;
    }
}