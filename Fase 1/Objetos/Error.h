//
// Created by Eduardo-Ixen on 19/08/2021.
//

#ifndef EDD_SMARTCLASS_201800524_ERROR_H
#define EDD_SMARTCLASS_201800524_ERROR_H
#include "iostream"
using namespace std;
class Error {
private:
    int id;
    string tipo;
    string descripcion;
public:
    Error();
    Error(int, string, string);

    void setId(int);
    void setTipo(string);
    void setDescripcion(string);

    int getId();
    string getTipo();
    string getDescripcion();
};


#endif //EDD_SMARTCLASS_201800524_ERROR_H
