#ifndef VECTOR_COMPLEX_H_INCLUDED
#define VECTOR_COMPLEX_H_INCLUDED

#include <iostream>
#include <cmath>
#include <stdlib.h>

/// Scopul clasei Vector_Complex este acela de a supraincarca a doua oara operatorul[], pentru a putea accesa, pentru un obiect M
/// de tip Matrice_Complexa, componenta (i, j), prin M[i][j].

class Vector_Complex{
    int n;
    Complex *v;
    public:
    Vector_Complex(){v = NULL;}
    Vector_Complex(Complex c, int dim) {v = new Complex[dim]; for(int i = 0; i < dim; i++) v[i] = c;}
    ~Vector_Complex() {delete [] v;}
    void set_n(int dim) {n = dim;}
    int get_n() {return n;}
    void citire() {std::cin >> n; v = new Complex[n]; for(int i = 0; i < n; i++) std::cin >> v[i];}
    void afisare() {std::cout << n << '\n'; for(int i = 0; i < n; i++) std::cout << v[i] << ' ';}
    Complex operator[](int);
    friend class Matrice_Complexa;
    friend class Matrice_patratica;
};

Complex Vector_Complex::operator[](int i)
{
    return v[i];
}

#endif // VECTOR_COMPLEX_H_INCLUDED
