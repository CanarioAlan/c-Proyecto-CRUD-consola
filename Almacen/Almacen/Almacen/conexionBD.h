#pragma once //reconoce que es una clase 
#include <mysql.h> //libreria mysql
#include <iostream> 
using namespace std;
class conexionBD{
private: MYSQL* cn; //controla la conexion
public:
	void abrir_conexion() { //abre la conexion
		cn = mysql_init(0); // el iniciador de la conexion
		cn = mysql_real_connect(cn, "localhost", "root", "9056", "almacen", 3306, NULL, 0);
	}
	MYSQL* getConector() { //usa el get para dar el retorno de estado de la conexion si es 0 esta conectado si es distinto fallo conexion
		return cn;
	}
	void cerrar_conexion() { //cierra la conexion como buena practica.
		mysql_close(cn);
	}
};

