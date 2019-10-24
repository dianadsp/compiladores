#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <iterator> 
#include <map> 
#include "gramatica.h"


using namespace std;
class AnalizadorSintacticoLL1{
private:
  Gramatica gr;
  map<string, map<string, vector<string> > > tas;
  void adicionar(string noTerminal, string terminal, vector<string> prod);
  const string DOLAR = "$";
public:
  void llenarTas();
  bool reconocerSentencia(string sentencia);
};