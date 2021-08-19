//
// Created by Eduardo-Ixen on 17/08/2021.
//

#include "NodoMatrizL.h"

NodoMatrizL::NodoMatrizL(Tarea* _tarea, int _id) {
    setTarea(_tarea);
    setId(_id);
    this->siguiente = NULL;
    this->anterior = NULL;
}

NodoMatrizL::NodoMatrizL() {
    this->tarea = NULL;
    this->id = 0;
    this->siguiente = NULL;
    this->anterior = NULL;
}

void NodoMatrizL::setTarea(Tarea * _tarea) {
    this->tarea = _tarea;
}

void NodoMatrizL::setId(int _id) {
    this->id = _id;
}

void NodoMatrizL::setSiguiente(NodoMatrizL* _siguiente) {
    this->siguiente = _siguiente;
}

void NodoMatrizL::setAnterior(NodoMatrizL* _anterior) {
    this->anterior = _anterior;
}

Tarea* NodoMatrizL::getTarea() {
    return this->tarea;
}

int NodoMatrizL::getId() {
    return this->id;
}

NodoMatrizL* NodoMatrizL::getSiguiente() {
    return this->siguiente;
}

NodoMatrizL* NodoMatrizL::getAnterior() {
    return this->anterior;
}


NodoMatrizL::~NodoMatrizL() {}

