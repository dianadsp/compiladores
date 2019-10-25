#include <string.h>
#include <iostream>
#include "tokens.h"
#include <stdio.h>

using namespace std;

int main(){
    char* pal=new char[40];
    std::cout<<": ";
    cin>>pal;
    Ctokens palabra(pal);
    cout<<palabra.expression;
    return 0;
}