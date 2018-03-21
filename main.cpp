#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Progressao.h>
#include <Geometrica.h>
#include <Aritmetica.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

using namespace std;

int main()
{

    /*
    Aritmetica ar;
    Dados a5 = 100 e r = 10, calcule o primeiro termo:
    a5=a1+(5–1).r
    100=a1+(5−1)⋅10
    100=a1+40
    100−40=a1
    a1=60

    ar.setSequence("100");
    cout << ar.getNthTerm(10, ar.getFirstTerm(), 5) << endl;
    */


    Geometrica ge;
    ge.setSequence("6,18");
    //posição que eu quero, posição do "primeiro termo"
    cout << ge.getNthTerm(1,2) << endl;
    cout << ge.getNthTerm(4,2) << endl;

    //quantidade de termos, posicao do "primeiro termo"
    cout << ge.getSum(6,2) << endl;

    //cout << ge.getProduct(6,2) << endl;


    //Valor do ultimo termo e posição do primeiro termo
    cout << ge.getQntTerms(486, 1) << endl;

    //quantidade de termos, posicao do "primeiro termo"

    Geometrica geo;
    geo.setSequence("75");
    cout << geo.getNthTerm(1,3) << endl;
    cout << geo.getNthTerm(4,3) << endl;
    cout << geo.getSum(10,3) << endl;
    cout << geo.getProduct(10,3) << endl;


    /*
    cout << ge.getSum(6) << endl;
    cout << ge.getProduct(6) << endl;
    ge.getAllTerms(10);
    cout << ge.getCurrentDate() << endl;
    */

}

