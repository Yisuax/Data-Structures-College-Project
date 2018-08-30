#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Nodo
{
private:
    T dato;
    Nodo<T> *sig;
public:
    Nodo(const T &d, Nodo<T> *s = nullptr){
        dato = d;
        sig = s;
    }

    template <class>
    friend class Lista;
};


template <class T>
class Lista
{
private:
    Nodo<T> *raiz;
public:
    Lista();
    ~Lista();
    void insertar_inicio(const T&);
    void insertar_final(const T&);
    void insertar_posicion(const T&,int);
    void eliminar_inicio(void);
    void eliminar_final(void);
    void eliminar_posicion(int);
    int tamanio();
    T& operator [](int posicion);
    string to_string();
};

template <class T>
Lista<T>::Lista()
{
    raiz = nullptr;
}

template <class T>
Lista<T>::~Lista()
{
    Nodo<T> *temp = raiz;

    while(temp!=nullptr){
        raiz = raiz->sig;
        delete temp;
        temp = raiz;
    }
}

template<class T>
void Lista<T>::insertar_inicio(const T &d)
{
    if(raiz==nullptr){
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    }
    else{
        Nodo<T> *nuevo = new Nodo<T>(d);
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

template <class T>
void Lista<T>::insertar_final(const T &d)
{
    if(raiz==nullptr){
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    }
    else{
        Nodo<T> *temp = raiz;

        while(temp->sig!=nullptr){
            temp = temp->sig;
        }
        Nodo<T> *nuevo = new Nodo<T>(d);
        temp->sig = nuevo;
    }
}

template <class T>
void Lista<T>::insertar_posicion(const T &d, int pos)
{
    if(raiz==nullptr){
        throw out_of_range("Lista vacia");
    }
    else{
        int cont=0;
        Nodo<T> *temp = raiz;

        while(temp->sig!=nullptr){
            if(cont++==pos-1){
                Nodo<T> *nuevo = new Nodo<T>(d);
                nuevo->sig = temp->sig;
                temp->sig = nuevo;
                break;
            }
            else if(temp->sig==nullptr){
                throw out_of_range("Posicion invalida");
            }
            temp = temp->sig;
        }
    }
}

template <class T>
void Lista<T>::eliminar_inicio()
{
    if(raiz==nullptr){
        //mandar exepcion
    }
    else{
        Nodo<T> *temp = raiz;
        raiz = raiz->sig;
        delete temp;
    }
}

template <class T>
void Lista<T>::eliminar_final()
{
    if(raiz==nullptr){
        //mandar exepcion
    }
    else if(raiz->sig==nullptr){
        eliminar_inicio();
    }
    else{
        Nodo<T> *temp = raiz;

        while(temp->sig->sig != nullptr){
            temp = temp->sig;
        }
        delete temp->sig;
        temp->sig = nullptr;
    }
}

template <class T>
void Lista<T>::eliminar_posicion(int pos)
{
    if(raiz==nullptr){
        cout<<"Lista Vacia";
    }
    else if(pos==0){
        eliminar_inicio();
    }
    else if(pos==tamanio()-1){
        eliminar_final();
    }
    else if(pos>0&&pos<tamanio()-1){
        int cont=1;
        Nodo<T> *temp = raiz->sig;
        Nodo<T> *ant = raiz;

        while(temp->sig!=nullptr){
            if(cont++==pos){
                ant->sig=temp->sig;
                break;
            }
            else if(temp->sig==nullptr){
                cout<<"El elemento no existe";
            }
            temp = temp->sig;
            ant = ant->sig;
        }
        delete temp;
    }
}

template <class T>
int Lista<T>::tamanio()
{
    Nodo<T> *temp = raiz;
    int cont = 0;
    while(temp!=nullptr){
        temp = temp->sig;
        cont++;
    }
    return cont;
}

template <class T>
T &Lista<T>::operator [](int posicion)
{
    if(posicion < 0){
        throw out_of_range("Posicion invalida");
    }
    else if(posicion >= tamanio()){
        throw out_of_range("Posicion invalida");
    }
    else{
        Nodo<T> *temp = raiz;
        int cont = 0;

        while(temp != nullptr){
            if(cont++==posicion){
                return temp->dato;
            }
            temp = temp->sig;
        }
    }
    exit(-1);
}

template <class T>
string Lista<T>::to_string()
{
    string lista = "[";
    Nodo<T> *temp = raiz;

    while(temp!=nullptr){
        lista += temp->dato;
        lista += ", ";
        temp = temp->sig;
    }
    lista += "]";

    return lista;
}


#endif // LISTA_H
