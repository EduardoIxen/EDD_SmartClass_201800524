//
// Created by Eduardo-Ixen on 11/08/2021.
//

#include "ListaDobleEstud.h"

ListaDobleEstud::ListaDobleEstud() {
    this->primero = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
}

void ListaDobleEstud::insertar(Estudiante* _estudiante) {
    auto* nuevoNodo = new NodoEstudiante(_estudiante, 0);
    if (this->primero == NULL){
        this->primero = nuevoNodo;
        this->ultimo = nuevoNodo;
        this->tamanio++;
        nuevoNodo->setId(this->tamanio);
    }else{
        nuevoNodo->setSiguiente(this->primero);
        this->primero->setAnterior(nuevoNodo);

        nuevoNodo->setAnterior(this->ultimo);
        this->ultimo->setSiguiente(nuevoNodo);

        this->ultimo = nuevoNodo;
        this->tamanio++;
        nuevoNodo->setId(tamanio);
    }
}

void ListaDobleEstud::recorrerLista() {
    if (this->tamanio==0){
        cout<<"----LISTA VACIA, NO SE PUEDE GENERAR EL REPORTE----";
        return;
    }
    NodoEstudiante* aux = this->getPrimero();
    while (aux->getSiguiente() != this->getPrimero()){
        cout<< aux->getEstudiante()->getNombre() << endl;
        aux = aux->getSiguiente();
    }
    cout<< aux->getEstudiante()->getNombre()<<endl;
}

void ListaDobleEstud::generarGrafo() {
    if (this->getTamanio()==0){
        cout<<"----LISTA VACIA, NO SE PUEDE GENERAR EL REPORTE----"<<endl;
        return;
    }

    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";
    string nombreArch = obtenerFechaHora();

    NodoEstudiante* aux = this->getPrimero();
    while (aux->getSiguiente() != this->getPrimero()){
        string hex = dirToString(&*aux);
        //nodo += "\"" + hex + "\"" + "[label=\"" + valrToString(tmp->getEstudiante()) + "\"];\n";
        nodo += "\"" + hex + "\"" + "[label=\" Carnet: " + to_string(aux->getEstudiante()->getCarnet()) + "\n"
                + "DPI: "+ to_string(aux->getEstudiante()->getDpi()) + "\n"
                + "Nombre: " + aux->getEstudiante()->getNombre() + "\n"
                + "Carrera: " + aux->getEstudiante()->getCarrera() + "\n"
                + "Correo: " + aux->getEstudiante()->getCorreo() + "\n"
                + "Pass: "  + aux->getEstudiante()->getPass() + "\n"
                + "Creditos: " + to_string(aux->getEstudiante()->getCreditos()) + "\n"
                + "Edad: " + to_string(aux->getEstudiante()->getEdad()) + "\n"
                + "\"];\n";
        enlace += "\""+ dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\" [dir=\"both\"];\n";
        aux = aux->getSiguiente();
    }
    //para el último nodo
    nodo += "\""+ dirToString(&*aux)+ "\"[label=\"Carnet: " + to_string(aux->getEstudiante()->getCarnet()) + "\n"
            + "DPI: "+ to_string(aux->getEstudiante()->getDpi()) + "\n"
            + "Nombre: " + aux->getEstudiante()->getNombre() + "\n"
            + "Carrera: " + aux->getEstudiante()->getCarrera() + "\n"
            + "Correo: " + aux->getEstudiante()->getCorreo() + "\n"
            + "Pass: "  + aux->getEstudiante()->getPass() + "\n"
            + "Creditos: " + to_string(aux->getEstudiante()->getCreditos()) + "\n"
            + "Edad: " + to_string(aux->getEstudiante()->getEdad()) + "\n"
            + "\"];\n";
    enlace += "\"" + dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\"[dir=\"both\"];\n";
    acum += nodo + enlace + "\n}\n";


    string filename("../Reportes/lsEstudiantes"+nombreArch+".dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()){
        cout<<"Error al abrit el archivo"<<filename<<endl;
    }else{
        file_out << acum << endl;
        cout << "----REPORTE GENERADO EXITOSAMENTE----"<< endl;
    }
    string cmd = "dot -T svg ../Reportes/lsEstudiantes"+nombreArch+".dot -o ../Reportes/lsEstudiantes"+nombreArch+".svg";
    system(cmd.c_str());

}

bool ListaDobleEstud::buscarEstudiante(string carnet) {
    if (this->tamanio==0){
        cout<<"----LISTA VACIA, NO HAY ELEMENTOS PARA BUSCAR----";
        return false;
    }
    if (this->getUltimo()->getEstudiante()->getCarnet() == stoi(carnet)){
        return true;
    }
    NodoEstudiante* aux = this->getPrimero();
    while (aux->getSiguiente() != this->getPrimero()){
        if(aux->getEstudiante()->getCarnet() == stoi(carnet)){
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

string ListaDobleEstud::dirToString(NodoEstudiante *valor) { //obtiene direccion de memoria del nodo para usarlo como identificador
    stringstream ss;
    ss << &*valor;
    return ss.str();
}

void ListaDobleEstud::setPrimero(NodoEstudiante * _primero) {
    this->primero = _primero;
}

void ListaDobleEstud::setUltimo(NodoEstudiante * _ultimo) {
    this->ultimo = _ultimo;
}

int ListaDobleEstud::getTamanio() {
    return this->tamanio;
}

NodoEstudiante* ListaDobleEstud::getPrimero() {
    return this->primero;
}
NodoEstudiante* ListaDobleEstud::getUltimo() {
    return this->ultimo;
}

void ListaDobleEstud::setTamanio(int _tamanio) {
    this->tamanio = _tamanio;
}

string ListaDobleEstud::obtenerFechaHora(){
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
