#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Progressao.h>
#include <Geometrica.h>
#include <Aritmetica.h>
#include <windows.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    /*
    Dados a5 = 100 e r = 10, calcule o primeiro termo:
    a5=a1+(5–1).r
    100=a1+(5−1)⋅10
    100=a1+40
    100−40=a1
    a1=60
    */


    //ar.getNthTerm(3, ar.getFirstTerm(), 1) << endl;

    /*cout << "NthTerm: " <<  ar.getNthTerm(1);
    cout << ", " << ar.getNthTerm(2);
    cout << ", " <<ar.getNthTerm(3);
    cout << ", " <<ar.getNthTerm(4) << endl;*/

    Aritmetica ar, ae;
    ar.setSequence("2");
    ae.setSequence("2, 5, 8");

    cout << "NthTerm ar: " <<  ar.getNthTerm(1);
    cout << ", " <<  ar.getNthTerm(2);
    cout << ", " <<  ar.getNthTerm(3);
    cout << ", " <<  ar.getNthTerm(4);
    cout << ", " <<  ar.getNthTerm(5)<< endl;
    cout << "Sum: " <<  ar.getSum(7) << endl << endl;

    cout << "NthTerm ae: " <<  ae.getNthTerm(1);
    cout << ", " <<  ae.getNthTerm(2);
    cout << ", " <<  ae.getNthTerm(3);
    cout << ", " <<  ae.getNthTerm(4);
    cout << ", " <<  ae.getNthTerm(5) << endl;
    cout << "Sum: " <<  ae.getSum(7) << endl;



    /*
    Geometrica ge;
    ge.setSequence("2, 6, 18");
    ge.getAllTerms(10);
    cout << ge.getSum(6) << endl;
    cout << ge.getProduct(6) << endl;
    */


}
