#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <iostream>
#include <Progressao.h>

class Aritmetica : public Progressao
{
private:
    float privateGetCommonDifference();
    bool isInput(bool isinput);
    bool isArithmetic(vector <float> userinput);
public:
    bool setSequence(string);

    void setTerm(float term);
    void setCommonDifference(float commonDifference);
    void setFirstTerm(float firstterm);
    void log();
    void serialize(ostream& stream);
    void deserialize(istream& stream);

    float getCommonDifference();
    float getFirstTerm();
    float getTerm();
    float getSum(float term);

    float getSpecificTerm(float specterm);
    float getNthTerm(float pos);
    string getCurrentData();
    void print();
};

#endif // ARITMETICA_H
