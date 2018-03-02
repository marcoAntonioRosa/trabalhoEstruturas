#include <iostream>
#include <vector>
#include <algorithm>

#include <Progressao.h>
#include <Aritmetica.h>

#include <mingw.thread.h>
#include <conio.h>
#include <windows.h>

using namespace std;


int main()
{
    Aritmetica ar;
    ar.setSequence("1,4,7");

    cout << ar.getSpecificTerm(40);
}
