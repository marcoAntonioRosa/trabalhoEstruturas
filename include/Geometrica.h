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
    void setCommonDifference(float commonDifference);
    void setFirstTerm(float firstterm);

    float getCommonDifference();
    float getFirstTerm();
    float getNthTerm(int wantedPos, int currentPos);
    long long getSum(int qTerms, int firstTermPos);
    long long getProduct(int qTerms, int firstTermPos);
    float getAllTerms(int qTerms, int firstTermPos);
    float getQntTerms(int lastTerm, int firstTermPos);
    float getDecompose(int lastTerm);

    void log(); //FUNÇÃO NÃO UTILIZADA
    void serialize(ostream& stream);
    void deserialize(istream& stream); //FUNÇÃO NÃO UTILIZADA
    string getCurrentDate();
    void print();
};

#endif // GEOMETRICA_H

