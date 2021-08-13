#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"
#include "./Estructuras/ListaDobleEstud.h"


int main() {
    ListaDobleEstud* listaEstudiantes = new ListaDobleEstud();
    ReadCsv leer;
    leer.readEstudiantes("nada", listaEstudiantes); //paso de lista por referencia
    cout<<"----------------------------- Comienzo recorrido"<<endl;
    listaEstudiantes->recorrerLista();
    listaEstudiantes->generarGrafo();
    cout<<"----------------------------- pass"<<endl;

    return 0;
}
