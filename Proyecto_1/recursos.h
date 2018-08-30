#ifndef RECURSOS_H
#define RECURSOS_H

#include <iostream>
using namespace std;

class Recursos
{
private:
    int id;
    string tipoR;
    int cantidad;
public:
    Recursos();
    int getId() const;
    void setId(const int &Rid);
    string getTipoR() const;
    void setTipoR(const string &Rtipo);
    int getCantidad() const;
    void setCantidad(int Rcant);

    bool operator <(Recursos r)
    {
        return cantidad < r.cantidad;
    }

};

#endif // RECURSOS_H
