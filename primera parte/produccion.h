#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <map> 

using namespace std;

class ProdContexto{
public:
    string nombre;
    map<string,string> contexto;
    ProdContexto(string& _nombre,map<string,string>& _contexto):nombre(_nombre),contexto(_contexto){}
};

class Produccion{
public:
    ProdContexto izq;
    vector<string> der;
    bool terminal;
    bool compare();
    Produccion(ProdContexto _izq, vector<string> _der): izq(_izq), der(_der){}
    string no_spaces(string);// quitamos espacios 
    
};



class ProduccionRegla{
    ProdContexto izq;
    vector<ProdContexto > der;
};

class ProduccionLexico{
    ProdContexto izquierdo;
    vector<string > izq;
};