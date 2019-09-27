#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Cproduccion{
    string izquierda;
    vector<string> production;
    bool terminal;
    bool compare();
    Cproduccion(string);
    vector<string> cut_per_equal();//cortamos en el :=
    vector<string> cut_per_or();//cortamos en el |
    string no_spaces(string);// quitamos espacios 
};