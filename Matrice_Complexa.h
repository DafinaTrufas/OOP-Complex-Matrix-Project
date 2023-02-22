#ifndef MATRICE_COMPLEXA_H_INCLUDED
#define MATRICE_COMPLEXA_H_INCLUDED

#include <cmath>
#include <stdlib.h>
#include <iostream>

int ok;

class Matrice_Complexa{
protected:
    int n, m;
    Complex **mat;
    static int nrp;
public:
    void alloc(int n, int m){this->n = n; this->m = m; mat = new Complex*[n]; for(int i = 0; i < n; i++) mat[i] = new Complex[m];}
    Matrice_Complexa(){n = m = 0; mat = NULL;}
    Matrice_Complexa(Complex c, int dim1, int dim2);
    ~Matrice_Complexa(){for(int i = 0; i < n; i++) delete[] mat[i]; delete[] mat;}
    Matrice_Complexa (const Matrice_Complexa&);
    void set_n(int nl) {n = nl;};
    void set_m(int nc) {m = nc;};
    int get_n() {return n;}
    int get_m() {return m;}
    virtual void citire();
    virtual void afisare();
    Complex urma();
    Matrice_Complexa transpusa();
    Matrice_Complexa elim(int, int);
    Complex determinant();
    Complex determinant1();
    Complex determinant2();
    bool inversabila();
    bool operator==(const Matrice_Complexa&);
    Matrice_Complexa& operator=(const Matrice_Complexa&);
    Matrice_Complexa operator+(const Matrice_Complexa&);
    Matrice_Complexa operator+(Complex);
    friend Matrice_Complexa operator+(Complex, const Matrice_Complexa&);
    Matrice_Complexa operator*(const Matrice_Complexa&);
    Matrice_Complexa operator^(int);
    Vector_Complex operator[](int);
    Matrice_Complexa inversa();
    void citire_mat(int, int);
    friend std::istream& operator>>(std::istream&, Matrice_Complexa&);
    friend std::ostream& operator<<(std::ostream&, Matrice_Complexa&);
    operator Complex();
    static void nr_patratice(){std::cout << nrp << '\n';}
};

int Matrice_Complexa::nrp = 0;

Matrice_Complexa::Matrice_Complexa(Complex c, int dim1, int dim2)
{
    if(dim1 <= 0) throw 1;
    if(dim2 <= 0) throw 'c';
    n = dim1;
    m = dim2;
    alloc(n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i][j] = c;
}

void Matrice_Complexa::citire_mat(int n, int m)
{
    alloc(n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            std::cin >> mat[i][j];
}

void Matrice_Complexa::citire()
{
    std::cin >> n >> m;
    if(n <= 0) throw 1;
    if(m <= 0) throw 'c';
    citire_mat(n, m);
}

void Matrice_Complexa::afisare()
{
    //if(n != m) std::cout << "Numar de linii: " << n << '\n' << "Numar de coloane: " << m << '\n';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            std::cout << mat[i][j] << ' ';
        std::cout << '\n';
    }
}

Matrice_Complexa::Matrice_Complexa (const Matrice_Complexa& mc)
{
    n = mc.n;
    m = mc.m;
    mat = new Complex*[mc.n];
    for(int i = 0; i < mc.n; i++)
    {
        mat[i] = new Complex[mc.m];
        for(int j = 0; j < mc.m; j++)
            mat[i][j] = mc.mat[i][j];
    }
}

Matrice_Complexa& Matrice_Complexa::operator= (const Matrice_Complexa& mc)
{
    if(this != &mc)
    {
        n = mc.n;
        m = mc.m;
        alloc(n, m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                mat[i][j] = mc.mat[i][j];
        }
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Matrice_Complexa& mc)
{
    in >> mc.n >> mc.m;
    mc.mat = new Complex*[mc.n];
    for(int i = 0; i < mc.n; i++) mc.mat[i] = new Complex[mc.m];
    for(int i = 0; i < mc.n; i++)
        for(int j = 0; j < mc.m; j++)
            in >> mc.mat[i][j];
    return in;
}

std::ostream& operator<<(std::ostream& out, Matrice_Complexa& mc)
{
    out << "nr de linii: " << mc.n << '\n' << "nr de coloane: " << mc.m << '\n';
    for(int i = 0; i < mc.n; i++)
    {
        for(int j = 0; j < mc.m; j++)
            out << mc.mat[i][j] << ' ';
        out << '\n';
    }
    return out;
}

Matrice_Complexa Matrice_Complexa::operator+(const Matrice_Complexa& mc)
{
    if(mc.n != n || mc.m != m)
    {
        Complex c(-1, 0);
        Matrice_Complexa b(c, n, m);
        std::cout << "Cele doua matrice nu au aceleasi dimensiuni, deci nu se poate realiza suma acestora. In acest caz, functia de adunare va returna o matrice de tipul primului operand, cu toate elementele egale cu -1.\n";
        return b;
    }
    Complex c(0, 0);
    Matrice_Complexa b(c, mc.n, mc.m);
    b.n = mc.n;
    b.m = mc.m;
    for(int i = 0; i < mc.n; i++)
        for(int j = 0; j < mc.m; j++)
            b.mat[i][j] = mat[i][j] + mc.mat[i][j];
    return b;
}

Matrice_Complexa Matrice_Complexa::operator+(Complex x)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i][j] = mat[i][j] + x;
    return *this;
}

Matrice_Complexa operator+(Complex c, const Matrice_Complexa& mc)
{
    for(int i = 0; i < mc.n; i++)
        for(int j = 0; j < mc.m; j++)
            mc.mat[i][j] = mc.mat[i][j] + c;
    return mc;
}

Matrice_Complexa Matrice_Complexa::operator*(const Matrice_Complexa& a)
{
    if(m != a.n)
    {
        Complex c(-1, 0);
        Matrice_Complexa b(c, n, m);
        std::cout << "Nu se poate efectua inmultirea.\n";
        return b;
    }
    else
    {
    Complex c(0, 0);
    Matrice_Complexa b(c, n, a.m);
    int i, j, k;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            for(k = 0; k < a.m; k++)
            {
                Complex aux;
                aux = mat[i][j] * a.mat[j][k];
                b.mat[i][k] = b.mat[i][k] + aux;
            }
    return b;
    }
}

Matrice_Complexa Matrice_Complexa::operator^(int p)
{
    if(n != m)
    {
        Complex c(-1, 0);
        Matrice_Complexa b(c, n, m);
        std::cout << "Nu se poate efectua ridicarea la putere.\n";
        return b;
    }
    Matrice_Complexa b, aux;
    b = aux = *this;
    for(int i = 1; i < p; i++)
    {
        b = b * aux;
        //cout << b;
    }
    return b;
}

Vector_Complex Matrice_Complexa::operator[](int i)
{
    Complex z(0, 0);
    Vector_Complex vc(z, m);
    for(int j = 0; j < m; j++)
        vc.v[j] = mat[i][j];
    return vc;
}

bool Matrice_Complexa::operator==(const Matrice_Complexa& mc)
{
    if(n != mc.n || m != mc.m) return 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!(mat[i][j].re == mc.mat[i][j].re && mat[i][j].im == mc.mat[i][j].im)) return 0;
    return 1;
}

Complex Matrice_Complexa::urma()
{

    if(n != m)
    {
        Complex e(-1, 0);
        std::cout << "Matricea nu este patratica, deci nu exista notiunea de urma pentru aceasta matrice. Returnez ";
        return e;
    }
    Complex tr(0, 0);
    for(int i = 0; i < n; i++)
         tr = tr + mat[i][i];
    return tr;
}

Matrice_Complexa Matrice_Complexa::elim(int lin, int col)
{
    Complex c(0, 0);
    Matrice_Complexa b(c, n - 1, m - 1);
    int il = 0, ic = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(i != lin && j != col)
            {
                b.mat[il][ic++] = mat[i][j];
                if(ic == m - 1)
                {
                    ic = 0;
                    il++;
                }
            }
    return b;
}

Complex Matrice_Complexa::determinant1()
{
    Complex e(-1, 0);
    if(n != m)
    {
        std::cout << "Matricea nu este patratica, deci nu exista notiunea de determinant pentru aceasta matrice. Returnez ";
        return e;
    }
    else return determinant();
}

Complex Matrice_Complexa::determinant()
{
    ok = 1;
    Complex s(1, 0), d(0, 0), aux, c;
    if(n == 1) {return mat[0][0];}
    for(int j = 0; j < n; j++)
    {
        Matrice_Complexa b;
        b = elim(0, j);
        c = b.determinant();
        aux = s * mat[0][j];
        aux = aux * c;
        d = d + aux;
        s.set_re(-s.get_re());
    }
    return d;
}

Matrice_Complexa Matrice_Complexa::transpusa()
{
    Complex c(0, 0);
    Matrice_Complexa b(c, m, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b.mat[j][i] = mat[i][j];
    return b;
}

bool Matrice_Complexa::inversabila()
{
    Complex c;
    c = determinant();
    if(c.re == 0 && c.im == 0) return 0;
    return 1;
}

Matrice_Complexa Matrice_Complexa::inversa()
{
    Complex s(1,0);
    Matrice_Complexa inv(s,n, m);
    inv = transpusa();
    Complex d = determinant(), d1;
    if(inversabila())
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if((i + j) % 2) s.set_re(-1);
                else s.set_re(1);
                Matrice_Complexa aux;
                aux = elim(j, i);
                d1 = aux.determinant();
                inv.mat[i][j] = d1 * s / d;

            }
    }
    return inv;
}

Matrice_Complexa::operator Complex()
{
    Complex c(-1, 0);
    if(n != m) return c;
    return determinant();
}

class Matrice_patratica : public Matrice_Complexa{
    int dim;
    static int nrd;
    public:
    Matrice_patratica():Matrice_Complexa(){dim = 0; nrp++;}
    Matrice_patratica(Complex c, int dim1): Matrice_Complexa(c, dim1, dim1){dim = dim1; nrp++;}
    ~Matrice_patratica(){for(int i = 0; i < n; i++) delete[] mat[i]; delete[] mat; nrp--;}
    void afisare()
    {
        n = m = dim;
        std::cout << "Dimensiunea matricei:" << dim << '\n';
        Complex c = determinant();
        std::cout << "Determinantul matricei:" << c << '\n';
        Matrice_Complexa::afisare();
    }
    void citire()
    {
        std::cin >> dim;
        if(dim <= 0) throw 1.0;
        Matrice_Complexa::citire_mat(dim, dim);
    }
    bool diagonala();
    static void nr_diagonale(){std::cout << nrd << '\n';}
};

int Matrice_patratica::nrd = 0;

bool Matrice_patratica::diagonala()
{
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
        {
            if(i == j && mat[i][j].re == 0 && mat[i][j].im == 0) return 0;
            if(i != j && (mat[i][j].re != 0 || mat[i][j].im != 0)) return 0;
        }
    nrd++;
    return 1;
}


#endif // MATRICE_COMPLEXA_H_INCLUDED
