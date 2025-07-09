#include "EstablecerConsola.hpp"
#include <iostream>

using std::cout;

// Mueve el cursor a la posición (x, y). En ANSI, el origen es (1,1)
void MoverCursor(short x, short y) {
    cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

// Cambia la visibilidad del cursor
void CambiarCursor(EstadoCursor estado, ModoCursor /*modo*/) {
    if (estado == APAGADO) {
        cout << "\033[?25l"; // Ocultar cursor
    } else {
        cout << "\033[?25h"; // Mostrar cursor
    }
}
