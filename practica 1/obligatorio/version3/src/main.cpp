#include <iostream>
#include <cmath> 
#include "circulo.h"

using namespace std;

double distancia (Punto p1, Punto p2){
	double sol;
	sol = sqrt(pow(p1.getX()-p2.getX(), 2)+pow(p1.getY()-p2.getY(), 2));
	
	return sol;
}

Punto puntoMedio(Punto p1, Punto p2){
    Punto pMedio;
    pMedio.setX((p1.getX()+p2.getX())/2.0);
    pMedio.setY((p1.getY()+p2.getY())/2.0);
    return pMedio;
}

double distancia (Circulo c1, Circulo c2){
    Punto centro1, centro2;
    double dist;

    centro1=c1.getCentro();
    centro2=c2.getCentro();
    dist=distancia(centro1,centro2)-c1.getRadio()-c2.getRadio();
    return dist;
}

bool interior (Punto p, Circulo c){
	bool si = false;
	if(distancia(p,c.getCentro()) <= c.getRadio())
		si = true;
	
	return si;
}

int main(){
    Circulo c1,c2;

    cout << "Introduzca un circulo en formato radio-(x,y): ";
    c1.leer();
    c1.escribir();
    cout << "Introduzca otro circulo: ";
    c2.leer();
    c2.escribir();	

    Circulo res;

    res.set(puntoMedio(c1.getCentro(),c2.getCentro()),
                     distancia(c1.getCentro(),c2.getCentro())/2);
    cout << "La distancia entre los círculos es: " << distancia(c1,c2) << " y el círculo que pasa por los dos centros es: ";
    res.escribir();
    cout << endl;
    return 0;
}

