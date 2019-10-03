#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <iterator> 
#include <map> 
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

bool AnalizadorSintacticoLL1::reconocerSentencia(string sentencia){

}