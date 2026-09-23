#ifndef VEHICULE_H
#define VEHICULE_H

class Vehicule
{
private:
    double kilometrage;
    double litres;

public:
    Vehicule();

    void setKilometrage(double km);
    void setLitres(double l);

    double calculerConsommation() const;
};

#endif