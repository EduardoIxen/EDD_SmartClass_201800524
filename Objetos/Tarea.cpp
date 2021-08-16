//
// Created by Eduardo-Ixen on 15/08/2021.
//

#include "Tarea.h"

Tarea::Tarea(int id, int carnet,string nombre, string descripcion, string materia,
             Fecha *fecha, int hora, Estado estado) {
    setId(id);
    setCarnet(carnet);
    setNombre(nombre);
    setDescripcion(descripcion);
    setMateria(materia);
    setFecha(fecha);
    setHora(hora);
    setEstado(estado);
}

Tarea::Tarea() {
    this->id = 0;
    this->carnet = 0;
    this->nombre = "";
    this->descripcion = "";
    this->materia = "";
    this->fecha = new Fecha(0,0,0);
    this->hora = 0;
    this->estado = Estado::INEXISTENTE;
}

int Tarea::getId(){
    return id;
}

void Tarea::setId(int id) {
    this->id = id;
}

int Tarea::getCarnet() {
    return carnet;
}

void Tarea::setCarnet(int carnet) {
    this->carnet = carnet;
}

string Tarea::getNombre() {
    return nombre;
}

void Tarea::setNombre(string nombre) {
    this->nombre = nombre;
}

string Tarea::getDescripcion() {
    return descripcion;
}

void Tarea::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Tarea::getMateria() {
    return materia;
}

void Tarea::setMateria(string materia) {
    this->materia = materia;
}

Fecha* Tarea::getFecha() {
    return fecha;
}

void Tarea::setFecha(Fecha* fecha) {
    this->fecha = fecha;
}

int Tarea::getHora() {
    return hora;
}

void Tarea::setHora(int hora) {
    this->hora = hora;
}

Estado Tarea::getEstado() {
    return estado;
}

void Tarea::setEstado(Estado estado) {
    this->estado = estado;
}
