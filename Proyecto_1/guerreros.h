#ifndef GUERREROS_H
#define GUERREROS_H

#include <iostream>
using namespace std;

class Guerreros
{
private:
    string tguerrero;
    int id;
    int salud;
    float fuerza;
    float escudo;
public:
    Guerreros();
    int getId() const;
    void setId(const int &gid);
    string getTguerrero() const;
    void setTguerrero(const string &tgue);
    int getSalud() const;
    void setSalud(int gsalud);
    float getFuerza() const;
    void setFuerza(float fue);
    float getEscudo() const;
    void setEscudo(float esc);
};

#endif // GUERREROS_H
