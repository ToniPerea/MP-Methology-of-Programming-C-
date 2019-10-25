#include "matriz.h"




MatrizEjercicio2::MatrizEjercicio2(){
	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			representacionMatriz[fila][columna] = 0;
		}
	}
}

MatrizEjercicio2::MatrizEjercicio2(int valor){
	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			representacionMatriz[fila][columna] = valor;
		}
	}
}

MatrizEjercicio2::MatrizEjercicio2(bool diagonal,int valor){
	// Si diagonal true - > diagonal sentido principal
	if(diagonal){
		
		for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
			for(int columna = 0; columna <= MatrizEjercicio2::DIMENSION - 1; columna++){
				
				if(fila == columna)
					representacionMatriz[fila][columna] = valor;
				else
					representacionMatriz[fila][columna] = 0;
			}
		}

	}
	else{
		for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
			for(int columna = MatrizEjercicio2::DIMENSION -1; columna >= 0; columna--){
				representacionMatriz[fila][columna] = 0;
				if(fila + columna + 1 == MatrizEjercicio2::DIMENSION)
					representacionMatriz[fila][columna] = valor;	
					
			}	
		}
	}
}


int MatrizEjercicio2::get_component(ushort indiceFila, ushort indiceColumna){
	return representacionMatriz[indiceFila][indiceColumna];
}

bool MatrizEjercicio2::set_component(ushort indiceFila, ushort indiceColumna, int valor){
	if(indiceFila < MatrizEjercicio2::DIMENSION && indiceColumna < MatrizEjercicio2::DIMENSION){
		representacionMatriz[indiceFila][indiceColumna] = valor;
		return true;
	}
	return false;
}


bool MatrizEjercicio2::increment_component(ushort indiceFila, ushort indiceColumna, int valor){
	if(indiceFila < MatrizEjercicio2::DIMENSION && indiceColumna < MatrizEjercicio2::DIMENSION){
		representacionMatriz[indiceFila][indiceColumna] += valor;
		return true;
	}
	return false;
}


void MatrizEjercicio2::imprimir(){
	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
		cout << "[" << fila << "]\t";
		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
			cout << representacionMatriz[fila][columna] << ' ';
		}
		cout << '\n';
	}
}


// MatrizEjercicio2 MatrizEjercicio2::suma(MatrizEjercicio2 & matrizA){
// 	MatrizEjercicio2 resultado;
// 	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
// 		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
// 			resultado.set_component(fila,columna,matrizA.get_component(fila,columna) + this->get_component(fila,columna));
// 		}
// 	}
// 	return resultado;
// }


// MatrizEjercicio2 MatrizEjercicio2::producto(MatrizEjercicio2 & matrizA){
// 	MatrizEjercicio2 resultado;
// 	int acumulador = 0;

// 	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
// 		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
// 			for(int k = 0; k < MatrizEjercicio2::DIMENSION; k++){
// 				resultado.increment_component(fila,columna,(this->get_component(fila,k) * matrizA.get_component(k,columna)));
// 			}

// 		}
		
// 	}
// 	return resultado;

// }


// int MatrizEjercicio2::traza(){

// 	int traza = 0;
// 	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
// 		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
// 			if(fila == columna)
// 				traza += this->get_component(fila,columna); 
// 		}
// 	}

// 	return traza;
// }



// MatrizEjercicio2 MatrizEjercicio2::producto_especial(MatrizEjercicio2 & matrizA){
// 	MatrizEjercicio2 resultado;
// 	for(int fila = 0; fila < MatrizEjercicio2::DIMENSION; fila++){
// 		for(int columna = 0; columna < MatrizEjercicio2::DIMENSION; columna++){
// 			resultado.set_component(fila,columna,matrizA.get_component(fila,columna) * this->get_component(fila,columna));
// 		}
// 	}
// 	return resultado;
// }

// MatrizEjercicio2 MatrizEjercicio2::twisted_mult(MatrizEjercicio2 & a){
// 	MatrizEjercicio2 miMatrizDiagonalP2(false, 1);
// 	return (this->producto(miMatrizDiagonalP2)).producto(a);
// }




