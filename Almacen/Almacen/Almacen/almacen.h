#pragma once
#include <iostream>
#include "conexionBD.h"
#include <string>
using namespace std;
class almacen{
private:
	string nombreProducto, categoria;
	int id_producto;
	float precio;
	//constructor
public: 
	almacen() {}
	almacen(int id_p, string N_Producto, float pre, string cat) {
		id_producto = id_p ;
		nombreProducto = N_Producto;
		precio = pre;
		categoria = cat;
	}
	//metodos set (es para modificar un atributo)
	void setId_prodcto(int i) { id_producto = i; }
	void setNombre_producto(string n) { nombreProducto = n; }
	void setPrecio(float p) { precio = p; }
	void setCategoria(string cat) { categoria = cat; }
	//metodos get (muestra el contenido)
	int getId_prodcto() { return id_producto; }
	string getNombre_prodcto() { return nombreProducto; }
	float getPrecio() { return precio; }
	string getCategoria() { return categoria; }
	//---------------------querys--------------------------------
	//Read -- leer
	void leer() {
		int query_estado = 0;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConector()) {
			cout << "listado de proctos:" <<endl<<endl;
			string consulta = "SELECT * FROM productos;";
			const char* c = consulta.c_str();
			query_estado = mysql_query(cn.getConector(),c);
			if (!query_estado) {
				resultado = mysql_store_result(cn.getConector());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " <<endl;
					/*for (int i = 0; i < 5; i++) {
						cout << fila[i] << " | "<<endl;
					}*/
				}
			}
			else{
				cout << "***** La consulta no se pudo concretar!!! *****";
			}
		}
		else{
			cout << "***** Fallo la conexion con el servidor!!! *****";
		}
		cn.cerrar_conexion();
	}
	//Create -- crear
	void crear() {
		int query_estado = 0;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string pre = to_string(precio);
			string consulta = "INSERT INTO productos (nombreProducto, precio, categoria ) VALUES ('" + nombreProducto + "'," + pre + ",'" + categoria + "' );";
			const char* c = consulta.c_str();
			query_estado = mysql_query(cn.getConector(), c);
			if (!query_estado) {
				system("cls");
				cout << "Ingresos de datos exitoso." << endl;
			}
			else{
				cout << "***** Fallo al crear el nuevo producto!!! *****";
			}
		}
		else{
			cout << "****** Fallo la conexion con el servidor!!! *****";
		}
		cn.cerrar_conexion();
	}
	//Update --- actualizar
	void actualizar() {
		int query_estado = 0;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string pre = to_string(precio);
			string id_p = to_string(id_producto);
			string consulta = "UPDATE productos SET nombreProducto = '" + nombreProducto + "', precio = " + pre + ", categoria = '" + categoria + "' WHERE id_productos = " + id_p + "; ";
			const char* c = consulta.c_str();
			query_estado = mysql_query(cn.getConector(), c);
			if (!query_estado) {
				system("cls");
				cout << "La actualizacion de los datos fue exitoso" << endl;
			}
			else{
				cout << "Fallo la actualizacion" << endl;
			}
		}else{
			cout << "****** Fallo la conexion con el servidor!!! *****";
		}
	}
	//Delete -- borrar
	void borrar() {
		int query_estado = 0;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConector()){
			string id_p = to_string(id_producto);
			string consulta = "DELETE FROM productos WHERE id_productos = " + id_p + "";
			const char* c = consulta.c_str();
			query_estado = mysql_query(cn.getConector(), c);
			if (!query_estado) {
				system("cls");
				cout << "----- Datos eliminados exitosamente. -----"<<endl;
			}
			else {
				cout << "***** Error al eliminar. *****";
			}
		}else{
			cout << "****** Fallo la conexion con el servidor!!! *****";
		}
		
		cn.cerrar_conexion();
	}
};