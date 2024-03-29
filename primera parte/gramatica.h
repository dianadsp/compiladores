#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include "produccion.h"


using namespace std;

class Gramatica{
public:
    string estadoInicial;
    vector<Produccion> production;
    set<string> terminales;
    set<string> noterminales;
    Gramatica(){};
    vector< vector<string> > getProduccion(string izq);
    void read(string text);
    ProdContexto getContexto(string);
};