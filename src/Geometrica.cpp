#include "Geometrica.h"
#include <math.h>
using namespace std;

bool Geometrica::setSequence(string userinput)
{
    this->userinput = userinput;
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
        if (input.size() == 1)
            setCommonDifference(input.at(0));
        else
            setCommonDifference(privateGetCommonDifference());
        return true;
    }
    this->isinput = false;
    return false;
}

void Geometrica::setTerm(float term)
{
    this->term = term;
}

void Geometrica::setFirstTerm(float firstterm)
{
    this->firstterm = firstterm;
}

void Geometrica::setCommonDifference(float commondifference)
{
    this->commondifference = commondifference;
}

bool Geometrica::isArithmetic(vector <float> input)
{
    vector <float> aux;

    if (isinput)
    {
        for (int x=input.size()-1; x>=1; x--)
        {
            aux.push_back(input.at(x) / input.at(x-1));
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

float Geometrica::privateGetCommonDifference()
{
    if(isArithmetic(input) && input.size() > 1)
    {
        setCommonDifference((input.at(1) / input.at(0)));
        return (input.at(1) / input.at(0));
    }
    else if (input.size() == 1)
    {
        return input.at(0);
    }
    return 0;
}

float Geometrica::getFirstTerm()
{
    return this->firstterm;
}

//Esse aqui é realmente necessário?
float Geometrica::getSpecificTerm(float specterm)
{
    float specificterm = getFirstTerm() * pow(privateGetCommonDifference(), (specterm - 1));
    return specificterm;
}

void Geometrica::print()
{
    if(isinput)
    {
        for(unsigned int x=0; x<input.size(); x++)
        {
            cout << input.at(x) << ",";
        }
    }
}

float Geometrica::getCommonDifference()
{
    return this->commondifference;
}

float Geometrica::getNthTerm(float commondifference, float term, float n)
{
    return term * pow(commondifference, (n-1));
}

float Geometrica::getSum(float term)
{
    return sum = getFirstTerm() * (pow(getCommonDifference(), term) - 1) / (getCommonDifference() - 1);
}

long long Geometrica::getProduct(float term)
{
    return product =(long long) sqrt( pow(getFirstTerm() * getNthTerm(getCommonDifference(), getFirstTerm(), term), term));
}

string Geometrica::getCurrentData()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[100];

    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"Data: %d/%m/%y Hora: %I:%M",timeinfo);
    string fulldata(buffer);
    return fulldata;
}


void Geometrica::serialize(ostream& stream)
{
    this->data = getCurrentData();
    stream << data << " " << userinput << " " << getCommonDifference() << " " << sum;
}

