#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <windows.h>
#include "aldeanos.h"
#include "guerreros.h"
#include "recursos.h"
#include "mapeo.h"
#include "arreglo.h"
#include "listadoble.h"
#include "colaprioridad.h"

class Civilizacion:public Aldeanos
{
private:
    int fila,columna;
    string nombre;
    Arreglo<Aldeanos> arr;
    ListaDoble<Guerreros> gue;
    ColaPrioridad<Recursos> rec;
    ColaPrioridad<Recursos> rec2;
    Recursos r;
public:
    Civilizacion();
    void AgregarAldeano(const Aldeanos &);
    void EliminarAldeano(string);
    void MostrarAldeano(void);
    void AgregarGuerrero(const Guerreros &);
    int BuscarGuerrero(int);
    void BuscarSGuerrero(string);
    void BuscarFGuerrero(string);
    void BuscarCGuerrero(string);
    void Modificar_Guerrero(void);
    void EliminarGuerrero(int);
    void EliminarCGuerrero(string);
    void EliminarSGuerrero(int);
    void MostrarGuerreros(void);
    string Tipo_Guerrero(int);
    int PoblacionTotal(void);
    int CantidadGuerreros(void);
    int CantidadAldeanos(void);
    int CantidadRecursos(void);
    int CantidadCRecursos(void);
    int ID(int);
    string TGue(int);
    int Sal(int);
    float Fue(int);
    float Esc(int);
    void AgregarRecurso(const Recursos &);
    void MostrarRecurso( void);
    void BuscarRecurso(string);
    void Modificar_Recurso(void);
    string Tipo_Recurso(int);
    int RID(int);
    string Trec(int);
    int Rcan(int);

    void setName(const string &nom);
    string getName() const;

    Aldeanos &operator[](int posicion)const;
    int getFila() const;
    void setFila(int f);
    int getColumna() const;
    void setColumna(int c);
};

#endif // CIVILIZACION_H
