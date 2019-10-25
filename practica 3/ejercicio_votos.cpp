//
//Nombre: Antonio Carlos Perea Parras
//
//DNI: 45944310Q
//
//
//
#include <iostream>

using namespace std;

struct Partido{
	string nombre_partido;
	int votos;
};

struct Provincia{
	string nombre_provincia;
	int escanios;
	int censo;
	int numero_partidos;
	int votos_nulos;
	int votos_blancos;
	Partido *partidos;
	int votos_totales;
	int porcentaje_votos_emitidos;
	int porcentaje_votos_abstencion;
	int porcentaje_votos_nulos;
	int porcentaje_votos_blancos;

};


struct Eleccion{
	string nombre;
	Provincia *provincias;
	int escanios;
	int numero_provincias;
};


int main(){
	Eleccion eleccion_costa;
	int votos_globales = 0;
	int votos_nulos_globales = 0;
	int votos_blancos_globales = 0;
	int porcentaje_de_votos_emitidos = 0;
	int poblacion_de_todas_las_provincias = 0;
	int porcentaje_de_abstencion_global = 0;
	int porcentaje_de_votos_nulos_global = 0;
	int porcentaje_de_votos_blancos_global = 0;
	int votos_totales_PP = 0;
	int votos_totales_PSOE = 0;
	int votos_totales_IU = 0;
	int porcentaje_votos_totales_PP = 0;
	int porcentaje_votos_totales_PSOE = 0;
	int porcentaje_votos_totales_IU = 0;

	for(int i = 0; i < eleccion_costa.numero_provincias; i++){
		eleccion_costa.provincias[i].votos_totales = 0;
		eleccion_costa.provincias[i].porcentaje_votos_emitidos = 0;
		eleccion_costa.provincias[i].porcentaje_votos_abstencion = 0;
		eleccion_costa.provincias[i].porcentaje_votos_nulos = 0;
		eleccion_costa.provincias[i].porcentaje_votos_blancos = 0;
	}
	

	cin >> eleccion_costa.nombre;

	cin >> eleccion_costa.numero_provincias;

	cin >> eleccion_costa.escanios;

	eleccion_costa.provincias = new Provincia[eleccion_costa.numero_provincias];

	// VAMOS A GUARDAR LOS DATOS

	for(int i = 0; i < eleccion_costa.numero_provincias; i++){
		cin >> eleccion_costa.provincias[i].nombre_provincia;
		cin >> eleccion_costa.provincias[i].escanios;
		cin >> eleccion_costa.provincias[i].censo;
		cin >> eleccion_costa.provincias[i].numero_partidos;

		eleccion_costa.provincias[i].partidos = new Partido[eleccion_costa.provincias[i].numero_partidos];

		for(int j = 0; j < eleccion_costa.provincias[i].numero_partidos; j++){
			cin >> eleccion_costa.provincias[i].partidos[j].nombre_partido;
			cin >> eleccion_costa.provincias[i].partidos[j].votos;
		}
		cin >> eleccion_costa.provincias[i].votos_nulos;
		cin >> eleccion_costa.provincias[i].votos_blancos;

	}

	//VAMOS A TRABAJAR CON LOS DATOS GLOBALES

	//VAMOS A CONTAR LOS VOTOS DE TODAS LA PROVINCIAS INCLUYENDO NULOS Y BLANCOS Y PORCENTAJE DE VOTOS DE TODO TIPO

	for(int i = 0; i < eleccion_costa.numero_provincias; i++){
		poblacion_de_todas_las_provincias += eleccion_costa.provincias[i].censo;
		for(int j = 0; j < eleccion_costa.provincias[i].numero_partidos; j++){
			votos_globales += eleccion_costa.provincias[i].partidos[j].votos;
		}

		votos_globales += eleccion_costa.provincias[i].votos_nulos;
		votos_globales += eleccion_costa.provincias[i].votos_blancos;
		votos_nulos_globales += eleccion_costa.provincias[i].votos_nulos;
		votos_blancos_globales += eleccion_costa.provincias[i].votos_blancos;
	}

	porcentaje_de_votos_emitidos = (votos_globales * 100) / poblacion_de_todas_las_provincias;
	porcentaje_de_abstencion_global = 100 - porcentaje_de_votos_emitidos;
	porcentaje_de_votos_nulos_global = (votos_nulos_globales * 100) / votos_globales;
	porcentaje_de_votos_blancos_global = (votos_blancos_globales * 100) / votos_globales;

	cout << endl << "############# DATOS GLOBALES #############" << endl;
	cout << "Total de Votantes y votos emitidos: " << votos_globales << endl;
	cout << "Porcentaje de participacion global: " << porcentaje_de_votos_emitidos << endl;
	cout << "Porcentaje de abstencion: " << porcentaje_de_abstencion_global << endl;
	cout << "Porcentaje de votos nulos " << porcentaje_de_votos_nulos_global << endl;
	cout << "Porcentaje de votos en blanco: " << porcentaje_de_votos_blancos_global << endl << endl;


	//DATOS REFERENTES A PROVINCIAS

	//INFORMACION GENERAL

	for(int i = 0; i < eleccion_costa.numero_provincias; i++){
		for(int j = 0; j < eleccion_costa.provincias[i].numero_partidos; j++){
			eleccion_costa.provincias[i].votos_totales += eleccion_costa.provincias[i].partidos[j].votos;
		}

		eleccion_costa.provincias[i].votos_totales += eleccion_costa.provincias[i].votos_nulos;
		eleccion_costa.provincias[i].votos_totales += eleccion_costa.provincias[i].votos_blancos;

		eleccion_costa.provincias[i].porcentaje_votos_emitidos = (eleccion_costa.provincias[i].votos_totales * 100) / eleccion_costa.provincias[i].censo;
		eleccion_costa.provincias[i].porcentaje_votos_abstencion = 100 - eleccion_costa.provincias[i].porcentaje_votos_emitidos;
		eleccion_costa.provincias[i].porcentaje_votos_nulos = (eleccion_costa.provincias[i].votos_nulos * 100) / eleccion_costa.provincias[i].votos_totales;
		eleccion_costa.provincias[i].porcentaje_votos_blancos = (eleccion_costa.provincias[i].votos_blancos * 100) / eleccion_costa.provincias[i].votos_totales;


		cout << "############# " << eleccion_costa.provincias[i].nombre_provincia << " #############" << endl;
		cout << "Total de Votantes y votos emitidos: " << eleccion_costa.provincias[i].votos_totales << endl;
		cout << "Porcentaje de participacion de la provincia: " << eleccion_costa.provincias[i].porcentaje_votos_emitidos << endl;
		cout << "Porcentaje de abstencion: " << eleccion_costa.provincias[i].porcentaje_votos_abstencion << endl;
		cout << "Porcentaje de votos nulos " << eleccion_costa.provincias[i].porcentaje_votos_nulos << endl;
		cout << "Porcentaje de votos en blanco: " << eleccion_costa.provincias[i].porcentaje_votos_blancos << endl << endl;



		
	}


	//DATOS DE LOS PARTIDOS POLITICOS( ESTE NO ENTENDIA MUY BIEN LO QUE PEDIA)

	for(int i = 0; i < eleccion_costa.numero_provincias; i++){
		for(int j = 0; j < eleccion_costa.provincias[i].numero_partidos; j++){
			if(eleccion_costa.provincias[i].partidos[j].nombre_partido == "PP"){
				votos_totales_PP += eleccion_costa.provincias[i].partidos[j].votos;

			}else if(eleccion_costa.provincias[i].partidos[j].nombre_partido == "PSOE"){
				votos_totales_PSOE += eleccion_costa.provincias[i].partidos[j].votos;

			}else if(eleccion_costa.provincias[i].partidos[j].nombre_partido == "IU"){
				votos_totales_IU += eleccion_costa.provincias[i].partidos[j].votos;
			}
		}	

		
	}

	porcentaje_votos_totales_PP = (votos_totales_PP * 100) / votos_globales;
	porcentaje_votos_totales_PSOE = (votos_totales_PSOE * 100) / votos_globales;
	porcentaje_votos_totales_IU = (votos_totales_IU * 100) / votos_globales;

	cout << "############# PP #############" << endl;
	cout << "Total de Votos: " << votos_totales_PP << endl;
	cout << "Porcentaje de Votos: " << porcentaje_votos_totales_PP << endl << endl;

	cout << "############# PSOE #############" << endl;
	cout << "Total de Votos: " << votos_totales_PSOE << endl;
	cout << "Porcentaje de Votos: " << porcentaje_votos_totales_PSOE << endl << endl;

	cout << "############# IU #############" << endl;
	cout << "Total de Votos: " << votos_totales_IU << endl;
	cout << "Porcentaje de Votos: " << porcentaje_votos_totales_IU << endl << endl;

	cout << "############# VOTOS NULOS TOTALES #############" << endl;
	cout << "Total: " << votos_nulos_globales << endl << endl;

	cout << "############# VOTOS BLANCOS TOTALES #############" << endl;
	cout << "Total: " << votos_blancos_globales << endl << endl;





	for(int i = 0; i < eleccion_costa.numero_provincias; i++){
			delete[] eleccion_costa.provincias[i].partidos;
		
	}

	delete[] eleccion_costa.provincias;





}