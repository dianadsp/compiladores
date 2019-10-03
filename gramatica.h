#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include "produccion.h"


using namespace std;

class Gramatica{
public:
    vector<Cproduccion> production;
    set<string> terminales;
    set<string> noterminales;
    vector< vector<string> > getProduccion(string izq);
    void read(string text){
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
            production.push_back(Cproduccion(izq, var));
        }
    }
    
};