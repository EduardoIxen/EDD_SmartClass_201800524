//
// Created by Eduardo-Ixen on 13/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_CESTUDIANTE_H
#define EDD_SMARTCLASS_201800524_CESTUDIANTE_H

#include "regex"
#include "../Estructuras/ListaDobleEstud.h"
#include "../Estructuras/NodoEstudiante.h"

class CEstudiante {
private:
    bool validarCarnet(string);
    bool validarDpi(string);
    bool validarCorreo(string);
    bool verificarNumero(string);
    void cambioDeDatos(NodoEstudiante*&);
public:
    void agregarEstudiante(ListaDobleEstud*&);
    void modificarEstudiante(ListaDobleEstud*&, string);
    void eliminarEstudiante(ListaDobleEstud*&, string);
};


#endif //EDD_SMARTCLASS_201800524_CESTUDIANTE_H
