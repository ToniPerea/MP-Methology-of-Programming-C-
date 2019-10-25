#include <iostream>
#include <cmath>    

using namespace std;

/// Clase Círculo

Circulo::Circulo()  {
	centro.setX(0);
	centro.setY(0);
	radio = 0;
}

Circulo::Circulo(Punto centro, double radio)  {
	this->centro = centro;
	this->radio = radio;
	// set(centro,radio);
}

void Circulo::set(Punto centro, double radio)  {
	this->centro = centro;
	this->radio = radio;
}

Punto Circulo::getCentro() const  {
	return centro;
}

double Circulo::getRadio() const {
	return radio;
}

void Circulo::escribir() const{
    cout << radio << "-";
    centro.escribir();
}

void Circulo::leer(){
    // Formato de lectura del círculo: radio-(x,y)
    char car;

    cin >> radio;
    cin >> car; //Leer -
    centro.leer();
}

double Circulo::area() const{
    return M_PI*radio*radio;
}
/// Clase Circulo

/// Funciones auxiliares



