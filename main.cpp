//
//  main.cpp
//
// Problem_20.cpp
//
//  Created by Aurimas Nausedas on 9/28/19.

#include <stdio.h>

#include "RungeKutta.hpp"
#include "MyRungeKutta.hpp"
#include "math.h"

int main()
{
    // laikas ir zingsnis
    double t = 0, h = 0.1;

    //masyvai
    const int n = 2; // masyvo ilgis

    // deklaruoju objekta
    MyRungeKutta X(t,h,n);

    // surasau pradines vertes i masyva x
    X[0] = 1;
    X[1] = 0;
    X.set(1);


    printf(" *** Runges ir Kutos Metodas: Masyvai ***\n\n");
    printf("   dx[0]/dt = -x[1], dx[1]/dt = x[0]\n\n");
    printf("      t = 0: x[0] = 1, x[1] = 0\n\n");
    printf("t      x[0]      cos(t)    x[1]      sin(t)\n");

    printf("--------------------------------------------\n");

    // output loop ----------------------------
    for (int i = 0; i <= 10; i++)
    {
        printf("%-.1lf    %-.4lf    %-.4lf    %-.4lf    %-.4lf\n",
               X.get_t(),X[0],cos(X.get_t()),X[1],sin(X.get_t()));

        X.step(); // Integravimas
    }

    printf("\n");
    return 0;
}
