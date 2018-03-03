#include "Aritmetica.h"

using namespace std;

bool Aritmetica::setSequence(string userinput)
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
            this->isinput = true;
            setFirstTerm(input.at(0));
            passed = true;
        }
    }

    if (passed && isArithmetic(input))
    {
        //privateGetCommonDiference();
        return true;
    }
    this->isinput = false;
    return false;
}

void Aritmetica::setTerm(float term)
{
    this->term = term;
}

void Aritmetica::setFirstTerm(float firstterm)
{
    this->firstterm = firstterm;
}
void Aritmetica::setCommonDiference(float commondifference)
{
    this->commondifference = commondifference;
}

bool Aritmetica::isArithmetic(vector <float> input)
{
    vector <float> aux;

    if (isinput)
    {
        for (int x=input.size()-1; x>=1; x--)
        {
            aux.push_back(input.at(x) - input.at(x-1));
        }

        if (adjacent_find(aux.begin(), aux.end(), not_equal_to<float>() ) == aux.end())
        {
            aux.clear();
            return true;
        }
    }
    aux.clear();
    return false;
}

float Aritmetica::privateGetCommonDiference()
{
    if(isArithmetic(input) && input.size() > 1)
    {
        setCommonDiference((input.at(1) - input.at(0)));
        return (input.at(1) - input.at(0));
    }
    else if (input.size() == 1)
    {
        return input.at(0);
    }
    return 0;
}

float Aritmetica::getFirstTerm()
{
    return this->firstterm;
}

float Aritmetica::getSpecificTerm(float specterm)
{
    float specificterm = getFirstTerm() + ((specterm - 1) * privateGetCommonDiference());
    return specificterm;
}

void Aritmetica::print()
{
    if(isinput)
    {
        for(unsigned int x=0; x<input.size(); x++)
        {
            cout << input.at(x) << ",";
        }
    }
}

float Aritmetica::getCommonDiference()
{
    return this->commondifference;
}

float Aritmetica::getNthTerm(float commondifference, float term, float index)
{
    // exemplo:
    // Dados a5 = 100 e r = 10, calcule o primeiro termo ????
    // como chamar a função ?? >> object.getNthTerm(10, object.getFirstTerm(), 5);
    //
    return term - ((index - 1)* commondifference);
}
