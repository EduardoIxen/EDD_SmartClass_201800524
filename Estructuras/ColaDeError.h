//
// Created by Eduardo-Ixen on 19/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_COLADEERROR_H
#define EDD_SMARTCLASS_201800524_COLADEERROR_H
#include <sstream>
#include "fstream"
#include "iostream"
#include "iomanip"
#include <chrono>
#include "NodoError.h"

class ColaDeError {
private:
    NodoError* primero;
    NodoError* ultimo;
    int tamanio;
    string dirToString(NodoError*);
    string obtenerFechaHora();
public:
    ColaDeError();
    void setPrimero(NodoError*);
    void setUltimo(NodoError*);
    void setTamanio(int);

    NodoError* getPrimero();
    NodoError* getUltimo();
    int getTamanio();

    void enqueue(Error*);
    void dequeue();
    void generarGrafo();

    void eliminar(string);
    NodoError* obtenerPrimero();
};


#endif //EDD_SMARTCLASS_201800524_COLADEERROR_H
