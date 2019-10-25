#include "imagen.h"
#include "utilidades.h"

int main(int argc, char **argv){
	unsigned char** m;
	int c, f;
	char** com;
    unsigned short num_com;


	imagen miImagen;

	cout << miImagen;

	leer_pgm("./data/galaxy.ascii.pgm", m, c,f,com,  num_com);

	imprimirImagen( m, c,f,com,  num_com);

	salvar_pgm("./data/otro.pgm", m, c,f,com,  num_com);



}