#ifndef PROGRESSAO_H
#define PROGRESSAO_H

#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Progressao
{
protected:
    vector <float> input;
    string userinput;
    bool isinput;

    float firstterm;
    float tempt;
    float term;
    float commondifference;
public:
//    virtual bool userInput(string) = 0;
//
//    virtual void setTerm(float term) = 0;
//    virtual void setCommonDiference(float commondifference) = 0;
//
//    virtual void print() = 0;
//    virtual bool isArithmetic() = 0;
//    virtual float getCommonDiference() = 0;
};

#endif // PROGRESSAO_H
