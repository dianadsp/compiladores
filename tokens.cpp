#include "tokens.h"
#include <string.h>
#include <iostream>
using namespace std;

Ctokens::Ctokens(char* entrada){
    this->tam=strlen(entrada);
    this->indice=0;
    //this->expression=new char[this->tam];
    //for(int i=0;i<tam;i++){
      //  this->expression[i]=entrada[i];
    //}
    this->expression=entrada;
    
}


//es numero
bool Ctokens::is_number(char cad){
    if (cad >57 )
        return false;
    if (cad < 48 )
        return false;  

    return true;
}


// es operador
bool Ctokens::is_operator(char cad){
    if (cad==43 )// +
        return true;
    if (cad==45 )// -
        return true;  
    if (cad==42)// *
        return true;
    if (cad==47)// ./.
        return true;
    return false;
}

bool is_equal(char cad){
    if(cad==61) // =
        return true;
    return false;
}


//es expresión1
bool Ctokens::is_exp1(){
    int i=this->indice;
    while(this->is_number(this->expression[i])){
                i++;
    }
    if(this->is_operator(this->expression[i])){
        while (this->is_number(this->expression[i]))
        {
            i++;
        }
        this->indice=i;
        return true;
    }
    else {return false;}
        
    return false;
}

//es expresión2
bool Ctokens::is_exp2(){
    int i=this->indice;
    if(this->expression[i]==40){// (
        this->indice++;
        if(this->is_expression()){
            if (this->expression[this->tam]==41){// )
                this->indice=i;
                return true;
            }   
        }        
    }    
    return false;
}



bool Ctokens::is_exp3(){
   /* int i=this->indice;
    if(this->is_validVariableName()){
        return true;
    }
    while(this->is_number(this->expression[i])){
                i++;
    }

    this->indice=i;*/
}


//es expresión en general
bool Ctokens::is_expression(){
    if(this->is_exp1 || this->is_exp2)
        return true;
    return false;
}

bool Ctokens::get_equal(){

}

bool Ctokens::is_validVariableName(){
    int i = this->indice;
    if((this->expression[i]>65 &&this->expression[i]<90) ||(this->expression[i]>97 &&this->expression[i]<122)){
        i++;
        for( ;i<this->tam;i++) {
            if (!(((this->expression[i] >57)&&(this->expression[i] < 48) ) || (this->expression[i]>65 &&this->expression[i]<90)||(this->expression[i]>97 &&this->expression[i]<122))){
                this->indice=i;
                return false;
            }
        }
        this->indice=i;
        return true;
    }
    return false;
}

