#ifndef JACOBI_H
#define JACOBI_H

#include <vector>
#include "Sistema.h"
#include "Norma.h"
using namespace std;


vector<double> Jacobi(Sistema m, vector<double> b_coluna, double eps, int iterMax);

#endif
