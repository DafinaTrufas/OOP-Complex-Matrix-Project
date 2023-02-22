#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <cmath>
#include <stdlib.h>

class Complex{
protected:
    double re, im;
public:
    Complex() {re = im = 0;}
    Complex(double a, double b) {re = a; im = b;}
    Complex(const Complex&);
    double get_re() {return re;}
    double get_im() {return im;}
    void set_re(double a) {re = a;}
    void set_im(double b) {im = b;}
    void citire();
    void afisare();
    friend std::istream& operator>>(std::istream&, Complex&);
    friend std::ostream& operator<<(std::ostream&, Complex&);
    double modul() {return sqrt(re*re + im*im);}
    void conjugat() {im = -im;}
    Complex& operator= (const Complex& );
    Complex operator+ (Complex&);
    Complex operator* (Complex&);
    Complex operator/ (Complex&);
    friend class Vector_Complex;
    friend class Matrice_Complexa;
    friend class Matrice_patratica;
};

Complex::Complex(const Complex& c)
{
    re = c.re;
    im = c.im;
}

void Complex::afisare()
{
    if(im == 0 && re == 0) std::cout << 0 << '\n';
    else if(im == 0) std::cout << re << '\n';
    else if (re == 0)
    {
        if(im > 0) std::cout << "i*" << im << '\n';
        else std::cout << "-i*" << -im << '\n';
    }
    else
    {
        if(im > 0) std::cout << re << "+i*" << im << '\n';
        else std::cout << re << "-i*" << -im << '\n';
    }
}

void Complex::citire()
{
    std::cin >> re >> im;
}

Complex& Complex::operator=(const Complex& c)
    {
        if (this != &c)
        {
            re = c.re;
            im = c.im;
        }
        return *this;
    }


Complex Complex::operator+(Complex& a)
{
    Complex b;
    b.re = re + a.re;
    b.im = im + a.im;
    return b;
}

Complex Complex::operator*(Complex& a)
{
    Complex b;
    b.re = re * a.re - im * a.im;
    b.im = re * a.im + im * a.re;
    return b;
}

Complex Complex::operator/(Complex& a)
{
    Complex b;
    b.re = (re * a.re + im * a.im) / (a.re * a.re + a.im * a.im);
    b.im = (im * a.re - re * a.im) / (a.re * a.re + a.im * a.im);
    return b;
}

std::istream& operator>>(std::istream& in, Complex& c)
{
    in >> c.re >> c.im;
    return in;
}

std::ostream& operator<<(std::ostream& out, Complex& c)
{
    if(c.im == 0 && c.re == 0) std::cout << 0;
    else if(c.im == 0) std::cout << c.re;
    else if (c.re == 0)
    {
        if(c.im > 0) std::cout << "i*" << c.im;
        else std::cout << "-i*" << -c.im;
    }
    else
    {
        if(c.im > 0) std::cout << c.re << "+i*" << c.im;
        else std::cout << c.re << "-i*" << -c.im;
    }
    return out;
}

#endif // COMPLEX_H_INCLUDED
