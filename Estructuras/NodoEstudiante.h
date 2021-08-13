//
// Created by Eduardo-Ixen on 11/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_NODOESTUDIANTE_H
#define EDD_SMARTCLASS_201800524_NODOESTUDIANTE_H

#include "../Objetos/Estudiante.h"

class NodoEstudiante {
private:
    Estudiante estudiante;
    int id;
    NodoEstudiante* siguiente;
    NodoEstudiante* anterior;
public:
    NodoEstudiante(Estudiante, int);
    void setEstudiante(Estudiante);
    void setId(int);
    void setSiguiente(NodoEstudiante*);
    void setAnterior(NodoEstudiante*);

    Estudiante getEstudiante();
    int getId();
    NodoEstudiante* getSiguiente();
    NodoEstudiante* getAnterior();
    virtual ~NodoEstudiante();
};


#endif //EDD_SMARTCLASS_201800524_NODOESTUDIANTE_H
