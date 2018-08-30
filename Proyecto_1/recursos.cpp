#include "recursos.h"

int Recursos::getId() const
{
    return id;
}

void Recursos::setId(const int &Rid)
{
    id = Rid;
}

string Recursos::getTipoR() const
{
    return tipoR;
}

void Recursos::setTipoR(const string &Rtipo)
{
    tipoR = Rtipo;
}

int Recursos::getCantidad() const
{
    return cantidad;
}

void Recursos::setCantidad(int Rcant)
{
    cantidad = Rcant;
}

Recursos::Recursos()
{

}
