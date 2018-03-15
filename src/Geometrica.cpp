#include "Geometrica.h"
#include <math.h>
using namespace std;

//Setters

//Cria uma stream com os números sem as virgulas, define o primeiro termo e a razão
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

    if (passed && isGeometric(input))
    {
        setCommonDifference(privateGetCommonDifference());
        return true;
    }
    this->isinput = false;
    return false;
}

//Define a razão
void Geometrica::setCommonDifference(float commonDifference)
{
    this->commonDifference = commonDifference;
}

//Define o primeiro termo
void Geometrica::setFirstTerm(float firstterm)
{
    this->firstterm = firstterm;
}

//Testa se a progressão é realmente geométrica, dividindo todos os termos pelos seus anteriores e comparando o primeiro termo com o ultimo
bool Geometrica::isGeometric(vector <float> input)
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


//Getters

//Define e retorna a razão
float Geometrica::privateGetCommonDifference()
{
    if(isGeometric(input) && input.size() > 1)
    {
        setCommonDifference((input.at(1) / input.at(0)));
        return (input.at(1) / input.at(0));
    }
    else if (input.size() == 1)
    {
        float commonDifference;
        cout << "Digite a razão: ";
        cin >> commonDifference;
        return commonDifference;
        //return input.at(0);
    }
    return 0;
}

//Apenas retorna a razão
float Geometrica::getCommonDifference()
{
    return this->commonDifference;
}

//Retorna o primeiro termo
float Geometrica::getFirstTerm()
{
    return this->firstterm;
}

//Calcula e retorna o valor de um termo na posição desejada
float Geometrica::getNthTerm(float pos)
{
    return this->term = getFirstTerm() * pow(getCommonDifference(), (pos-1));
}

//Calcula e retorna a soma dos termos de acordo com a quantidade dos mesmos
float Geometrica::getSum(float qterm)
{
    return this->sum = getFirstTerm() * (pow(getCommonDifference(), qterm) - 1) / (getCommonDifference() - 1);
}

//Calcula e retorna o produto dos termos de acordo com a quantidade dos mesmos
long long Geometrica::getProduct(float qterm)
{
    return this->product =(long long) sqrt( pow(getFirstTerm() * getNthTerm(qterm), qterm));
}


float Geometrica::getAllTerms(float pos)
{
    print();
    if(isGeometric(input) && pos>input.size())
    {
        for (int x=input.size(); x<pos; x++)
        {
            cout << getNthTerm(x+1); //O +1 server para ele não repetir o valor anterior
            if(x < pos-1)
                cout << ", ";
        }
        cout << endl;
    }
    return 0;

}

//Salvar em arquivo
void Geometrica::serialize(ostream& stream)
{
    this->data = getCurrentDate();
    stream << data << " " << userinput << " " << getCommonDifference() << " " << sum;
}

string Geometrica::getCurrentDate()
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

void Geometrica::print()
{
    if(isinput)
    {
        for(unsigned int x=0; x<input.size(); x++)
        {
            cout << input.at(x) << ", ";
            /*if(x < input.size()-1)
                cout << ", ";
            */
        }
        //cout << endl;
    }
}

