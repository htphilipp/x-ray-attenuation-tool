#ifndef XMATFORMULA_H
#define XMATFORMULA_H

//#include "xmatformula_global.h"
#include "./xmat.h"
#include <cmath>

class XmatFormula : public Xmat
{
public:
    XmatFormula(std::string);
    XmatFormula(std::string,double);

    //using Xmat::edges;

private:

    struct elemPart
    {
        std::string elem;
        double      num;
    };
    std::vector<elemPart>   parseFormula(std::string);
    std::vector<elemPart>   elemMix;

    void    initRoutine(std::string);

};

#endif // XMATFORMULA_H
