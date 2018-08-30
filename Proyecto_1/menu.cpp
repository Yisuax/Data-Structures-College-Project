#include "menu.h"

Menu::Menu()
{
    string opc,opc2;
    string dato;
    int valor;
    float value;
    Aldeanos ald;
    Guerreros war;
    Recursos rec;
    Lista<Civilizacion*> l;
    Mapeo<Civilizacion*> mapa(21,21);

    while(true){
        system("cls");
        cout<<"1.-Agregar Civilizacion\n2.-Buscar Civilizacion\n3.-Eliminar Civilizacion\n4.-Mostrar Civilizaciones\n5.-Configuracion\n6.-Mostrar Mapa\n0.-Salir\n-> ";
        cin>>opc;
        if(opc=="1"){
            string nomb;
            int f,c;
            while(true){
                system("cls");
                cin.ignore();
                cout<<"Nombre de la civilizacion: ";
                getline(cin, nomb);
                cout<<"Ubicacion en el mapa (20*20):\nFila: ";
                cin>>f;
                cout<<"Columna: ";
                cin>>c;
                if(f<0||f>20||c<0||c>20){
                    system("cls");
                    cout<<"Ubicacion inexistente en el mapa";
                    Sleep(1500);
                }
                else{
                    break;
                }
            }
            agregarCivilizacion(l,mapa,nomb,f,c);

        }
        else if(opc=="2"){
            system("cls");
            int cont=1;
            cin.ignore();
            cout<<"Nombre de la Civilizacion: ";
            getline(cin, dato);
            for(int i=0;i<l.tamanio();i++){
                if(l[i]->getName()==dato){
                    while(true){
                        system("cls");
                        cout<<"1.-Agregar Aldeano\n2.-Eliminar Aldeano\n"
                              "3.-Agregar Guerrero\n4.-Eliminar Guerrero\n5.-Buscar Guerreros\n6.-Modificar Guerreros\n"
                              "7.-Agregar Recursos\n8.-Buscar Recursos\n9.-Modificar Recursos\n"
                              "10.-Resumen\n0.Volver\n-> ";
                        cin>>opc;
                        if(opc=="1"){
                            system("cls");
                            cin.ignore();
                            cout<<"Nombre del aldeano: ";
                            getline(cin, dato);
                            ald.setNombre(dato);
                            cout<<"Genero del aldeano: ";
                            cin>>dato;
                            ald.setGenero(dato);
                            cout<<"Edad del aldeano: ";
                            cin>>valor;
                            ald.setEdad(valor);
                            cout<<"Salud del aldeano: ";
                            cin>>valor;
                            ald.setSalud(valor);
                            l[i]->AgregarAldeano(ald);
                        }
                        else if(opc=="2"){
                            system("cls");
                            if(l[i]->CantidadAldeanos()==0){
                                cout<<"No hay aldeanos registrados";
                                Sleep(1500);
                            }
                            else{
                                cin.ignore();
                                cout<<"Nombre del aldeano a eliminar: ";
                                getline(cin, dato);
                                l[i]->EliminarAldeano(dato);
                            }
                        }
                        else if(opc=="3"){
                            do{
                                system("cls");
                                cout<<"Clase de guerrero:\n1.Lancero\n2.Asesino\n3.Paladin\n4.Tanque\n-> ";
                                cin>>valor;
                                dato=l[i]->Tipo_Guerrero(valor);
                                war.setTguerrero(dato);
                            }while(dato=="0");
                            cout<<"Salud del guerrero: ";
                            cin>>valor;
                            war.setSalud(valor);
                            cout<<"Fuerza del guerrero: ";
                            cin>>value;
                            war.setFuerza(value);
                            cout<<"Escudo del guerrero: ";
                            cin>>value;
                            war.setEscudo(value);
                            for(int v=0;v<l[i]->CantidadGuerreros();v++){
                                while(true){
                                    valor=rand()%9999+1;
                                    if(valor!=l[i]->ID(v)){break;}
                                    else{}
                                }
                            }
                            war.setId(valor);
                            cout<<"ID del guerrero es: "<<valor;
                            Sleep(1500);
                            l[i]->AgregarGuerrero(war);
                        }
                        else if(opc=="4"){
                            system("cls");
                            if(l[i]->CantidadGuerreros()==0){
                                cout<<"No hay guerreros registrados";
                                Sleep(1500);
                            }
                            else{
                                cin.ignore();
                                cout<<"Opciones de eliminacion:\n1.ID\n2.Clases de guerrero\n3.Salud menor a\n0.Volver\n-> ";
                                cin>>opc2;
                                Eliminar_Guerrero(opc2,i,l);
                            }
                        }
                        else if(opc=="5"){
                            system("cls");
                            if(l[i]->CantidadGuerreros()==0){
                                cout<<"No hay guerreros registrados";
                                Sleep(1500);
                            }
                            else{
                                Busqueda_Guerrero(i,l);
                            }
                        }
                        else if(opc=="6"){
                            system("cls");
                            if(l[i]->CantidadGuerreros()==0){
                                cout<<"No hay guerreros registrados";
                                Sleep(1500);
                            }
                            else{
                                l[i]->Modificar_Guerrero();
                            }
                        }
                        else if(opc=="7"){
                            system("cls");
                            do{
                                system("cls");
                                cout<<"Tipo de recurso:\n1.chicas\n2.alcohol\n3.Fourloko\n4.Hongos\n-> ";
                                cin>>valor;
                                dato=l[i]->Tipo_Recurso(valor);
                                rec.setTipoR(dato);
                            }while(dato=="0");
                            cout<<"Cantidad del recurso: ";
                            cin>>valor;
                            rec.setCantidad(valor);
                            for(int v=0;v<l[i]->CantidadCRecursos();v++){
                                while(true){
                                    valor=rand()%9999+1;
                                    if(valor!=l[i]->RID(v)){break;}
                                    else{}
                                }
                            }
                            rec.setId(valor);
                            cout<<"ID del recurso es: "<<valor;
                            Sleep(1500);
                            l[i]->AgregarRecurso(rec);
                        }
                        else if(opc=="8"){
                            while(true){
                                system("cls");
                                cout<<"Buscar recursos por:\n1.Reservas mayores a\n2.Reservas menores a\n3.Tipo de recurso\n0.Volver\n-> ";
                                cin>>opc;
                                if(opc=="0"){
                                    break;
                                }
                                system("cls");
                                l[i]->BuscarRecurso(opc);
                            }
                        }
                        else if(opc=="9"){
                            system("cls");
                            l[i]->Modificar_Recurso();
                        }
                        else if(opc=="10"){
                            system("cls");
                            cout<<"Civilizacion: "<<l[i]->getName()<<endl;
                            cout<<"Habitantes: "<<l[i]->PoblacionTotal()<<"\tRecursos Totales: "<<l[i]->CantidadRecursos()<<" unidades"<<endl<<endl;
                            cout<<"Aldeanos: "<<endl<<endl;
                            l[i]->MostrarAldeano();
                            cout<<"\nGuerreros: "<<endl<<endl;
                            l[i]->MostrarGuerreros();
                            cout<<"\nRecursos: "<<endl<<endl;
                            l[i]->MostrarRecurso();
                            system("pause>null");
                        }
                        else if(opc=="0"){
                            break;
                        }
                        else{
                            system("cls");
                            cout<<"opcion invalida"<<endl<<endl;
                            system("pause>null");
                        }
                    }
                }
                if(cont>l.tamanio()){
                    cout<<"Civilizacion no encontrada";
                    Sleep(2000);
                }
                cont++;
            }
        }
        else if(opc=="3"){
            system("cls");
            int cont=1;
            cin.ignore();
            cout<<"Civilizacion a eliminar: ";
            getline(cin, dato);
            for(int i=0;i<l.tamanio();i++){
                if(l[i]->getName()==dato){
                    l.eliminar_posicion(i);
                    Sleep(1500);
                    break;
                }
                cont++;
                if(cont>l.tamanio()){
                    cout<<"Civilizacion no encontrada";
                    Sleep(2000);
                }
            }
        }
        else if(opc=="4"){
            system("cls");
            if(l.tamanio()==0){
                cout<<"No hay civilizaciones agregadas"<<endl;
            }
            else{
                for(int i=0;i<l.tamanio();i++){
                    cout<<"Civilizacion: "<<l[i]->getName()<<endl;
                    cout<<"Recursos: "<<l[i]->CantidadRecursos()<<" unidades"<<endl;
                    cout<<"Poblacion: "<<l[i]->PoblacionTotal()<<endl;
                    cout<<"Aldeanos: "<<l[i]->CantidadAldeanos()<<endl;
                    cout<<"Guerreros: "<<l[i]->CantidadGuerreros()<<endl<<endl;
                }
            }
            system("pause>null");
        }
        else if(opc=="5"){
            system("cls");
            cout<<"1.-Guardar\n2.-Respaldar\n0.-Volver\n-> ";
            cin>>opc2;
            if(opc2=="1"){
                while(true){
                    system("cls");
                    cout<<"\n\t\tSobreescribir los archivos guardados?\n\t   1.Si   2.No   -> ";
                    cin>>opc2;
                    if(opc2=="1"){
                        Respaldar(l);
                        break;
                    }
                    else if(opc2=="2"){
                        break;
                    }
                    else{
                        cout<<"\n\t\tOpcion invalida";Sleep(500);
                    }
                }
            }
            else if(opc2=="2"){
                while(true){
                    system("cls");
                    cout<<"\n\t\tSe perderan los archivos no guardados\n\tDesea continuar:   1.Si   2.No   -> ";
                    cin>>opc2;
                    if(opc2=="1"){
                        Recuperar(l,mapa,ald,war,rec);
                        break;
                    }
                    else if(opc2=="2"){
                        break;
                    }
                    else{
                        cout<<"\n\t\tOpcion invalida";Sleep(500);
                    }
                }
            }
            else if(opc2=="0"){
                Sleep(100);
            }
        }
        else if(opc=="6"){
            system("cls");
            MostrarMapa(mapa,l);
        }
        else if(opc=="0"){
            exit(0);
        }
    }

}

Menu::~Menu()
{

}

void Menu::agregarCivilizacion(Lista<Civilizacion *> &lista,Mapeo<Civilizacion *> &map,string n,int fila,int columna)
{
    Civilizacion *c = new Civilizacion();
    c->setName(n);
    c->setFila(fila);
    c->setColumna(columna);
    lista.insertar_final(c);
    map[fila][columna] = c;

}


void Menu::MostrarMapa(Mapeo<Civilizacion*> &map,Lista<Civilizacion*> &l)
{
    Civilizacion *m;
    if(l.tamanio()==0){
        for(int i=1;i<map.getFilas();i++){
            for(int j=1;j<map.getColumnas();j++){
                cout<<"0\t";
            }
            cout<<endl<<endl;
        }
        system("pause>null");
        return;
    }
    for(int i=1;i<map.getFilas();i++){
        for(int j=1;j<map.getColumnas();j++){
            m=map[i][j];
            if(m!=nullptr){
                cout<<m->getName()<<"\t";
            }
            else{
                cout<<m<<"\t";
            }
        }
        cout<<endl<<endl;
    }
    system("pause>null");
}

void Menu::Respaldar(Lista<Civilizacion*> &l1)
{
    ofstream archivo("Civilizaciones.txt", ios::out);

            for(int i=0;i<l1.tamanio();i++){
                archivo<<l1[i]->getName()<<endl;
                archivo<<l1[i]->getFila()<<endl;
                archivo<<l1[i]->getColumna()<<endl;
                ofstream aldeanos(l1[i]->getName()+".txt", ios::out);
                    for(int j=0;j<l1[i]->CantidadAldeanos();j++){
                        Civilizacion *c = l1[i];
                        Aldeanos &al2 = (*c)[j];
                        aldeanos<< al2.getNombre() <<endl;
                        aldeanos<< al2.getEdad() <<endl;
                        aldeanos<< al2.getGenero() <<endl;
                        aldeanos<< al2.getSalud() <<endl;
                    }
                aldeanos.close();
                ofstream guerreros("Guerreros "+l1[i]->getName()+".txt",ios::out);
                for(int k=0;k<l1[i]->CantidadGuerreros();k++){

                    guerreros<< l1[i]->ID(k) <<endl;
                    guerreros<< l1[i]->TGue(k) <<endl;
                    guerreros<< l1[i]->Sal(k) <<endl;
                    guerreros<< l1[i]->Fue(k) <<endl;
                    guerreros<< l1[i]->Esc(k) <<endl;
                }
                guerreros.close();
                ofstream recurso("Recursos "+l1[i]->getName()+".txt",ios::out);
                for(int l=0;l<l1[i]->CantidadCRecursos();l++){
                    recurso<< l1[i]->RID(l) << endl;
                    recurso<< l1[i]->Trec(l) << endl;
                    recurso<< l1[i]->Rcan(l) << endl;
                }
                recurso.close();
            }
        archivo.close();
}

void Menu::Recuperar(Lista<Civilizacion*> &l2,Mapeo<Civilizacion *> &mp,Aldeanos &al,Guerreros &gue,Recursos &rec)
{
    int i=0;
    ifstream archivo("Civilizaciones.txt", ios::in);

    if(archivo.is_open()){
        do{
            l2.eliminar_final();
        }while(l2.tamanio()!=0);
        while(!archivo.eof()){
            string line,li;
            int coo1,coo2;
            getline(archivo, line);
            if(archivo.eof())break;
            li=line;
            getline(archivo,line);
            stringstream ss(line);
            ss>>coo1;
            getline(archivo,line);
            stringstream ss1(line);
            ss1>>coo2;
            agregarCivilizacion(l2,mp,li,coo1,coo2);
            ifstream aldeanos(li+".txt", ios::in);

            if(aldeanos.is_open()){
                while(!aldeanos.eof()){
                    string nline;
                    int val;

                    getline(aldeanos,nline);
                    if(aldeanos.eof())break;
                    al.setNombre(nline);
                    getline(aldeanos,nline);
                    stringstream ss(nline);
                    ss>>val;
                    al.setEdad(val);
                    getline(aldeanos,nline);
                    al.setGenero(nline);
                    getline(aldeanos,nline);
                    stringstream ss2(nline);
                    ss2>>val;
                    al.setSalud(val);
                    l2[i]->AgregarAldeano(al);
                }
            }
            aldeanos.close();
            ifstream guerreros("Guerreros "+li+".txt",ios::in);

            if(guerreros.is_open()){
                while(!guerreros.eof()){
                    string nline;
                    int val;
                    float val2;

                    getline(guerreros,nline);
                    if(guerreros.eof())break;
                    stringstream ssn(nline);
                    ssn>>val;
                    gue.setId(val);
                    getline(guerreros,nline);
                    gue.setTguerrero(nline);
                    getline(guerreros,nline);
                    stringstream ss(nline);
                    ss>>val;
                    gue.setSalud(val);
                    getline(guerreros,nline);
                    stringstream ss2(nline);
                    ss2>>val2;
                    gue.setFuerza(val2);
                    getline(guerreros,nline);
                    stringstream ss3(nline);
                    ss3>>val2;
                    gue.setEscudo(val2);
                    l2[i]->AgregarGuerrero(gue);
                }
            }
            guerreros.close();
            ifstream recurso("Recursos "+li+".txt",ios::in);

            if(recurso.is_open()){
                while(!recurso.eof()){
                    string nline;
                    int val;

                    getline(recurso,nline);
                    if(recurso.eof())break;
                    stringstream ssn(nline);
                    ssn>>val;
                    rec.setId(val);
                    getline(recurso,nline);
                    rec.setTipoR(nline);
                    getline(recurso,nline);
                    stringstream ssn2(nline);
                    ssn2>>val;
                    rec.setCantidad(val);
                    l2[i]->AgregarRecurso(rec);
                }
            }
            recurso.close();
            i++;
        }
    }
    else{
        cout<<"\n\t\tNo hay archivos de guardado";system("pause>null");
    }
    archivo.close();
}


void Menu::Eliminar_Guerrero(string sel,int i,Lista<Civilizacion*> &l)
{
    string dato;
    int val;
    while(true){
        system("cls");
        if(sel=="1"){
            cout<<"ID del guerrero a eliminar: ";
            cin>>val;
            l[i]->EliminarGuerrero(val);
            break;
        }
        else if(sel=="2"){
            cout<<"Clase a eliminar:\n1.-Paladin\n2.-Asesino\n3.-Hechizero\n4.Tanque\n0.Volver\n-> ";
            cin>>dato;
            if(dato=="1"){
                dato="Paladin";
                l[i]->EliminarCGuerrero(dato);
            }
            else if(dato=="2"){
                dato="Asesino";
                l[i]->EliminarCGuerrero(dato);
            }
            else if(dato=="3"){
                dato="Hechizero";
                l[i]->EliminarCGuerrero(dato);
            }
            else if(dato=="4"){
                dato="Tanque";
                l[i]->EliminarCGuerrero(dato);
            }
            else{
                cout<<"Clase inexistente";
                Sleep(1500);
            }
            break;
        }
        else if(sel=="3"){
            cout<<"Eliminar Guerreros con salud menor a: ";
            cin>>val;
            l[i]->EliminarSGuerrero(val);
            break;
        }
        else if(sel=="0"){
            break;
        }
        else{
            cout<<"Opcion inexistente";
            Sleep(1500);
        }
    }
}

void Menu::Busqueda_Guerrero(int i, Lista<Civilizacion *> &l)
{
    string dato,opc,opc2;
    int val;
    while(true){
        system("cls");
        cout<<"Buscar Guerrero por:\n1.Salud\n2.Fuerza\n3.Clase\n0.Volver\n-> ";
        cin>>opc;
        if(opc=="1"){
            system("cls");
            cout<<"1.Salud Mayor a\n2.Salud Menor a\n-> ";
            cin>>opc2;
            l[i]->BuscarSGuerrero(opc2);
        }
        else if(opc=="2"){
            system("cls");
            cout<<"1.Fuerza Mayor a\n2.Fuerza Menor a\n-> ";
            cin>>opc2;
            l[i]->BuscarFGuerrero(opc2);
        }
        else if(opc=="3"){
            do{
                system("cls");
                cout<<"Buscar Guerreros de clase:\n1.Paladin\n2.Asesino\n3.Hechizero\n4.Tanque\n-> ";
                cin>>val;
                dato=l[i]->Tipo_Guerrero(val);
            }while(dato=="0");
            l[i]->BuscarCGuerrero(dato);
        }
        else if(opc=="0"){
            break;
        }
        else{
            cout<<"Opcion inexistente";
            Sleep(1500);
        }
    }
}
