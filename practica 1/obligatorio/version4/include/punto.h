#ifndef PUNTO_H
#define PUNTO_H

class Punto{
private:
	double x; ///< coordenada x del punto
	double y; ///< coordenada y del punto};
public:
	Punto(); ///< constructor. Pone a 0 las dos coordenadas
	Punto(double x, double y);///< constructor. Inicializa un punto con dos valores x y
	double getX() const; ///< Devuelve la coordenada x del punto
	double getY() const; ///< Devuelve la coordenada y del punto
	void setX(double nuevoX); ///< Asigna el valor nuevoX a la coordenada x del punto
	void setY(double nuevoY); ///< Asigna el valor nuevoY a la coordenada y del punto
	void escribir() const; ///<  Escribe un punto en formato (x,y)
	void leer(); ///< // Lee un punto en el formato (x,y)
};

#endif
