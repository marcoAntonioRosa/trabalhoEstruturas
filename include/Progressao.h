#ifndef PROGRESSAO_H
#define PROGRESSAO_H

#include <sstream>
#include <vector>

using namespace std;

class Progressao
{
protected:
    vector <float> input;
    float tempt;
    string userinput;
    bool isinput;
public:
    virtual bool userInput(string) = 0;
    virtual void getValues() = 0;
};

#endif // PROGRESSAO_H
