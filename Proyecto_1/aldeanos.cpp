#include "aldeanos.h"

string Aldeanos::getNombre() const
{
    return nombre;
}

void Aldeanos::setNombre(const string &n)
{
    nombre = n;
}

string Aldeanos::getGenero() const
{
    return genero;
}

void Aldeanos::setGenero(const string &g)
{
    genero = g;
}

int Aldeanos::getEdad() const
{
    return edad;
}

void Aldeanos::setEdad(const int &e)
{
    edad = e;
}

int Aldeanos::getSalud() const
{
    return salud;
}

void Aldeanos::setSalud(const int &s)
{
    salud = s;
}

Aldeanos::Aldeanos()
{

}
