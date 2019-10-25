#include <iostream>

using namespace std;


struct vectorSD {
	double *info;
	int util;
    int reservado;
};

void Inicializar(vectorSD &nuevo, int n){
	nuevo.util = 0;
	nuevo.reservado = n;
	nuevo.info = new double[n];
}

void Aniade(vectorSD &vector, double n){

	if(vector.util == vector.reservado){
		double *aux = new double[vector.util * 2];

		aux[vector.util] = n;

		for(int i = 0; i < vector.util; i++){
			aux[i] = vector.info[i];
		}

		delete[] vector.info;

		vector.info = aux;

		vector.reservado *= 2;
		vector.util++;


	}else{
		vector.info[vector.util] = n;
		vector.util++;
	}


}

void Copia(vectorSD original, vectorSD &copia){

	Inicializar(copia, original.util);

	for(int i = 0; i < original.util; i++){
		Aniade(copia, original.info[i]);
	}


}

void LiberarMemoria(vectorSD &vector){
	delete[] vector.info;
	vector.info = NULL;
	vector.util = 0;
	vector.reservado = 0;
}


int main(){
	vectorSD v1;
	vectorSD v1_copia;
	double numero_a_introducir;
	int memoria_a_cargar;

	cout << "Elige la memoria a reservar: ";
	cin >> memoria_a_cargar;

	Inicializar(v1, memoria_a_cargar);

	cout << v1.util << endl;
	cout << v1.reservado << endl;

	cout << "Introduce un valor para el vector: ";
	cin >> numero_a_introducir;

	Aniade(v1, numero_a_introducir);

	cout << v1.util << endl;
	cout << v1.reservado << endl;

	for(int i = 0; i < v1.util; i++){
		cout << "El vector: " << v1.info[i] << endl;
	}

	cout << "COPIA REALIZADA···············100%" << endl;

	Copia(v1,v1_copia);

	cout << v1.util << endl;
	cout << v1.reservado << endl;
	for(int i = 0; i < v1.util; i++){
		cout << "El vector v1: " << v1.info[i] << endl;
	}

	cout << endl;

	cout << v1_copia.util << endl;
	cout << v1_copia.reservado << endl;
	for(int i = 0; i < v1.util; i++){
		cout << "El vector v1 copiado: " << v1_copia.info[i] << endl;
	}

	cout << endl;

	cout << "Vamos a proceder con liberar la memoria de v1·················100%" << endl;

	LiberarMemoria(v1);

	cout << v1.util << endl;
	cout << v1.reservado << endl << endl;






	
}