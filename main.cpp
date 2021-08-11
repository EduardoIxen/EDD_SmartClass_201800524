#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Estudiante est1;
    est1.setCarnet(21);
    est1.setNombre("Tomas");
    cout << est1.getCarnet() <<endl;
    cout << est1.getNombre()<< endl;
    auto* est2 = new Estudiante(12,312312,"Eduardo", "carre","edad","asd",21,3);
    cout<<est2->verEstudiante()<<endl;

    ReadCsv leer;
    leer.readEstudiantes("nada");

    return 0;
}
