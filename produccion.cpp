#include "produccion.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string Produccion::no_spaces(string input){
    string output;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == ' ') {
            continue;
        } else {
            output += input[i];
        }
    }
    return output;
}



