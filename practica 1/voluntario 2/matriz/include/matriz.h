#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;

/** Clase MatrizEjercicio2
* Representa una matriz cuadrada de DIMENSION x DIMENSION
* @todo: documentacion doxygen
*/
class MatrizEjercicio2{
	

	public:
		static const int DIMENSION = 10;

	private:
		int representacionMatriz[DIMENSION][DIMENSION];

	public:

		MatrizEjercicio2();
		MatrizEjercicio2(int valor);
		MatrizEjercicio2(bool diagonal,int valor);

		int get_component(ushort indiceFila, ushort indiceColumna);
		bool set_component(ushort indiceFila, ushort indiceColumna, int valor);
		bool increment_component(ushort indiceFila, ushort indiceColumna, int valor);
		void imprimir();

		//MatrizEjercicio2 suma(MatrizEjercicio2 & matrizA);

		//MatrizEjercicio2 producto(MatrizEjercicio2 & matrizA);

		//int traza();

		//MatrizEjercicio2 producto_especial(MatrizEjercicio2 & matrizA);


		//MatrizEjercicio2 twisted_mult(MatrizEjercicio2 & a);




};


#endif