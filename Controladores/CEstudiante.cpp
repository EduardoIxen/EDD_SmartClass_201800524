//
// Created by Eduardo-Ixen on 13/08/2021.
//

#include "CEstudiante.h"

void CEstudiante::agregarEstudiante(ListaDobleEstud*& lista) {
    auto * nuevoEst = new Estudiante();
    string carnet, edad, creditos, nombre, carrera, correo, pass, dpi;
    do {
        cout << "############# INGRESE EL CARNET DEL ESTUDIANTE #############"<<endl;
        cin >> carnet;
    } while (!validarCarnet(carnet));
    do {
        cout << "############## INGRESE EL DPI DEL ESTUDIANTE ###############"<<endl;
        cin >> dpi;
        cin.ignore();
    } while (!validarDpi(dpi) && !dpi.empty());
    do{
        cout << "##################### INGRESE EL NOMBRE ####################"<<endl;
        getline(cin, nombre);
    } while (nombre.empty());
    do {
        cout << "#################### INGRESE LA CARRERA ####################"<<endl;
        getline(cin, carrera);
    } while (carrera.empty());

    do {
        cout << "#################### INGRESE EL CORREO #####################"<<endl;
        getline(cin, correo);
    } while (!validarCorreo(correo));
    do {
        cout << "################### INGRESE LA CONTRASENIA #################"<<endl;
        getline(cin, pass);
    } while (pass.empty());
    do {
        cout << "#################### INGRESE LOS CREDITOS ####################"<<endl;
        getline(cin, creditos);
    } while (!verificarNumero(creditos));
    do {
        cout << "##################### INGRESE LA EDAD ######################"<<endl;
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

    lista->insertar(*nuevoEst);
}

void CEstudiante::modificarEstudiante(ListaDobleEstud*& lista) {

}

void CEstudiante::eliminarEstudiante(ListaDobleEstud*& lista) {

}

bool CEstudiante::validarCarnet(string _carnet) {
    if (_carnet.length() == 9)
    {
        if (verificarNumero(_carnet)){
            return true;
        }else{
            cout << "----Carnet invalido, debe de conformarse de solo digitos.----" << endl;
            return false;
        }
    }
    else
    {
        cout << "----Carnet invalido, debe ser de un numero de 9 digitos.----" << endl;
        return false;
    }
}

bool CEstudiante::validarDpi(string _dpi) {
    if (_dpi.length() == 13)
    {
        if (verificarNumero(_dpi)){
            return true;
        } else{
            cout << "----DPI invalido, unicamente debe conformarse de numeros.----" << endl;
            return false;
        }
    }
    else
    {
        cout << "----DPI invalido, debe ser de un numero de 13 digitos.----" << endl;
        return false;
    }
}

bool CEstudiante::validarCorreo(string correo) {
    if (regex_match(correo, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)((.com)|(.es)|(.org))")))
    {
        cout << "---Correo aceptado---"<<endl;
        return true;
    }
    else
    {
        cout << "---Correo invalido---"<<endl;
        return false;
    }
}

bool CEstudiante::verificarNumero(string numero) {
    for (int i = 0; i < numero.size(); ++i) {
        if (!isdigit(numero[i]) ){
            cout<<numero[i]<<endl;
            cout << "----Lo ingresado no es un numero.----" << endl;
            return false;
        }
    }
    cout << "----Numero aceptado.----" << endl;
    return true;
}