#include "produccion.h"

class EstadoCompilador {
    EstadoCompilador();
    Produccion *produccionRef;
    int posAsterico;
    int posPalabra;
    EstadoCompilador *origen;
    void dummy();
};
