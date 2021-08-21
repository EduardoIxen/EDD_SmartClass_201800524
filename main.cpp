#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"
#include "./Estructuras/ListaDobleEstud.h"
#include "./Controladores/CEstudiante.h"
#include "./Objetos/Tarea.h"
#include "./Objetos/EnumEstado.h"
#include "./ReadFile/ReadTareas.h"
#include "./Estructuras/LinealizarMatriz.h"
#include "./Controladores/CTarea.h"
#include "./Estructuras/ColaDeError.h"
#include "./Menu/Menu.h"

int main() {
    Menu menu;
    menu.menuPrincipal();
    return 0;
}
