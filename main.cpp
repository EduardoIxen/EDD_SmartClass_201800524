#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"


int main() {
    ReadCsv leer;
    leer.readEstudiantes("nada");
    cout<<"----------------------------- pass"<<endl;
    //leer.listaDobleEst->recorrerLista();
    leer.listaDobleEst->generarGrafo();


    return 0;
}
