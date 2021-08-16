//
// Created by Eduardo-Ixen on 15/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_TAREA_H
#define EDD_SMARTCLASS_201800524_TAREA_H

#include <string>
#include "Fecha.h"
#include "EnumEstado.h"

using namespace std;
class Tarea {
private:
    int id;
    int carnet;
    string nombre;
    string descripcion;
    string materia;
    Fecha* fecha;
    int hora;
    Estado estado;
public:
    Tarea(int id, int carnet, string nombre, string descripcion, string materia,
          Fecha *fecha, int hora, Estado estado);

    Tarea();

    int getId();

    void setId(int id);

    int getCarnet();

    void setCarnet(int carnet);

    string getNombre();

    void setNombre(string nombre);

    string getDescripcion();

    void setDescripcion(string descripcion);

    string getMateria();

    void setMateria(string materia);

    Fecha* getFecha();

    void setFecha(Fecha* fecha);

    int getHora();

    void setHora(int hora);

    Estado getEstado();

    void setEstado(Estado estado);

};


#endif //EDD_SMARTCLASS_201800524_TAREA_H
