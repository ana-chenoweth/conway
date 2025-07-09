#include <iostream>
#include "console/EstablecerConsola.hpp"
#include "utils/FuncionesAuxiliares.hpp"


#define ENTER 13
#define ESCAPE 27

using namespace std;

int main()
{

    char tecla;
    int m, n;
    cout << "Capturando las dimensiones del tablero... \n\n";
    cout << "MAX (" << MAXREN << ") ";
    do {
        m = CapturarEntero("Filas: ");
        if (m > MAXREN) {
            cout << "El numero NO puede ser mayor a " << MAXREN << ". ";
        }
    } while (m < 1 || m > MAXREN);
    cout << endl;
    cout << "MAX (" << MAXCOL << ") ";
    do {
        n = CapturarEntero("Columnas: ");
        if (n > MAXCOL) {
            cout << "El numero NO puede ser mayor a " << MAXCOL << ". ";
        }
    } while (n < 1 || n > MAXCOL);
    CambiarCursor(APAGADO, NORMAL);
    return 0;
}


