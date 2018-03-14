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

    ar.setSequence("100");
    cout << ar.getNthTerm(10, ar.getFirstTerm(), 5) << endl;
    */


    Geometrica ge;
    ge.setSequence("2,6,18");
    cout << ge.getNthTerm(6) << endl;
    cout << ge.getSum(6) << endl;
    cout << ge.getProduct(6) << endl;
    ge.getAllTerms(10);
    cout << ge.getCurrentDate() << endl;


}
