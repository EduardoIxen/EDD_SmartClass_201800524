//
// Created by Eduardo-Ixen on 15/08/2021.
//

#include "ReadTareas.h"

void ReadTareas::readTareas(string path, Tarea *(&matrizTar)[9][30][5], ListaDobleEstud *&listaEst, ColaDeError*& colaDeError) {
    string mes, dia, hora, carnet, nombre, descripcion, materia, fecha, estado, linea;
    char delimitador = ',';
    int id = 0;
    int numLinea = 1;
    path = R"(C:\Users\tomas\CLionProjects\EDD_SmartClass_201800524\Tareas.csv)";

    ifstream archivo(path); //obtener el contenido del archivo

    if (archivo.fail()) {
        cout << "ERROR// OCURRIO UN ERROR AL ABRIR EL ARCHIVO." << endl;
        return;
    }

    getline(archivo, linea);  //separar el contenido del archivo en lineas (quitamos la linea del encabezado csv)
    while (getline(archivo, linea)) {
        numLinea += 1;
        stringstream stream(linea); //convertir string en stream para insertar y extraer desde y a string
        getline(stream, mes, delimitador);
        getline(stream, dia, delimitador);
        getline(stream, hora, delimitador);
        getline(stream, carnet, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, descripcion, delimitador);
        getline(stream, materia, delimitador);
        getline(stream, fecha, delimitador);
        getline(stream, estado, delimitador);

        if (validarDatos(carnet, fecha, hora, dia, mes, listaEst, colaDeError, numLinea)) {
            Tarea *nuevaT = new Tarea(id++, stoi(carnet), nombre, descripcion, materia, crearFecha(fecha), stoi(hora),
                                      obtenerEstado(estado));
            matrizTar[stoi(hora) - 8][stoi(dia) - 1][stoi(mes) - 7] = nuevaT;
            /*
             * Días del mes 1-30 -> posición en matriz = dia - 1 = 0;
             * Meses de Julio a Noviembre-> posiciones en matriz = mes - 7 = 0;  (0=Julio, 1=Agosto, 2=Sept...)
             * Horas de 8 - 16 -> posiciones en matriz = hora - 8 = 0;
             */
        }
    }
    archivo.close();
}

bool
ReadTareas::validarDatos(string carnet, string fecha, string hora, string dia, string mes, ListaDobleEstud *&listaEst, ColaDeError*& colaDeError, int numLinea) {
    bool existeCarnet = listaEst->buscarEstudiante(carnet);
    bool fechaValida = validarFecha(fecha);
    bool encabezadoValido = validarEncabezado(mes, dia, hora);
    string descripcion = "Linea numero"+ to_string(numLinea)+"\n";

    if (existeCarnet && fechaValida && encabezadoValido) return true;

    if (!existeCarnet){
        descripcion += "*No existe el carnet: " + carnet+"\n";
    }
    if(!fechaValida){
        descripcion += "*Fecha invalida: "+ fecha+ "\n";
    }
    if(!encabezadoValido){
        descripcion += "*Verificar que el dia, mes y hora esten dentro del\n rango establecido. (Dia: "+dia+ ",Mes: "+mes+" ,Hora "+hora+")" "\n";
    }

    cout << "ERROR// TAREA CON DATOS INCORRECTOS" << endl;
    Error* nuevoError = new Error();
    nuevoError->setId(0);
    nuevoError->setTipo("Tarea");
    nuevoError->setDescripcion(descripcion);
    colaDeError->enqueue(nuevoError);
    return false;
}

bool ReadTareas::validarFecha(string fecha) {
    string anio, mes, dia;
    int nMes, nDia;
    stringstream stream(fecha);
    getline(stream, anio, '/');
    getline(stream, mes, '/');
    getline(stream, dia, '/');
    nMes = stoi(mes);
    nDia = stoi(dia);
    if ((nDia > 0 && nDia <= 30) && (nMes >= 7 && nMes <= 11)) return true;
    return false;
}

bool ReadTareas::validarEncabezado(string mes, string dia, string hora) {
    int _mes, _dia, _hora;
    _mes = stoi(mes);
    _dia = stoi(dia);
    _hora = stoi(hora);
    if ((_dia > 0 && _dia <= 30) && (_mes >= 7 && _mes <= 11) && (_hora >= 8 && _hora <= 16)) return true;
    return false;
}

Estado ReadTareas::obtenerEstado(string estado) {
    transform(estado.begin(), estado.end(), estado.begin(), ::toupper);
    if (estado == "INCUMPLIDO") {
        return Estado::INCUMPLIDO;
    } else if (estado == "PENDIENTE") {
        return Estado::PENDIENTE;
    } else if (estado == "CUMPLIDO") {
        return Estado::CUMPLIDO;
    }
    return Estado::INEXISTENTE;
}

Fecha *ReadTareas::crearFecha(string fecha) {
    string anio, mes, dia;
    int nMes, nDia, nAnio;
    stringstream stream(fecha);
    getline(stream, anio, '/');
    getline(stream, mes, '/');
    getline(stream, dia, '/');
    nMes = stoi(mes);
    nDia = stoi(dia);
    nAnio = stoi(anio);
    Fecha *nuevaFecha = new Fecha(nDia, nMes, nAnio);
    return nuevaFecha;
}
