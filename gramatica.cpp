#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include "gramatica.h"


using namespace std;

vector< vector<string> > Gramatica::getProduccion(string izq){
    vector< vector<string> > result;
    for(int i = 0; i < production.size(); ++i){
        if(production[i].izq == izq){
            result.push_back(production[i].der);
        }
    }
    return result;
}

void Gramatica::read(string text){
    string izq = text.substr(0, text.find(":="));
    string der = text.substr(text.find(":=")+2);
    string result = "";
    for(int i = 0; i < izq.size(); ++i){
        if(izq[i]!=' '){
            result += izq[i];
        }
    }
    izq=result;
    stringstream right(der);
    string temp;
    while(getline(right, temp, '|')){
        vector<string> var;
        stringstream sub_token(temp);
        string tmp;
        while(getline(sub_token, tmp, ' ')){
            string result = "";
            for(int i = 0; i < tmp.size(); ++i){
                if(tmp[i] != ' '){
                    result += tmp[i];
                }
            }
            tmp=result;
            if(tmp != ""){
                var.push_back(tmp);
            }
        }
        production.push_back(Produccion(izq, var));
    }
    }