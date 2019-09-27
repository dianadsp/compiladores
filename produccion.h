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
    Cproduccion();
    void cut_per_equal();//cortamos en el :=
    void cut_per_or();//cortamos en el |
    void no_spaces();// quitamos espacios 
};