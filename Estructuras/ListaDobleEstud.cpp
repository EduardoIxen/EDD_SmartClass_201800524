//
// Created by Eduardo-Ixen on 11/08/2021.
//

#include "ListaDobleEstud.h"

ListaDobleEstud::ListaDobleEstud() {
    this->primero = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
}

void ListaDobleEstud::insertar(Estudiante _estudiante) {
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
    NodoEstudiante* aux = this->getPrimero();
    while (aux->getSiguiente() != this->getPrimero()){
        cout<< aux->getEstudiante().getNombre() << endl;
        aux = aux->getSiguiente();
    }
    cout<< aux->getEstudiante().getNombre()<<endl;
}

void ListaDobleEstud::generarGrafo() {
    string acum = "digraph G{\n rankdir = LR; \nnode [shape=box]; \ncompound=true; \n";
    string nodo = "";
    string enlace = "";

    NodoEstudiante* aux = this->getPrimero();
    while (aux->getSiguiente() != this->getPrimero()){
        string hex = dirToString(&*aux);
        //nodo += "\"" + hex + "\"" + "[label=\"" + valrToString(tmp->getEstudiante()) + "\"];\n";
        nodo += "\"" + hex + "\"" + "[label=\" Carnet: " + to_string(aux->getEstudiante().getCarnet()) + "\n"
                + "DPI: "+ to_string(aux->getEstudiante().getDpi()) + "\n"
                + "Nombre: " + aux->getEstudiante().getNombre() + "\n"
                + "Carrera: " + aux->getEstudiante().getCarrera() + "\n"
                + "Correo: " + aux->getEstudiante().getCorreo() + "\n"
                + "Pass: "  + aux->getEstudiante().getPass() + "\n"
                + "Creditos: " + to_string(aux->getEstudiante().getCreditos()) + "\n"
                + "Edad: " + to_string(aux->getEstudiante().getEdad()) + "\n"
                + "\"];\n";
        enlace += "\""+ dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\" [dir=\"both\"];\n";
        aux = aux->getSiguiente();
    }
    //para el último nodo
    nodo += "\""+ dirToString(&*aux)+ "\"[label=\"Carnet: " + to_string(aux->getEstudiante().getCarnet()) + "\n"
            + "DPI: "+ to_string(aux->getEstudiante().getDpi()) + "\n"
            + "Nombre: " + aux->getEstudiante().getNombre() + "\n"
            + "Carrera: " + aux->getEstudiante().getCarrera() + "\n"
            + "Correo: " + aux->getEstudiante().getCorreo() + "\n"
            + "Pass: "  + aux->getEstudiante().getPass() + "\n"
            + "Creditos: " + to_string(aux->getEstudiante().getCreditos()) + "\n"
            + "Edad: " + to_string(aux->getEstudiante().getEdad()) + "\n"
            + "\"];\n";
    enlace += "\"" + dirToString(&*aux) + "\" -> \"" + dirToString(&*(aux->getSiguiente())) + "\"[dir=\"both\"];\n";
    acum += nodo + enlace + "\n}\n";

    string filename("../Reportes/lsEstudiantes.dot");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()){
        cout<<"Error al abrit el archivo"<<filename<<endl;
    }else{
        file_out << acum << endl;
        cout << "La escritura fue un exito."<< endl;
    }
    string cmd = "dot -Tpng ../Reportes/lsEstudiantes.dot -o ../Reportes/lsEstudiantes.png";
    system(cmd.c_str());

}

string ListaDobleEstud::dirToString(NodoEstudiante *valor) { //obtiene direccion de memoria del nodo para usarlo como identificador
    stringstream ss;
    ss << &*valor;
    return ss.str();
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