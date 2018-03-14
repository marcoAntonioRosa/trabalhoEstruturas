#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Progressao.h>
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
    ar.setSequence("1,2,3,4,5");

    cout << ar.getSumFromTheFirstNElements(5);



}
