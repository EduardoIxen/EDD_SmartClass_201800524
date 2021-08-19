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
    static string dirToString(NodoEstudiante* valor);
public:
    ListaDobleEstud();
    void insertar(Estudiante*);
    void setUltimo(NodoEstudiante*);
    void setPrimero(NodoEstudiante*);
    void setTamanio(int);
    int getTamanio();
    NodoEstudiante* getPrimero();
    NodoEstudiante* getUltimo();
    void recorrerLista();
    void generarGrafo();
    bool buscarEstudiante(string carnet);
};


#endif //EDD_SMARTCLASS_201800524_LISTADOBLEESTUD_H
