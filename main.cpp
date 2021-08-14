#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"
#include "./Estructuras/ListaDobleEstud.h"
#include "./Controladores/CEstudiante.h"


int main() {
    auto* listaEstudiantes = new ListaDobleEstud();
    ReadCsv leer;
    leer.readEstudiantes("nada", listaEstudiantes); //paso de lista por referencia
    cout<<"----------------------------- Comienzo recorrido"<<endl;
    listaEstudiantes->recorrerLista();
    listaEstudiantes->generarGrafo();
    cout<<"----------------------------- pass"<<endl;
    CEstudiante agregarEst;
    agregarEst.agregarEstudiante(listaEstudiantes);
    listaEstudiantes->generarGrafo();
    return 0;
}
