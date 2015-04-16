//============================================================================
// Name        : C++Ejercicio2.cpp
// Author      : Mario Cristóbal Arenzana
//============================================================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

#include <string>
#include <iostream>
#include <map>

#include "lectura.h"
#include "numericas.h"

#include "persona.h"

//tipo clave
typedef unsigned int clave;

//definición del tipo mapa
typedef map<clave, persona, less<int> > mapa;

#include "funciones.h"


int main() {

	clave key;

  mapa lista;

  	 mapa_vacio(lista);

  mapa::iterator i;

int entrada;

do{
cout << "----------Introduce opción----------" << endl;
cout << "1.- Introducir persona" << endl;
cout << "2.- Borrar clave " << endl;
cout << "3.- Borrado completo de la lista (sin liberar)" << endl;
cout << "4.- Mostrar datos asociados a una clave" << endl;
cout << "0.- Salir" << endl;

	entrada=leernumero("");

  switch (entrada){

  case 1:

	  key=leernumero("Introduce la clave que deseas introducir");

	  if(buscar(lista, key)==0){
		  insertar(lista, key);
		  cout << "Clave introducida con éxito" << endl;
	  }else{
		  cout << "La clave ya existe, no puede ser introducida" << endl;
	  }

	  break;

  case 2:

	  key=leernumero("Introduce la clave que deseas borrar");

	  	  if(buscar(lista, key)==0){
	  		  cout << "No existe, no se puede eliminar" << endl;
	  	  }else{
	  		  eliminar(lista, key);
	  		  cout << "Clave eliminada con éxito" << endl;
	  	  }

	  break;

  case 3:
	  eliminar(lista);
	  cout << "Lista eliminada completamente con éxito" << endl;
	  break;

  case 4:

	  key=leernumero("Introduce la clave de la que deseas mostrar datos");

 	 	  	  if(buscar(lista, key)==0){
 	 	  		  cout << "No existe, no se puede mostrar" << endl;
 	 	  	  }else{

 	 	  		  mostrar(lista, key);
 	 	  	  }

   break;

  }


}while(entrada!=0);

return 0;
}
