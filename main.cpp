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
    ar.setSequence("1,3,5,7");

    cout << ar.getCommonDiference() << endl;
}
