//
// Created by Eduardo-Ixen on 18/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_CTAREA_H
#define EDD_SMARTCLASS_201800524_CTAREA_H

#include "../Estructuras/LinealizarMatriz.h"
#include "CEstudiante.h"

class CTarea {
private:
    bool verificarCarnet(string);
    bool verificarNumero(string);
    bool verificarFecha(string);
    bool verificarHora(string);
    Fecha* crearFecha(string);
    int obtenerPosicionNodo(string, int);
    void cambioDeDatos(NodoMatrizL*&, LinealizarMatriz*&, ListaDobleEstud*&);
    string obtenerEstado(Estado);
public:
    void agregarTarea(LinealizarMatriz*&, ListaDobleEstud*& );
    void modificarTarea(LinealizarMatriz*&, int, ListaDobleEstud*&);
    void eliminarTarea(LinealizarMatriz*&, int);
};


#endif //EDD_SMARTCLASS_201800524_CTAREA_H
