//
// Created by Eduardo-Ixen on 19/08/2021.
//

#include "Menu.h"

Menu::Menu() {}

void Menu::menuPrincipal() {
    string path;
    string opcion = "";
    bool repetir = true;
    cout << "******************************************" << endl;
    cout << "*     MANEJO DE ESTRUCTURAS DE DATOS     *" << endl;
    cout << "* CREADO POR-> EDUARDO TOMAS IXEN RUCUCH *" << endl;
    cout << "******************************************" << endl;
    cout << "" << endl;

    do {
        cout << "************************* MENU ***********************" << endl;
        cout << "1-Carga de estudiantes" << endl;
        cout << "2-Carga de tareas" << endl;
        cout << "3-Ingreso manual" << endl;
        cout << "4-Reportes" << endl;
        cout << "5-Salir" << endl;
        cout << "******************************************************" << endl;
        cout << ">>";
        cin >> opcion;
        cin.ignore();
        if (opcion == "1") {
            cout << "**************** CARGA DE ESTUDIANTES ****************" << endl;
            cout << "Ingrese la ruta del archivo." << endl;
            cout << ">>";
            getline(cin, path);
            listaEstudiantes = new ListaDobleEstud();
            nuevaCola = new ColaDeError();
            if (matrizLinealizada->getTamanio() > 0) {
                matrizLinealizada = new LinealizarMatriz();
                cout << "----TAREAS ELIMINADAS, VUELVA A CARGARLAS PARA VALIDAR A LOS ESTUDIANTES----" << endl;
            }
            cargarEstudiantes.readEstudiantes(path, listaEstudiantes, nuevaCola);
        } else if (opcion == "2") {
            if (listaEstudiantes->getTamanio() > 0) {
                cout << "****************** CARGA DE TAREAS ******************" << endl;
                cout << "Ingrese la ruta del archivo." << endl;
                cout << ">>";
                getline(cin, path);
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 30; ++j) {
                        for (int k = 0; k < 5; ++k) {
                            matrizTareas[i][j][k] = nullptr;
                        }
                    }
                }
                cargarTareas.readTareas(path, matrizTareas, listaEstudiantes, nuevaCola);
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 30; ++j) {
                        for (int k = 0; k < 5; ++k) {
                            //i = horas j=dias k = meses   formula row major ( i * TamColum + j ) * TamProf + k
                            int id = (i * 30 + j) * 5 + k;
                            if (matrizTareas[i][j][k] != NULL) {
                                matrizLinealizada->insertar(matrizTareas[i][j][k], id);
                            } else {
                                matrizLinealizada->insertar(NULL, id);
                            }
                        }
                    }
                }
            } else {
                cout << "ERROR// PARA CARGAR TAREAS PRIMERO AGREGUE ESTUDIANTES" << endl;
            }

        } else if (opcion == "3") {
            menuIngresoManual();
        } else if (opcion == "4") {
            menuReportes();
        } else if (opcion == "5") {
            cout << "******************* FIN DEL PROGRAMA ******************" << endl;
        } else {
            opcion = "";
            cout << "******************* OPCION INVALIDA ******************" << endl;
        }

    } while (opcion != "5");

}

void Menu::menuIngresoManual() {
    string opcion = "";
    string opcionSubmenu = "";
    do {
        cout << "******************* INGRESO MANUAL *******************" << endl;
        cout << "1-Estudiantes" << endl;
        cout << "2-Tareas" << endl;
        cout << "3-Regresar" << endl;
        cout << ">>";
        cin >> opcion;
        if (opcion == "1") {
            do {
                cout << "****************** MENU ESTUDIANTES ******************" << endl;
                cout << "1-Agregar" << endl;
                cout << "2-Modificar" << endl;
                cout << "3-Eliminar" << endl;
                cout << "4-Regresar" << endl;
                cout << ">>";
                cin >> opcionSubmenu;
                if (opcionSubmenu == "1") {
                    cout << "******************* AGREGAR ESTUDIANTE ******************" << endl;
                    controladorEstudiante.agregarEstudiante(listaEstudiantes);
                } else if (opcionSubmenu == "2") {
                    string dpi = "";
                    cout << "**************** MODIFICAR ESTUDIANTE ****************" << endl;
                    cout << "Ingrese el dpi del estudiante que desea modificar" << endl;
                    cout << ">>";
                    cin >> dpi;
                    controladorEstudiante.modificarEstudiante(listaEstudiantes, dpi);
                } else if (opcionSubmenu == "3") {
                    string dpi = "";
                    cout << "***************** ELIMINAR ESTUDIANTE ****************" << endl;
                    cout << "Ingrese el dpi del estudiante que desea eliminar" << endl;
                    cout << ">>";
                    cin >> dpi;
                    controladorEstudiante.eliminarEstudiante(listaEstudiantes, dpi);
                }

            } while (opcionSubmenu != "4");
        } else if (opcion == "2") {
            do {
                cout << "********************* MENU TAREAS ********************" << endl;
                cout << "1-Agregar" << endl;
                cout << "2-Modificar" << endl;
                cout << "3-Eliminar" << endl;
                cout << "4-Regresar" << endl;
                cout << ">>";
                cin >> opcionSubmenu;
                if (opcionSubmenu == "1") {
                    cout << "******************* AGREGAR TAREA ********************" << endl;
                    controladorTarea.agregarTarea(matrizLinealizada, listaEstudiantes);
                } else if (opcionSubmenu == "2") {
                    string indice = "";
                    cout << "******************* MODIFICAR TAREA ******************" << endl;
                    cout << "Ingrese el indice de la tarea que desea modificar" << endl;
                    cout << ">>";
                    cin >> indice;
                    controladorTarea.modificarTarea(matrizLinealizada, stoi(indice), listaEstudiantes);
                } else if (opcionSubmenu == "3") {
                    string indice = "";
                    cout << "******************* ELIMINAR TAREA *******************" << endl;
                    cout << "Ingrese el indice de la tarea que desea eliminar" << endl;
                    cout << ">>";
                    cin >> indice;
                    controladorTarea.eliminarTarea(matrizLinealizada, stoi(indice));
                }
            } while (opcionSubmenu != "4");
        }
    } while (opcion != "3");
}

void Menu::menuReportes() {
    string opcionSubmenu = "";
    do {
        cout << "******************** MENU REPORTES *******************" << endl;
        cout << "1-Lista de estudiantes." << endl;
        cout << "2-Lista de taresa linealizada." << endl;
        cout << "3-Busqueda en lista de tareas linealizadas." << endl;
        cout << "4-Busqueda de posicion en lista de tareas linealizadas." << endl;
        cout << "5-Cola de errores." << endl;
        cout << "6-Codigo generado de salida." << endl;
        cout << "7-Regresar" << endl;
        cout << ">>";
        cin >> opcionSubmenu;
        if (opcionSubmenu == "1") {
            if (nuevaCola->getTamanio() == 0) {
                listaEstudiantes->generarGrafo();
            } else {
                cout << "----ERROR// NO SE PUEDE GENERAR EL REPORTE POR ERRORES ALMACENADOS EN LA COLA----" << endl;
            }
        } else if (opcionSubmenu == "2") {
            if (nuevaCola->getTamanio() == 0) {
                matrizLinealizada->generarGrafo();
            } else {
                cout << "----ERROR// NO SE PUEDE GENERAR EL REPORTE POR ERRORES ALMACENADOS EN LA COLA----" << endl;
            }
        } else if (opcionSubmenu == "3") {
            string mes = "";
            string dia = "";
            string hora = "";
            do {
                cout << "************************* BUSQUEDA EN DE TAREAS ********************" << endl;
                cout << "Ingrese el mes de la tarea" << endl;
                cout << ">>";
                cin >> mes;
                cout << "Ingrese el dia de la tarea" << endl;
                cout << ">>";
                cin >> dia;
                cout << "Ingrese la hora de la tarea" << endl;
                cout << ">>";
                cin >> hora;
            } while (!validarBusqueda(dia, mes, hora));
            matrizLinealizada->buscar(stoi(mes), stoi(dia), stoi(hora));
        } else if (opcionSubmenu == "4") {
            string mes = "";
            string dia = "";
            string hora = "";
            do {
                cout << "****************** BUSQUEDA DE POSICION DE LA TAREA ***************" << endl;
                cout << "Ingrese el mes de la tarea" << endl;
                cout << ">>";
                cin >> mes;
                cout << "Ingrese el dia de la tarea" << endl;
                cout << ">>";
                cin >> dia;
                cout << "Ingrese la hora de la tarea" << endl;
                cout << ">>";
                cin >> hora;
            } while (!validarBusqueda(dia, mes, hora));

            //i = horas j=dias k = meses   formula row major ( i * TamColum + j ) * TamProf + k
            int indice = ((stoi(hora) - 8) * 30 + (stoi(dia) - 1)) * 5 + (stoi(mes) - 7);
            if (indice >= 0 && indice <= 1349) {
                cout << "El indice es: " << indice << endl;
            } else {
                cout << "Indice invalido dentro de la lista de tareas." << endl;
            }
        } else if (opcionSubmenu == "5") {
            nuevaCola->generarGrafo();
        } else if (opcionSubmenu == "6") {
            Salida nuevaSalida;
            nuevaSalida.generarTxt(listaEstudiantes, matrizLinealizada);
        } else if (opcionSubmenu == "7") {
            cout << "<- Regreso" << endl;
        } else {
            opcionSubmenu = "";
            cout << "ERROR// OPCION INVALIDA" << endl;
        }
    } while (opcionSubmenu != "7");
}

bool Menu::validarBusqueda(string dia, string mes, string hora) {
    int nmes = stoi(mes);
    int ndia = stoi(dia);
    int nhora = stoi(hora);

    if ((nmes >= 7 && nmes <= 11) && (ndia >= 1 && ndia <= 30) && (nhora >= 8 && nhora <= 16)) return true;
    cout << "----LOS DATOS INGRESADOS ESTAN FUERA DEL RANGO VALIDO----" << endl;
    return false;
}