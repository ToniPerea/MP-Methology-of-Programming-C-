#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class ADN{
public:
	static const int MAX = 20;

private:
	char nombre[MAX];
	char secuencia[MAX];
	
public:
	ADN(){

	}

	ADN(char n[], char s[]){
		strcpy(nombre, n);
		strcpy(secuencia,s);
	}

	char * getNombre(){
		return nombre;
	}

	char * getSecuencia(){
		return secuencia;
	}

};

bool pertenece(char cad1[], char cad2[]){
	// Cad1 cadena de la base de datos [secuencia]
	// cad2 la cadena a saber si es o no el bicho
								
	// Cad 1 ['G', 'G', 'A', 'T',' A', 'C', 'T', '\0']: lombiz de tierra i
	// Cad 2 [ 'A', 'C', 'T', 'G', 'G', 'A', 'T', \0'] j
				
	bool encontrado = false;
	bool coinciden = false;
	int indice_cadena1 = 0;
	int longitudCadena1 = strlen(cad1);
	int longitudCadena2 = strlen(cad2);
	
	for(int i = 0, j=0; i < longitudCadena1 && j < longitudCadena2; i++){
		if(cad2[j] == cad1[i%longitudCadena1]){
			//i++;
			j++;
			encontrado = true;
			
		}else{
			//i++;
			if(encontrado){
				j--;
			}
			encontrado = false;
		}





	}

	if(encontrado){
		coinciden = true;
	}


	return coinciden;


}


int main(int argc, char* argv[]){
	vector<ADN> miBD(1000);


	int numUsados = 3;

	for(int i = 0; i < 1000; i++){
		miBD[i] = ADN("", "undefined");

	}
	char c1[] = {'A', 'T', 'A', 'A', 'T', 'G', 'G', 'A', 'C', 'A', 'A', 'T', '\0'};
	char c2[] = {'G','G','A','T','A','C','T','\0'};
	char c3[] = {'A','G','A','G', 'A', 'T', '\0'};
	miBD[0] = ADN("La mosca del Vinagre", c1);
	miBD[1] = ADN("La lombriz de tierra", c2);
	miBD[2] = ADN("La ameba verde", c3);


	char Cad1 [] =  {'G', 'G', 'A', 'T','A', 'C', 'T', '\0'};

	cout << "Buscamos la cadena: " << c1 << "\n\n";
	for(int i =0; i < numUsados; i++){
		if(pertenece(c1,miBD[i].getSecuencia())){
			cout << miBD[i].getNombre() << endl;
		}
	}


	
	/*char Cad2 [] =  {'A', 'C', 'T', 'G', 'G', 'A', 'T', '\0'};
	char Cad3 [] =  {'A', 'X', 'T', 'W', 'G', 'R', 'C', '\0'};

	cout << Cad1 << '\n';
	cout << Cad2 << '\n';

	cout << "#########\n";

	cout << boolalpha << pertenece(Cad1,Cad2) << '\n';
	cout << boolalpha << pertenece(Cad2,Cad1) << '\n';

	cout << boolalpha << pertenece(Cad3,Cad1) << '\n';*/
}