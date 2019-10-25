#include <iostream>
#include <string>

using namespace std;

int main(){
	int contador1, contador2;
	int iterador = 0;

	cin >> contador1;

	string *cadena1 = new string[contador1];

	for(int i = 0; i < contador1; i++){
		cin >> cadena1[i];
	}

	cin >> contador2;

	string *cadena2 = new string[contador2];

	for(int i = 0; i < contador2; i++){
		cin >> cadena2[i];
	}

	
	for(int i = 0; i < contador2; i++){
		for(int j = 0; j < contador1; j++){
			if(cadena2[i] == cadena1[j]){
				iterador++;
			}
		}
	}

	string *cadena_interseccion = new string[iterador];

	iterador = 0;

	for(int i = 0; i < contador2; i++){
		for(int j = 0; j < contador1; j++){
			if(cadena2[i] == cadena1[j]){
				cadena_interseccion[iterador] = cadena2[i];
				iterador++;
			}
		}
	}

	for(int i = 0; i < iterador; i++){
		cout << cadena_interseccion[i] << endl;
	}

	delete[]cadena1;
	delete[]cadena2;
	delete[]cadena_interseccion;




}