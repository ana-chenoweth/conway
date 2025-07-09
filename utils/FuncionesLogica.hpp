#ifndef FUNCIONESLOGICA_HPP_INCLUDED
#define FUNCIONESLOGICA_HPP_INCLUDED
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

#define MAXREN 33
#define MAXCOL 35
#define MAXELEM 20


typedef int tipo;

void PonerVecinos(tipo **&arreglo, tipo **&Vecinos, int m, int n);
void GeneracionNueva(tipo **&matrizVivos, tipo **&matrizVecinos, int m , int n);
void **BichosVivosMuertos(tipo **&matrizVivos, int m , int n);

#endif // FUNCIONESLOGICA_HPP_INCLUDED
