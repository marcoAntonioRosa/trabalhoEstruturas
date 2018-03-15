#include "Aritmetica.h"

using namespace std;

bool Aritmetica::setSequence(string userinput)
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
        setCommonDifference(privateGetCommonDifference());
        return true;
    }
    this->isinput = false;
    return false;
}

void Aritmetica::setFirstTerm(float firstTerm)
{
    this->firstTerm = firstTerm;
}

void Aritmetica::setCommonDifference(float commonDifference)
{
    this->commonDifference = commonDifference;
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

float Aritmetica::privateGetCommonDifference()
{
    if(isArithmetic(input) && input.size() > 1)
    {
        setCommonDifference((input.at(1) - input.at(0)));
        return (input.at(1) - input.at(0));
    }
    else if (input.size() == 1)
    {
        float commonDifference;
        cout << "Digite a razão: ";
        cin >> commonDifference;
        return commonDifference;
    }
    return 0;
}

float Aritmetica::getFirstTerm()
{
    return this->firstTerm;
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

float Aritmetica::getCommonDifference()
{
    return this->commonDifference;
}

float Aritmetica::getNthTerm(float pos)
{
    return this->term = getFirstTerm() + ((pos - 1) * getCommonDifference());
}

float Aritmetica::getSum(float term)
{
    return this->term = ((getFirstTerm() + getNthTerm(term)) * term) /2;
}

string Aritmetica::getCurrentDate()
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

void Aritmetica::serialize(ostream& stream)
{
    this->date = getCurrentDate();
    stream << date << " " << userinput << " " << getCommonDifference() << " " << sum;
}
