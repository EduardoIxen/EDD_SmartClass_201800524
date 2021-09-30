//
// Created by Eduardo-Ixen on 21/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_SALIDA_H
#define EDD_SMARTCLASS_201800524_SALIDA_H

#include "../Estructuras/ListaDobleEstud.h"
#include "../Estructuras/LinealizarMatriz.h"
//#include "locale.h"
//#include "wchar.h"
#include "string"
#include "iostream"

//using namespace std;
class Salida {
private:
    string obtenerEstado(Estado);
    string obtenerFechaHora();
public:
    void generarTxt(ListaDobleEstud*&, LinealizarMatriz*&);
};


#endif //EDD_SMARTCLASS_201800524_SALIDA_H
