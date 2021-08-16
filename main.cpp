#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"
#include "./Estructuras/ListaDobleEstud.h"
#include "./Controladores/CEstudiante.h"
#include "./Objetos/Tarea.h"
#include "./Objetos/EnumEstado.h"
#include "./ReadFile/ReadTareas.h"


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
    Tarea* nuevaT = new Tarea(1,201800524, "Tarea 1", "Hacer una edd", "EDD", new Fecha(12,7,2021), 13, Estado::PENDIENTE);
    cout<<"car"<<nuevaT->getCarnet()<<endl;
    cout<<"nomb"<<nuevaT->getNombre()<<endl;

    Tarea* nuec = new Tarea();
    int contador = 0;

    Tarea* matrizTar[9][30][5] ;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 5; ++k) {
                matrizTar[i][j][k] = nullptr;
            }
        }
    }

    /*for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 5; ++k) {
                if(matrizTar[i][j][k]== nullptr){
                    cout<<"nada"<<endl;
                    contador++;
                    cout<<contador<<endl;
                }
            }
        }
    }*/

    ReadTareas cargarT;
    cargarT.readTareas("sin dato", matrizTar ,listaEstudiantes);
    cout<<"recorrer desde main"<<endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 5; ++k) {
                if(matrizTar[i][j][k] != NULL){
                    cout<<"no nulo"<<i<<j<<k<<endl;
                }
            }
        }
    }

    return 0;
}
