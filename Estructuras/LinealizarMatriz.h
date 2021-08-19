//
// Created by Eduardo-Ixen on 17/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_LINEALIZARMATRIZ_H
#define EDD_SMARTCLASS_201800524_LINEALIZARMATRIZ_H

#include "iostream"
#include "sstream"
#include "fstream"
#include "NodoMatrizL.h"

class LinealizarMatriz {
private:
    NodoMatrizL* primero;
    NodoMatrizL* ultimo;
    int tamanio;
    string dirToString(NodoMatrizL*);
    string obtenerEstado(Estado);
public:
    LinealizarMatriz();
    void insertar(Tarea* , int);
    bool insertarManual(Tarea*, int);
    void buscar(int, int, int);
    void recorrerLista();
    void generarGrafo();

    void setPrimero(NodoMatrizL*);
    void setUltimo(NodoMatrizL*);
    void setTamanio(int);
    NodoMatrizL* getPrimero();
    NodoMatrizL* getUltimo();
    int getTamanio();
};


#endif //EDD_SMARTCLASS_201800524_LINEALIZARMATRIZ_H
