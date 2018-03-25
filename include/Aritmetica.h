#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <iostream>
#include <Progressao.h>

class Aritmetica : public Progressao
{
private:
    float privateGetCommonDifference();
    bool isInput(bool isinput);
    bool isArithmetic(vector <float> input);
public:
    bool setSequence(string);
    void setCommonDifference(float commonDifference);
    void setFirstTerm(float firstterm);

    float getCommonDifference();
    float getFirstTerm();
    float getNthTerm(int wantedPos, int currentPos);
    float getSum(float qTerms, int firstTermPos);

    void log(); //FUNÇÃO NÃO UTILIZADA
    void serialize(ostream& stream);
    void deserialize(istream& stream); //FUNÇÃO NÃO UTILIZADA
    string getCurrentDate();
    void print();
};

#endif // ARITMETICA_H
