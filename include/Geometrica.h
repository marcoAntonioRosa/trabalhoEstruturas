#ifndef GEOMETRICA_H
#define GEOMETRICA_H

#include <iostream>
#include <Progressao.h>

class Geometrica : public Progressao
{
private:
    float privateGetCommonDifference();
    bool isInput(bool isinput);
    bool isGeometric(vector <float> input);
public:
    bool setSequence(string);
    void setCommonDifference(float commondifference);
    void setFirstTerm(float firstterm);

    float getCommonDifference();
    float getFirstTerm();
    float getNthTerm(float pos);
    float getSum(float qterm);
    long long getProduct(float qterm);
    float getAllTerms(float pos);

    void log(); //FUNÇÃO NÃO UTILIZADA
    void serialize(ostream& stream);
    void deserialize(istream& stream); //FUNÇÃO NÃO UTILIZADA
    string getCurrentDate();
    void print();
};

#endif // GEOMETRICA_H

