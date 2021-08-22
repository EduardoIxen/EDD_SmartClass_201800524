//
// Created by Eduardo-Ixen on 18/08/2021.
//

#include "CTarea.h"

void CTarea::agregarTarea(LinealizarMatriz *& listaTareas) {
    auto* nuevaTarea = new Tarea();
    string carnet, nombre, descripcion, materia, fecha, hora, estado;
    Estado nuevoEstado = Estado::INEXISTENTE;
    bool estadoAceptado = false;

    do {
        cout << "############# INGRESE EL CARNET DEL ESTUDIANTE #############" << endl;
        cin >> carnet;
        cin.ignore(); //limpiar el buffer de datos
    } while (!verificarCarnet(carnet));
    do {
        cout << "################ INGRESE EL NOMBRE DE LA TAREA ##############" << endl;
        getline(cin, nombre);
    } while (nombre.empty());
    do {
        cout << "############# INGRESE LA DESCRIPCION DE LA TAREA #############" << endl;
        getline(cin, descripcion);
    } while (nombre.empty());
    do {
        cout << "##################### INGRESE LA MATERIA ####################" << endl;
        getline(cin, materia);
    } while (nombre.empty());
    do {
        cout << "############### INGRESE LA FECHA (anio/mes/dia) ##############" << endl;
        cin >> fecha;
        cin.ignore();
    } while (!verificarFecha(fecha));
    do {
        cout << "##################### INGRESE LA HORA ####################" << endl;
        cin >> hora;
        cin.ignore();
    } while (!verificarHora(hora));
    do {
        int opcion =0;
        cout << "################### SELECCIONE EL ESTADO ##################" << endl;
        cout << "1) Pendiente" << endl;
        cout << "2) Realizado" << endl;
        cout << "2) Incumplido" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                nuevoEstado = Estado::PENDIENTE;
                estadoAceptado = true;
                break;
            case 2:
                nuevoEstado = Estado::CUMPLIDO;
                estadoAceptado = true;
                break;
            case 3:
                nuevoEstado = Estado::INCUMPLIDO;
                estadoAceptado = true;
                break;
            default:
                cout<<"ERROR// OPCION INVALIDA";
                break;
        }
    } while (!estadoAceptado);

    nuevaTarea->setId(obtenerPosicionNodo(fecha, stoi(hora)));
    nuevaTarea->setCarnet(stoi(carnet));
    nuevaTarea->setNombre(nombre);
    nuevaTarea->setDescripcion(descripcion);
    nuevaTarea->setMateria(materia);
    nuevaTarea->setFecha(crearFecha(fecha));
    nuevaTarea->setHora(stoi(hora));
    nuevaTarea->setEstado(nuevoEstado);

    listaTareas->insertarManual(nuevaTarea, obtenerPosicionNodo(fecha, stoi(hora)));

}

void CTarea::modificarTarea(LinealizarMatriz *& listaTareas, int indice) {
    auto* aux = listaTareas->getPrimero();

    while (aux != NULL){ //dejar el ciclo cuando llegue al final con sig = null
        if (aux->getId() == indice){
            if (aux->getTarea() != NULL){
                cambioDeDatos(*&aux, listaTareas);
                return;
            } else{
                cout<<"----NO SE ENCUENTRAN TAREAS EN LA POSICION INGRESADA----"<<endl;
                return;
            }
        }
        aux = aux->getSiguiente();
    }
    cout<<"----NO SE ENCONTRO LA POSICION INGRESADA----"<<endl;

}

void CTarea::eliminarTarea(LinealizarMatriz *& listaTareas, int indice) {
    auto* aux = listaTareas->getPrimero();
    int confirmar = 0;

    while (aux != NULL){ //dejar el ciclo cuando llegue al final con sig = null
        if (aux->getId() == indice){
            if (aux->getTarea() != NULL){
                do{
                    cout<<"---- ESTA SEGURO DE QUE DESEA ELIMINAR LA TAREA? ----"<<endl;
                    cout<<"1) Si"<<endl;
                    cout<<"2) No"<<endl;
                    cin >> confirmar;
                    cin.ignore();
                    if (confirmar == 1){
                        aux->setTarea(NULL);
                        cout<<"--------------------- TAREA ELIMINADA -----------------"<<endl;
                        return;
                    }else if (confirmar == 2){
                        cout<<"------------------- NO SE ELIMINO LA TAREA -------------"<<endl;
                        return;
                    }
                } while (true);
            } else{
                cout<<"----NO SE ENCUENTRAN TAREAS EN LA POSICION INGRESADA----"<<endl;
                return;
            }
        }
        aux = aux->getSiguiente();
    }
    cout<<"----NO SE ENCONTRO LA POSICION INGRESADA----"<<endl;
}

bool CTarea::verificarCarnet(string _carnet) {
    if (_carnet.length() == 9) {
        if (verificarNumero(_carnet)) {
            return true;
        } else {
            cout << "----Carnet invalido, debe de conformarse de solo digitos.----" << endl;
            return false;
        }
    } else {
        cout << "----Carnet invalido, debe ser de un numero de 9 digitos.----" << endl;
        return false;
    }
}

bool CTarea::verificarNumero(string numero) {
    for (int i = 0; i < numero.size(); ++i) {
        if (!isdigit(numero[i])) {
            cout << numero[i] << endl;
            cout << "----Lo ingresado no es un numero.----" << endl;
            return false;
        }
    }
    cout << "----Numero aceptado.----" << endl;
    return true;
}

bool CTarea::verificarFecha(string fecha) {
    string anio, mes, dia;
    int nMes, nDia;
    stringstream stream(fecha);
    getline(stream, anio, '/');
    getline(stream, mes, '/');
    getline(stream, dia, '/');
    nMes = stoi(mes);
    nDia = stoi(dia);
    if ((nDia > 0 && nDia <= 30) && (nMes >= 7 && nMes <= 11)){
        return true;
    } else{
        cout<<"--FECHA INVALIDA: Verifique los rangos y el formato de entreda (anio/mes/dia)."<<endl;
    }
    return false;
}
bool CTarea::verificarHora(string hora) {
    int _hora = 0;
    if(verificarNumero(hora)){
        _hora = stoi(hora);
        if (_hora >= 8 && _hora <= 16){
            return true;
        }
    }
    cout<<"--HORA INVALIDA: Verifique que este en el rango de 8-16."<<endl;
    return false;
}

Fecha* CTarea::crearFecha(string fecha) {
    string anio, mes, dia;
    int nMes, nDia, nAnio;
    stringstream stream(fecha);
    getline(stream, anio, '/');
    getline(stream, mes, '/');
    getline(stream, dia, '/');
    nMes = stoi(mes);
    nDia = stoi(dia);
    nAnio = stoi(anio);
    Fecha *nuevaFecha = new Fecha(nDia, nMes, nAnio);
    return nuevaFecha;
}

int CTarea::obtenerPosicionNodo(string fecha, int hora) {
    string anio, mes, dia;
    int nMes, nDia, nAnio, posicion;
    stringstream stream(fecha);
    getline(stream, anio, '/');
    getline(stream, mes, '/');
    getline(stream, dia, '/');
    nMes = stoi(mes);
    nDia = stoi(dia);
    nAnio = stoi(anio);
    //i = horas j=dias k = meses   formula row major ( i * TamColum + j ) * TamProf + k
    posicion = ((hora-8) * 30 + (nDia-1)) * 5 + (nMes-7);
    return posicion;
}

void CTarea::cambioDeDatos(NodoMatrizL *& nodo, LinealizarMatriz*& listaTareas) {
    int opcion = 0;
    string op = "";
    string carnet, nombre, descripcion, materia, fecha, hora;
    bool estadoAceptado = false;
    Estado nuevoEstado = Estado::INEXISTENTE;
    Fecha* fechaTemp;
    int horaTemp = 0;

    do {
        cout << "MENU MODIFICACION:" << endl;
        cout << "1) Modificar carnet" << endl;
        cout << "2) Modificar nombre" << endl;
        cout << "3) Modificar descripcion" << endl;
        cout << "4) Modificar materia" << endl;
        cout << "5) Modificar fecha" << endl;
        cout << "6) Modificar hora" << endl;
        cout << "7) Modificar estado" << endl;
        cout << "8) Salir." << endl;
        cout << ">>";
        cin >> op;
        cin.ignore();
        opcion = stoi(op);
        switch (opcion) {
            case 1:
                cout<<"Dato actual "<<nodo->getTarea()->getCarnet()<<endl;
                do {
                    cout << "############# INGRESE EL NUEVO CARNET #############" << endl;
                    cin >> carnet;
                    cin.ignore();
                } while (!verificarCarnet(carnet));
                nodo->getTarea()->setCarnet(stoi(carnet));
                break;
            case 2:
                cout<<"Dato actual "<<nodo->getTarea()->getNombre()<<endl;
                do {
                    cout << "############# INGRESE EL NUEVO NOMBRE #############" << endl;
                    getline(cin, nombre);
                } while (nombre.empty());
                nodo->getTarea()->setNombre(nombre);
                break;
            case 3:
                cout<<"Dato actual "<<nodo->getTarea()->getDescripcion()<<endl;
                do {
                    cout << "############ INGRESE LA NUEVA DESCRIPCION ############" << endl;
                    getline(cin, descripcion);
                } while (descripcion.empty());
                nodo->getTarea()->setDescripcion(descripcion);
                break;
            case 4:
                cout<<"Dato actual "<<nodo->getTarea()->getMateria()<<endl;
                do {
                    cout << "############# INGRESE LA NUEVA MATERIA #############" << endl;
                    getline(cin, materia);
                } while (materia.empty());
                nodo->getTarea()->setMateria(materia);
                break;
            case 5:
                cout<<"Dato actual "<<nodo->getTarea()->getFecha()->obtenerFecha("/")<<endl;
                do {
                    cout << "########## INGRESE LA NUEVA FECHA (anio/mes/dia) ########" << endl;
                    cin >> fecha;
                    cin.ignore();
                } while (!verificarFecha(fecha));
                fechaTemp =nodo->getTarea()->getFecha();
                nodo->getTarea()->setFecha(crearFecha(fecha));
                //mover posicion a nuevo indice
                if (listaTareas->insertarManual(nodo->getTarea(), obtenerPosicionNodo(nodo->getTarea()->getFecha()->obtenerFecha("/"),nodo->getTarea()->getHora()))){
                    cout<<"INDICE DEL NODO CAMBIADO, NUEVO INDICE: "<<obtenerPosicionNodo(nodo->getTarea()->getFecha()->obtenerFecha("/"), nodo->getTarea()->getHora())<<endl;
                    nodo->setTarea(NULL);
                    return;
                } else{
                    nodo->getTarea()->setFecha(fechaTemp);
                }
                break;
            case 6:
                cout << "Dato actual " << nodo->getTarea()->getHora() << endl;
                do {
                    cout << "################ INGRESE LA NUEVA HORA ################" << endl;
                    cin >> hora;
                    cin.ignore();
                } while (!verificarHora(hora));
                horaTemp = nodo->getTarea()->getHora();
                nodo->getTarea()->setHora(stoi(hora));
                if (listaTareas->insertarManual(nodo->getTarea(), obtenerPosicionNodo(nodo->getTarea()->getFecha()->obtenerFecha("/"),nodo->getTarea()->getHora()))){
                    cout<<"INDICE DEL NODO CAMBIADO, NUEVO INDICE: "<<obtenerPosicionNodo(nodo->getTarea()->getFecha()->obtenerFecha("/"), nodo->getTarea()->getHora())<<endl;
                    nodo->setTarea(NULL);
                    return;
                } else{
                    nodo->getTarea()->setHora(horaTemp);
                }
                break;
            case 7:
                cout << "Dato actual " << obtenerEstado(nodo->getTarea()->getEstado()) << endl;
                do {
                    int opcion2 = 0;
                    cout << "############### SELECCIONE EL NUEVO ESTADO ##############" << endl;
                    cout << "1) Pendiente" << endl;
                    cout << "2) Realizado" << endl;
                    cout << "2) Incumplido" << endl;
                    cin >> opcion2;
                    cin.ignore();
                    switch (opcion2) {
                        case 1:
                            nuevoEstado = Estado::PENDIENTE;
                            estadoAceptado = true;
                            break;
                        case 2:
                            nuevoEstado = Estado::CUMPLIDO;
                            estadoAceptado = true;
                            break;
                        case 3:
                            nuevoEstado = Estado::INCUMPLIDO;
                            estadoAceptado = true;
                            break;
                        default:
                            cout << "ERROR// OPCION INVALIDA";
                            break;
                    }
                } while (!estadoAceptado);
                nodo->getTarea()->setEstado(nuevoEstado);
                break;
            case 8:
                break;
            default:
                cout << "-----------------OPCION INVALIDA-----------------" << endl;
        }
    } while (opcion != 8);
}

string CTarea::obtenerEstado(Estado estado){
    if (estado == Estado::CUMPLIDO){
        return "Cumplido";
    }else if (estado == Estado::PENDIENTE){
        return "Pendiente";
    } else if (estado == Estado::INCUMPLIDO){
        return "Incumplido";
    }
    return "Inexistente";
}