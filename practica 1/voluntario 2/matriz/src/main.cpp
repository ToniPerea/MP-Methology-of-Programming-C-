#include "matriz.h"
#include "utilidades.h"

int main(int argc, char* argv[]){
	cout << "Hola mundo" << endl;

	MatrizEjercicio2 miMatrizCeros;
	MatrizEjercicio2 miMatrizUnos(1);
	MatrizEjercicio2 miMatrizDoses(2);
	MatrizEjercicio2 miMatrizTreses(3);

	MatrizEjercicio2 miMatrizDiagonalP1(true,1);
	MatrizEjercicio2 miMatrizDiagonalP2(false,1);

	cout << "Matriz suma = Matriz de unos + matriz de doses : \n"; 
	suma(miMatrizUnos,miMatrizDoses).imprimir();

	cout << "\n\nMatriz de treses: \n";
	miMatrizTreses.imprimir();


	cout << "\n\nProducto de unos y doses: \n";
	producto(miMatrizUnos,miMatrizDoses).imprimir();


	cout << "\n\nTraza de la matriz de doses: " << traza(miMatrizDoses) << "\n";


	cout << "\n\nProducto especial de unos y doses: \n";
	producto_especial(miMatrizUnos,miMatrizDoses).imprimir();

	cout << "\n\n Matriz con diagonal principal con unos \n";
	miMatrizDiagonalP1.imprimir();

	cout << "\n\n Matriz con diagonal principal inversa con unos \n";
	miMatrizDiagonalP2.imprimir();



	cout << "\n\n Twisted mult \n";
	twisted_mult(miMatrizUnos,miMatrizDoses).imprimir();

	
}