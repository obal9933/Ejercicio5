//============================================================================
// Name        : EJERCICIO5.cpp
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
#include "alumno.h"

//definicion mapa
typedef multimap<int, int, less<int> > mapa;

#define DIM 100

#include "funciones.h"

int main() {

int entrada;

alumno lista[DIM];

	llenarvector(lista);

	mapa nota1;
	mapa nota2;
	mapa nota3;

	llenarmapa(nota1,lista,1);
	llenarmapa(nota2,lista,2);
	llenarmapa(nota3,lista,3);

	do{


	cout << "----------Introduce opción----------" << endl;
	cout << "1.- Ordenado 1 nota" << endl;
	cout << "2.- Ordenado 2 nota" << endl;
	cout << "3.- Ordenado 3 nota" << endl;

	cout << "0.- Salir" << endl;

		entrada=leernumero("");

		switch (entrada){

		case 1:
			mostrarmapa(nota1, lista);
			break;

		case 2:
				mostrarmapa(nota2, lista);
				break;

		case 3:
				mostrarmapa(nota3, lista);
				break;
		}

	}while(entrada!=0);

	return 0;
}
