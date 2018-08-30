#include "civilizacion.h"

string Civilizacion::getName() const
{
    return nombre;
}

void Civilizacion::setName(const string &nom)
{
    nombre = nom;
}

int Civilizacion::getFila() const
{
    return fila;
}

void Civilizacion::setFila(int f)
{
    fila = f;
}

int Civilizacion::getColumna() const
{
    return columna;
}

void Civilizacion::setColumna(int c)
{
    columna = c;
}

Civilizacion::Civilizacion()
{
    
}

void Civilizacion::AgregarAldeano(const Aldeanos &peo)
{
    arr.insertar(peo);
}

void Civilizacion::EliminarAldeano(string name)
{
    for(int i=0;i<=arr.longitud();i++){
        if(arr[i].getNombre()==name){
            arr.eliminar_posicion(i);
        }
    }
}

void Civilizacion::MostrarAldeano()
{
    for(int i=0;i<arr.longitud();i++){
        cout<<"Nombre: "<<arr[i].getNombre()<<endl;
        cout<<"Genero: "<<arr[i].getGenero()<<endl;
        cout<<"Edad: "<<arr[i].getEdad()<<" a"<<char(164)<<"os"<<endl;
        cout<<"Salud: "<<arr[i].getSalud()<<" pts"<<endl<<endl;
    }
}

int Civilizacion::PoblacionTotal(void)
{
    return arr.longitud()+gue.getSize();
}

int Civilizacion::CantidadGuerreros()
{
    return gue.getSize();
}

int Civilizacion::CantidadAldeanos()
{
    return arr.longitud();
}

int Civilizacion::CantidadRecursos()
{
    int ct=0;
    for(int i=0;i<rec.Tamano();i++){
        ct=ct+rec[i].getCantidad();
    }
    return ct;
}

int Civilizacion::CantidadCRecursos()
{
    return rec.Tamano();
}

int Civilizacion::ID(int i)
{
    return gue[i].getId();
}

string Civilizacion::TGue(int i)
{
    return gue[i].getTguerrero();
}

int Civilizacion::Sal(int i)
{
    return gue[i].getSalud();
}

float Civilizacion::Fue(int i)
{
    return gue[i].getFuerza();
}

float Civilizacion::Esc(int i)
{
    return gue[i].getEscudo();
}


void Civilizacion::AgregarGuerrero(const Guerreros &g)
{
    gue.insertar_final(g);
}

int Civilizacion::BuscarGuerrero(int id)
{
    for(int i=0;i<gue.getSize();i++){
        if(gue[i].getId()==id){
            cout<<"ID: "<<gue[i].getId()<<endl;
            cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
            cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
            cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
            cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
            return i;
        }
    }
    return -1;
}

void Civilizacion::BuscarSGuerrero(string sel)
{
    int sal;
    if(sel=="1"){
        cout<<"Buscar guerreros con salud mayor a: ";
        cin>>sal;
        for(int i=0;i<gue.getSize();i++){
            if(gue[i].getSalud()>sal){
                cout<<"ID: "<<gue[i].getId()<<endl;
                cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
                cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
                cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
                cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
            }
        }
    }
    else if(sel=="2"){
        cout<<"Buscar guerreros con salud menor o igual a: ";
        cin>>sal;
        for(int i=0;i<gue.getSize();i++){
            if(gue[i].getSalud()<=sal){
                cout<<"ID: "<<gue[i].getId()<<endl;
                cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
                cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
                cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
                cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
            }
        }
    }
    system("pause>null");
}

void Civilizacion::BuscarFGuerrero(string sel)
{
    float fue;
    if(sel=="1"){
        cout<<"Buscar guerreros con fuerza mayor a: ";
        cin>>fue;
        for(int i=0;i<gue.getSize();i++){
            if(gue[i].getFuerza()>fue){
                cout<<"ID: "<<gue[i].getId()<<endl;
                cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
                cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
                cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
                cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
            }
        }
    }
    else if(sel=="2"){
        cout<<"Buscar guerreros con fuerza menor o igual a: ";
        cin>>fue;
        for(int i=0;i<gue.getSize();i++){
            if(gue[i].getFuerza()<=fue){
                cout<<"ID: "<<gue[i].getId()<<endl;
                cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
                cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
                cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
                cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
            }
        }
    }
    system("pause>null");
}

void Civilizacion::BuscarCGuerrero(string cl)
{
    for(int i=0;i<gue.getSize();i++){
        if(gue[i].getTguerrero()==cl){
            cout<<"ID: "<<gue[i].getId()<<endl;
            cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
            cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
            cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
            cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
        }
    }
    system("pause>null");
}

void Civilizacion::Modificar_Guerrero()
{
    string opc,dato;
    int b1,opc2;
    cout<<"Ingrese ID del guerrero a modificar: ";
    cin>>opc2;
    while(true){
        system("cls");
        b1=BuscarGuerrero(opc2);
        if(b1!=-1){
            int val,val2;
            cout<<"Desea modificar algo: Si/No\t";
            cin>>opc;
            if(opc=="Si"||opc=="SI"||opc=="sI"||opc=="si"||opc=="S"||opc=="s"){
                system("cls");
                cout<<"Parametro a modificar:\n1.Salud\n2.Fuerza\n3.Escudo\n-> ";
                cin>>opc;
                if(opc=="1"){
                    system("cls");
                    cout<<"Salud del guerrero: ";
                    cin>>val;
                    gue[b1].setSalud(val);
                }
                else if(opc=="2"){
                    system("cls");
                    cout<<"Fuerza del guerrero: ";
                    cin>>val2;
                    gue[b1].setFuerza(val2);
                }
                else if(opc=="3"){
                    system("cls");
                    cout<<"Escudo del guerrero: ";
                    cin>>val2;
                    gue[b1].setEscudo(val2);
                }
                else{
                    cout<<"Opcion inexistente";
                    Sleep(1500);
                }
            }
            else if(opc=="No"||opc=="NO"||opc=="nO"||opc=="no"||opc=="N"||opc=="n"){
                break;
            }
            else{}
        }
        else{
            cout<<"Guerrero no encontrado";
            Sleep(1500);
            break;
        }
    }
}

void Civilizacion::EliminarGuerrero(int id)
{
    for(int i=0;i<gue.getSize();i++){
        if(gue[i].getId()==id){
            gue.eliminar_posicion(i);
            break;
        }
    }
}

void Civilizacion::EliminarCGuerrero(string cl)
{
    for(int i=0;i<gue.getSize();i++){
        if(gue[i].getTguerrero()==cl){
            gue.eliminar_posicion(i);
            i=-1;
        }
    }
}

void Civilizacion::EliminarSGuerrero(int sal)
{
    for(int i=0;i<gue.getSize();i++){
        if(gue[i].getSalud()<sal){
            gue.eliminar_posicion(i);
            i=-1;
        }
    }
}

void Civilizacion::MostrarGuerreros()
{
    for(int i=0;i<gue.getSize();i++){
        cout<<"ID: "<<gue[i].getId()<<endl;
        cout<<"Tipo de Guerrero: "<<gue[i].getTguerrero()<<endl;
        cout<<"Salud: "<<gue[i].getSalud()<<" pts"<<endl;
        cout<<"Fuerza: "<<gue[i].getFuerza()<<" pts"<<endl;
        cout<<"Escudo: "<<gue[i].getEscudo()<<" pts"<<endl<<endl;
    }
}

string Civilizacion::Tipo_Guerrero(int sel)
{
    string tipo;
    if(sel==1){
        tipo="Paladin";
    }
    else if(sel==2){
        tipo="Asesino";
    }
    else if(sel==3){
        tipo="Hechizero";
    }
    else if(sel==4){
        tipo="Tanque";
    }
    else{
        cout<<"Clase inexistente";
        Sleep(1000);
        tipo="0";
    }
    return tipo;
}

void Civilizacion::AgregarRecurso(const Recursos &r)
{
    rec.encolar(r);
}

void Civilizacion::MostrarRecurso()
{
    for(int i=0;i<rec.Tamano();i++){
        cout<<"ID: "<< rec[i].getId()<<endl;
        cout<<"Tipo: "<< rec[i].getTipoR()<<endl;
        cout<<"Cantidad : "<< rec[i].getCantidad()<<" unidades"<<endl<<endl;
    }
}


void Civilizacion::BuscarRecurso(string sel)
{
    int cant;
    string tp;
    if(sel=="1"){
        cout<<"Buscar recursos con cantidad mayor a: ";
        cin>>cant;
        cout<<endl;
        for(int i=0;i<rec.Tamano();i++){
            if(rec[i].getCantidad()>cant){
                cout<<"ID: "<< rec[i].getId()<<endl;
                cout<<"Tipo: "<< rec[i].getTipoR()<<endl;
                cout<<"Cantidad : "<< rec[i].getCantidad()<<" unidades"<<endl<<endl;
            }
        }
    }
    else if(sel=="2"){
        cout<<"Buscar recursos con cantidad menor o igual a: ";
        cin>>cant;
        cout<<endl;
        for(int i=0;i<rec.Tamano();i++){
            if(rec[i].getCantidad()<=cant){
                cout<<"ID: "<< rec[i].getId()<<endl;
                cout<<"Tipo: "<< rec[i].getTipoR()<<endl;
                cout<<"Cantidad : "<< rec[i].getCantidad()<<" unidades"<<endl<<endl;
            }
        }
    }
    else if(sel=="3"){
        cout<<"Buscar recursos de tipo:\n1.Chicas\n2.alcohol\n3.Fourloko\n4.Hongos\n-> ";
        cin>>tp;
        cout<<endl;
        if(tp=="1")tp="Chicas";
        else if(tp=="2")tp="alcohol";
        else if(tp=="3")tp="Fourloko";
        else if(tp=="4")tp="Dogras";
        for(int i=0;i<rec.Tamano();i++){
            if(rec[i].getTipoR()==tp){
                cout<<"ID: "<< rec[i].getId()<<endl;
                cout<<"Tipo: "<< rec[i].getTipoR()<<endl;
                cout<<"Cantidad : "<< rec[i].getCantidad()<<" unidades"<<endl<<endl;
            }
        }
    }
    system("pause>null");
}

void Civilizacion::Modificar_Recurso()
{
    int opc,cont=0;
    string opcm;

    cout<<"Ingrese ID del recurso a modificar: ";
    cin>>opc;
    while(true){
        system("cls");
        for(int i=0;i<rec.Tamano();i++){
            if(rec[i].getId()==opc){
                cout<<"ID: "<< rec[i].getId()<<endl;
                cout<<"Tipo: "<< rec[i].getTipoR()<<endl;
                cout<<"Cantidad : "<< rec[i].getCantidad()<<" unidades"<<endl<<endl;
                cout<<"Desea modificar la cantidad: Si/No\t";
                cin>>opcm;
                if(opcm=="Si"||opcm=="SI"||opcm=="sI"||opcm=="si"||opcm=="S"||opcm=="s"){
                    system("cls");
                    cout<<"Cual es la nueva cantidad de unidades de este recurso: ";
                    cin>>opc;
                    rec[i].setCantidad(opc);
                    cont=rec.Tamano();
                    for(int j=cont;j>0;j--){
                        r=rec.descolar();
                        rec2.encolar(r);
                    }
                    for(int j=cont;j>0;j--){
                        r=rec2.descolar();
                        rec.encolar(r);
                    }
                    if(opc==0){
                        rec.descolar();
                    }
                    cont=0;
                    break;
                }
                else if(opcm=="No"||opcm=="NO"||opcm=="nO"||opcm=="no"||opcm=="N"||opcm=="n"){
                    cont=0;
                    break;
                }
            }
            cont++;
        }
        if(cont!=0){
            cout<<"Recurso no encontrado";
            Sleep(1500);
            break;
        }
        break;
    }
}

string Civilizacion::Tipo_Recurso(int sel)
{
    string tipo;
    if(sel==1){
        tipo="Chicas";
    }
    else if(sel==2){
        tipo="alcohol";
    }
    else if(sel==3){
        tipo="Fourloko";
    }
    else if(sel==4){
        tipo="Hongos";
    }
    else{
        cout<<"Recurso inexistente";
        Sleep(1000);
        tipo="0";
    }
    return tipo;
}

int Civilizacion::RID(int i)
{
    return rec[i].getId();
}

string Civilizacion::Trec(int i)
{
    return rec[i].getTipoR();
}

int Civilizacion::Rcan(int i)
{
    return rec[i].getCantidad();
}


Aldeanos &Civilizacion::operator[](int posicion) const
{
    return arr[posicion];
}

