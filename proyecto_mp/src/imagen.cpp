#include "imagen.h"

imagen::imagen(){
	anchura = 0;
	altura = 0;
	tipo = "";
	numeroComentarios = 0;
	maxGrises = 0;
	matriz = NULL;
}

imagen::imagen(int filas,int columnas){
	altura = filas;
	anchura = columnas;
	tipo = "";
	matriz = new color*[altura];

	for(int i = 0; i < filas; i++){
		matriz[i] = new color[columnas];
	}
}

imagen::imagen(const imagen &original){
	altura = original.altura;
	anchura = original.anchura;
	numeroComentarios = original.numeroComentarios;
	maxGrises = original.maxGrises;
	vComentarios = original.vComentarios;
	tipo = original.tipo;

	if(!original.matriz){
		matriz = NULL;
	}else{
		matriz = new color*[altura];
		for(int i = 0; i < altura; i++){
			matriz[i] = new color[anchura];
			for(int j = 0; j < anchura; j++){
		       matriz[i][j] = original.matriz[i][j];
	        }
	    }
	}
}

imagen::~imagen(){
	for(int i = 0; i < altura; i++){
		delete[] matriz[i];
	}

	delete[] matriz;
}

int imagen::getAltura(){
	return altura;
}
int imagen::getAnchura(){
	return anchura;
}
unsigned short imagen::getNumeroComentarios(){
	return numeroComentarios;
}
int imagen::getMaxGrises(){
	return maxGrises;
}
vector<string> imagen::getComentarios(){
	return vComentarios;
}
color** imagen::getMatriz(){
	return matriz;
}

string imagen::getTipo(){
	return tipo;
}

void imagen::setAltura(int a){
	altura = a;
}
void imagen::setAnchura(int a){
	anchura = a;
}
void imagen::setNumeroComentarios(unsigned short n){
	numeroComentarios = n;
}
void imagen::setMaxGrises(int n){
	maxGrises = n;
}
void imagen::setComentarios(vector <string> otro){
	vComentarios = otro;
}
void imagen::setMatriz(color** otro){
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < anchura; j++){
			matriz[i][j] = otro[i][j];
		}
	}
}

void imagen::setTipo(string t){
	tipo = t;
}

imagen & imagen::operator=(const imagen &original){
	if(this != &original){
		altura = original.altura;
		anchura = original.anchura;
		numeroComentarios = original.numeroComentarios;
		maxGrises = original.maxGrises;
		vComentarios = original.vComentarios;
		tipo = original.tipo;

		if(!original.matriz){
			matriz = NULL;
		}else{
			matriz = new color*[altura];
			for(int i = 0; i < altura; i++){
				matriz[i] = new color[anchura];
				for(int j = 0; j < anchura; j++){
			       matriz[i][j] = original.matriz[i][j];
		        }
		    }
		}

	}

	return *this;
}

ostream & operator<<(ostream &os, const imagen &original){
	os << original.tipo << '\n';

	
	for(int i = 0; i < original.vComentarios.size(); i++){
		os << "# " << original.vComentarios[i] << "\n";
	}

	os << original.altura << ' ' <<original.anchura << '\n';
	os << original.maxGrises << '\n';

	cout << "Estoy guardando una imagen: " << original.tipo << endl;

	if(original.tipo == "P5"){
		for(int i = 0; i < original.altura; i++){
			for(int j = 0; j < original.anchura; j++){
				os << (unsigned char) original.matriz[i][j];
			}
		}
	}else if(original.tipo == "P2"){
		for(int i = 0; i < original.altura; i++){
			for(int j = 0; j < original.anchura; j++){
				os << (int) original.matriz[i][j] << ' ';
			}
			os << '\n';
		}
	}
	

	return os;
}

void imagen::rellenar(int c){
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < anchura; j++){
			matriz[i][j] = c;
		}
	}
}



imagen::imagen(color** otro, int anchura,int altura, char** com, unsigned short num_com, string t){
	this->altura = altura;
	this->anchura = anchura;

	this->maxGrises = 255;
	this->tipo = t;

	matriz = new color*[altura];
	for(int i = 0; i < altura; i++){
		matriz[i] = new color[anchura];
		for(int j = 0; j < anchura; j++){
			matriz[i][j] = otro[i][j];
		}
	}

	this->numeroComentarios = num_com;

	for(int i = 0; i < num_com; i++){
		vComentarios.push_back(com[i]);
	}

}

void imagen::guardarImagen(string filename){
	ofstream paqui(filename, ios::out);
	paqui << *this;
 	paqui.close();
}


void imagen::collage(imagen otra, int x, int y){


	int contFilas = 0;
		int contColumnas = 0;
		for(int i = 0; contFilas < otra.getAltura();i++){
			for(int j = 0;(contFilas < otra.getAltura() && contColumnas < otra.getAnchura()) ;j++){
				int nI = y + i;
				int nJ = x + j;
				if(nI > 0 && nI < getAltura() && nJ > 0 && nJ < getAnchura()){
					matriz[nI][nJ] = otra.getMatriz()[i][j];
					
				}
				contColumnas++;
			}
			contFilas++;
			contColumnas=0;
		}



}

void imagen::contraste(int max, int min){
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < anchura; j++){
			matriz[i][j] = min + (((max - min) / maxGrises) * matriz[i][j]);
		}
	}
}

void imagen::cambiarComentarios(vector<string> nuevo){
	numeroComentarios = nuevo.size();
	vComentarios = nuevo;
}


void imagen::cambiarComentarios(string nuevo){
	this->vComentarios.clear();
	numeroComentarios = 0;
	
	int i = nuevo.find("_");
	int j = 0;

	cout << "Empiezo" << endl;
	while(nuevo.find("_",i+1)){
		j = nuevo.find("_",i+1);

		string meter = nuevo.substr(i+1, j-2-i);

		vComentarios.push_back(meter);
		numeroComentarios++;
		
		i = j;
		
	}

}