#ifndef FUNCIONESAUXILIARES_HPP_INCLUDED
#define FUNCIONESAUXILIARES_HPP_INCLUDED
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

#define MAXREN 33
#define MAXCOL 35
#define MAXELEM 20


typedef int tipo;

void Imprimir(tipo **arreglo, int m, int n);

tipo **Crear(int m, int n);
void Destruir(tipo **&arreglo);

int CapturarEntero(const char solicitud[]);

#endif // FUNCIONESAUXILIARES_HPP_INCLUDED
