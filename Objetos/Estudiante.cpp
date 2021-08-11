//
// Created by Eduardo-Ixen on 10/08/2021.
//

#include "Estudiante.h"

Estudiante::Estudiante() {}

Estudiante::Estudiante(int _carnet, long long int _dpi, string _nombre, string _carrera, string _correo,
                       string _pass, int _creditos, int _edad) {
    this->carnet = _carnet;
    this->dpi = _dpi;
    this->nombre = _nombre;
    this->carrera = _carrera;
    this->correo = _correo;
    this->pass = _pass;
    this->creditos = _creditos;
    this->edad = _edad;
}

void Estudiante::setCarnet(int _carnet){
    this->carnet = _carnet;
}

void Estudiante::setDpi(long long int _dpi){
    this->dpi = _dpi;
}

void Estudiante::setNombre(string _nombre){
    this->nombre = _nombre;
}

void Estudiante::setCarrera(string _carrera){
    this->carrera = _carrera;
}

void Estudiante::setCorreo(string _correo){
    this->correo = _correo;
}

void Estudiante::setPass(string _pass){
    this->pass = _pass;
}

void Estudiante::setCreditos(int _creditos){
    this->creditos = _creditos;
}

void Estudiante::setEdad(int _edad){
    this->edad = _edad;
}

string Estudiante::verEstudiante(){
    return "Carnet->" + to_string(carnet) + "\n"+
    "DPI->"+to_string(dpi) + "\n" +
    "Nombre->"+nombre + "\n"+
    "Carrera->"+this->carrera + "\n"+
    "Correo->"+this->correo + "\n"+
    "Pass->"+this->pass+"\n"+
    "Creditos->"+ to_string(this->creditos)+"\n"+
    "Edad->"+to_string(this->edad)+"\n";
}

int Estudiante::getCarnet(){return this->carnet;}

long long int Estudiante::getDpi(){return this->dpi;}

string Estudiante::getNombre(){return this->nombre;}

string Estudiante::getCarrera(){return this->carrera;}

string Estudiante::getCorreo(){return this->correo;}

string Estudiante::getPass(){return this->pass;}

int Estudiante::getCreditos(){return this->creditos;}

int Estudiante::getEdad(){return this->edad;}

Estudiante::~Estudiante() {
}
