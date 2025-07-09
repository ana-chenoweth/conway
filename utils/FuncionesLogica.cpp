#include "FuncionesLogica.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::setw;

void GeneracionNueva(tipo **&matrizVivos, tipo **&matrizVecinos, int m , int n)
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(matrizVivos[i][j] == 0){
                if(matrizVecinos[i][j] == 3){
                    matrizVivos[i][j] = 1;
                }
            } else{
                if(matrizVecinos[i][j] !=3 && matrizVecinos[i][j] !=2){
                    matrizVivos[i][j] = 0;
                }
            }
        }
    }

}
//**********************************************************************************
void PonerVecinos( tipo **&arreglo, tipo **&Vecinos, int m, int n)
{
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                Vecinos[i][j] = 0;
            }
        }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(arreglo[i - 1][j] == 1) Vecinos[i][j] +=1;
            if(arreglo[i + 1][j] == 1) Vecinos[i][j] +=1;
            if(arreglo[i][j - 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i][j + 1] == 1) Vecinos[i][j] +=1;

            if(arreglo[i - 1][j - 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i + 1][j + 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i - 1][j + 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i + 1][j - 1] == 1) Vecinos[i][j] +=1;
        }
    }

}
//*************************************************************************
void **BichosVivosMuertos(tipo **&matrizVivos, int m , int n)
{
    srand(time(NULL));
    for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                    matrizVivos[i][j] = rand() % 2;
                }
    }
}
