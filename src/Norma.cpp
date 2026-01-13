#include "Norma.h"

double calculaNorma(int n, vector<double>& x, vector<double>& v) {
    double normaNum = 0;
    double normaDen = 0;
    for (int i = 0; i < n; i++) {
        double t = abs(v[i] - x[i]);
        if (t > normaNum) normaNum = t;
        if (abs(v[i]) > normaDen) normaDen = abs(v[i]);
        x[i] = v[i]; 
    }
    return normaNum / normaDen;
}