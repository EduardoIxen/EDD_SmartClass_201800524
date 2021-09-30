//
// Created by Eduardo-Ixen on 15/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_READTAREAS_H
#define EDD_SMARTCLASS_201800524_READTAREAS_H
#include "iostream"
#include "fstream"
#include "sstream"
#include "bits/stdc++.h"
#include "../Estructuras/ListaDobleEstud.h"
#include "../Objetos/Tarea.h"
#include "../Estructuras/ColaDeError.h"

using namespace std;

class ReadTareas {
private:
    bool validarDatos(string, string, string, string, string, ListaDobleEstud*&, ColaDeError*& colaDeError, int);
    bool validarFecha(string);
    bool validarEncabezado(string, string, string);
    Estado obtenerEstado(string);
    Fecha* crearFecha(string);
public:
    void readTareas(string path, Tarea* (&matrizTar)[9][30][5] ,ListaDobleEstud*& listaEst, ColaDeError*&); //paso de matriz por referencia
};


#endif //EDD_SMARTCLASS_201800524_READTAREAS_H
