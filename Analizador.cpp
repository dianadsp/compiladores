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
    stack<string> pila;
    pila.push(DOLAR);
    pila.push(gram.estadoInicial);
    entrada.push(DOLAR);

/////////dividir la cadena en palabras e ingresarla a la pila
    std::istringstream isstream(cadena);
    while(!isstream.eof()){
        std::string tempStr;
        isstream >> tempStr;
        //  cout<<"parte de la cadena: "<<tempStr<<endl;
        entrada.push(tempStr);
    }
    

    while(!entrada.empty() && !pila.empty()){
        if(entrada.front()==pila.top()){ 
            cout<<"son iguales saco ambos: "<<pila.top();           
            entrada.pop();
            pila.pop();
        }
        else{
            string tmp=pila.top();
            cout<<"no son iguales, saco esto de la pila: "<<tmp<<" --";           
            pila.pop();
            for (auto x : tas[tmp][entrada.front()]){  
                if (x!="lambda"){
                    cout<<"guardo esto"<<x;
                    pila.push(x);
                }                
            }         
        }
        cout<<endl;
    }
    return entrada.empty() && pila.empty();
}
