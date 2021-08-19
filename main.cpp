#include <iostream>
#include "./Objetos/Estudiante.h"
#include "./ReadFile/ReadCsv.h"
#include "./Estructuras/ListaDobleEstud.h"
#include "./Controladores/CEstudiante.h"
#include "./Objetos/Tarea.h"
#include "./Objetos/EnumEstado.h"
#include "./ReadFile/ReadTareas.h"
#include "./Estructuras/LinealizarMatriz.h"


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
    listaEstudiantes->generarGrafo();
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

    auto* linealizar = new LinealizarMatriz();

    ReadTareas cargarT;
    cargarT.readTareas("sin dato", matrizTar ,listaEstudiantes);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 30; ++j) {
            for (int k = 0; k < 5; ++k) {
                //i = horas j=dias k = meses   formula row major ( i * TamColum + j ) * TamProf + k
                int id = (i * 30 + j)*5+k;
                if(matrizTar[i][j][k] != NULL){
                    linealizar->insertar(matrizTar[i][j][k], id);
                }else{
                    linealizar->insertar(NULL, id);
                }
            }
        }
    }

    cout<<"Ya linealizadoooo."<<endl;
    linealizar->recorrerLista();
    int dia, mes, hora;
    cout<<"Ingrese el dia"<<endl;
    cin >> dia;
    cin.ignore();
    cout<<"Ingrese el mes"<<endl;
    cin >> mes;
    cin.ignore();
    cout<<"Ingrese la hora"<<endl;
    cin >> hora;
    cin.ignore();
    linealizar->buscar(mes,dia,hora);

    linealizar->generarGrafo();
    return 0;
}
