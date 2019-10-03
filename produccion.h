#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Produccion{
public:
    string izq;
    vector<string> der;
    string izquierda;
    vector<string> production;
    bool terminal;
    bool compare();
    Produccion(string _izq, vector<string> _der):izq(_izq), der(_der){};
    string no_spaces(string);// quitamos espacios 
};