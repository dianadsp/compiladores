#include "produccion.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
Cproduccion::Cproduccion (string entrada){
    entrada=this->no_spaces(entrada);
}

string Cproduccion::no_spaces(string input){
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

vector<string> Cproduccion::cut_per_equal(){
    vector<string> output;
   // for(int i = 0; i < input.length(); i++) {
     //   if(input[i] == ':') {
       //     if()
         //   continue;
        //} else {
         //   output += input[i];
        //}
   // }
    return output;
}

