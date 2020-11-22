//
//  MyRungeKutta.hpp
//
//  Created by Aurimas Nausedas on 9/28/19.

#ifndef MyRungeKutta_hpp
#define MyRungeKutta_hpp

#include <stdio.h>
#include "RungeKutta.hpp"

class MyRungeKutta : public RungeKutta
{
public:
    MyRungeKutta(double lt, double lh, int ln) :
    RungeKutta(lt, lh, ln){};
    void set(double la){a = la;};
    void fk(const double *lx, double *lf);

private:
    double a;
};


#endif /* MyRungeKutta_hpp */
