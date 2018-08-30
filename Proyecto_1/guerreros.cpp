#include "guerreros.h"

Guerreros::Guerreros()
{

}

int Guerreros::getId() const
{
    return id;
}

void Guerreros::setId(const int &gid)
{
    id = gid;
}

string Guerreros::getTguerrero() const
{
    return tguerrero;
}

void Guerreros::setTguerrero(const string &tgue)
{
    tguerrero = tgue;
}

int Guerreros::getSalud() const
{
    return salud;
}

void Guerreros::setSalud(int gsalud)
{
    salud = gsalud;
}

float Guerreros::getFuerza() const
{
    return fuerza;
}

void Guerreros::setFuerza(float fue)
{
    fuerza = fue;
}

float Guerreros::getEscudo() const
{
    return escudo;
}

void Guerreros::setEscudo(float esc)
{
    escudo = esc;
}

