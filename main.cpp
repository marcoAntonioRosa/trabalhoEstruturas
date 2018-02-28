#include <iostream>

#include <Progressao.h>
#include <Aritmetica.h>

using namespace std;

int main()
{
    Progressao* progressao = new Aritmetica();

    progressao->userInput("2k,3,4,7,8,9");
    progressao->getValues();

}
