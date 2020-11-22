//
//  RungeKutta.cpp
//
//  Created by Aurimas Nausedas on 9/28/19.

#include "RungeKutta.hpp"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// konstruktorius
RungeKutta::RungeKutta(double lt, double lh, int ln)
{
    t = lt;
    h = lh;
    n = ln;


    x = new double[n];
    xt = new double[n];
    f = new double[n];
    ft = new double[n];

    // patikrinu, kad masyvas sekmingai alokuotas
    // turi pasikeisti adresas
    if (x == 0)
    {
        printf("Nepavyko alokuoti x masyvo\n");
        exit(1);
    }

    if (xt == 0)
    {
        printf("Nepavyko alokuoti xt masyvo\n");
        exit(1);
    }

    if (f == 0)
    {
        printf("Nepavyko alokuoti f masyvo\n");
        exit(1);
    }

    if (ft == 0)
    {
        printf("Nepavyko alokuoti ft masyvo\n");
        exit(1);
    }

    // eilute apacioje nereikalingos ivedus operatoriu
    // surasau i x masyva pateiktas pradines x vertes
    //for (int i = 0; i < n; i++) {x[i] = lx[i];};

}

// destruktorius
RungeKutta:: ~RungeKutta()
{
    delete []x;
    delete []xt;
    delete []f;
    delete []ft;
}

// step funkcija
void RungeKutta::step()
{
    // atnaujinu f masyve saugomas vertes
    fk(x,f);

    // paskaiciuoju a_tilde
    for (int i = 0; i < n; i++)
    {
        xt[i] = x[i] + h * f[i];
    }

    // paskaiciuju t sekanciame taske
    t += h;

    // paskaiciuoju fk vertems naujuose taskuose
    fk(xt,ft);

    // perrasau vertes adresais a and t
    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] + (h / 2) * (f[i] + ft[i]);
    }

}
