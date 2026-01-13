#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
using namespace std;

struct Sistema {
    int n;
    vector<vector<double>> A;
    vector<double> b;
};

#endif