#include <vector>
using namespace std;
typedef pair<int,int> Coord;

class Ctokens{
public:	// Variables y funciones de la clase de ámbito público
    char* expression;
    int tam;
    int indice;
    char tipo;//E (entero), V (variable), O (operador), I(Igual), P(parentesis)

	//Ctokens(char*,int);
    vector<Ctokens> analizadorLexico(char*);
    Ctokens reconocerNumero(char**,int&);
    Ctokens reconocerVariable(char**,int&);
    Ctokens reconocerOperador(char**,int&);
	
    Coord getEXPR1(vector<Ctokens>&,int,int);
    Coord getEXPR2(vector<Ctokens>&,int,int);
    Coord getEXPR3(vector<Ctokens>&,int,int);
    Coord getEXPR(vector<Ctokens>&,int,int);
    Coord getIGUALDAD(vector<Ctokens>&,int,int);
    Coord getCOM( vector<Ctokens>&);
};