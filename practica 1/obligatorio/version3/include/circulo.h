#ifndef CIRCULO_H
#define CIRCULO_H

#include "punto.h"

class Circulo {
private:
    Punto centro; ///< Centro del círculo
    double radio; ///< radio del círculo
public:
    Circulo(); ///< Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double radio); ///< Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double radio); ///< Asigna el centro y el radio a un circulo
    Punto getCentro() const; ///< Devuelve el centro de un circulo
    double getRadio() const; ///< Devuelve el radio de un circulo
    void escribir() const; ///< Escribe círculo en formato radio-centro
    void leer(); ///< lee círculo en formato radio-centro
    double area() const; ///< Devuelve el área de un círculo
};

#endif
