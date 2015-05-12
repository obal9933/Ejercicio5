//============================================================================
// Name        : archivosejercicio3.cpp
// Author      : Mario Cristóbal Arenzana
// Version     :
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "lectura.h"
#include "numericas.h"
#include "alumno.h"

// definicion del mapa y su criterio
typedef multimap<string, int, greater<string> > mapa;

#include "recorrer.h"

#define DIM 10000

#include "mostraralumno.h"
#include "crearalumnos.h"
#include "insertaralumnos.h"
#include "borraralumnos.h"
#include "generarmapa.h"

FILE *registro;
FILE *huecoslibres;
FILE *mapaalumnos;

int main() {
	srand (time(NULL));
	mapa m;

	mapa::iterator j;

	int opcion;
	unsigned int i;
	int altas=0;
	int bajas=0;

	char DNIC[9];

	registro=fopen("C:\\Users\\usuario\\Desktop\\registro.bin","r");
		fscanf(registro,"%d \n", &altas);
		fscanf(registro,"%d \n", &bajas);
	fclose(registro);

	huecoslibres=fopen("C:\\Users\\usuario\\Desktop\\huecos.bin","w");
	fclose(huecoslibres);

	cout << "abrir  vector de huecos" << endl;
	huecoslibres=fopen("C:\\Users\\usuario\\Desktop\\huecos.bin","r");
	vector<int> libres;
	cout << "creado vector de huecos" << endl;
	int libre;

	while( feof(huecoslibres)== 0)
	{
	     fscanf(huecoslibres,"%d \n",&libre);
	     libres.push_back(libre);
	};
	fclose(huecoslibres);
	cout << "rellenado vector de huecos" << endl;

	generar_partirfichero(m);

	 do{

		 cout << "-------------------------------" << endl;
		 cout << "1.- Mostrar todos los alumnos" << endl;
		 cout << "2.- Mostrar alumno concreto" << endl;
		 cout << "3.- Insertar nuevo alumno" << endl;
		 cout << "4.- Eliminar alumno" << endl;
		 cout << "9.- Crear nuevos alumnos" << endl;
		 cout << "0.- Salir" << endl;
		 cout << "-------------------------------" << endl;
		 opcion=leernumero("");

		 switch (opcion){
		 case 1:
			 recorrer(m);
		 break;

		 case 2:
			 mostrar_mapa(m);
		 	 mostrar(m);
		 break;

		 case 3:
		 	 insertar(m,libres,altas,bajas);
		 break;

		 case 4:
		 	 borrar(m,libres,bajas,altas);
		 break;

		 case 9:
			 crearalumnos(altas,m);

		 break;
		 }
	 }while(opcion!=0);


	 registro=fopen("C:\\Users\\usuario\\Desktop\\registro.bin","w");
		fprintf(registro,"%d \n",altas);
		fprintf(registro,"%d \n",bajas);
	 fclose(registro);


	 huecoslibres=fopen("C:\\Users\\usuario\\Desktop\\huecoslibres.bin","w");
	 	 for(i=0;i<=libres.size();i++){
		 fprintf(huecoslibres,"%d \n",libres[i]);
	 };

	 fclose(huecoslibres);

	 mapaalumnos=fopen("C:\\Users\\usuario\\Desktop\\mapaalumnos.bin","w");
	 cout << "guardando mapa"<< endl;
		 for(j = m.begin() ; j != m.end() ; j++){
			 strcpy( DNIC, (*j).first.c_str() );
			 fprintf(mapaalumnos,"%s %d \n",DNIC,(*j).second);
		 };
		 cout << "mapa guardado"<< endl;
		 fclose(huecoslibres);

	return 0;
}
