//
// Created by Eduardo-Ixen on 11/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_LISTADOBLEESTUD_H
#define EDD_SMARTCLASS_201800524_LISTADOBLEESTUD_H

#include "iostream"
#include "sstream"
#include "fstream"
#include "NodoEstudiante.h"
#include "../Objetos/Estudiante.h"

//using namespace std;
class ListaDobleEstud {
private:
    NodoEstudiante* primero;
    NodoEstudiante* ultimo;
    int tamanio;
    string dirToString(NodoEstudiante* valor);
public:
    ListaDobleEstud();
    void insertar(Estudiante);
    int getTamanio();
    NodoEstudiante* getPrimero();
    NodoEstudiante* getUltimo();
    void recorrerLista();
    void generarGrafo();
};


#endif //EDD_SMARTCLASS_201800524_LISTADOBLEESTUD_H
