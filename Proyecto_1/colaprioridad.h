#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include "listadoble.h"

template <class T>
class ColaPrioridad
{
private:
    int tam;
    ListaDoble<T> colaPri;
public:
    ColaPrioridad();
    bool vacia();
    void encolar(T);
    T descolar();
    int Tamano();
    T &operator[](int pos);
};

template <class T>
ColaPrioridad<T>::ColaPrioridad()
{
    tam=0;
}

template <class T>
bool ColaPrioridad<T>::vacia()
{
    return colaPri.vacia();
}

template <class T>
void ColaPrioridad<T>::encolar(T dato)
{
    if(vacia()){
        colaPri.insertar_inicio(dato);
    }
    else{
        int i;
        for(i=0;i<colaPri.getSize();++i){
            if(dato<colaPri[i]){
                colaPri.insertar_posicion(dato,i);
                break;
            }
        }
        if(i==colaPri.getSize()){
            colaPri.insertar_final(dato);
        }
    }
    tam++;
}

template <class T>
T ColaPrioridad<T>::descolar()
{
    if(vacia()){
        throw out_of_range("Cola vacia");
    }
    T copia = colaPri[0];
    colaPri.eliminar_inicio();

    tam--;
    return copia;
}

template <class T>
int ColaPrioridad<T>::Tamano()
{
    return tam;
}

template <class T>
T &ColaPrioridad<T>::operator [](int pos)
{
    if(pos<0||pos>=tam){
        throw out_of_range("Fuera de esta lista");
    }
    int cont = 0;
    while(cont<tam){
        if(cont++==pos){
            return colaPri[pos];
        }
        colaPri[cont];
    }
    exit(-1);
}



#endif // COLAPRIORIDAD_H

