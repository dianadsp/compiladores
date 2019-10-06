#include <vector>
#include <set>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include "Analizador.h"

using namespace std;

int main(){
   
    AnalizadorSintacticoLL1 prueba1;
    prueba1.llenarTas();
    cout<<prueba1.reconocerSentencia("num + num + num + num");


    return 0;
}