#ifndef GEOMETRICA_H
#define GEOMETRICA_H

#include <iostream>
#include <Progressao.h>

class Geometrica : public Progressao
{
private:
    float privateGetCommonDifference();
    bool isInput(bool isinput);
    bool isArithmetic(vector <float> userinput);
public:
    bool setSequence(string);
    void setTerm(float term);
    void setCommonDifference(float commondifference);
    void setFirstTerm(float firstterm);
    void log();
    void serialize(ostream& stream);
    void deserialize(istream& stream);

    float getCommonDifference();
    float getFirstTerm();
    float getTerm();
    float getSum(float commondifference,  float an, float pos);
    float getProduct(float commondifference, float an, float am);


    float getSpecificTerm(float specterm);
    float getNthTerm(float commondifference, float term, float an, float am);
    string getCurrentData();
    void print();
};

#endif // GEOMETRICA_H

