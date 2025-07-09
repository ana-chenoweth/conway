#include "FuncionesAuxiliares.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::setw;

//*************************************************
int CapturarEntero(const char solicitud[])
{
    int x;
    cout << solicitud;
    cin >> x;
    while(cin.fail() || x != (int)x){
        cout << "Error: valor no valido";
        if(cin.fail()){
            cout << ", se espera un numero" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
        }else{
            cout << ", se espera un numero entero" << endl;
        }
        cout << solicitud;
        cin >> x;
    }
    return x;
}
//**********************************************************************************
void Imprimir(tipo **arreglo, int m, int n)
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
                if(arreglo[i][j]){
                    cout << setw(4) << '*';
                }
                else {
                        cout << setw(4) << " ";}
            }
            cout << endl;
        }
}
//**********************************************************************************
tipo **Crear(int m, int n)
{
    tipo **arreglo = new tipo *[m];
    arreglo[0] = new tipo[m * n];
    for (int i = 1; i < m; ++i)
        arreglo[i] = arreglo[0] + i * n;

    return arreglo;
}

//*************************************************
void Destruir(tipo **&arreglo)
{
    delete[] arreglo[0];
    delete[] arreglo;
    arreglo = nullptr;
}
