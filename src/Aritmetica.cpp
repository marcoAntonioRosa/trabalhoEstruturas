#include "Aritmetica.h"

using namespace std;

bool Aritmetica::userInput(string userinput)
{
    stringstream stream(userinput);

    bool passed = false;
    while (stream >> tempt)
    {
        if (stream.peek() == ',')
            stream.ignore();

        input.push_back(tempt);

        if (stream.tellg() == -1)
        {
            passed = true;
            this->isinput = true;
        }
    }

    if (passed)
    {
        return true;
    }
    this->isinput = false;
    return false;
}

void Aritmetica::getValues()
{
    if(isinput)
    {
        for(unsigned int x=0; x<input.size(); x++)
        {
            cout << input.at(x) << endl;
        }
    }
}

