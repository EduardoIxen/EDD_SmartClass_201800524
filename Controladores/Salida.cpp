//
// Created by Eduardo-Ixen on 21/08/2021.
//

#include "Salida.h"
void Salida::generarTxt(ListaDobleEstud *& listaEst, LinealizarMatriz *& listaTar) {
    NodoEstudiante* auxEst = listaEst->getPrimero();
    //setlocale(LC_ALL, "");
    string contenido = "¿$Elements?\n";
    while (auxEst != listaEst->getUltimo() && listaEst->getTamanio() > 0){
        contenido += "\t" + string ("¿element type=\"user\"?") + "\n"
                +"\t\t¿item Carnet = "+ to_string(auxEst->getEstudiante()->getCarnet())+" $?" + "\n"
                +"\t\t¿item DPI = \""+ to_string(auxEst->getEstudiante()->getDpi())+"\" $?" + "\n"
                +"\t\t¿item Nombre = \""+auxEst->getEstudiante()->getNombre()+"\" $?" + "\n"
                +"\t\t¿item Carrera = \""+auxEst->getEstudiante()->getCarrera()+"\" $?" + "\n"
                +"\t\t¿item Password = \""+auxEst->getEstudiante()->getPass()+"\" $?" + "\n"
                +"\t\t¿item Creditos = "+ to_string(auxEst->getEstudiante()->getCreditos())+" $?" + "\n"
                +"\t\t¿item Edad = "+ to_string(auxEst->getEstudiante()->getEdad())+" $?" + "\n"
                +"\t¿$element? \n";
        auxEst = auxEst->getSiguiente();
    }
    contenido += "\t" + string ("¿element type=\"user\"?") + "\n"
            +"\t\t¿item Carnet = "+ to_string(auxEst->getEstudiante()->getCarnet())+" $?" + "\n"
            +"\t\t¿item DPI = \""+ to_string(auxEst->getEstudiante()->getDpi())+"\" $?" + "\n"
            +"\t\t¿item Nombre = \""+auxEst->getEstudiante()->getNombre()+"\" $?" + "\n"
            +"\t\t¿item Carrera = \""+auxEst->getEstudiante()->getCarrera()+"\" $?" + "\n"
            +"\t\t¿item Password = \""+auxEst->getEstudiante()->getPass()+"\" $?" + "\n"
            +"\t\t¿item Creditos = "+ to_string(auxEst->getEstudiante()->getCreditos())+" $?" + "\n"
            +"\t\t¿item Edad = "+ to_string(auxEst->getEstudiante()->getEdad())+" $?" + "\n"
            +"\t¿$element? \n";

    NodoMatrizL* auxTar = listaTar->getPrimero();
    while (auxTar != NULL && listaTar->getTamanio() > 0){
        if(auxTar->getTarea() != NULL){
            contenido += "\t" + string ("¿element type=\"task\"?") + "\n"
                    +"\t\t¿item Carnet = "+ to_string(auxTar->getTarea()->getCarnet())+" $?" + "\n"
                    +"\t\t¿item Nombre = \""+auxTar->getTarea()->getNombre()+"\" $?" + "\n"
                    +"\t\t¿item Descripcion = \""+auxTar->getTarea()->getDescripcion()+"\" $?" + "\n"
                    +"\t\t¿item Materia = \""+auxTar->getTarea()->getMateria()+"\" $?" + "\n"
                    +"\t\t¿item Fecha = \""+ auxTar->getTarea()->getFecha()->obtenerFecha()+"\" $?" + "\n"
                    +"\t\t¿item Hora = \""+ to_string(auxTar->getTarea()->getHora())+":00\" $?" + "\n"
                    +"\t\t¿item Estado = \""+ obtenerEstado(auxTar->getTarea()->getEstado()) +"\" $?" + "\n"
                    +"\t¿$element? \n";
        }
        auxTar = auxTar->getSiguiente();
    }
    /*if(auxTar->getTarea() != NULL){
        contenido += "\t" + string ("¿element type=\"task\"?") + "\n"
                +"\t\t¿item Carnet = "+ to_string(auxTar->getTarea()->getCarnet())+" $?" + "\n"
                +"\t\t¿item Nombre = \""+auxTar->getTarea()->getNombre()+"\" $?" + "\n"
                +"\t\t¿item Descripcion = \""+auxTar->getTarea()->getDescripcion()+"\" $?" + "\n"
                +"\t\t¿item Materia = \""+auxTar->getTarea()->getMateria()+"\" $?" + "\n"
                +"\t\t¿item Fecha = \""+ auxTar->getTarea()->getFecha()->obtenerFecha()+"\" $?" + "\n"
                +"\t\t¿item Hora = \""+ to_string(auxTar->getTarea()->getHora())+":00\" $?" + "\n"
                +"\t\t¿item Estado = \""+ obtenerEstado(auxTar->getTarea()->getEstado()) +"\" $?" + "\n"
                +"\t¿$element? \n";
    }*/

    contenido += "¿$Elements?";

    string salida("../Reportes/salida"+obtenerFechaHora()+".txt");
    fstream file_out;
    file_out.open(salida, ios_base::out);
    if (!file_out.is_open()){
        cout<<"Error al abrit el archivo"<<salida<<endl;
    }else{
        file_out<<contenido<<endl;
        cout << "----ARCHIVO CREADO CORRECTAMENTE----."<< endl;
    }
}

string Salida::obtenerEstado(Estado estado) {
    //transform(estado.begin(), estado.end(), estado.begin(), ::toupper); upercase
    if (estado == Estado::INCUMPLIDO) {
        return "Incumplido";
    } else if (estado == Estado::PENDIENTE) {
        return "Pendiente";
    } else if (estado == Estado::CUMPLIDO) {
        return "Cumplido";
    }
    return "Inexistente";
}
string Salida::obtenerFechaHora(){
    time_t rawtime;
    struct tm * timeContext;

    stringstream textStream;

    time(&rawtime);

    timeContext = localtime(&rawtime);

    textStream << asctime(timeContext);

    string seg = to_string(timeContext->tm_sec);
    string min = to_string(timeContext->tm_min);
    string hor = to_string(timeContext->tm_hour);

    return hor+"_"+min+"_"+seg;
}