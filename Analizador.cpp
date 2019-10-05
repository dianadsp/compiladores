#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <iterator> 
#include <map> 
#include <stack>
#include <queue>
#include "Analizador.h"

using namespace std;
void AnalizadorSintacticoLL1::adicionar(string noTerminal, string terminal, vector<string> v){
    tas[noTerminal][terminal] = v;
}

void AnalizadorSintacticoLL1::llenarTas(){
    adicionar( "E", "(", {"T", "Ep"} );
    adicionar( "E","num", {"T","Ep"} );
    adicionar( "E","id", {"T","Ep"} );
    adicionar( "Ep","+", {"+","T","Ep"} );
    adicionar( "Ep","-", {"-","T","Ep"} );
    adicionar( "Ep",")", {"lambda"} );
    adicionar( "Ep",DOLAR, {"lambda"} );
    adicionar( "T", "(", {"F", "Tp"} );
    adicionar( "T", "num", {"F", "Tp"} );
    adicionar( "T", "id", {"F", "Tp"} );
    adicionar( "Tp", "+", {"lambda"} );
    adicionar( "Tp", "-", {"lambda"} );
    adicionar( "Tp", "*", {"*","F", "Tp"} );
    adicionar( "Tp", "/", {"/","F", "Tp"} );
    adicionar( "Tp", "*", {"*","F", "Tp"} ); 
    adicionar( "Tp", ")", {"lambda"} );
    adicionar( "Tp", DOLAR, {"lambda"} );
    adicionar( "F", "(", {"(", "E", ")"} );
    adicionar( "F", "num", {"num"} );
    adicionar( "F", "id", {"id"} );

}

bool AnalizadorSintacticoLL1::reconocerSentencia(string cadena){
    Gramatica gram;
    queue<string> entrada;
    entrada.push(cadena);
    stack<string> pila;
    pila.push(DOLAR);
    pila.push(gram.estadoInicial);
    entrada.push(DOLAR);
    while(!entrada.empty() && !pila.empty()){
        if(entrada.front()==pila.top()){            
            entrada.pop();
            pila.pop();
        }
        else{
            string tmp=pila.top();
            pila.pop();
            for (auto x : tas[tmp][entrada.front()]){  
                if (x!="lambda"){
                    pila.push(x);
                }                
            }         
        }
    }
    return entrada.empty() && pila.empty();
}
