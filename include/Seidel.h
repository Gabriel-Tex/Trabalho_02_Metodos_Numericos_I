#ifndef SEIDEL_H
#define SEIDEL_H

#include "Sistema.h"
#include "Norma.h"
using namespace std;

vector<double> resolverSeidel(Sistema m, vector<double> b_coluna, double eps, int iterMax);

#endif