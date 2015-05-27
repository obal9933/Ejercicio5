//============================================================================
// Name        : Ejercicio6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "lectura.h"
#include "numericas.h"

typedef map<string, string, less<string> > mapa_acceso;

#include "funciones.h"

int main() {

	string clave, usuario;
	int entrada;

	mapa_acceso mapa_claves;

	do{
		cout << "-------Selecciona opción-------" << endl;
		cout << "1.- Introducir usuario y clave" << endl;
		cout << "2.- Eliminar usuario y clave" << endl;
		cout << "3.- Modificar claves" << endl;
		cout << "4.- Validar a un usuario si su clave es correcta" << endl;
		cout << "0.- Salir" << endl;
		entrada=leernumero("");

		switch (entrada){

		case 1:
			introducir_usuario(mapa_claves);
			cout << "usuario introducido con éxito" << endl;
			break;

		case 2:
			borrar_usuario(mapa_claves);

					break;

		case 3:

			modificar_contrasena(mapa_claves);

					break;

		case 4:
			validaraunusuario(mapa_claves);
					break;

		}

	}while(entrada!=0);

	return 0;
}
