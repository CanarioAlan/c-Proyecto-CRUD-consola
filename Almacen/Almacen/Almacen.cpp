#include <iostream>
#include <stdlib.h> //libreria necesaria para hacer la opcion de cerrar
#include <stdio.h>
#include "config.h"
#include "conexionBD.h"
#include "almacen.h"
using namespace std;
void leer() {
	system("cls");
	string nombreProducto, categoria;
	int id_producto = 0, n = 0;
	float precio = 0;
	almacen a = almacen(id_producto, nombreProducto, precio, categoria);
	a.leer();
	cout <<endl<< "--- Que quieres hacer? ---"<<endl;
	cout << "1. Regresar al menu principal." <<endl;
	cout << "2. Cerrar el programa. "<<endl;
	cin >> n;
	switch (n){
	case 1: //main(); //buscar como ir al mein de vuelta
		break;
	case 2: abort; // cierra el programa
	default:
		cout << "***** La opcion ingresada fue incorrecta!!! ****"<<endl;
		break;
	}
}
void crear(){
	system("cls");
	string nombreProducto, categoria,repuesta, opcion = "si";
	int id_producto = 0, n = 0;
	float precio = 0;
	cin.ignore();
	cout << "----- Elejiste la opcion de agregar un producto. -----" << endl;
	cout << "Ingresa el nombre del prodcuto: ";
	getline(cin, nombreProducto);
	cout << "ingresa el precio del producto: ";
	cin >> precio;
	cout << "Por ultimo ingresa su categoria:";
	cin >> categoria;
	cout << endl << "Los datos agregados fueron: " << endl;
	cout << nombreProducto << " | " << precio << " | " << categoria << endl;
	cout << "Son correctos los datos ingresados? si o no? ";
	cin >> repuesta;
	if (repuesta == opcion) {
		almacen a = almacen(id_producto, nombreProducto, precio, categoria);
		a.crear();
		cout << "que quieres hacer? " << endl;
		cout << "Que quieres hacer? " << endl;
		cout << "1. Regresar al menu principal." << endl;
		cout << "2. Cerrar el programa. " << endl;
		cin >> n;
		switch (n) {
		case 1: //main(); //buscar como ir al mein de vuelta
			break;
		case 2: abort; // cierra el programa
		default:
			cout << "***** La opcion ingresada fue incorrecta!!! ****" << endl;
			break;
		}
	}else {
		cout << "ingresa nuevamente los datos"; 
		crear();
	}
}
void actualizar() {
	system("cls");
	string nombreProducto, categoria, repuesta, opcion = "si";
	int id_producto = 0, n = 0;
	float precio = 0;
	cin.ignore();

}
int main(){
	string nombreProducto, categoria;
	int id_producto = 0, n = 0;
	float precio = 0;
	almacen a = almacen(id_producto, nombreProducto, precio, categoria);
	//a.leer();
	cout << "--- Elija una opcion ---"<<endl;
	cout << "1. Ver lista de productos" << endl;
	cout << "2. Agregar un producto" << endl;
	cout << "3. editar un producto" << endl;
	cout << "4. Eliminar un producto" << endl;
	cout << "5. Cerrar el programa" << endl;
	cin >> n;
	switch (n){
	case 1: 
		leer();
		system("pause");
		break;
	case 2: 
		crear();
		system("pause");
		break;
	case 3: 
		actualizar();
		system("pause");
		break;
	case 4: cout<<"Esta opcion no esta disponible aun.";
		break;
	default:
		cout << "usted selecciono una opcion incorrecta!";
		break;
	}
}