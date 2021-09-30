//
// Created by Eduardo-Ixen on 13/08/2021.
//

#include "CEstudiante.h"

void CEstudiante::agregarEstudiante(ListaDobleEstud *&lista) {
    /*
     * Agregar un estudiante a la lista circular doblemente enlazada de forma manual,
     * solicitándole uno a uno los datos que se necesitan para crear el objeto.
     *
     * */
    auto *nuevoEst = new Estudiante();
    string carnet, edad, creditos, nombre, carrera, correo, pass, dpi;
    do {
        cout << "############# INGRESE EL CARNET DEL ESTUDIANTE #############" << endl;
        cin >> carnet;
        cin.ignore();
    } while (!validarCarnet(carnet));
    do {
        cout << "############## INGRESE EL DPI DEL ESTUDIANTE ###############" << endl;
        cin >> dpi;
        cin.ignore(); //limpiar buffer de datos
    } while (!validarDpi(dpi) && !dpi.empty());
    do {
        cout << "##################### INGRESE EL NOMBRE ####################" << endl;
        getline(cin, nombre);
    } while (nombre.empty());
    do {
        cout << "#################### INGRESE LA CARRERA ####################" << endl;
        getline(cin, carrera);
    } while (carrera.empty());

    do {
        cout << "#################### INGRESE EL CORREO #####################" << endl;
        getline(cin, correo);
    } while (!validarCorreo(correo));
    do {
        cout << "################### INGRESE LA CONTRASENIA #################" << endl;
        getline(cin, pass);
    } while (pass.empty());
    do {
        cout << "#################### INGRESE LOS CREDITOS ####################" << endl;
        getline(cin, creditos);
    } while (!verificarNumero(creditos));
    do {
        cout << "##################### INGRESE LA EDAD ######################" << endl;
        getline(cin, edad);
    } while (!verificarNumero(edad));

    nuevoEst->setCarnet(stoi(carnet));
    nuevoEst->setDpi(stoll(dpi, nullptr, 10));
    nuevoEst->setNombre(nombre);
    nuevoEst->setCarrera(carrera);
    nuevoEst->setCorreo(correo);
    nuevoEst->setPass(pass);
    nuevoEst->setCreditos(stoi(creditos));
    nuevoEst->setEdad(stoi(edad));
    lista->insertar(nuevoEst);
    cout << "----Estudiante: " << nombre << " (" << carnet << ") " << "agregado correctamente----" << endl;
}

void CEstudiante::modificarEstudiante(ListaDobleEstud *&lista, string dpi) {
    /*
     * Buscar al estudiante por medio del dpi en la lista doblemente enlazada
     * y asi obtener el nodo que lo contiene para luego modificarlo en cambioDeDatos();
     * */
    if (!verificarNumero(dpi)) {
        cout << "----DPI INVALIDO----" << endl;
        return;
    }
    long long int _dpi = stoll(dpi, nullptr, 10);

    NodoEstudiante *aux = lista->getPrimero();
    while (aux->getSiguiente() != lista->getPrimero()) {
        if (aux->getEstudiante()->getDpi() == _dpi) {
            cambioDeDatos(*&aux); //lleva al formulario de cambio de datos
            return;
        }
        aux = aux->getSiguiente();
    }
    if (lista->getUltimo()->getEstudiante()->getDpi() == _dpi) {
        cambioDeDatos(*&aux);
    }
}

void CEstudiante::eliminarEstudiante(ListaDobleEstud *&lista, string dpi) {
    if (!verificarNumero(dpi)) {
        cout << "----DPI INVALIDO----" << endl;
        return;
    }
    if (lista->getTamanio() == 0) {
        cout << "---- LISTA VACIA ----" << endl;
        return;
    }
    long long int _dpi = stoll(dpi, nullptr, 10);
    NodoEstudiante *aux = lista->getPrimero();


    if (lista->getUltimo()->getEstudiante()->getDpi() == _dpi) {
        if (lista->getTamanio() == 1) {
            lista->setPrimero(NULL);
            lista->setUltimo(NULL);
            lista->setTamanio(lista->getTamanio() - 1);
            return;
        }
        NodoEstudiante *nodoAux = lista->getUltimo();
        aux->setAnterior(nodoAux->getAnterior());
        nodoAux->getAnterior()->setSiguiente(aux);
        lista->setUltimo(nodoAux->getAnterior());
        lista->setTamanio(lista->getTamanio() - 1);
        return;
    }
    if (lista->getPrimero()->getEstudiante()->getDpi() == _dpi) {
        if (lista->getTamanio() == 1) {
            lista->setPrimero(NULL);
            lista->setUltimo(NULL);
            lista->setTamanio(lista->getTamanio() - 1);
            return;
        }
        NodoEstudiante *nodoAux = aux;
        aux->getAnterior()->setSiguiente(nodoAux->getSiguiente());
        aux->getSiguiente()->setAnterior(nodoAux->getAnterior());
        lista->setUltimo(nodoAux->getAnterior());
        lista->setPrimero(nodoAux->getSiguiente());
        lista->setTamanio(lista->getTamanio() - 1);
        return;
    }

    while (aux->getSiguiente() != lista->getPrimero()) {
        if (aux->getEstudiante()->getDpi() == _dpi) {
            NodoEstudiante *nodoAux = aux;
            aux->getAnterior()->setSiguiente(nodoAux->getSiguiente());
            aux->getSiguiente()->setAnterior(nodoAux->getAnterior());
            lista->setTamanio(lista->getTamanio() - 1);
            return;
        }
        aux = aux->getSiguiente();
    }

    cout << "----Estudiante no encontrado.----" << endl;

}

bool CEstudiante::validarCarnet(string _carnet) {
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

bool CEstudiante::validarDpi(string _dpi) {
    if (_dpi.length() == 13) {
        if (verificarNumero(_dpi)) {
            return true;
        } else {
            cout << "----DPI invalido, unicamente debe conformarse de numeros.----" << endl;
            return false;
        }
    } else {
        cout << "----DPI invalido, debe ser de un numero de 13 digitos.----" << endl;
        return false;
    }
}

bool CEstudiante::validarCorreo(string correo) {
    if (regex_match(correo, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)((.com)|(.es)|(.org))"))) {
        cout << "---Correo aceptado---" << endl;
        return true;
    } else {
        cout << "---Correo invalido---" << endl;
        return false;
    }
}

bool CEstudiante::verificarNumero(string numero) {
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

void CEstudiante::cambioDeDatos(NodoEstudiante *&nodo) {
    /*
     * Modifica los datos del nodo recibido, solicitándole al usuario
     * uno a uno los datos para cambiarlos.
     * */
    string opcion = "";
    string carnet, edad, creditos, nombre, carrera, correo, pass, dpi;
    int opConv = 0;
    do {
        cout << "MENU MODIFICACION:" << endl;
        cout << "1) Modificar carnet" << endl;
        cout << "2) Modificar dpi" << endl;
        cout << "3) Modificar nombre" << endl;
        cout << "4) Modificar carrera" << endl;
        cout << "5) Modificar correo" << endl;
        cout << "6) Modificar contrasenia" << endl;
        cout << "7) Modificar creditos" << endl;
        cout << "8) Modificar edad" << endl;
        cout << "9) Salir." << endl;
        cin >> opcion;
        cin.ignore();
        opConv = stoi(opcion);
        switch (opConv) {
            case 1:
                cout << "Dato actual: " << nodo->getEstudiante()->getCarnet() << endl;
                do {
                    cout << "############# INGRESE EL NUEVO CARNET DEL ESTUDIANTE #############" << endl;
                    cin >> carnet;
                    cin.ignore();
                } while (!validarCarnet(carnet));
                nodo->getEstudiante()->setCarnet(stoi(carnet));
                cout << "----Carnet modificado correctamente---- " << endl;
                break;
            case 2:
                cout << "Dato actual: " << nodo->getEstudiante()->getDpi() << endl;
                do {
                    cout << "############## INGRESE EL NUEVO DPI DEL ESTUDIANTE ###############" << endl;
                    cin >> dpi;
                    cin.ignore(); //limpiar buffer de datos
                } while (!validarDpi(dpi) && !dpi.empty());
                nodo->getEstudiante()->setDpi(stoll(dpi, nullptr, 10));
                cout << "----Dpi modificado correctamente---- " << endl;
                break;
            case 3:
                cout << "Dato actual: " << nodo->getEstudiante()->getNombre() << endl;
                do {
                    cout << "##################### INGRESE EL NUEVO NOMBRE ####################" << endl;
                    getline(cin, nombre);
                } while (nombre.empty());
                nodo->getEstudiante()->setNombre(nombre);
                cout << "----Nombre modificado correctamente---- " << endl;
                break;
            case 4:
                cout << "Dato actual: " << nodo->getEstudiante()->getCarrera() << endl;
                do {
                    cout << "#################### INGRESE LA NUEVA CARRERA ####################" << endl;
                    getline(cin, carrera);
                } while (carrera.empty());
                nodo->getEstudiante()->setCarrera(carrera);
                cout << "----Carrera modificada correctamente---- " << endl;
                break;
            case 5:
                cout << "Dato actual: " << nodo->getEstudiante()->getCorreo() << endl;
                do {
                    cout << "#################### INGRESE EL NUEVO CORREO #####################" << endl;
                    getline(cin, correo);
                } while (!validarCorreo(correo));
                nodo->getEstudiante()->setCorreo(correo);
                cout << "----Correo modificado correctamente---- " << endl;
                break;
            case 6:
                cout << "Dato actual: " << nodo->getEstudiante()->getPass() << endl;
                do {
                    cout << "################### INGRESE LA NUEVA CONTRASENIA #################" << endl;
                    getline(cin, pass);
                    cin.ignore();
                } while (pass.empty());
                nodo->getEstudiante()->setPass(pass);
                cout << "----Contrasenia modificada correctamente---- " << endl;
                break;
            case 7:
                do {
                    cout << "#################### INGRESE LOS CREDITOS NUEVOS ####################" << endl;
                    getline(cin, creditos);
                    cin.ignore();
                } while (!verificarNumero(creditos));
                nodo->getEstudiante()->setCreditos(stoi(creditos));
                cout << "----Creditos modificado correctamente---- " << endl;
                break;
            case 8:
                do {
                    cout << "##################### INGRESE LA NUEVA EDAD ######################" << endl;
                    getline(cin, edad);
                } while (!verificarNumero(edad));
                nodo->getEstudiante()->setEdad(stoi(edad));
                cout << "----Edad modificada correctamente---- " << endl;
                break;
            case 9:
                break;
            default:
                cout << "-----------------OPCION INVALIDA-----------------" << endl;
        }
    } while (opConv != 9);

}