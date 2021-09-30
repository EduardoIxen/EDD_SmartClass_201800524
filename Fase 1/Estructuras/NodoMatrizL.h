//
// Created by Eduardo-Ixen on 17/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_NODOMATRIZL_H
#define EDD_SMARTCLASS_201800524_NODOMATRIZL_H
#include "stdlib.h"
#include "../Objetos/Tarea.h"

class NodoMatrizL {
private:
    Tarea* tarea;
    NodoMatrizL* siguiente;
    NodoMatrizL* anterior;
    int id;
public:
    void setTarea(Tarea*);
    void setId(int);
    void setSiguiente(NodoMatrizL*);
    void setAnterior(NodoMatrizL*);
    Tarea* getTarea();
    int getId();
    NodoMatrizL* getSiguiente();
    NodoMatrizL* getAnterior();
    NodoMatrizL(Tarea*, int);
    NodoMatrizL();
    ~NodoMatrizL();
};


#endif //EDD_SMARTCLASS_201800524_NODOMATRIZL_H
