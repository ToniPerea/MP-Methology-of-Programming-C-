/**
  * @file tiempo.cpp 
  * @brief Utilidades para la gestión de datos temporales usando structs 
  * @author MP-GI - Grupo F
  *
  */
  
#include <iostream>
using namespace std;

struct Tiempo {
	int horas, minutos, segundos;
};

int convertirASegundos(Tiempo t)  {
	int segundos_totales;

	segundos_totales = (t.horas * 3600) + (t.minutos * 60) + t.segundos;

	return segundos_totales;
}

Tiempo convertirATiempo(int segundos)  {

	Tiempo nuevo;

	int tiempo_restante;

	nuevo.segundos = segundos % 60;
	tiempo_restante = segundos / 60;
	nuevo.minutos = tiempo_restante % 60;
	tiempo_restante = tiempo_restante /60;
	nuevo.horas = tiempo_restante % 60;

	return nuevo;



}

void repararTiempo(Tiempo& t)  {
	while(t.horas > 23 || t.minutos > 59 || t.segundos > 59){
		if (t.horas > 23){
			t.horas = t.horas-24;
		}
		if (t.minutos > 59){
			t.minutos = t.minutos-60;
			t.horas++;
		}		
		if (t.segundos > 59){
			t.segundos = t.segundos-60;
			t.minutos++;
		}
	}
}

bool esPosterior(Tiempo t1, Tiempo t2)  {
	bool posterior = true;

	if(convertirASegundos(t2) > convertirASegundos(t1))
		posterior = false;

	return posterior;
}

Tiempo incrementarTiempo(Tiempo t, int s)  {

	Tiempo nuevo;
	Tiempo segundos_en_tiempo = convertirATiempo(s);

	nuevo.horas = t.horas + segundos_en_tiempo.horas;
	nuevo.minutos = t.minutos + segundos_en_tiempo.minutos;
	nuevo.segundos = t.segundos + segundos_en_tiempo.segundos;

	return nuevo;


}

void imprimeTiempo(Tiempo t)  {
	cout << "[" << t.horas << "h :" << t.minutos << "m :" << t.segundos << "s]" << endl;
}


int main() {
	Tiempo t_inicial={10, 30, 45}, t;
	int aux;

	cout << "Tiempo inicial: ";
	imprimeTiempo(t_inicial);
		
	cout << "Introduce HH MM SS" << endl;
	cin >> t.horas >> t.minutos >> t.segundos;
	aux = convertirASegundos(t);
	imprimeTiempo(t);	
	cout << "Equivalente a " << aux << " segundos" << endl;
	
	Tiempo taux = convertirATiempo(aux);
	cout << "A la inversa es ";
	imprimeTiempo(taux);	
	
	repararTiempo(t);
	cout << "Reparado es ";
	imprimeTiempo(t);	
	
	if (esPosterior(t_inicial, t)) 
		cout << "El tiempo inicial es más grande" << endl;
	else
		cout << "El tiempo inicial es más pequeño" << endl;	
		
	taux = incrementarTiempo(t,100);
	cout << "El tiempo inicial más 100 segundos es ";
	imprimeTiempo(taux);	
	
	return 0;
}

 
