#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Cproduccion{
    public:
    string izq;
    vector<string> der;
    string izquierda;
    vector<string> production;
    bool terminal;
    bool compare();
    Cproduccion(string);
    Cproduccion(string _izq, vector<string> _der):izq(_izq), der(_der){};
    string no_spaces(string);// quitamos espacios 
};