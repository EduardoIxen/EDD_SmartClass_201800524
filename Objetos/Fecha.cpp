//
// Created by Eduardo-Ixen on 15/08/2021.
//

#include "Fecha.h"

int Fecha::getDia() {
    return dia;
}

void Fecha::setDia(int dia) {
    this->dia = dia;
}

int Fecha::getMes() {
    return mes;
}

void Fecha::setMes(int mes) {
    this->mes = mes;
}

int Fecha::getAnio() {
    return anio;
}

void Fecha::setAnio(int anio) {
    this->anio = anio;
}

Fecha::Fecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

Fecha::Fecha() {}
