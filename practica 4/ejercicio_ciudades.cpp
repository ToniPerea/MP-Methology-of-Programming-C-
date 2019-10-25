//
//Antonio Carlos Perea Parras
//
//
//El ejercicio no esta completado al 100%
//
#include <iostream>
#include <fstream>

using namespace std;

struct InfoCiudad {
      char * nombre;            // Nombre
      int poblacion;            // Numero habitantes
};

class RedCiudades {
   private:
      int num_ciudades;         // Numero de ciudades
      InfoCiudad * info;        // info[i]: info de la ciudad i
      double ** distancia;      // distancia entre i y j

   public:

   	RedCiudades(){
   		num_ciudades = 0;
   		info = NULL;
   		distancia = NULL;
   	}

   	~RedCiudades(){
   		delete[] info;
   		
   		for(int i = 0; i < num_ciudades; i++){
			delete[] distancia[i];
		}

		delete[] distancia;
		distancia = NULL;
		info = NULL;
		num_ciudades = 0;
	}
   	
   	bool EstoyVacia(){
   		bool vacio = false;

   		if(info == NULL && distancia == NULL && num_ciudades == 0){
   			vacio = true;
   		}

   		return vacio;
   	}

   	RedCiudades(const RedCiudades &original){
   		num_ciudades = original.num_ciudades;

   		for(int i = 0; i < num_ciudades; i++){
   			info[i] = original.info[i];
   		}

   		for(int i = 0; i < num_ciudades; i++){
			for(int j = 0; j < num_ciudades; j++){
				distancia[i][j] = distancia[i][j];
			}
		}

   	}

   	RedCiudades &operator=(const RedCiudades &orig){
		if(this != &orig){
			delete[] info;
   		
   			for(int i = 0; i < num_ciudades; i++){
				delete[] distancia[i];
			}

			delete[] distancia;
			distancia = NULL;
			info = NULL;
			num_ciudades = 0;

			num_ciudades = orig.num_ciudades;
			info = new InfoCiudad[num_ciudades];

			for(int i = 0; i < num_ciudades; i++){
				info[i] = orig.info[i];
			}

			for(int i = 0; i < num_ciudades; i++){
				for(int j = 0; j < num_ciudades; j++){
					distancia[i][j] = orig.distancia[i][j];
				}	
			}


			
		}

		return *this;

	}


   	int NumCiudades(){
   		return num_ciudades;
   	}

   	double Distancia(int ciudad1, int ciudad2){ 
   		return distancia[ciudad1][ciudad2];
   	}

	char * NombreCiudad(int ciudad){
		return info[ciudad].nombre;
	}

    int PoblacionCiudad(int ciudad){
    	return info[ciudad].poblacion;
    }

	int CiudadMejorConectada(){
		int *contador = new int[num_ciudades];

		for(int i = 0; i < num_ciudades; i++){
			contador[i] = 0;
		}

		for(int i = 0; i < num_ciudades; i++){
			for(int j = 0; j < num_ciudades; j++){
				if(distancia[i][j] != 0 ){
					contador[i]++;
				}
			}

		}

		int max = 0;

		for(int i = 0; i < num_ciudades; i++){
			if(contador[i] > max){
				max = contador[i];
			}
		}


		return max;
	}



	friend ostream &operator<<(ostream &flujo,const RedCiudades &ciudad);

	friend istream &operator>>(istream &flujo,const RedCiudades &ciudad);




                               
};

ostream &operator<<(ostream &flujo,const RedCiudades &ciudad){
	flujo << ciudad.num_ciudades << "\n";

	for(int i = 0; i < ciudad.num_ciudades; i++){
		flujo << i << " " << ciudad.info[i].nombre << " " << ciudad.info[i].poblacion << "\n";
	}

	for(int i = 0; i < ciudad.num_ciudades; i++){
		for(int j = 0; j < ciudad.num_ciudades; j++){
			flujo << i << " " << j << " " << ciudad.distancia[i][j] << "\n";
		}
	}

	return flujo;
}

istream &operator>>(istream &flujo,RedCiudades &ciudad){
	flujo >> ciudad.num_ciudades;

   	ciudad.info = new InfoCiudad[ciudad.num_ciudades];

	for(int i = 0; i < ciudad.num_ciudades; i++){
		flujo >> i;   
		flujo >> ciudad.info[i].nombre;
		flujo >> ciudad.info[i].poblacion;
	}

	ciudad.distancia = new double*[ciudad.num_ciudades];

	for(int i = 0; i < ciudad.num_ciudades; i++){
		ciudad.distancia[i] = new double[ciudad.num_ciudades];
	}

	for(int i = 0; i < ciudad.num_ciudades; i++){
		for(int j = 0; j < ciudad.num_ciudades; j++){
			flujo >> i;
			flujo >> j;
			flujo >> ciudad.distancia[i][j];
		}
	}

	return flujo;
}
}



int main(){

}