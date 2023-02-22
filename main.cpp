#include <iostream>
#include <vector>
#include "Complex.h"
#include "Vector_Complex.h"
#include "Matrice_Complexa.h"
#include <ctime>
#include <vector>

using namespace std;

int meniu1(int o)
{
    while(o)
    {
    if(o == 1)
    {
        int optiune;
        double a, b, c, d;
        cout<<"Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand operatorii supraincarcati: Introduceti partea reala si partea imaginara, separate prin spatiu;\n 2 - Testare constructori;\n 3 - Testare set-er si get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare modul si conjugat;\n 6 - Revenire la meniul principal;\n Pentru a opri executia programului, introduceti 0.\n";
        cin >> optiune;
        while(optiune)
        {
            switch(optiune)
            {
                case 1: {
                            cout << "Testare citire si afisare, utilizand operatorii supraincarcati (Introduceti partea reala si partea imaginara, separate prin spatiu):\n";
                            Complex c;
                            cin >> c;
                            cout << c;
                            cout << "\nDoriti alta optiune?\n Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand operatorii supraincarcati: Introduceti partea reala si partea imaginara, separate prin spatiu;\n 2 - Testare constructori;\n 3 - Testare set-er si get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare modul si conjugat;\n 6 - Revenire la meniul principal;\n Daca doriti sa opriti executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 2: {
                            cout << "Testare constructori:\n";
                            cout << "Constructorul de initializare fara parametri:\n";
                            Complex c1;
                            c1.afisare();
                            cout << "Constructorul de initializare cu parametri:\n";
                            cout << "partea reala = "; cin >> a;
                            cout << "partea imaginara = "; cin >> b;
                            Complex c2(a, b);
                            c2.afisare();
                            cout << "Constructorul de copiere (Se copiaza obiectul creat prin constructorul fara parametri si cel creat prin constructorul cu paramteri, in alte doua obiecte):\n";
                            Complex c3(c1), c4(c2);
                            c3.afisare();
                            c4.afisare();
                            cout << "\nDoriti alta optiune?\n Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand operatorii supraincarcati: Introduceti partea reala si partea imaginara, separate prin spatiu;\n 2 - Testare constructori;\n 3 - Testare set-er si get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare modul si conjugat;\n 6 - Revenire la meniul principal;\n Daca doriti sa opriti executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 3: {
                            cout << "Testare set-er si get-er:\n";
                            Complex c;
                            cout << "partea reala = "; cin >> a;
                            c.set_re(a);
                            cout << c.get_re() << '\n';
                            cout << "partea imaginara = "; cin >> b;
                            c.set_im(b);
                            cout << c.get_im() << '\n';
                            cout << "\nDoriti alta optiune?\n Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand operatorii supraincarcati: Introduceti partea reala si partea imaginara, separate prin spatiu;\n 2 - Testare constructori;\n 3 - Testare set-er si get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare modul si conjugat;\n 6 - Revenire la meniul principal;\n Daca doriti sa opriti executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 4: {
                            cout << "Testare operatori supraincarcati:\n";
                            cout << "partea reala pt c1 = "; cin >> a;
                            cout << "partea imaginara pt c1 = "; cin >> b;
                            cout << "partea reala pt c2 = "; cin >> c;
                            cout << "partea imaginara pt c2 = "; cin >> d;
                            Complex c1(a, b), c2(c, d);
                            Complex c3 = c1;
                            cout << "operator de atribuire explicit (Se creeaza un obiect c3, caruia i se atribuie obiectul c1):\n" << c3 << '\n';
                            c3 = c1 + c2;
                            cout << "Suma: " << c3 << '\n';
                            c3 = c1 * c2;
                            cout << "Produs: " << c3 << '\n';
                            c3 = c1 / c2;
                            cout << "Impartire: " << c3 << '\n';
                            cout << "\nDoriti alta optiune?\n Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand operatorii supraincarcati: Introduceti partea reala si partea imaginara, separate prin spatiu;\n 2 - Testare constructori;\n 3 - Testare set-er si get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare modul si conjugat;\n 6 - Revenire la meniul principal;\n Daca doriti sa opriti executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 5: {
                            cout << "Testare modul si conjugat:\n";
                            cout << "partea reala = "; cin >> a;
                            cout << "partea imaginara = "; cin >> b;
                            Complex c(a, b);
                            cout << "Modul: " << c.modul() << '\n';
                            c.conjugat();
                            Complex c1 = c;
                            cout << "Conjugat: " << c1;
                            cout << "\nDoriti alta optiune?\n Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand operatorii supraincarcati: Introduceti partea reala si partea imaginara, separate prin spatiu;\n 2 - Testare constructori;\n 3 - Testare set-er si get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare modul si conjugat;\n 6 - Revenire la meniul principal;\n Daca doriti sa opriti executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 6: {
                           cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Testarea clasei Complex;\n 2 - Testarea clasei Matrice_Complexa;\nPentru a opri executia programului, introduceti 0.\n";
                           cin >> o;
                           if(o == 0) return 0;
                           else meniu1(o);
                           break;
                        }
                default: {cout << "Optiune inexistenta";}
            }
        } exit(0);
    }
    else if(o == 2)
    {
        int optiune;
        cout<<"Alegeti una dintre urmatoarele optiuni:\n 1 - Testare citire si afisare, utilizand metodele: Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei;\n 2 - Testare constructori;\n 3 - Testare get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare metode pentru transpusa, urma, matricea obtinuta prin eliminarea unei linii si a unei coloane, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei;\n 6 - Revenire la meniul principal;\n Pentru a opri executia programului, introduceti 0.\n";
        cin>>optiune;
        while(optiune)
        {
            switch(optiune)
            {
                case 1: {
                            cout << "Testare citire si afisare, utilizand metodele (Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei):\n";
                            Matrice_Complexa m1;
                            m1.citire();
                            m1.afisare();
                            cout << "\nDoriti alta optiune?\n 1 - Testare citire si afisare, utilizand metodele: Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei;\n 2 - Testare constructori;\n 3 - Testare get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare metode pentru transpusa, urma, minori, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei;\n 6 - Revenire la meniul principal.\n Pentru a opri executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 2: {
                            cout << "Testare constructori:\n";
                            cout << "Constructorul de initializare cu parametri: Introduceti dimensiunile matricei, separate printr-un spatiu si un numar complex, cu care sa fie initializate toate elementele matricei:\n";
                            Complex c;
                            int n, m;
                            cin >> n >> m >> c;
                            Matrice_Complexa m2(c, n, m);
                            m2.afisare();
                            cout << "Constructorul de copiere:\n";
                            Matrice_Complexa m3(m2);
                            m3.afisare();
                            cout << "\nDoriti alta optiune?\n 1 - Testare citire si afisare, utilizand metodele: Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei;\n 2 - Testare constructori;\n 3 - Testare get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare metode pentru transpusa, urma, minori, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei;\n 6 - Revenire la meniul principal.\n Pentru a opri executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 3: {
                            cout << "Testare get-er (Se citeste o matrice si, prin intermdiul metodelor get-er, se furnizeaza dimensiunile acesteia):\n";
                            Matrice_Complexa m4;
                            cin >> m4;
                            cout << m4.get_n() << ' ' << m4.get_m();
                            cout << "\nDoriti alta optiune?\n 1 - Testare citire si afisare, utilizand metodele: Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei;\n 2 - Testare constructori;\n 3 - Testare get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare metode pentru transpusa, urma, minori, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei;\n 6 - Revenire la meniul principal.\n Pentru a opri executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 4: {
                            cout << "Testare operatori supraincarcati:\n";
                            Matrice_Complexa m1, m2, m3;
                            cout << "Operator citire si afisare (Se citesc doua matrice (m1 si m2) si se afiseaza):\n";
                            cin >> m1 >> m2;
                            cout << m1 << m2;
                            cout << "Operator de atribuire (Se creeaza matricea m4, careia i se atribuie aceleasi date ca ale matricei m1):\n";
                            Matrice_Complexa m4 = m1;
                            cout << m4;
                            cout << "Operator de testare a egalitatii:\n";
                            bool b1, b2;
                            cout << "Se testeaza egalitatea dintre m1 si m4: ";
                            b1 = (m4 == m1);
                            cout << b1 << '\n';
                            b2 = (m1 == m2);
                            cout << "Se testeaza egalitatea dintre m1 si m2: ";
                            cout << b2 << '\n';
                            cout << "Suma matricelor m1 si m2:\n";
                            m3 = m1 + m2;
                            cout << m3;
                            cout << "Produsul matricelor m1 si m2:\n";
                            m3 = m1 * m2;
                            cout << m3;
                            cout << "Ridicarea la putere a matricei m1:\n";
                            int p;
                            cout << "Introduceti puterea: " ;
                            cin >> p;
                            m3 = m1 ^ p;
                            cout << m3;
                            cout << "Adunarea unui scalar la toate componentele matricei m1 (prefixat si postfixat):\n";
                            Complex c1, c2;
                            cout << "Se citesc doua numere complexe (c1 si c2). Se va realiza operatia c1 + m1 + c2:\n";
                            cin >> c1 >> c2;
                            m3 = c1 + m1 + c2;
                            cout << m3;
                            cout << "Operator de indexare: \n";
                            cout << "Se citesc doi indici i si j:\n";
                            int i, j;
                            cin >> i >> j;
                            cout << "Elementul de pe pozitia (i, j) din m2: ";
                            if(i >= m2.get_n()) cout << "Indicele liniei depaseste dimensiunea matricei.\n";
                            if(j >= m2.get_m()) cout << "Indicele coloanei depaseste dimensiunea matricei.\n";
                            else
                            {
                                Complex c = m2[i][j];
                                cout << c << '\n';
                            }
                            cout << "Operatorul de conversie (Se realizeaza conversia obiectului de tip Matrice_Complexa m2 la unul de tip Complex, prin intermediul notiunii de determinant. In cazul in care matricea nu este patratica, valoarea la care se face conversia este -1):\n";
                            Complex c;
                            c = m2;
                            cout << c;
                            cout << "\nDoriti alta optiune?\n 1 - Testare citire si afisare, utilizand metodele: Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei;\n 2 - Testare constructori;\n 3 - Testare get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare metode pentru transpusa, urma, minori, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei;\n 6 - Revenire la meniul principal.\n Pentru a opri executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                case 5: {
                            cout << "Testare metode pentru matricea obtinuta prin eliminarea unei linii si a unei coloane, transpusa, urma, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei:\n";
                            Matrice_Complexa m8, m9;
                            cout << "Se citeste o matrice de la tastatura:\n";
                            cin >> m8;
                            cout << m8;
                            cout << "Matricea obtinuta prin eliminarea liniei i si a coloanei j:\n";
                            int i, j;
                            cin >> i >> j;
                            if(i >= m8.get_n()) cout << "Indicele liniei depaseste dimensiunea matricei.\n";
                            if(j >= m8.get_n()) cout << "Indicele coloanei depaseste dimensiunea matricei.\n";
                            else
                            {
                                m9 = m8.elim(i, j);
                                cout << m9;
                            }
                            cout << "Transpusa matricei:\n";
                            m9 = m8.transpusa();
                            cout << m9;
                            cout << "Urma:\n";
                            Complex c = m8.urma();
                            cout << c << '\n';

                            cout << "Determinant: ";
                            c = m8.determinant1();
                            cout << c << '\n';
                            cout << "Este matricea inversabila? ";
                            if(ok == 0) cout << "Nu.\n";
                            else
                            {
                                int b;
                                b = m8.inversabila();
                                if(b)
                                {
                                    cout << "Da.\nInversa matricei:\n";
                                    Matrice_Complexa m10;
                                    m10 = m8.inversa();
                                    cout << m10;
                                }
                                else cout << "Nu.\n";
                            }
                            cout << "\nDoriti alta optiune?\n 1 - Testare citire si afisare, utilizand metodele: Introduceti numarul de linii si numarul de coloane, separate printr-un spatiu, apoi elementele matricei;\n 2 - Testare constructori;\n 3 - Testare get-er;\n 4 - Testare operatori supraincarcati;\n 5 - Testare metode pentru transpusa, urma, minori, determinant, verificarea faptului ca o matrice este inversabila, calculul inversei;\n 6 - Revenire la meniul principal.\n Pentru a opri executia programului, introduceti 0.\n";
                            cin>>optiune;
                            break;
                        }
                    case 6: {
                            cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Testarea clasei Complex;\n 2 - Testarea clasei Matrice_Complexa;\nPentru a opri executia programului, introduceti 0.\n";
                            cin >> o;
                            if(o == 0) return 0;
                            else meniu1(o);
                            break;
                            }
                    default: {cout << "Optiune inexistenta\n";}
            }

        } exit (0);
    }

    else if(o == 0)return 0;
    else
    {
        cout << "Optiune inexistenta\n";
        cin >> o;
    }
    } return 0;
}

void meniu2(int o)
{
int n, m, i;
vector<int>v;
    while(o)
    {

        switch(o)
        {
        case 1:
            {
                cout << "Citirea unei matrice patratice, afisarea acesteia si a determinantului sau si verificarea faptului ca aceasta este diagonala\n";
                cout << "Introduceti dimensiunea matricei, apoi elementele, prin parte reala si parte imaginara, separate prin spatii:\n";
                Matrice_patratica m1;
                m1.citire();
                m1.afisare();
                if(m1.diagonala()) cout << "Matricea data este diagonala.\n\n";
                else cout << "Matricea data nu este diagonala.\n\n";
                cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Citirea unei matrice patratice, afisarea acesteia si a determinantului sau si verificarea faptului ca aceasta este diagonala;\n 2 - Crearea unei matrice patratice, avand toate elementele egale cu o valoare citita de la tastatura;\n 3 - Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice);\n 4 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2;\n 5 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2.\n";
                cin >> o;
                break;
            }
        case 2:
            {
                cout << "Crearea unei matrice patratice, avand toate elementele egale cu o valoare citita de la tastatura\n";
                cout << "Introduceti numarul complex cu care doriti sa fie egale toate elementele matricei:\n";
                Complex c;
                cin >> c;
                cout << '\n';
                int ok = 0;
                Matrice_patratica m1;
                while(!ok)
                {
                    ok = 1;
                    try
                    {
                        cout << "Introduceti dimensiunea matricei: \n";
                        cin >> n;
                        Matrice_patratica m1(c, n);
                        m1.afisare();
                    }
                    catch(int x)
                    {
                        ok = 0;
                        cout << "Dimensiunea introdusa este negativa. Introduceti o dimensiune valida.\n";
                    }
                }

                cout << "\nDoriti alta optiune?\n 1 - Citirea unei matrice patratice, afisarea acesteia si a determinantului sau si verificarea faptului ca aceasta este diagonala;\n 2 - Crearea unei matrice patratice, avand toate elementele egale cu o valoare citita de la tastatura;\n 3 - Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice);\n 4 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2;\n 5 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2.\n";
                cin >> o;
                break;
            }
        case 3:
            {
                cout << "Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice)\n";
                cout << "\nIntroduceti numarul de matrice pe care doriti sa le cititi:\n";
                cin >> n;
                cout << "\nLa fiecare pas, daca se afiseaza 'Matrice oarecare', introduceti cele doua dimensiuni matricei, iar apoi elementele, prin parte reala si parte imaginara, separate prin spatii, iar daca se afiseaza 'Matrice patratica', introduceti dimensiunea matricei, iar apoi elementele, prin parte reala si parte imaginara, separate prin spatii\n";
                Matrice_Complexa* p[n];
                srand(time(0));
                int ptr;
                for(i = 0; i < n; i++)
                {
                    if(rand()%2)
                    {
                        cout << "Matrice patratica" << '\n';
                        p[i] = new Matrice_patratica;
                        ptr = 1;
                    }
                    else
                    {
                        cout << "Matrice oarecare" << '\n';
                        p[i] = new Matrice_Complexa;
                        ptr = 0;
                    }
                    ok = 0;
                    while(!ok)
                    {
                        ok = 1;
                        try
                        {
                            p[i]->citire();
                        }
                        catch(int x)
                        {
                            ok = 0;
                            cout << "Numarul de linii introdus este negativ. Introduceti o dimensiune valida.\n";
                        }
                        catch(char a)
                        {
                            ok = 0;
                            cout << "Numarul de coloane introdus este negativ. Introduceti o dimensiune valida.\n";
                        }
                        catch(double x)
                        {
                            ok = 0;
                            cout << "Dimensiunea introdusa este negativa. Introduceti o dimensiune valida.\n";
                        }
                    }
                    if(ptr) dynamic_cast<Matrice_patratica*>(p[i])->diagonala();
                }
                for(i = 0; i < n; i++)
                {
                    p[i]->afisare();
                    cout << '\n';
                }
                cout << "Indicii matricelor patratice:\n";
                for(int i = 0; i < n; i++)
                    if(dynamic_cast<Matrice_patratica*>(p[i]))
                        v.push_back(i);
                cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Citirea unei matrice patratice, afisarea acesteia si verificarea faptului ca matricea este diagonala;\n 2 - Crearea unei matrice patratice, avand toate elementele egale cu o valoare citita de la tastatura;\n 3 - Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice);\n 4 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2;\n 5 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2.\n";
                cin >> o;
                break;
            }
        case 4:
            {
                cout << "3 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2\n";
                cout << "Numarul matricelor patratice: ";
                Matrice_Complexa::nr_patratice();
                cout << "Numarul matricelor diagonale: ";
                Matrice_patratica::nr_diagonale();
                cout << "\nDoriti alta optiune?\n 1 - Citirea unei matrice patratice, afisarea acesteia si a determinantului sau si verificarea faptului ca aceasta este diagonala;\n 2 - Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice);\n 3 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2;\n 4 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2.\n Pentru a opri executia programului, introduceti 0.\n";
                cin >> o;
                break;
            }
        case 5:
            {
                cout << "4 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2\n";
                if(v.empty()) cout << "Nu au fost citite matrice patratice\n";
                else for(i = 0; i < v.size(); i++) cout << v[i] << ' ';
                cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Citirea unei matrice patratice, afisarea acesteia si a determinantului sau si verificarea faptului ca aceasta este diagonala;\n 2 - Crearea unei matrice patratice, avand toate elementele egale cu o valoare citita de la tastatura;\n 3 - Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice);\n 4 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2;\n 5 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2.\n";
                cin >> o;
                break;
            }
        }
    }
}

int main()
{
cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Testarea operatiilor de baza din clasele Complex si Matrice_Complexa;\n 2 - Testarea operatiilor cu matrice patratice si diagonale\n";
int o;
cin >> o;
if (o == 1)
{
    cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Testarea clasei Complex;\n 2 - Testarea clasei Matrice_Complexa;\nPentru a opri executia programului, introduceti 0.\n";
    int o;
    cin >> o;
    meniu1(o);
}
else
{
    cout << "Alegeti una dintre urmatoarele optiuni:\n 1 - Citirea unei matrice patratice, afisarea acesteia si a determinantului sau si verificarea faptului ca matricea este diagonala;\n 2 - Crearea unei matrice patratice, avand toate elementele egale cu o valoare citita de la tastatura;\n 3 - Citirea, memorarea si afisarea a n matrice, de tipuri diferite (oarecare sau patratice);\n 4 - Afisarea numarului de matrice patratice si a numarului de matrice diagonale, dintre cele citite la optiunea 2;\n 5 - Afisarea indicilor la care se gasesc matricele patratice, in sirul citit la optiunea 2.\n";
    cin >> o;
    meniu2(o);
}
return 0;
}

