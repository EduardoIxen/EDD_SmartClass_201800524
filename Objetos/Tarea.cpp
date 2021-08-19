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
    return this->id;
}

void Tarea::setId(int _id) {
    this->id = _id;
}

int Tarea::getCarnet() {
    return this->carnet;
}

void Tarea::setCarnet(int _carnet) {
    this->carnet = _carnet;
}

string Tarea::getNombre() {
    return this->nombre;
}

void Tarea::setNombre(string _nombre) {
    this->nombre = _nombre;
}

string Tarea::getDescripcion() {
    return this->descripcion;
}

void Tarea::setDescripcion(string _descripcion) {
    this->descripcion = _descripcion;
}

string Tarea::getMateria() {
    return this->materia;
}

void Tarea::setMateria(string _materia) {
    this->materia = _materia;
}

Fecha* Tarea::getFecha() {
    return this->fecha;
}

void Tarea::setFecha(Fecha* _fecha) {
    this->fecha = _fecha;
}

int Tarea::getHora() {
    return this->hora;
}

void Tarea::setHora(int _hora) {
    this->hora = _hora;
}

Estado Tarea::getEstado() {
    return this->estado;
}

void Tarea::setEstado(Estado _estado) {
    this->estado = _estado;
}
