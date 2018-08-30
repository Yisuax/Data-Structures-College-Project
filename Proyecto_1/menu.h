#ifndef MENU_H
#define MENU_H

#include "civilizacion.h"
#include "lista.h"
#include "listadoble.h"
#include <windows.h>
#include <time.h>
#include <sstream>
#include <fstream>
using namespace std;


class Menu
{
public:
    Menu();
    ~Menu();
    void agregarCivilizacion(Lista<Civilizacion*> &,Mapeo<Civilizacion *> &,string,int,int);
    void MostrarMapa(Mapeo<Civilizacion*> &,Lista<Civilizacion*> &);
    void Respaldar(Lista<Civilizacion*> &);
    void Recuperar(Lista<Civilizacion*> &,Mapeo<Civilizacion *> &,Aldeanos &,Guerreros &,Recursos &);
    void Eliminar_Guerrero(string,int,Lista<Civilizacion*> &);
    void Busqueda_Guerrero(int,Lista<Civilizacion*> &);
};

#endif // MENU_H
