//
// Created by Eduardo-Ixen on 19/08/2021.
//

#include "Error.h"

Error::Error() {}

Error::Error(int id, string tipo, string descripcion) {
    this->id = id;
    this->tipo = tipo;
    this->descripcion = descripcion;
}

void Error::setId(int id) {
    this->id = id;
}

void Error::setTipo(string tipo) {
    this->tipo = tipo;
}

void Error::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

int Error::getId() {
    return this->id;
}

string Error::getTipo() {
    return this->tipo;
}

string Error::getDescripcion() {
    return this->descripcion;
}