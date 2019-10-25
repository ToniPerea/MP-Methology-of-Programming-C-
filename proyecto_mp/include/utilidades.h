#ifndef __UTILIDADES_H__
#define __UTILIDADES_H__

#include <iostream>
#include <fstream>

using namespace std;

typedef int color;

bool leer_pgm(char *name, color ** &m, int &c,int &f, char** &com, unsigned short &num_com,string & t);
bool salvar_pgm(char *name, color ** m, int c, int f, char** com, unsigned short num_com);



void imprimirImagen(color ** &m, int &c,int &f, char** &com, unsigned short &num_com,string t);




#endif