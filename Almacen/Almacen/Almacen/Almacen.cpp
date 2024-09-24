#include <iostream>
#include <stdio.h>
#include <stdlib.h> //libreria necesaria para hacer la opcion de cerrar
#include "config.h"
#include "conexionBD.h"
#include "almacen.h"
#include <Windows.h>
using namespace std;
void crear();
int categoria_menu();
bool validarRespuesta(string repuesta);
void menu();
void gotoxy(int , int );
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void opciones() {
	system("cls");
	int opcion = 0;
	string op = "si";
	cout << "¿Que quieres hacer ahora?" << endl;
	cout << "1. Regresar al menu principal. " << endl;
	cout << "2. Cerrar programa. " << endl;
	cin >> opcion;
	do{
		switch (opcion) {
		case 1:
			menu();
			break;
		case 2:
			cout << "¿Seguro deseas salir?" << endl;
			cout << "1. si" << endl;
			cout << "2. no" << endl;
			cin >> opcion;
			if (opcion == 1) {
				cout << "Se ha cerrado el programa...";
				exit(0);
			}else{
				menu();
			}
			break;
		default:
			cout << "Opcion invalida";
			break;
		}
	} while (true);
	
}

/*Lee la db*/
void leer() {
	system("cls");
	string nombreProducto, categoria;
	int id_producto = 0, n = 0;
	float precio = 0;
	almacen a = almacen(id_producto, nombreProducto, precio, categoria);
	a.leer();
	system("pause");
	system("cls");
}
/*Agrega a la db*/
void crear() {
	system("cls");
	string nombreProducto, categoria, repuesta, opcion = "si";
	int id_producto = 0, n = 0;
	float precio = 0;
	// Llamar al menú de categorías
	cout << "----- Elejiste la opcion de agregar un producto. -----" << endl;
	n = categoria_menu();
	// Validar la selección de categoría
	switch (n) {
	case 1:
		cout << "Seleccionaste 'Bebida'" << endl;
		categoria = "Bebida";
		break;
	case 2:
		cout << "Seleccionaste 'Lacteo'" << endl;
		categoria = "Lacteo";
		break;
	case 3:
		cout << "Seleccionaste 'Panificacion'" << endl;
		categoria = "Panificacion";
		break;
	default:
		cout << "Opción inválida. Debes ingresar un número entre 1 y 3." << endl;
		crear();  // Volver a ejecutar en caso de error
		return;
	}
	// Capturar el nombre del producto
	system("cls");
	cin.ignore();  // Limpiar buffer
	cout << "La categoria del será: " << categoria << endl;
	cout << "Ingresa el nombre del producto: ";
	getline(cin, nombreProducto);
	// Capturar el precio del producto
	cout << "Ingresa el precio del producto: $";
	cin >> precio;
	if (cin.fail()) {
		cin.clear();  // Limpiar el estado de error
		cin.ignore(1000, '\n');  // Limpiar el buffer
		cout << "Precio inválido. Debes ingresar un número." << endl;
		system("pause");
		crear();  // Volver a ejecutar en caso de error
		return;
	}
	// Mostrar los datos agregados
	cout << endl << "Los datos agregados fueron:" << endl;
	cout << nombreProducto << " | $" << precio << " | " << categoria << endl;
	// Validar si los datos ingresados son correctos
	cout << "¿Son correctos los datos ingresados? (si/no): ";
	cin >> repuesta;
	if (validarRespuesta(repuesta)) {
		// Crear el objeto almacen y guardar el producto
		almacen a(id_producto, nombreProducto, precio, categoria);
		a.crear();
	}
	else {
		cout << "Por favor ingresa nuevamente los datos." << endl;
		crear();  // Volver a ejecutar
	}
}
// Función que presenta el menú de categorías
int categoria_menu() {
	int n = 0;
	cout << "Elige la categoría del producto" << endl;
	cout << "1. Bebida" << endl;
	cout << "2. Lacteo" << endl;
	cout << "3. Panificación" << endl;
	cin >> n;
	// Validación del número ingresado
	if (cin.fail() || (n < 1 || n > 3)) {
		cin.clear();  // Limpiar el estado de error
		cin.ignore(1000, '\n');  // Limpiar el buffer
		cout << "Opción inválida. Debes ingresar un número entre 1 y 3." << endl;
		return categoria_menu();  // Volver a solicitar la categoría
	}
	return n;
}
// Función para validar si la respuesta es afirmativa
bool validarRespuesta(string repuesta) {
	// Convertir a minúsculas para comparar fácilmente
	for (auto& c : repuesta) c = tolower(c);

	return (repuesta == "si");
}
/*
void crea(){
	system("cls");
	string nombreProducto, categoria,repuesta, opcion = "si";
	int id_producto = 0, n = 0;
	float precio = 0;
	cin.ignore();
	cout << "----- Elejiste la opcion de agregar un producto. -----" << endl;
	cout << "Ingresa el nombre del prodcuto: ";
	getline(cin, nombreProducto);
	cout << "ingresa el precio del producto: $";
	cin >> precio;
	cout << "Por ultimo ingresa su categoria:";
	cin >> categoria;
	cout << endl << "Los datos agregados fueron: " << endl;
	cout << nombreProducto << " | $" << precio << " | " << categoria << endl;
	cout << "Son correctos los datos ingresados? si o no? ";
	cin >> repuesta;
	if (repuesta == opcion) {
		almacen a = almacen(id_producto, nombreProducto, precio, categoria);
		a.crear();
	}else {
		cout << "ingresa nuevamente los datos"; 
		crear();
	}
}
*/

/*Actualiza un dato de la db*/
void actualizar() {
	system("cls");
	string nombreProducto, categoria, repuesta, opcion = "si";
	int id_producto = 0, n = 0;
	float precio = 0;
	almacen a = almacen(id_producto, nombreProducto, precio, categoria);
	a.leer();
	cout << "'\n' Que producto deseas actualizar? " <<endl;
	cout << "Indique la ID del prodcuto: ";
	cin >> id_producto;
	cin.ignore();
	// Validar la entrada de id_producto
	if (cin.fail() || id_producto <= 0) {
		cin.clear();  // Limpiar el estado de error
		cin.ignore(1000, '\n');  // Limpiar el buffer
		cout << "***** ID inválido. Inténtalo nuevamente. *****" << endl;
		return;  // Salir de la función
	}
	cout << "Indique el nuevo nombre: ";
	getline(cin, nombreProducto);
	cout << "Indique el precio: $";
	cin >> precio;
	n = categoria_menu();
	// Validar la selección de categoría
	switch (n) {
	case 1:
		categoria = "Bebida";
		break;
	case 2:
		categoria = "Lacteo";
		break;
	case 3:
		categoria = "Panificacion";
		break;
	default:
		cout << "Opción inválida. Debes ingresar un número entre 1 y 3." << endl;
		crear();  // Volver a ejecutar en caso de error
		return;
	}
	a.setId_prodcto(id_producto);
	a.setNombre_producto(nombreProducto);
	a.setPrecio(precio);
	a.setCategoria(categoria);
	a.actualizar();
}
/*Elimna el producto seleccionado*/
void eliminar() {
	system("cls");
	string nombreProducto, categoria, repuesta, opcion = "si";
	int id_producto = 0, n = 0;
	float precio = 0;
	almacen a = almacen(id_producto, nombreProducto, precio, categoria);
	cout << "que producto deseas eliminar? ";
	a.leer();
	cout << "Introdusca el Id del producto que quiere eliminar. :";
	cin >> n;
	a.setId_prodcto(n);
	a.borrar();
}	
/*Funcion del menu*/
void menu() {
	system("cls");
	string nombreProducto, categoria;
	int id_producto = 0, n = 0;
	float precio = 0;
	almacen a = almacen(id_producto, nombreProducto, precio, categoria);
	int opcion = 0;
	do {
		cout << "--------------------" << "Menu" << "--------------------" << endl;
		cout << "************************************" << endl;
		cout << "--- Elija una opcion ---" << endl;
		cout << "1. Ver lista de productos" << endl;
		cout << "2. Agregar un producto" << endl;
		cout << "3. Editar un producto" << endl;
		cout << "4. Eliminar un producto" << endl;
		cout << "5. Cerrar el programa" << endl;
		cin >> opcion;
		switch (opcion) {
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
		case 4: 
			eliminar();
			system("pause");
			break;
		case 5: opciones();
			break;
		default:
			cout << "usted selecciono una opcion incorrecta!";
			break;
		}
	} while (opcion != 0);
}
int main(){
	setlocale(LC_ALL, "");//Puede acceptar los acentos y mostrar los acentos 
	system("COLOR B0");
	cout <<endl << endl<< "          =========================================================================================\n"  << endl;
	cout << "               ___________              AAAAA   L       M     M   AAAAA    CCCCC  EEEEE  N   N  \n";
	cout << "              /          /|            A     A  L       MM   MM  A     A  C       E      NN  N  \n";
	cout << "             /__________/ |            AAAAAAA  L       M M M M  AAAAAAA  C       EEEEE  N N N  \n";
	cout << "             |          | |            A     A  L       M  M  M  A     A  C       E      N  NN  \n";
	cout << "             |  [__]    | |            A     A  LLLLLL  M     M  A     A   CCCCC  EEEEE  N   N  \n";
	cout << "             |__________|/  \n";

	cout << "\n                           Bienvenido al sistema de gestor de productos!\n";
	cout << "          =========================================================================================\n"<<endl<<endl<<endl<<endl<<endl;
	system("pause");
	menu();
	
}