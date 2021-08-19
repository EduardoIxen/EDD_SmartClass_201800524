//
// Created by Eduardo-Ixen on 19/08/2021.
//

#include "ColaDeError.h"

ColaDeError::ColaDeError() {
    this->ultimo = NULL;
    this->primero = NULL;
    this->tamanio = 0;
}

void ColaDeError::setPrimero(NodoError *primero) {
    this->primero = primero;
}

void ColaDeError::setUltimo(NodoError *ultimo) {
    this->ultimo = ultimo;
}

void ColaDeError::setTamanio(int tamanio) {
    this->tamanio = tamanio;
}

NodoError* ColaDeError::getPrimero() {
    return this->primero;
}

NodoError* ColaDeError::getUltimo() {
    return this->ultimo;
}

int ColaDeError::getTamanio() {
    return this->tamanio;
}

void ColaDeError::enqueue(Error *error) {
    NodoError* nuevoNodo = new NodoError(error, this->getTamanio()+1);
    if (getPrimero() == NULL){
        setPrimero(nuevoNodo);
        setUltimo(nuevoNodo);
        setTamanio(getTamanio()+1);
        nuevoNodo->getError()->setId(this->getTamanio());
    } else{
        getUltimo()->setSiguiente(nuevoNodo);
        setUltimo(nuevoNodo);
        setTamanio(getTamanio()+1);
        nuevoNodo->getError()->setId(this->getTamanio());
    }

}

void ColaDeError::dequeue() {
    if (getPrimero() == NULL){
        cout<<"--------COLA DE ERRORES VACIA--------"<<endl;
        return;
    }
    setPrimero(getPrimero()->getSiguiente());
    setTamanio(getTamanio()-1);
}

void ColaDeError::generarGrafo() {
    if (getTamanio() == 0){
        cout<<"----LISTA VACIA, NO SE PUEDE GENERAR EL REPORTE----"<<endl;
        return;
    }

    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";

    NodoError* aux = getPrimero();
    nodo += R"("Inicio de la cola" -> ")"+ dirToString(&*getPrimero())+"\" [dir=\"back\"];\n";
    while (aux != getUltimo()){
        string hex = dirToString(&*aux);
        nodo += "\"" + hex +"\"" + "[label=\" Id: " + to_string(aux->getError()->getId()) + "\n"
                +"Tipo: " +aux->getError()->getTipo() + "\n"
                +"Descripcion: "+ aux->getError()->getDescripcion() +"\n"
                +"\"];\n";
        enlace += "\""+ dirToString(&*aux) + "\" -> \""+ dirToString(&*(aux->getSiguiente())) + "\" [dir=\"back\"];\n";
        aux = aux->getSiguiente();
    }

    string hex = dirToString(&*aux);
    nodo += "\"" + hex +"\"" + "[label=\" Id: " + to_string(aux->getError()->getId()) + "\n"
            +"Tipo: " +aux->getError()->getTipo() + "\n"
            +"Descripcion: "+ aux->getError()->getDescripcion() +"\n"
            +"\"];\n";
    enlace += "\""+ dirToString(&*aux) + "\" -> \""+ "Final de la cola" + "\" [dir=\"back\"];\n";

    acum += nodo + enlace + "\n}\n";

    string filename("../Reportes/ColaError.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()){
        cout<<"Error al abrit el archivo"<<filename<<endl;
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito."<< endl;
    }
    string cmd = "dot -T svg ../Reportes/ColaError.dot -o ../Reportes/ColaError.svg";
    system(cmd.c_str());
}

string ColaDeError::dirToString(NodoError *valor) {
    stringstream ss;
    ss << &*valor;
    return ss.str();
}