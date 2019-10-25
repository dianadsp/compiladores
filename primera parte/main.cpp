#include <vector>
#include <set>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include "Analizador.h"
#include "tokens.h"
//#include "gramatica.h"

using namespace std;

int main(){
   
    /*AnalizadorSintacticoLL1 prueba1;
    prueba1.llenarTas();
    cout<<prueba1.reconocerSentencia("num + num + num + num");*/

    /*char linea[] = "variable3 = ( (1+2) * (3+4) )  * ( variable1 + variable 2 )";
    Ctokens* token;
	vector<Ctokens> tokens = token->analizadorLexico(linea);

    cout<<linea;
    for(int i = 0; i < tokens.size(); ++i){
        cout << "Palabra: " << tokens[i].expression<< endl;
    }

    if(token->getCOM(tokens).first!=-1){
        cout<<"se reconoce"<<endl;
    }
    else{
        cout<<"no se reconoce"<<endl;
    }*/

    Gramatica g;
    /*g.read("O  := S P");
    g.read("S := Det Sus");
    g.read("P := V Obj");
    g.read("Det := el | la");
    g.read("Sus := ninho | ninha");
    g.read("V := corre | grita");
    g.read("Obj := mucho | poco");*/

    g.read("Sustantivo[gen=?g] := Det[gen=?g] Sustantivo[gen=?g]");
    g.read("Det[gen=f] := la");
    g.read("Det[gen=m] := el");
    g.read("Sustantivo[gen=f] := ninha");
    g.read("Sustantivo[gen=m] := ninho");
    vector< vector<string> > prod=g.getProduccion("Sustantivo[gen=f]");

	for(int i = 0; i < prod.size();i++){
		for(int j = 0; j < prod[i].size();j++){
			cout<<prod[i][j]<< "  ";
		}
		cout << endl;
	}
    
    //g.print_production();

    /*char linea[] = "la ninha corre mucho \n";
    Ctokens* token;
	vector<Ctokens> tokens = token->analizadorLexico(linea);

    cout<<linea;
    for(int i = 0; i < tokens.size(); ++i){
        cout << "Palabra: " << tokens[i].expression<< endl;
    }*/

    /*AnalizadorSintacticoLL1 sin;
    sin.llenarTas();
    cout << sin.reconocerSentencia(linea) << endl;*/
    
    return 0;
}