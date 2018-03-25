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
void Geometrica::setFirstTerm(float firstTerm)
{
    this->firstTerm = firstTerm;
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
        cout << "Digite a razao: ";
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
    return this->firstTerm;
}

//Calcula e retorna o valor de um termo na posição desejada
float Geometrica::getNthTerm(int wantedPos, int currentPos)
{
    return this->term = getFirstTerm() * pow(getCommonDifference(), (wantedPos-currentPos));
}

//Calcula e retorna a soma dos termos de acordo com a quantidade dos mesmos
long long Geometrica::getSum(int qTerms, int firstTermPos)
{
    if (firstTermPos != 1)
        setFirstTerm(getNthTerm(1, firstTermPos));

    return this->sum = (long long)((getFirstTerm() * (pow(getCommonDifference(), qTerms) - 1) / (getCommonDifference() - 1))) ;
}

//Calcula e retorna o produto dos termos de acordo com a quantidade dos mesmos
long long Geometrica::getProduct(int qTerms, int firstTermPos)
{
    if (firstTermPos != 1){
        setFirstTerm(getNthTerm(1, firstTermPos));
    }

    /*cout << "First term: " << getFirstTerm() << endl;
    cout << "qTerms: " << qTerms << endl;
    cout << "firstTermPos: " << firstTermPos << endl;
    cout << "Last term " << getNthTerm(qTerms, 1) << endl;*/

    return this->product =(long long) sqrt( pow(getFirstTerm() * getNthTerm(qTerms, 1), qTerms));
}


float Geometrica::getAllTerms(int qTerms, int firstTermPos)
{
    print();
    if(isGeometric(input) && qTerms>input.size())
    {
        for (int x=input.size(); x<qTerms; x++)
        {
            cout << getNthTerm(x+1, firstTermPos); //O +1 server para ele não repetir o valor anterior
            if(x < qTerms-1)
                cout << ", ";
        }
        cout << endl;
    }
    return 0;

}

float Geometrica::getQntTerms(int lastTerm, int firstTermPos)
{
    return this->term = getDecompose(lastTerm) + firstTermPos;
}

float Geometrica::getDecompose(int lastTerm)
{
    int count;
    count = 0;
    lastTerm = lastTerm / getFirstTerm();
    while(lastTerm > 1){
        lastTerm = lastTerm / getCommonDifference();
        count++;
    }
    return count;
}


//Salvar em arquivo
void Geometrica::serialize(ostream& stream)
{
    this->date = getCurrentDate();
    stream << date << " " << userinput << " " << getCommonDifference() << " " << sum;
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

