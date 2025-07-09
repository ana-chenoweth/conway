#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "console/EstablecerConsola.hpp"
#include "utils/FuncionesAuxiliares.hpp"
#include "utils/FuncionesLogica.hpp"

#define ENTER 13
#define ESCAPE 27

using namespace std;

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

bool kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}

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

    std::cout << "\033[2J\033[H"; // limpia la pantalla;

    cout << "Pulsa ENTER para empezar: ";

    try {
        tipo **Actual = Crear(m+2, n+2);
        tipo **Siguiente = Crear(m+2, n+2);

        BichosVivosMuertos(Actual, m , n);

        while(true){
            if(kbhit()){
                tecla = getch();
                if(tecla == ESCAPE) break;
                if(tecla == ENTER){
                    MoverCursor(2,4);
                    cout << endl << endl;
                    Imprimir(Actual, m, n);

                    PonerVecinos(Actual, Siguiente, m, n);
                    //Ahora la Siguiente tiene el numero de vecinos
                    cout << endl << endl;
                    GeneracionNueva(Actual, Siguiente, m, n);
                    //Ahora la actual tiene el numero de bichos vivos

                }
            }
        }
        Destruir(Actual);
        Destruir(Siguiente);
    } catch (const bad_alloc &) {
        cout << "Error en la asignacion de memoria" << endl;
    } catch (const char *msn) {
        cerr << "Error: " << msn << endl;
    } catch (...) {
        cout << "Ocurrio un error inesperado" << endl;
    }
    CambiarCursor(ENCENDIDO, NORMAL);

    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();;
    return 0;
}


