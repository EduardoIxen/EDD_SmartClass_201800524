//
// Created by Eduardo-Ixen on 11/08/2021.
//

#include "ReadCsv.h"

void ReadCsv::readEstudiantes(string _path, ListaDobleEstud *&listaDobleEst, ColaDeError*& colaDeError) {
    string carnet, dpi, nombre, carrera, correo, passw, creditos, edad;
    int numeroLinea = 1;
    //_path = R"(C:\Users\tomas\CLionProjects\EDD_SmartClass_201800524\Estudiantes.csv)";

    string linea;
    char delimitador = ',';

    ifstream archivo(_path);

    if (archivo.fail()) {
        cout << "ERROR// OCURRIO UN ERROR AL ABRIR EL ARCHIVO." << endl;
        return;
    }
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        numeroLinea += 1;
        stringstream stream(linea); //convertir string en stream para insertar y extraer desde y a string
        getline(stream, carnet, delimitador);
        getline(stream, dpi, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, carrera, delimitador);
        getline(stream, passw, delimitador);
        getline(stream, creditos, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, correo, delimitador);

        validarDatos(carnet, dpi, correo, colaDeError, numeroLinea);

        auto *nuevoEstudiante = new Estudiante(stoi(carnet), stoll(dpi, nullptr, 10), nombre, carrera, correo, passw,
                                               stoi(creditos), stoi(edad));
        listaDobleEst->insertar(nuevoEstudiante);
    }
    archivo.close();
    cout<<"----Estudiantes cargados, errores encontrodos: "<<colaDeError->getTamanio()<<"----"<<endl;
}

void ReadCsv::validarDatos(string carnet, string dpi, string correo, ColaDeError*& colaDeError, int numeroLinea) {
    Error* nuevoError = new Error();
    bool carnetValido = true;
    bool dpiValido = true;
    bool correoValido = true;
    string descripcion = "Linea numero: "+ to_string(numeroLinea) + "\n";

    if (carnet.length() != 9) {
        cout << "--Carnet invalido--" << endl;
        descripcion += "*Carnet invalido: " + carnet +"\n";
        carnetValido = false;
    }

    if (dpi.length() != 13) {
        cout << "--Dpi invalido--" << endl;
        descripcion += "*DPI invalido: " + dpi +"\n";
        dpiValido = false;
    }

    if (!regex_match(correo, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)((.com)|(.es)|(.org))"))) {
        cout << "--Correo invalido--";
        descripcion += "*Correo invalido: " + correo +"\n";
        correoValido = false;
    }

    if (!carnetValido || !dpiValido || !correoValido){
        nuevoError->setTipo("Estudiante");
        nuevoError->setDescripcion(descripcion);
        nuevoError->setId(0);
        colaDeError->enqueue(nuevoError);
    }
}
