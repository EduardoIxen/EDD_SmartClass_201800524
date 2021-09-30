//
// Created by Eduardo-Ixen on 19/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_NODOERROR_H
#define EDD_SMARTCLASS_201800524_NODOERROR_H
#include "../Objetos/Error.h"

class NodoError {
private:
    Error* error;
    int id;
    NodoError* siguiente;
public:
    NodoError();
    NodoError(Error*, int);

    void setError(Error*);
    void setId(int);
    void setSiguiente(NodoError*);

    Error* getError();
    int getId();
    NodoError* getSiguiente();
};


#endif //EDD_SMARTCLASS_201800524_NODOERROR_H
