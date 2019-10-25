/**
  * @file fruteria.cpp 
  * @brief Programa para la gestión de tickets de compra usando structs 
  * @author MP-GI - Grupo F
  *
  */
  
#include<iostream>
#include<string>

using namespace std;

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};

// Imprime un producto en pantalla
void imprimeProducto(Producto a)
{
    cout << a.nombre << "\t\t" << a.peso << "\t" << a.precio_kg;
}

// Crea un producto y lo inicializa con los parámetros que recibe
Producto creaProducto(string nombre, int peso, float precio)
{
    Producto nuevo;

    nuevo.nombre = nombre;
    nuevo.peso = peso;
    nuevo.precio_kg = precio;

    return nuevo;

}

// Incrementa el precio por kilo de los productos de una lista en k%
void incrementarPrecios(Compra & c, int k)
{
    for(int i = 0;i < c.MAX; i++)
        c.lista[i].precio_kg += (c.lista[i].precio_kg * k)/100;
}


// Muestra la lista de la compra
void imprimirCompra(const Compra & c)
{
    for(int i = 0;i < c.MAX; i++)
        cout << c.lista[i].nombre << "\t\t" << c.lista[i].peso << "\t" << c.lista[i].precio_kg << endl;
}



// Extrae el precio y el peso totales de una lista de la compra
void obtenerImporteYPeso(const Compra & c, float & precio, int & peso)
{
    for(int i = 0;i < c.MAX; i++)
    {
        precio += c.lista[i].precio_kg * c.lista[i].peso;
        peso += c.lista[i].peso;
    }

    precio = precio/1000;
    peso = peso/1000;
    
}

// Muestra la lista de la compra y el importe final desglosado en subtotal, IVA y total
void imprimirTicketCompra(const Compra & c)
{
    float subtotal;
    float subtotal_con_iva;
    float iva;

    for(int i = 0;i < c.MAX; i++)
        cout << c.lista[i].nombre << "\t\t" << c.lista[i].peso << "\t" << c.lista[i].precio_kg << endl;

    for(int i = 0;i < c.MAX; i++)
        subtotal += c.lista[i].precio_kg * c.lista[i].peso;

    subtotal = subtotal/1000;

    cout << "Subtotal:" << "\t\t" << subtotal << endl;

    iva = subtotal * 0.21;

    cout << "IVA (21%):" << "\t\t" << iva << endl;

    subtotal_con_iva= subtotal + iva;

    cout << "Total de la compra:" << "\t" << subtotal_con_iva << endl;
}


int main()
{
    const int TAM = 10;
    Producto actual;
    Compra mi_compra;
    float precio;
    int peso;
    string nombre;

    for(int i = 0; i < TAM; i++)
    {
        cin >> nombre >> peso >> precio;
        mi_compra.lista[i] = creaProducto(nombre, peso, precio);
    }

    // se muestra la lista de productos.
    cout << "\n ******** Prueba de funcion listarCompra ******** \n";
    imprimirCompra(mi_compra);

    // se muestra el importe total de la compra y el peso
    cout << "\n ******** Prueba de funcion obtenerImporteYPeso ******** \n";
    obtenerImporteYPeso(mi_compra, precio, peso);
    cout << "\nEl importe de la compra es: " << precio << ", su compra pesa:" 
		 << peso << " Kg. " << endl;

    // se muestra el ticket de la compra.
    cout << "\n ******** Prueba de la funcion mostrarTicketCompra ******** \n";
    imprimirTicketCompra(mi_compra);

    cout << "\n ******** Prueba de la funcion incrementarPrecio ********";
    incrementarPrecios(mi_compra, 10);
    cout << "\n ******** y listarCompra de nuevo   \t\t********\n\n";
    imprimirCompra(mi_compra);

    return(0);
}


 
