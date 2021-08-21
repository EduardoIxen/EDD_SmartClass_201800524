//
// Created by Eduardo-Ixen on 19/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_MENU_H
#define EDD_SMARTCLASS_201800524_MENU_H
#include "iostream"
#include "string"
#include "../Estructuras/ListaDobleEstud.h"
#include "../Estructuras/ColaDeError.h"
#include "../ReadFile/ReadCsv.h"
#include "../ReadFile/ReadTareas.h"
#include "../Objetos/Tarea.h"
#include "../Estructuras/LinealizarMatriz.h"
#include "../Controladores/CEstudiante.h"
#include "../Controladores/CTarea.h"

using namespace std;
class Menu {
private:
    ListaDobleEstud* listaEstudiantes;
    ReadCsv cargarEstudiantes;
    CEstudiante controladorEstudiante;


    Tarea* matrizTareas[9][30][5] ;
    LinealizarMatriz* matrizLinealizada;
    ReadTareas cargarTareas;
    CTarea controladorTarea;


    ColaDeError* nuevaCola;

    void menuIngresoManual();
    void menuReportes();
public:
    Menu();
    void menuPrincipal();
};


#endif //EDD_SMARTCLASS_201800524_MENU_H
