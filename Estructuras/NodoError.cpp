//
// Created by Eduardo-Ixen on 19/08/2021.
//

#include "NodoError.h"
NodoError::NodoError() {
    this->error = NULL;
    this->setSiguiente(NULL);
    this->id = 0;
}

NodoError::NodoError(Error *error, int id) {
    this->error = error;
    this->id = id;
}

void NodoError::setId(int id) {
    this->id = id;
}

void NodoError::setError(Error *error) {
    this->error = error;
}

void NodoError::setSiguiente(NodoError *siguiente) {
    this->siguiente = siguiente;
}

int NodoError::getId() {
    return this->id;
}

Error* NodoError::getError() {
    return this->error;
}

NodoError* NodoError::getSiguiente() {
    return this->siguiente;
}