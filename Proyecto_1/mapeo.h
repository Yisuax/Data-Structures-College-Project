#ifndef MAPEO_H
#define MAPEO_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Mapeo
{
private:
    vector<vector<T>> *matrix;
    int filas;
    int columnas;
public:
    Mapeo();
    Mapeo(int,int);
    Mapeo(int,int,const T&);
    ~Mapeo();

    vector<T> &operator[](int);

    vector<vector<T>> &getMatrix();
    int getFilas() const;
    int getColumnas() const;
};

template <class T>
int Mapeo<T>::getFilas() const
{
return filas;
}

template <class T>
int Mapeo<T>::getColumnas() const
{
return columnas;
}

template <class T>
Mapeo<T>::Mapeo()
{
    matrix = new vector<vector<T>>(10,vector<T>(10));
    filas=columnas=10;
}

template <class T>
Mapeo<T>::Mapeo(int fila, int columna)
{
    matrix = new vector<vector<T>>(fila,vector<T>(columna));
    filas = fila;
    columnas = columna;
}

template <class T>
Mapeo<T>::Mapeo(int fila, int columna, const T &dato)
{
    matrix = new vector<vector<T>>(fila,vector<T>(columna,dato));
    filas = fila;
    columnas = columna;
}

template <class T>
Mapeo<T>::~Mapeo()
{
    delete matrix;
}

template <class T>
vector<T> &Mapeo<T>::operator[](int fila)
{
    return (*matrix)[fila];
}

template <class T>
vector<vector<T> > &Mapeo<T>::getMatrix()
{
    return *matrix;
}


#endif // MAPEO_H
