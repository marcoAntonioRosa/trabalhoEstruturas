#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <iostream>
#include <Progressao.h>

class Aritmetica : public Progressao
{
private:
    bool isInput(bool isinput);
    bool isArithmetic(vector <float> userinput);
public:
    bool setSequence(string);

    void setTerm(float term);
    void setCommonDiference(float commondifference);
    void setFirstTerm(float firstterm);

    float getCommonDiference();
    float getFirstTerm();
    float getTerm();

    float getSpecificTerm(float specterm);


    void print();
};


#endif // ARITMETICA_H
