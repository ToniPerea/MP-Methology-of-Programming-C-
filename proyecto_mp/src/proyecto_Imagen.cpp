#include <iostream>
#include <string>
#include <fstream>


using namespace std;

typedef unsigned char color;

namespace config{
    string P2 = "P2";
    string P5 = "P5";
}


int main(int argc, char* argv[]){
	string x;
	string filename;

	int filas, columnas, resolucion_maxima;
	color **matriz;

	if(argc < 2){
		cerr << "Error: ./executable <path to image>\n";
		exit(-1);
	}else{
		filename = argv[1];
		ifstream paqui(filename, ios::in);
		if(paqui.is_open()){
			cout << "Esta abierto\n\n";

			paqui >> x;
			
			if(x == config::P5 || x == config::P2){
				cout << "Estoy es un archivo PGM, asi que de puta madre.\n\n";
				string lectura;
				bool salir = false;
				int place = 0;

				while(!salir){
					place = paqui.tellg();
					paqui >> lectura;
					if(lectura[0] == '#'){
						getline(paqui, lectura);
					}else{
						salir = true;
					}
				}
				


				paqui.seekg(place);
				paqui >> filas;
				paqui >> columnas;

				matriz = new color*[filas];

				for(int i = 0; i < filas; i++){
					matriz[i] = new color[columnas];
				}

				paqui >> resolucion_maxima;

				for(int i = 0; i < filas; i++){
					for(int j = 0; j < columnas; j++){
						paqui >> matriz[i][j];
					}
				}

				for(int i = 0; i < filas; i++){
					for(int j = 0; j < columnas; j++){
						cout << matriz[i][j] << " ";
					}
					cout << "\n";
				}

			}else{
				cout << "Tu no me has pasado un PMG asi que vete.\n\n";
			}

		}

	}

	

	

}