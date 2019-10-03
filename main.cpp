#include <vector>
#include <set>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include "produccion.h"
#include "gramatica.h"

using namespace std;





int main(){
    Gramatica gram;
    gram.read("E  := T Ep");
    gram.read("Ep := + T Ep");
    gram.read("Ep := - T Ep");
    gram.read("Ep := lambda");
    gram.read("T  := F Tp");
    gram.read("Tp := * F Tp  |  /  F Tp  | lambda");
    gram.read("F  := ( E ) | num | id");
    cout << endl;
    cout << endl;
    cout<<"\t+\t-\t*\t/\t(\t)\tnum \t id \t $"<<endl;
    for(int i = 0; i < gram.production.size()-1; i=i+2){
        vector< vector<string> > produc = gram.getProduccion(gram.production[i].izq);
        cout << gram.production[i].izq << "\t";
        for(int j = 0; j < produc.size(); j++){            
            for(int k = 0; k < produc[j].size(); k++){
                cout << produc[j][k] <<"\t";
            }
            cout <<"\t ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    return 0;
}