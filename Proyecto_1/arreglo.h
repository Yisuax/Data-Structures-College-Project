#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>

class Arreglo
{
    T *arreglo;
    const static int MAX = 5;
    int indice;
    int tam;
public:
    Arreglo();
    ~Arreglo();
    Arreglo(const Arreglo<T> &a);
    void insertar(const T &dato);
    void agregarInicio(const T &dato);
    void agregar(const T &dato, int posicion);
    void eliminar_final(void);
    void eliminar_inicio(void);
    void eliminar_posicion(int posicion);
    T &operator[](int posicion)const;
    int tama()const;
    int longitud()const;
    T *getArreglo() const;
    void setArreglo(T *value);
};

template <class T>

Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    tam = MAX;
    indice = 0;
}

template <class T>
Arreglo<T>::~Arreglo()
{
    delete []arreglo;
}

template <class T>
Arreglo<T>::Arreglo(const Arreglo<T> &a)
{
    tam = a.tama();
    indice = a.longitud();
    arreglo = new T[tam];

    for(int i=0; i<indice; ++i){
        arreglo[i] = a[i];
    }
}

template <class T>
void Arreglo<T>::insertar(const T &dato)
{
    if(indice<tam){
        arreglo[indice++] = dato;
    }
    else{
        T *temp = new T[tam+5];
        for(int i=0;i<indice;i++){
            temp[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = temp;
        tam = tam + 5;
        arreglo[indice++] = dato;
    }
}

template <class T>
void Arreglo<T>::agregarInicio(const T &dato)
{
    if(indice==tam){
        T *temp = new T[tam+5];
        for(int i=0;i<indice;i++){
            temp[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = temp;
        tam = tam + 5;
    }
    for(int i=indice;i>0;i--){
        arreglo[i]=arreglo[i-1];
    }
    arreglo[0]=dato;
    indice++;
}

template <class T>
void Arreglo<T>::agregar(const T &dato, int posicion)
{
    if(posicion == 0){
        agregarInicio(dato);
    }
    else if(posicion == indice){
        insertar(dato);
    }
    else if(posicion > 0 && posicion < indice){
        if(indice==tam){
            T *temp = new T[tam++];
            for(int i=0;i<indice;i++){
                temp[i] = arreglo[i];
            }
            delete []arreglo;
            arreglo = temp;
            tam = tam + 5;
        }
        for(int i=indice; i > posicion; i--){
            arreglo[i] = arreglo[i-1];
        }
        arreglo[posicion] = dato;
        indice++;
    }
    else{
        throw out_of_range("posicion no valida");
    }
}

template <class T>
void Arreglo<T>::eliminar_final()
{
    if(indice == 0){
        throw out_of_range("Arreglo vacio");
    }
    indice--;
}

template <class T>
void Arreglo<T>::eliminar_inicio()
{
    if(indice == 0){
        throw out_of_range("Arreglo vacio");
    }
    for(int i=0;i<indice-1;i++){
        arreglo[i]=arreglo[i+1];
    }
    indice--;
}

template <class T>
void Arreglo<T>::eliminar_posicion(int posicion)
{
    if(indice == 0){
        throw out_of_range("Arreglo vacio");
    }
    else if(posicion >= 0 && posicion <= indice){
        for(int i=posicion; i < indice; i++){
            arreglo[i] = arreglo[i+1];
        }
        indice--;
    }
}


template <class T>
T &Arreglo<T>::operator[](int posicion)const
{
    if(posicion<0||posicion>indice){
        throw out_of_range("No existe la posicion");
    }
    return arreglo[posicion];
}

template <class T>
int Arreglo<T>::tama()const
{
    return tam;
}

template <class T>
int Arreglo<T>::longitud()const
{
    return indice;
}

template <class T>
T *Arreglo<T>::getArreglo() const
{
    return arreglo;
}

template <class T>
void Arreglo<T>::setArreglo(T *value)
{
    arreglo = value;
}



#endif // ARREGLO_H
