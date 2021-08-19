//
// Created by Eduardo-Ixen on 15/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_FECHA_H
#define EDD_SMARTCLASS_201800524_FECHA_H
#include "iostream"

using namespace std;
class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int dia, int mes, int anio);

    Fecha();

    int getDia();

    void setDia(int dia);

    int getMes();

    void setMes(int mes);

    int getAnio();

    void setAnio(int anio);

    string obtenerFecha(string separador);

};


#endif //EDD_SMARTCLASS_201800524_FECHA_H
