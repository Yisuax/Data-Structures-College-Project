#ifndef ALDEANOS_H
#define ALDEANOS_H

#include <iostream>
using namespace std;

class Aldeanos
{
private:
    string nombre;
    string genero;
    int edad;
    int salud;
public:
    Aldeanos();
    string getNombre() const;
    void setNombre(const string &n);
    string getGenero() const;
    void setGenero(const string &g);
    int getEdad() const;
    void setEdad(const int &e);
    int getSalud() const;
    void setSalud(const int &s);
};

#endif // ALDEANOS_H
