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
    vector<Cproduccion> production;
    set<string> terminales;
    set<string> noterminales;
    vector< vector<string> > getProduccion(string izq);
    void read(string text);
    
};