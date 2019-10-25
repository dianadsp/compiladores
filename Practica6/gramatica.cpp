#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include "gramatica.h"
typedef map<string,string>::iterator integer;


using namespace std;

vector< vector<string> > Gramatica::getProduccion(string izq){
    vector< vector<string> > result;
    ProdContexto contexto= getContexto(izq);

    for(int i = 0; i < production.size(); i++){
        if(production[i].izq.nombre == contexto.nombre){
            map<string,string> map1=production[i].izq.contexto;
            map<string,string> map2=contexto.contexto;
            bool valido;
            for (integer k = map2.begin(); k!=map2.end(); ++k){
                valido=false;
                for (integer j = map1.begin(); j!=map1.end(); ++j){
                    if (j->first==k->first && j->second==k->second){
                        valido=true;
                    }                    
                }
                if(!valido)break;
            }
            if (valido){
                result.push_back(production[i].der);
            }               
        }
    }
    return result;
}

void Gramatica::read(string text){
    stringstream ss(text);
	string izq,igual,aux;
	ss >> izq;
	ProdContexto contexto = getContexto(izq);
	ss >> igual;
	if(igual != ":="){
		cout <<"error"<<endl;
		return;
	}
	vector<string> der;
	while (ss >> aux) 
	{
		der.push_back(aux);
		if(aux == "|"){
			production.push_back(Produccion(contexto,der));
			der.clear();
		}
	}
	production.push_back(Produccion(contexto,der));

    /*string izq = text.substr(0, text.find(":="));
    string der = text.substr(text.find(":=")+2);
    string result = "";
    for(int i = 0; i < izq.size(); ++i){
        if(izq[i]!=' '){
            result += izq[i];
        }
    }
    izq=result;

    stringstream tokens_der(der);
    string temp;
    while(getline(tokens_der, temp, '|')){
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
    }*/

}

ProdContexto Gramatica::getContexto(string linea){
    map<string,string> cont;
    size_t tmp1,tmp2,tmp3;
    tmp1=tmp3=linea.find("[");
    string palabra=linea.substr(0,tmp1);
    cout<<"Expresion: "<<linea<<endl;
    cout<<"Nombre: "<<palabra<<endl;
    while (++tmp3<linea.size()){
        tmp1=tmp3;
        tmp2=linea.find("=",tmp3)+1;
        tmp3=linea.find(",",tmp3);
        if(tmp3>linea.size()){
            tmp3=linea.find("]");
        }

        string map1=linea.substr(tmp1,tmp2-tmp1-1);
        //cout<<"AQUII: "<<map1<<endl;
        string map2=linea.substr(tmp2,tmp3-tmp2);
        //cout<<"AQUII2: "<<map2<<endl;
        cont[map1]=map2;
        cout<<"Condicion: "<<map1<<" -> "<<map2<<endl;
    } 
    cout<<endl;
    return ProdContexto(palabra,cont);
}