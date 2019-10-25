#include <iostream>
#include <cmath>

using namespace std;

struct coeficientes{
	int coef;
    int grado;
    coeficientes* sig;
};

typedef coeficientes *TipoPolinomio;

int evaluarUnTermino(int coefi, int grado, int valor);
int evaluar(const TipoPolinomio p, const int valor);
int obtener (const TipoPolinomio p, const int i);
TipoPolinomio sumar(const TipoPolinomio p1, const TipoPolinomio p2);
TipoPolinomio sumar(const TipoPolinomio p1, const TipoPolinomio p2);
TipoPolinomio derivada(const TipoPolinomio p);

void imprimirPolinomio(TipoPolinomio p){
	TipoPolinomio iterador = p;
	while(iterador != NULL){
		cout << iterador->coef << "x^" << iterador->grado << " + ";
		iterador = iterador->sig;
	}
}



int main(int argc, char* argv[]){
	cout << "Hola" << endl;
	coeficientes c1;
	TipoPolinomio p1 = new coeficientes[1];
	
	p1->coef = 2;
	p1->grado = 2;
	p1->sig = new coeficientes[1];
	
	p1->sig->coef = 3;
	p1->sig->grado = 1;
	p1->sig->sig = NULL;
	cout << p1->coef;
	cout << p1->grado;
	cout << "\nEvaluacion:" << evaluar(p1, 3);
	cout << "\nObtener el termino de grado 2: " << obtener(p1,2);

	TipoPolinomio p2 = new coeficientes[1];

	p2->coef = 5;
	p2->grado = 2;
	p2->sig = new coeficientes[1];
	
	p2->sig->coef = 3;
	p2->sig->grado = 0;
	p2->sig->sig = NULL;

	cout << "derivamos: ";
	TipoPolinomio p3 = derivada(p1);
	cout << endl;
	cout << p3->coef;
	cout << p3->grado;

}


// 1-> Escribe una función que evalué un polinomio p en un entero valor
int evaluarUnTermino(int coefi, int grado, int valor){
	return (coefi * pow(valor,grado));
}

int evaluar(const TipoPolinomio p, const int valor){
	
	TipoPolinomio iterador = p;
	int acum = 0;
	while(iterador != NULL){
		acum += evaluarUnTermino(iterador->coef, iterador->grado, valor);
		iterador = iterador->sig;
	}
	return acum;
	
}

// 2-> Escribe una función que devuelva el coeficiente del término de grado i de una polinomio p

int obtener (const TipoPolinomio p, const int i){
	TipoPolinomio iterador = p;
	while(iterador->sig != NULL && iterador->grado != i){
		iterador = iterador->sig;
	}

	return iterador->coef;
}


// 3-> Escribe una función que sume dos polinomio p1, p2
TipoPolinomio sumar(const TipoPolinomio p1, const TipoPolinomio p2){
	TipoPolinomio iterador = p1;
	TipoPolinomio iterador2 =p2;
	TipoPolinomio resultado = new coeficientes[1];
	while(iterador->sig!=NULL){
		resultado->coef = iterador->coef + iterador2->coef;
		resultado->grado = iterador->grado;
		resultado->sig = new coeficientes[1];
		//resultado = resultado->sig;
	}
	resultado->sig=NULL;

	return resultado;
}


TipoPolinomio derivada(const TipoPolinomio p){
	TipoPolinomio iterador = p;
	TipoPolinomio resultado = new coeficientes[1];
	while(iterador->sig != NULL){
		resultado->coef = iterador->grado*iterador->coef;
		resultado->grado = iterador->grado - 1;
		
		resultado->sig = new coeficientes[1];
		//resultado = resultado->sig;
		iterador = iterador->sig;
	}
	resultado->sig=NULL;
	return resultado;
}





