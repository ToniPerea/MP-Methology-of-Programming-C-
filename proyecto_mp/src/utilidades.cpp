#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "utilidades.h"

using namespace std;

bool leer_pgm(char *name, color ** &m, int &c,int &f, char** &com, unsigned short &num_com, string &t){
	ifstream leer(name);
	string x;
	vector <string> temporal;
	

	if(leer.is_open()){
		string tipo = "a";
		leer >> tipo;
		t = tipo;

			
			if(tipo == "P5" || tipo == "P2" ){
				string lectura;
				bool salir = false;
				int place = 0;

				while(!salir){
					place = leer.tellg();
					leer >> lectura;
					if(lectura[0] == '#'){
						getline(leer, lectura);
						// com[num_com] = lectura;
						// num_com++;
						temporal.push_back(lectura);
					}else{
						salir = true;
					}
				}

				com = new char*[temporal.size()];
				for(int i = 0; i < temporal.size(); i++){
					com[i] = new char[temporal[i].size()];
				}

				num_com = (unsigned short) temporal.size();

				for(int i = 0; i < temporal.size(); i++){
					strcpy(com[i], temporal[i].c_str());
				}


				leer.seekg(place);
				leer >> f;
				leer >> c;

				m = new color*[f];

				for(int i = 0; i < f; i++){
					m[i] = new color[c];
				}

				leer >> x; // para saltarme los maxGrises
				char cc;


				if(tipo == "P5"){
					for(int i = 0; i < f; i++){
						for(int j = 0; j < c; j++){
							leer.get(cc);
							m[i][j] = cc;
						}
					}
				}else{
					//ifstream infile(argv[1]);
  					stringstream ss;
					ss << leer.rdbuf();
					for(int i = 0; i < f; i++){
						for(int j = 0; j < c; j++){
							ss >> m[i][j];
						}	
					}
    					
				}
				



				return true;


			}
		
	}else{
		cerr << "Estoy cerrado\n";
		
	}

	return false;
}



// Saca una imagen por la salida estanddar STDOUT
void imprimirImagen(color ** &m, int &c,int &f, char** &com, unsigned short &num_com){
	cout << "Filas: " << f << '\n';
	cout << "Columnas" << c << '\n';

	cout << "Numero de comentarios: " << num_com << '\n';
	for(int i = 0; i < num_com; i++){
		cout << com[i] << '\n';
	}

	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++){
			cout << m[i][j];
		}
	}

}

// Saca una imagen por la salida especificada (un archivo)
bool salvar_pgm(char *name, color ** m, int c, int f, char** com, unsigned short num_com,string t){
	ofstream salvar(name);
	if(salvar.is_open()){
		salvar << "P5" << '\n';

		for(int i = 0; i < num_com; i++){
			salvar << '#' << com[i] << '\n';
		}

		salvar << f << ' ' << c << '\n';

		salvar << 255 << '\n';

		if(t == "P5"){
			for(int i = 0; i < f; i++){
				for(int j = 0; j < c; j++){
					salvar << (unsigned char) m[i][j];
				}
			}
		}else if(t == "P2"){
			for(int i = 0; i < f; i++){
				for(int j = 0; j < c; j++){
					salvar << m[i][j] << ' ';
				}
				salvar << '\n';
			}
		}
		

		return true;
	}
	return false;
}