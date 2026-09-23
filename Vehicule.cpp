#include "Vehicule.h"

Vehicule::Vehicule()
{
    kilometrage = 0;
    litres = 0;
}

void Vehicule::setKilometrage(double km)
{
    kilometrage = km;
}

void Vehicule::setLitres(double l)
{
    litres = l;
}

double Vehicule::calculerConsommation() const
{
    if (kilometrage <= 0)
    {
        return 0;
    }

    return (litres / kilometrage) * 100;
}