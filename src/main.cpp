#include <iostream>
#include <iomanip>
#include "Sistema.h"
#include "Norma.h"
#include "Jacobi.h"
#include "Seidel.h"
using namespace std;

Sistema sistema = {
    3, // n
    {  // A
        {5, 3, 1},
        {5, 6, 1},
        {1, 6, 7}
    },
    {1, 2, 3} // b
};

int main() {

    double eps = 0.0001;
    int maxIt = 100;


    vector<vector<double>> inversa(sistema.n, vector<double>(sistema.n));

    cout << fixed << setprecision(4);
    cout << "Calculando a Inversa de A e o vetor de deslocamento d..." << endl;


    for (int j = 0; j < sistema.n; j++) {
        vector<double> e(sistema.n, 0.0);
        e[j] = 1.0; 
        
        vector<double> col_inversa = resolverSeidel(sistema, e, eps, maxIt);

        for (int i = 0; i < sistema.n; i++) {
            inversa[i][j] = col_inversa[i];
        }
    }

    vector<double> d(sistema.n, 0.0);
    bool perigo = false;

    cout << "\nVetor deslocamento {d}:" << endl;
    for (int i = 0; i < sistema.n; i++) {
        for (int j = 0; j < sistema.n; j++) {
            d[i] += inversa[i][j] * sistema.b[j];
        }
        cout << "d[" << i+1 << "] = " << d[i] << " cm" << endl;
        if (abs(d[i]) > 0.4) perigo = true;
    }

    if (perigo) {
        cout << "\nALERTA: Ocorrerão danos sérios (deslocamento > 0.4 cm)!" << endl;
    } else {
        cout << "\nSISTEMA SEGURO: Deslocamentos dentro do limite." << endl;
    }

    return 0;
}