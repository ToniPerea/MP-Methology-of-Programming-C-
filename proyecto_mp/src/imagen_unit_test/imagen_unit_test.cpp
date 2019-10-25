#include "imagen.h"
#include "utilidades.h"

int main(int argc, char **argv){
	imagen miImagen;
	cout << miImagen;
	miImagen.rellenar(155);
	cout << miImagen;
}