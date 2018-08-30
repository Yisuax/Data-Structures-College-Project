#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class NodoN
{
    T dato;
    NodoN<T> *sig;
    NodoN<T> *ant;
public:
    NodoN(const T &d){
        dato = d;
        sig = nullptr;
        ant = nullptr;
    }
    template <class>
    friend class ListaDoble;
};

template <class T>
class ListaDoble
{
private:
    NodoN<T> *primero;
    NodoN<T> *ultimo;
    int size;
public:
    ListaDoble();
    bool vacia();
    void insertar_inicio(const T &);
    void insertar_final(const T &);
    void insertar_posicion(const T &,int);
    void eliminar_inicio();
    void eliminar_final();
    void eliminar_posicion(int);
    T& operator[](int posicion);
    int getSize() const;
};

template <class T>
ListaDoble<T>::ListaDoble()
{
    primero = ultimo = nullptr;
    size = 0;
}

template <class T>
bool ListaDoble<T>::vacia()
{
    return size==0;
}

template <class T>
void ListaDoble<T>::insertar_inicio(const T &d)
{
    if(vacia()){
        NodoN<T> *nuevo = new NodoN<T>(d);
        primero = ultimo = nuevo;
    }
    else{
        NodoN<T> *nuevo = new NodoN<T>(d);
        nuevo->sig = primero;
        primero->ant = nuevo;
        primero = nuevo;
    }
    size++;
}

template <class T>
void ListaDoble<T>::insertar_final(const T &d)
{
    if(vacia()){
        NodoN<T> *nuevo = new NodoN<T>(d);
        primero = ultimo = nuevo;
    }
    else{
        NodoN<T> *nuevo = new NodoN<T>(d);
        nuevo->ant=ultimo;
        ultimo->sig=nuevo;
        ultimo=nuevo;
    }
    size++;
}

template <class T>
void ListaDoble<T>::insertar_posicion(const T &d, int pos)
{
    if(pos<0||pos>=size){
        throw out_of_range("Fuera de la lista");
    }
    if(pos==0){
        insertar_inicio(d);
    }
    else if(pos==size){
        insertar_final(d);
    }
    else{
        NodoN<T> *temp=primero;
        int cont=0;

        while(temp!=nullptr){
            if(cont++==pos){
                NodoN<T> *nuevo = new NodoN<T>(d);
                nuevo->sig=temp;
                nuevo->ant=temp->ant;
                temp->ant->sig=nuevo;
                temp->ant=nuevo;
                size++;
                break;
            }
            temp = temp->sig;
        }
    }
}

template <class T>
void ListaDoble<T>::eliminar_inicio()
{
    if(vacia()){
        throw out_of_range("Lista vacia");
    }
    if(primero==ultimo){
        delete primero;
        primero = ultimo=nullptr;
        size--;
    }
    else{
        NodoN<T> *temp = primero;
        primero->sig->ant=nullptr;
        primero=primero->sig;
        delete temp;
        size--;
    }
}

template <class T>
void ListaDoble<T>::eliminar_final()
{
    if(vacia()){
        throw out_of_range("Lista vacia");
    }
    if(primero==ultimo){
        delete primero;
        primero = ultimo=nullptr;
        size--;
    }
    else{
        NodoN<T> *temp = ultimo;
        NodoN<T> *nAnt = ultimo->ant;
        nAnt->sig = nullptr;
        ultimo = nAnt;
        delete temp;
        size--;
    }
}

template <class T>
void ListaDoble<T>::eliminar_posicion(int pos)
{
    if(vacia()){
        throw out_of_range("Lista vacia");
    }
    if(pos<0||pos>=size){
        throw out_of_range("Fuera de la lista");
    }
    if(pos==0){
        eliminar_inicio();
    }
    else if(pos==size-1){
        eliminar_final();
    }
    else{
        NodoN<T> *temp = primero;
        int cont =0;
        while(temp!=nullptr){
            if(cont++==pos){
                NodoN<T> *nAnt = temp->ant;
                NodoN<T> *nSig = temp->sig;
                nAnt->sig = nSig;
                nSig->ant = nAnt;
                delete temp;
                size--;
                break;
            }
            temp = temp->sig;
        }
    }
}


template <class T>
T &ListaDoble<T>::operator[](int posicion)
{
    if(posicion<0||posicion>=size){
        throw out_of_range("Fuera de la lista");
    }
    NodoN<T> *temp = primero;
    int cont =0;
    while(temp!=nullptr){
        if(cont++==posicion){
            return temp->dato;
        }
        temp = temp->sig;
    }
    exit(-1);
}

template <class T>
int ListaDoble<T>::getSize() const
{
return size;
}

#endif // LISTADOBLE_H
