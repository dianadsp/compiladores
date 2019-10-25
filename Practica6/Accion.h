#include "EstadoCompilador.h"
#include <queue>

using namespace std;

class Accion {
public:
    virtual bool sePuedeAplicar( EstadoCompilador *estado) = 0;
    virtual void aplica(EstadoCompilador *estado, queue<EstadoCompilador*> chart) = 0;
};