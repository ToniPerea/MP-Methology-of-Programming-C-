#include "matriz.h"

MatrizEjercicio2 suma(MatrizEjercicio2 & matrizA, MatrizEjercicio2 & matrizB){
	MatrizEjercicio2 resultado;
	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			resultado.set_component(fila,columna,matrizA.get_component(fila,columna) + matrizB.get_component(fila,columna));
		}
	}
	return resultado;
}

MatrizEjercicio2 producto(MatrizEjercicio2 & matrizA, MatrizEjercicio2 & matrizB){
	MatrizEjercicio2 resultado;
	int acumulador = 0;

	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			for(int k = 0; k < MatrizEjercicio2::DIMENSION; k++){
				resultado.increment_component(fila,columna,(matrizA.get_component(fila,k) * matrizB.get_component(k,columna)));
			}

		}
		
	}
	return resultado;
}

int traza(MatrizEjercicio2 & matrizA){
	int traza = 0;
	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			if(fila == columna)
				traza += matrizA.get_component(fila,columna); 
		}
	}

	return traza;
}

MatrizEjercicio2 producto_especial(MatrizEjercicio2 & matrizA, MatrizEjercicio2 & matrizB){
	MatrizEjercicio2 resultado;
	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			resultado.set_component(fila,columna,matrizA.get_component(fila,columna) * matrizB.get_component(fila,columna));
		}
	}
	return resultado;
}


MatrizEjercicio2 twisted_mult(MatrizEjercicio2 & matrizA, MatrizEjercicio2 & matrizB){
	MatrizEjercicio2 miMatrizDiagonalP2(false, 1);
	MatrizEjercicio2 intermedia = producto(matrizA,miMatrizDiagonalP2);
	return producto(intermedia,matrizB);
}