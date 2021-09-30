//
// Created by Eduardo-Ixen on 11/08/2021.
//

#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante(Estudiante* _estudiante, int _id)
{
    this->estudiante = _estudiante;
    this->id = _id;
    this->siguiente = NULL;
    this->anterior = NULL;
}

void NodoEstudiante::setEstudiante(Estudiante* _estudiante){
    this->estudiante = _estudiante;
}

void NodoEstudiante::setId(int _id){
    this->id = _id;
}

void NodoEstudiante::setSiguiente(NodoEstudiante* _siguiente){
    this->siguiente = _siguiente;
}

void NodoEstudiante::setAnterior(NodoEstudiante* _anterior){
    this->anterior = _anterior;
}

Estudiante* NodoEstudiante::getEstudiante(){
    return this->estudiante;
}

int NodoEstudiante::getId(){
    return this->id;
}

NodoEstudiante* NodoEstudiante::getSiguiente(){
    return this->siguiente;
}

NodoEstudiante* NodoEstudiante::getAnterior(){
    return this->anterior;
}

NodoEstudiante::~NodoEstudiante() {

}

NodoEstudiante::NodoEstudiante() {

}
