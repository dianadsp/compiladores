
class Ctokens{
public:	// Variables y funciones de la clase de ámbito público
    char* expression;
    int tam;
    int indice;
	Ctokens(char*);	// Constructor 
	bool is_exp1();
    bool is_exp2();
    bool is_exp3();
    bool is_number(char);
    bool is_operator(char);
    bool is_expression();
    bool is_validVariableName();
    bool get_equal();
    bool is_equal(char);
};