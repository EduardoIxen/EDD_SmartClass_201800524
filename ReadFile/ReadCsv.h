//
// Created by Eduardo-Ixen on 11/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_READCSV_H
#define EDD_SMARTCLASS_201800524_READCSV_H

#include "iostream"
#include "fstream"
#include "sstream"
#include "regex"
#include "../Objetos/Estudiante.h"
#include "../Estructuras/ListaDobleEstud.h"

using namespace std;

class ReadCsv {
private:
public:
    void readEstudiantes(string, ListaDobleEstud*&); //Recibir lista por referencia
    void validarDatos(string, string, string);
};


#endif //EDD_SMARTCLASS_201800524_READCSV_H
