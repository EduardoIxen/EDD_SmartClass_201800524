#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"
#include "./Estructuras/ListaDobleEstud.h"
#include "./Controladores/CEstudiante.h"


int main() {
    auto* listaEstudiantes = new ListaDobleEstud();
    ReadCsv leer;
    leer.readEstudiantes("nada", listaEstudiantes); //paso de lista por referencia
    //listaEstudiantes->recorrerLista(); //recorrer lista
    //listaEstudiantes->generarGrafo(); //generar grafo
    cout<<"----------------------------- pass"<<endl;
    CEstudiante agregarEst;
    //agregarEst.agregarEstudiante(listaEstudiantes); //agregar estudiantes a mano
    //agregarEst.modificarEstudiante(listaEstudiantes, "3423442386382"); //modificar estudiantes de la lista
    //listaEstudiantes->generarGrafo();
    //agregarEst.eliminarEstudiante(listaEstudiantes, "7249529279753");
    //cout<<listaEstudiantes->getTamanio()<<endl;


    return 0;
}
