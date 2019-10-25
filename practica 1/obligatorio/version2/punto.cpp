#include <iostream>
#include <cmath> 
using namespace std;

/// Clase Punto

Punto::Punto(){
	x=0;
	y=0;
}
Punto::Punto(double x, double y){
	this->x=x;
	this->y=y;
}

double Punto::getX() const {
	return x;
} 

double Punto::getY() const {
	return y;
} 

void Punto::setX(double nuevoX)  {
	x=nuevoX;
}

void Punto::setY(double nuevoY)  {
	y=nuevoY;
}
 
 
void Punto::escribir() const{
    cout << "(" << x << "," << y << ")" << endl;
}


void Punto::leer(){
    // Formato de lectura del punto: (x,y)
    char car;
    cin >> car >> x >> car >> y >> car;
}
