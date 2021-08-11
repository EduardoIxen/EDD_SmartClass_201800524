//
// Created by Eduardo-Ixen on 10/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_ESTUDIANTE_H
#define EDD_SMARTCLASS_201800524_ESTUDIANTE_H

#include<iostream>

using namespace std;

class Estudiante {
private:
    int carnet;
    long long int dpi;
    string nombre;
    string carrera;
    string correo;
    string pass;
    int creditos;
    int edad;

public:
    Estudiante(int, long long int, string, string, string, string, int, int);
    Estudiante();

    void setCarnet(int);
    void setDpi(long long int);
    void setNombre(string);
    void setCarrera(string);
    void setCorreo(string);
    void setPass(string);
    void setCreditos(int);
    void setEdad(int);

    int getCarnet();
    long long int getDpi();
    string getNombre();
    string getCarrera();
    string getCorreo();
    string getPass();
    int getCreditos();
    int getEdad();

    string verEstudiante();

    ~Estudiante(); //destructor
};


#endif //EDD_SMARTCLASS_201800524_ESTUDIANTE_H
