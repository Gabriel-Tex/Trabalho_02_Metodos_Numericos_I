#include "Seidel.h"

vector<double> resolverSeidel(Sistema m, vector<double> b_coluna, double eps, int iterMax) {
    int n = m.n;
    vector<double> x(n);
    vector<double> v(n);

    for (int i = 0; i < n; i++) {
        double r = 1.0 / m.A[i][i];
        for (int j = 0; j < n; j++) {
            if (i != j) m.A[i][j] *= r;
        }
        b_coluna[i] *= r;
        x[i] = b_coluna[i];
    }

    int k = 0;
    double norma;
    do {
        k++;
        for (int i = 0; i < n; i++) {
            double soma = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) soma += m.A[i][j] * x[j];
            }
            v[i] = x[i];
            x[i] = b_coluna[i] - soma;
        }
        norma = calculaNorma(n, v, x); 
    } while (norma > eps && k < iterMax);

    return x;
}