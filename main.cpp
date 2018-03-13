#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Progressao.h>
#include <Geometrica.h>
#include <Aritmetica.h>
#include <windows.h>

using namespace std;

int main()
{
    Aritmetica ar;
    /*
    Dados a5 = 100 e r = 10, calcule o primeiro termo:
    a5=a1+(5–1).r
    100=a1+(5−1)⋅10
    100=a1+40
    100−40=a1
    a1=60
    */

    ar.setSequence("100");
    cout << ar.getNthTerm(10, ar.getFirstTerm(), 5) << endl;

    Geometrica ge;
    ge.setSequence("54");
    //razao, termo, posição do termo, posição do termo no qual estou buscando
    cout << ge.getNthTerm(3, ge.getFirstTerm(), 4, 6) << endl;
    //razao, numero de termos, posição do termo em destaque. PRECISO CONCERTAR ISSO
    cout << ge.getSum(3, 6, 4) << endl;
    //Razão, posição do termo, total de termos
     cout << ge.getProduct(3, 4, 6) << endl;
}
