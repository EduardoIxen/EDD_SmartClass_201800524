//
// Created by Eduardo-Ixen on 11/08/2021.
//

#include "ReadCsv.h"

void ReadCsv::readEstudiantes(string _path, ListaDobleEstud*& listaDobleEst) {
    string carnet, dpi, nombre, carrera, correo, passw, creditos, edad;
    //_path = R"(C:\Users\tomas\OneDrive\Documents\201800524\2021\Segundo semestre\EDD\Laboratorio\EDD_SmartClass_201800524\Estudiantes2.csv)";
    _path = R"(C:\Users\tomas\CLionProjects\EDD_SmartClass_201800524\Estudiantes.csv)";

    string linea;
    char delimitador = ',';

    ifstream archivo(_path);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo de tareas." << endl;
        exit(1);
    }
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea); //convertir string en stream para insertar y extraer desde y a string
        getline(stream, carnet, delimitador);
        getline(stream, dpi, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, carrera, delimitador);
        getline(stream, passw, delimitador);
        getline(stream, creditos, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, correo, delimitador);

        validarDatos(carnet, dpi, correo);

        auto* nuevoEstudiante = new Estudiante(stoi(carnet), stoll(dpi, nullptr, 10), nombre, carrera, correo, passw, stoi(creditos), stoi(edad));
        listaDobleEst->insertar(*nuevoEstudiante);
        cout<<"parar"<<endl;
    }
    archivo.close();

}

void ReadCsv::validarDatos(string carnet, string dpi, string correo) {
    bool numerosValidos = false;
    bool correoValido = false;

    if (carnet.length() == 9)
    {
        cout << "Carnet valido" << endl;
        cout << carnet << endl;
    }
    else
    {
        cout << "--Carnet invalido--" << endl;
    }

    if (dpi.length() == 13)
    {
        cout << "Dpi valido" << endl;
        cout << dpi << endl;
    }
    else
    {
        cout << "--Dpi invalido--" << endl;
    }

    if (regex_match(correo, regex("([a-z]+)([_.a-z0-9]*)([a-z0-9]+)(@)([a-z]+)((.com)|(.es)|(.org))")))
    {
        cout << "Correo valido" << endl;
    }
    else
    {
        cout << "--Correo invalido--";
        cout << correo << endl;
    }
}
