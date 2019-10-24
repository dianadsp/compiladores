#include "tokens.h"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

/*Ctokens::Ctokens(char* expr,int index){
    this->expression=expr;
    this->indice=index;
}*/

Coord Ctokens::getEXPR1(vector<Ctokens>& tokens,int inicio,int fin){
    for (int i = inicio; i < fin; i++){
        if(tokens[i].tipo=='O'){
            Coord expr=getEXPR(tokens,inicio,i-1);
            if(expr.first!=-1){
                Coord expr1=getEXPR(tokens,i+1,fin);
                if(expr1.first!=-1){
                    return make_pair(inicio,fin);
                }
            }
        }
    }
    return make_pair(-1,-1);  
}

Coord Ctokens::getEXPR2(vector<Ctokens>& tokens,int inicio,int fin){
    if(*(tokens[inicio].expression)=='(' && *(tokens[fin].expression)==')'){
        Coord expr=getEXPR(tokens,inicio+1,fin-1);
        if(expr.first!=-1){
            return make_pair(inicio,fin);
        }
    }
    return make_pair(-1,-1);
}

Coord Ctokens::getEXPR3(vector<Ctokens>& tokens,int inicio,int fin){
    if(inicio==fin){
        if(tokens[inicio].tipo=='V' || tokens[inicio].tipo=='E'){
            return make_pair(inicio,fin);
        }
    }
    return make_pair(-1,-1);
}


Coord Ctokens::getEXPR(vector<Ctokens>& tokens,int inicio,int fin){
    Coord expr1=getEXPR1(tokens,inicio,fin);
    if(expr1.first!=-1){
        return make_pair(inicio,fin);
    }
    Coord expr2=getEXPR2(tokens,inicio,fin);
    if(expr2.first!=-1){
        return make_pair(inicio,fin);
    }
    Coord expr3=getEXPR3(tokens,inicio,fin);
    if(expr3.first!=-1){
        return make_pair(inicio,fin);
    }
    return make_pair(-1,-1);
}

Coord Ctokens::getIGUALDAD(vector<Ctokens>& tokens,int inicio,int fin){
    if(tokens[inicio].tipo=='V' && tokens[inicio+1].tipo=='I'){
        Coord expr=getEXPR(tokens,inicio+2,fin);
        if(expr.first!=-1){
            return make_pair(inicio,fin);
        }
    }
    return make_pair(inicio,fin);    
}

Coord Ctokens::getCOM( vector<Ctokens>& tokens){
    Coord expr = getEXPR(tokens, 0, tokens.size()-1);
	if(expr.first!=-1){
		return expr;	
    }
	Coord igualdad = getIGUALDAD(tokens, 0, tokens.size()-1);
	if(igualdad.first!=-1){
		return igualdad;
    }	
	return make_pair(-1,-1);
}

Ctokens Ctokens::reconocerNumero(char** ptr,int& i){
    Ctokens palabra;
    char* pal=new char;
    palabra.tipo='E';
    palabra.indice=i;
    int pos=0;
    while((**ptr>='0' && **ptr<='9')){
        *(pal+pos)=**ptr;
        pos++;
        (*ptr)++;
    }  
    *(pal+pos)='\0';
    i=i+pos;
    palabra.expression=pal;
    return palabra;    
}


Ctokens Ctokens::reconocerVariable(char** ptr,int& i){
    Ctokens palabra;
    char* pal=new char;
    palabra.tipo='V';
    palabra.indice=i;
    int pos=0;
    while((**ptr>='A' && **ptr<='Z') || (**ptr>='a' && **ptr<='z') || (**ptr>='0' && **ptr<='9')){
        *(pal+pos)=**ptr;
        pos++;
        (*ptr)++;
    }  
    *(pal+pos)='\0';
    i=i+pos;
    palabra.expression=pal;
    return palabra;
}

Ctokens Ctokens::reconocerOperador(char** ptr, int& i){
    Ctokens palabra;
    char* pal=new char;
    if(**ptr=='='){
        palabra.tipo='I';
    }
    else if(**ptr=='(' or **ptr==')'){
        palabra.tipo='P';
    }
    else{
        palabra.tipo='O';
    }

    palabra.indice=i;
    *pal=**ptr;
    (*ptr)++;
    i++;
    palabra.expression=pal;
    return palabra;
}


vector<Ctokens> Ctokens::analizadorLexico(char* linea){
    vector<Ctokens> tokens;
    int pos=0;
    while (*linea !='\0'){
        if(*linea>= '0' && *linea<='9'){
            Ctokens token=reconocerNumero(&linea,pos);
            tokens.push_back(token);
        }
        else if(*linea>='A' && *linea<='Z'){
            Ctokens token=reconocerVariable(&linea,pos);
            tokens.push_back(token);

        }
        else if(*linea>='a' && *linea<='z'){
            //cout<<*linea<<endl;
            Ctokens token=reconocerVariable(&linea,pos);
            tokens.push_back(token);
        }
        else if(*linea=='+'){
            //cout<<*linea<<endl;
            Ctokens token=reconocerOperador(&linea,pos);
            tokens.push_back(token);

        }
        else if(*linea=='-'){
            //cout<<*linea<<endl;
            Ctokens token=reconocerOperador(&linea,pos);
            tokens.push_back(token);

        }
        else if(*linea=='*'){
            //cout<<*linea<<endl;
            Ctokens token=reconocerOperador(&linea,pos);
            tokens.push_back(token);

        }
        else if(*linea=='/'){
            //cout<<*linea<<endl;
            Ctokens token=reconocerOperador(&linea,pos);
            tokens.push_back(token);

        }
        else if(*linea=='='){
            //cout<<*linea<<endl;
            Ctokens token=reconocerOperador(&linea,pos);
            tokens.push_back(token);
        }
        else if(*linea=='(' or *linea==')'){
            //cout<<*linea<<endl;
            Ctokens token=reconocerOperador(&linea,pos);
            tokens.push_back(token);
        }
        else{
            //cout<<*linea<<endl;
            linea++;
            pos++;
        }
    }
    return tokens;
}
