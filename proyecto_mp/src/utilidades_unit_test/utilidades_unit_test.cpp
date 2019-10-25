#include "imagen.h"
#include "utilidades.h"
#include <map>


// Galaxia
// leer_pgm("./data/galaxy.ascii.pgm", m, c,f,com,  num_com);
// imagen galaxia(m, c,f,com,  num_com);

// Baboon
// leer_pgm("./data/baboon.pgm", m, c,f,com,  num_com);
// imagen baboon(m, c,f,com,  num_com);

// Ballons
// leer_pgm("./data/balloons.ascii.pgm", m, c,f,com,  num_com);
// imagen ballons(m, c,f,com,  num_com);

// Plane
// leer_pgm("./data/plane.pgm", m, c,f,com,  num_com);
// imagen plane(m, c,f,com,  num_com);


// Moto
// leer_pgm("./data/moto.pgm", m, c,f,com,  num_com);
// imagen moto(m, c,f,com,  num_com);




int main(int argc, char **argv){
	unsigned int** m;
	int c, f;
	char** com;
    unsigned short num_com;
	string t;
	map<string,imagen> misImagenes;

	leer_pgm("./data/galaxy.ascii.pgm", m, c,f,com,  num_com,t);
	imagen galaxia(m, c,f,com,  num_com,t);

	leer_pgm("./data/baboon.pgm", m, c,f,com,  num_com,t);
	imagen baboon(m, c,f,com,  num_com,t);

	leer_pgm("./data/balloons.ascii.pgm", m, c,f,com,  num_com,t);
	imagen ballons(m, c,f,com,  num_com,t);

	leer_pgm("./data/plane.pgm", m, c,f,com,  num_com,t);
	imagen plane(m, c,f,com,  num_com,t);

	leer_pgm("./data/moto.pgm", m, c,f,com,  num_com,t);
	imagen moto(m, c,f,com,  num_com,t);


	// Metemos las imagenes en el MAP

	misImagenes.insert(std::pair<string,imagen>("galaxia",galaxia));
	misImagenes.insert(std::pair<string,imagen>("baboon",baboon));
	misImagenes.insert(std::pair<string,imagen>("ballons",ballons));
	misImagenes.insert(std::pair<string,imagen>("plane",plane));
	misImagenes.insert(std::pair<string,imagen>("moto",moto));

	misImagenes["ballons"].guardarImagen("./data/prueba/ballon.pgm");


	moto.contraste(2000, 0);
	moto.guardarImagen("./data/prueba/moto.pgm");


	//galaxia.guardarImagen("./data/prueba/galaxia.pgm");

	
	//baboon.guardarImagen("./data/prueba/baboon.pgm");

	//galaxia.collage(baboon, 800,50);
	//galaxia.guardarImagen("./data/prueba/galaxia.pgm");




}