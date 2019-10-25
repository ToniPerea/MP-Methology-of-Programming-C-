#ifndef __IMAGEN_H__
#define __IMAGEN_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

typedef int color;

/*! Clase Imagen */
class imagen{
private:

	int altura;								/*!< valor que representa la altura de la imagen */
	int anchura;							/*!< valor que representa la anchura de la imagen */
	unsigned short numeroComentarios;		/*!< valor que el número de comentarios(cada línea = un comentario) */
	string tipo;							/*!< valor que representa el tipo de archivo que es (P5 o P2) */
	int maxGrises;							/*!< valor que representa el valor máximo de grises  */
	vector <string> vComentarios;			/*!< vector de string que guarda los comentarios */
	color **matriz;							/*!< matriz de tipo color que almacena los valores(píxeles) de la imagen */
public:
	/**
       * Constructor por defecto ::
       * Inicializa filas y columnas, número de comentarios y el máximo de grises a 0.
       * Inicializa la matriz de píxeles nula, el vector de comentarios nulo y la cadena mágica de identificación del tipo de imagen a desconocido.
    */
	imagen();

	/**
       * Constructor por parámetros ::
       * Inicializa las filas y las columnas al mismo número de filas y columnas que se les pasa mediante argumentos.
	   * Reserva tantas filas y columnas en la matriz como se le indica.
	   * Mantiene el vector nulo, la cadena mágica de identificación del tipo de fichero a desconocido y el número de comentarios no lo modifica.
	   * @param filas número de filas a reservar
	   * @param columnas número de columnas a reservar
    */
	imagen(int filas, int columnas);

	/**
       * Constructor de copia ::
       * Inicializa filas y columnas, número de comentarios y el máximo de grises  a 0.
	   * Mantiene la matriz de píxeles nula y el vector también.
	   * @param original objeto imagen del cual se realizara la copia
    */
	imagen(const imagen &original);

	/**
       * Destructor ::
       * Se encargar de eliminar la memoria reservada de un objeto imagen. 
    */
	~imagen();

	/**
       * Constructor por parámetros ::
       * Inicializa un objeto de tipo imagen con los datos recibidos.
	   * @param otro Matriz que contienes los valores de los píxeles de la imagen.
	   * @param anchura Valor entero que guarda el valor de la anchura de la imagen.
	   * @param altura Valor entero que guarda el valor de la altura de la imagen.
	   * @param com Doble puntero que almacena los comentarios de la imagen.
	   * @param num_com Guarda el número de comentarios que hay.
	   * @param t Guarda el tipo de la imagen "P5" y "P2".
    */
	imagen(color** otro, int anchura,int altura, char** com, unsigned short num_com,string t);

	
	/**
       * Devuelve la altura del objeto imagen deseado.
    */
	int getAltura();
	
	/**
       * Devuelve la anchura del objeto imagen deseado.
    */
	int getAnchura();
	
	/**
       * Devuelve el número de comentarios del objeto imagen deseado.
    */
	unsigned short getNumeroComentarios();
	
	/**
       * Devuelve el número máximo de grises del objeto imagen deseado.
    */
	int getMaxGrises();
	
	/**
       * Devuelve los comentarios del objeto imagen deseado.
    */
	vector<string> getComentarios();
	
	/**
       * Devuelve la matriz del objeto imagen deseado.
    */
	color** getMatriz();
	
	/**
       * Devuelve el tipo(P5 o P2) del objeto imagen deseado.
    */
	string getTipo();

	
	/**
       * Modifica la altura del objeto imagen deseado. 
	   * @param a Es un entero que recibe la función y sustituirá a la altura de la imagen.
    */
	void setAltura(int a);
	
	/**
       * Modifica la anchura del objeto imagen deseado. 
	   * @param a Es un entero que recibe la función y sustituirá a la anchura de la imagen.
    */
	void setAnchura(int a);
	
	/**
       * Modifica el número de comentarios del objeto imagen deseado. 
	   * @param n Es un entero que recibe la función y sustituirá al número de comentarios de la imagen.
    */
	void setNumeroComentarios(unsigned short n);
	
	/**
       * Modifica el número máximo de grises  del objeto imagen deseado. 
	   * @param n Es un entero que recibe la función y sustituirá el número máximo de grises de la imagen.
    */
	void setMaxGrises(int n);
	
	/**
       * Modifica los comentarios del objeto imagen deseado. 
	   * @param otro Es un vector de string que recibe la función y sustituirá los comentarios de la imagen.
    */
	void setComentarios(vector <string> otro);
	
	/**
       * Modifica la matriz del objeto imagen deseado. 
	   * @param otro Valor tipo color con doble puntero recibe la función y sustituirá la matriz de la imagen.
    */
	void setMatriz(color** otro);
	
	/**
       * Modifica el tipo(P5 o P2) del objeto imagen deseado. 
	   * @param t Es un string que recibe la función y sustituirá el tipo de la imagen.
    */
	void setTipo(string t);

	
	/**
       * Sobrecarga del operador de asignación. 
	   * @param original Sobrecarga el operador de asignación para que se pueda usar entre objetos de tipo imagen.
    */
	imagen &operator=(const imagen &original);
	friend ostream &operator<<(ostream &os, const imagen &original);
	
	/**
       * Rellana todos los píxeles de una imagen del valor introducido. 
	   * @param c Es el valor del pixel por el que sustituirán todos los píxeles.
    */	void rellenar(color c);

	
	/**
       * Vuelca el contenido del nuestra a imagen en un archivo descrito por filename
	   * @param filename Es el nombre del archivo donde se volcarán los datos.
    */
	void guardarImagen(string filename);

	
	/**
       * Realiza una superposición de una imagen sobre otra
       * @param otra Es la imagen que se va a superponer
       * @param x Es un entero que indica la posicion en el eje de abcisas sobre el que se aplica la superposición
	   * @param y Es un entero que indica la posicion en el eje de ordenadas sobre el que se aplica la superposición
    */
	void collage(imagen otra, int x, int y);
	
	/**
       * Realiza un contraste en la imagen
       * @param max Es el máximo de contraste de la imagen.
       * @param min Es el máximo de contraste de la imagen.
    */
	void contraste(int max, int min);
	
	/**
       * Cambia los comentarios por el conjunto de comentarios recibidos en formato de vector
       * Se usará cuando se conozca a priori los comentarios.
       * @param nuevo Es el vector string que recibe con el comentario a sustituir.
    */
	void cambiarComentarios(vector<string> nuevo);
	
	/**
       * Cambia los comentarios por el comentario recibido
       * @param nuevo Es el string que recibe con el comentario a sustituir.
    */
	void cambiarComentarios(string nuevo);
};
















#endif