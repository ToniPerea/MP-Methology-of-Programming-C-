#include "imagen.h"
#include "utilidades.h"
#include <cstdlib>


static const string separador = "____________________________________________________________";

void mostrarMenu(vector<string> miMenu){
	cout << "Menu de opciones\n";
	for(int i = 0; i < miMenu.size(); i++){
		cout << "---> " <<  miMenu[i] << '\n';
	}
	cout << separador << '\n';
}



int main(int argc, char **argv){
	color ** m;
	int c, f;
	char** com;
    unsigned short num_com;
	string t;

	vector<string> menu;
	menu.push_back("Salir <exit>"); // opcion 0

	menu.push_back("Rellenar una imagen <rellenar> <data/imagen.pgm> <valor>");
	menu.push_back("Realizar un collage <collage> <data/imagen.pgm> <data/imagen.pgm> <x> <y>");
	menu.push_back("Cambiar el contraste <contraste> <data/imagen.pgm> <max> min>");
	menu.push_back("Cambiar comentarios <camb_coment> <comentarios>");


	// leer_pgm("/Users/antonioperea/Desktop/proyecto_mp/data/dog.pgm", m, c,f,com,  num_com,t);
	// imagen abc(m,c,f,com,num_com,t);
	// abc.guardarImagen("data/salidaPrimero.pgm");


	// leer_pgm("/Users/antonioperea/Desktop/proyecto_mp/data/galaxy.ascii.pgm", m, c,f,com,  num_com,t);
	// imagen dce(m,c,f,com,num_com,t);
	// dce.guardarImagen("data/salidaSegundo.pgm");


	// dce.collage(abc, -40,-40);
	// dce.guardarImagen("data/salidaCollagePrimeraSegunda.pgm");


	imagen miImagen;
	string lectura = "";
	mostrarMenu(menu);
	getline(cin, lectura);

	string comando = lectura.substr(0, lectura.find(" "));


	
	while(comando != "exit"){
		if(comando == "rellenar"){
			cout << "Rellenando\n";
			int posIni = lectura.find(" ");
			int posOtro = lectura.find(" ",posIni+1);
			string primero = lectura.substr(posIni+1, posOtro-posIni-1);
			posIni = lectura.find(" ",posOtro);
			string segundo = lectura.substr(posIni+1, lectura.size()-posIni-1);

			char* fichero = (char*) primero.c_str();
			leer_pgm(fichero, m, c,f,com,  num_com,t);
			imagen nueva(m, c,f,com,  num_com,t);
			
			int relleno = stoi(segundo);
			nueva.rellenar( (color) relleno );
			miImagen = nueva;
			miImagen.guardarImagen("data/salidaRellenar.pgm");
			
		}else if(comando == "collage"){
			cout << "Collage\n";

			int posIni = lectura.find(" ");
			int posOtro = lectura.find(" ",posIni+1);
			string primero = lectura.substr(posIni+1, posOtro-posIni-1);

			posIni = lectura.find(" ",posOtro);
			posOtro = lectura.find(" ",posIni+1);
			string segundo = lectura.substr(posIni+1, posOtro-posIni-1 );


			posIni = lectura.find(" ",posOtro);
			posOtro = lectura.find(" ",posIni+1);
			string tercero = lectura.substr(posIni+1, posOtro-posIni-1 );


			posIni = lectura.find(" ",posOtro);
			string cuarto = lectura.substr(posIni+1, lectura.size()-posIni-1);


			char* fichero1 = (char*) primero.c_str();
			char* fichero2 = (char*) segundo.c_str();
			
			int x =  stoi(tercero);
			int y =  stoi(cuarto);

			leer_pgm(fichero1, m, c,f,com,  num_com,t);
			imagen nueva(m, c,f,com,  num_com,t);

			leer_pgm(fichero2, m, c,f,com,  num_com,t);
			imagen otra(m, c,f,com,  num_com,t);

			nueva.collage(otra,x,y);

			miImagen = nueva;
			
			miImagen.guardarImagen("data/salidaCollage.pgm");

		}else if(comando == "contraste"){
			cout << "Contraste\n";

			int posIni = lectura.find(" ");
			int posOtro = lectura.find(" ",posIni+1);
			string primero = lectura.substr(posIni+1, posOtro-posIni-1);


			posIni = lectura.find(" ",posOtro);
			posOtro = lectura.find(" ",posIni+1);
			string tercero = lectura.substr(posIni+1, posOtro-posIni-1 );


			posIni = lectura.find(" ",posOtro);
			string cuarto = lectura.substr(posIni+1, lectura.size()-posIni-1);

			char* fichero1 = (char*) primero.c_str();


			int max =  stoi(tercero);
			int min =  stoi(cuarto);

			leer_pgm(fichero1, m, c,f,com,  num_com,t);
			imagen nueva(m, c,f,com,  num_com,t);
			nueva.contraste(max,min);
			miImagen = nueva;
			nueva.guardarImagen("data/salidaContraste.pgm");

		}else if(comando == "camb_coment"){
				// contraste data/dog.pgm 700 0 data/salida.pgm
				// camb_coment _nombre: Anda Paqui _apellidos: Adios Manuela _digo: Tania _antonio: cree que no funciona _yo: creo que si
			cout << "Cambiando comentarios\n";
			int posIni = lectura.find(" ");

			string primero = lectura.substr(posIni+1, lectura.size()-posIni-1);

			cout << "He entendido de comentario: "  << primero << endl;

			


			if(!miImagen.getMatriz()){
				cout << "No puedo cambiar los comentarios de una imagen que desconozco, por favor, lee una imagen antes\n";
			}else{
				miImagen.cambiarComentarios(primero);
				miImagen.guardarImagen("data/salidaCambiarcomentarios.pgm");
			}
		}else{
			cout << "Lo siento, no existe ese comando\n\n";
		}


		mostrarMenu(menu);
		getline(cin, lectura);
		comando = lectura.substr(0, lectura.find(" "));
	}


	// imagen miImagen;

	// cout << miImagen;

	// leer_pgm("./data/galaxy.ascii.pgm", m, c,f,com,  num_com);
	// imprimirImagen( m, c,f,com,  num_com);
	// salvar_pgm("./data/otro.pgm", m, c,f,com,  num_com);





}