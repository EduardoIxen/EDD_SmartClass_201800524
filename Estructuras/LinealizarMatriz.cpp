//
// Created by Eduardo-Ixen on 17/08/2021.
//

#include "LinealizarMatriz.h"

LinealizarMatriz::LinealizarMatriz() {
    this->tamanio = 0;
    this->primero = NULL;
    this->ultimo = NULL;
}

void LinealizarMatriz::setPrimero(NodoMatrizL* _primero) {
    this->primero = _primero;
}

void LinealizarMatriz::setUltimo(NodoMatrizL* _ultimo) {
    this->ultimo = _ultimo;
}

void LinealizarMatriz::setTamanio(int _tamanio) {
    this->tamanio = _tamanio;
}

NodoMatrizL* LinealizarMatriz::getPrimero() {
    return this->primero;
}

NodoMatrizL* LinealizarMatriz::getUltimo() {
    return this->ultimo;
}

int LinealizarMatriz::getTamanio() {
    return this->tamanio;
}

void LinealizarMatriz::insertar(Tarea* _valor, int _id) {
    auto* nuevoNodo = new NodoMatrizL(_valor, _id);
    if (this->primero == NULL){
        this->primero = nuevoNodo;
        this->ultimo = nuevoNodo;
        this->tamanio++;
        //nuevoNodo->setId(this->tamanio);
    }else{
        nuevoNodo->setSiguiente(this->primero);
        this->primero->setAnterior(nuevoNodo);

        nuevoNodo->setAnterior(this->ultimo);
        this->ultimo->setSiguiente(nuevoNodo);

        this->ultimo = nuevoNodo;
        this->tamanio++;
        //nuevoNodo->setId(this->tamanio);
    }

}

void LinealizarMatriz::recorrerLista() {
    if (this->tamanio == 0){
        std::cout<<"----LISTA VACIA, NO SE PUEDE GENERAR EL REPORTE----";
        return;
    }
    NodoMatrizL* aux = this->primero;
    while (aux->getSiguiente() != this->getPrimero()){
        if (aux->getTarea() != NULL){
            std::cout<<"id nodo: "<<aux->getId()<< std::endl;
            //std::cout<<"carner"<<aux->getTarea()->getCarnet()<< std::endl;
        }else{
            std::cout<<"es nuul: "<<aux->getId()<< std::endl;
        }
        aux = aux->getSiguiente();
    }
    if (aux->getTarea() != NULL){
        std::cout<<"id nodo: "<<aux->getId()<< std::endl;
        //std::cout<<"carner"<<aux->getTarea()->getCarnet()<< std::endl;
    }else{
        std::cout<<"es nuul: "<<aux->getId()<< std::endl;
    }

}

void LinealizarMatriz::buscar(int mes, int dia, int hora) {
    //mes = mes - 7;
    //dia = dia - 1;
    //hora = hora - 8;

    int id = ((hora-8) * 30 + (dia-1))*5+(mes-7);
    if (this->tamanio == 0){
        std::cout<<"----LISTA VACIA, NO SE PUEDE GENERAR EL REPORTE----";
        return;
    }
    NodoMatrizL* aux = this->primero;
    while (aux->getSiguiente() != this->getPrimero()){
        if (aux->getId() == id){
            if (aux->getTarea() != NULL){
                std::cout<<"id nodo: "<<aux->getId()<< std::endl;
                std::cout<<"carner"<<aux->getTarea()->getCarnet()<< std::endl;
                std::cout<<"id tarea"<<aux->getTarea()->getId()<< std::endl;
                return;
            }else{
                std::cout<<"NO SE ENCONTRARON TAREAS EL: "<<dia<<"/"<<mes<<" A LAS "<<hora<< " HORAS."<<std::endl;
                return;
            }
        }
        aux = aux->getSiguiente();
    }
    if (aux->getId() == id){
        if (aux->getTarea() != NULL){
            std::cout<<"id nodo: "<<aux->getId()<< std::endl;
            std::cout<<"carner"<<aux->getTarea()->getCarnet()<< std::endl;
            std::cout<<"id tarea"<<aux->getTarea()->getId()<< std::endl;
            return;
        } else{
            std::cout<<"NO SE ENCONTRARON TAREAS EL: "<<dia<<"/"<<mes<<" A LAS "<<hora<< " HORAS."<<std::endl;
            return;
        }
    }
    std::cout<<"NO SE ENCONTRARON TAREAS EL: "<<dia<<"/"<<mes<<" A LAS "<<hora<< " HORAS."<<std::endl;
}

void LinealizarMatriz::generarGrafo() {
    if(this->getTamanio() == 0){
        cout<<"----LISTA VACIA, NO SE PUEDE GENERAR EL REPORTE----"<<endl;
        return;
    }
    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";

    NodoMatrizL* aux = this->getPrimero();
    while (aux->getSiguiente() != this->getPrimero()){
        string hex = dirToString(&*aux);
        if (aux->getTarea() != NULL){
            nodo += "\"" +hex + "\"" + "[label=\" Posicion: " + to_string(aux->getId()) + "\n"
                    +"Carnet: " + to_string(aux->getTarea()->getCarnet()) + "\n"
                    +"Nombre: " + aux->getTarea()->getNombre() + "\n"
                    +"Descripcion: "+ aux->getTarea()->getDescripcion() + "\n"
                    +"Materia: "+ aux->getTarea()->getMateria() + "\n"
                    +"Fecha: "+ aux->getTarea()->getFecha()->obtenerFecha("/") + "\n"
                    +"Hora: " + to_string(aux->getTarea()->getHora()) + "\n"
                    + "Estado: "+ obtenerEstado(aux->getTarea()->getEstado()) + "\n"
                    +"\"];\n";
            enlace += "\"" + dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\" [dir=\"both\"];\n";
        }else{
            nodo += "\"" +hex + "\"" + "[label=\" Posicion: " + to_string(aux->getId()) + "\n"
                    +"NULL" + "\n"
                    +"\"];\n";
            enlace += "\"" + dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\" [dir=\"both\"];\n";
        }
        aux = aux->getSiguiente();
    }
    if (aux->getTarea() != NULL){
        nodo += "\"" + dirToString(&*aux) + "\"" + "[label=\" Posicion: " + to_string(aux->getId()) + "\n"
                +"Carnet: " + to_string(aux->getTarea()->getCarnet()) + "\n"
                +"Nombre: " + aux->getTarea()->getNombre() + "\n"
                +"Descripcion: "+ aux->getTarea()->getDescripcion() + "\n"
                +"Materia: "+ aux->getTarea()->getMateria() + "\n"
                +"Fecha: "+ aux->getTarea()->getFecha()->obtenerFecha("/") + "\n"
                +"Hora: " + to_string(aux->getTarea()->getHora()) + "\n"
                + "Estado: "+ obtenerEstado(aux->getTarea()->getEstado()) + "\n"
                +"\"];\n";
        enlace += "\"" + dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\" [dir=\"both\"];\n";
    }else{
        nodo += "\"" + dirToString(&*aux) + "\"" + "[label=\" Posicion: " + to_string(aux->getId()) + "\n"
                +"NULL" + "\n"
                +"\"];\n";
        enlace += "\"" + dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\" [dir=\"both\"];\n";
    }
    acum += nodo + enlace + "\n}\n";

    string filename("../Reportes/lsTareas.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()){
        cout<<"Error al abrit el archivo"<<filename<<endl;
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito."<< endl;
    }
    string cmd = "dot -T svg ../Reportes/lsTareas.dot -o ../Reportes/lsTareas.svg";
    system(cmd.c_str());

}

string LinealizarMatriz::dirToString(NodoMatrizL *valor) { //obtiene direccion de memoria del nodo para usarlo como identificador
    stringstream ss;
    ss << &*valor;
    return ss.str();
}

string LinealizarMatriz::obtenerEstado(Estado estado){
    if (estado == Estado::CUMPLIDO){
        return "Cumplido";
    }else if (estado == Estado::PENDIENTE){
        return "Pendiente";
    } else if (estado == Estado::INCUMPLIDO){
        return "Incumplido";
    }
    return "Inexistente";
}