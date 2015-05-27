//============================================================================
// Name        : Evaluacion3.cpp
// Author      : Mario Cristóbal Arenzana
// Version     : 4.0.3
// Copyright   : 
// Description : Ejercicio 3ª evaluación programa gestión consulta médica
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

typedef map<int, int, greater<int> > mapapaciente;
typedef map<int, int, less<int> > mapacita;
typedef map<int, int, greater<int> > mapahistorico;

#include "lectura.h"
#include "numericas.h"
#include "cargarficheros.h"
#include "comprobacionarchivos.h"
#include "strucpaciente.h"
#include "cita.h"
#include "generadorpacientes.h"
#include "grabarficheros.h"

#include "filtros.h"

#include "historico.h"
#include "crearcita.h"
#include "borrarcita.h"
#include "crearpaciente.h"
#include "bajapaciente.h"
#include "mostrarpaciente.h"

#include "menu.h"

int main() {

	srand(time(NULL));

	mapapaciente m;
	mapacita mc;
	mapahistorico mh;
	int altas=0;
	int bajas=0;
	int citas=0;
	int nhistorico=0;

	vector<int> libres;
	vector<int> citaslibres;

	//Comprueba que el archivo de huecos exista.
	com_huecos();
	//carga el archivo de huecos en el vector libres
	car_huecos(libres);
	//comprueba que el archivo de citas libars exista
	com_citasLibres();
	//carga el archivo de citas libres
	car_libres_citas(citaslibres);
	//comprueba que exista el archivo de pacientes
	com_pacientes();
	//comprueba que exista el mapa de pacientes y si existe lo carga
	com_mapapacientes(m);
	//Comprueba que exista el archivo de registros
	com_altas();
	//carga el archivo de registros
	car_altas(altas,bajas,citas,nhistorico);
	//comprueba que exista el archivo de citas
	com_citas();
	//comprueba que exista el archivo mapa de citas
	com_mapacitas();
	//carga el mapa de citas
	car_mapacitas(mc);
	//comprueba que exista el archivo histórico
	com_historico();
	//comprueba que exista el archivo mapa hgistorico y lo carga
	com_mapahistorico(mh);

	//Muestra y entra al menu principal del programa
	//se le pasan como parámentros, mapa de pacientes, vector de pacientes libres, altas, bajas, citas, mapa de citas, vector de citas libres, mapa del historico y numero de historicos que existen
	mostrar_menu(m,libres,altas,bajas,citas,mc,citaslibres,mh,nhistorico);

	//si existen altas graba el mapa de pacientes
	if(altas!=0)
	gra_mapapaciente(m);

	//si existen citas graba el mapa de citas
	if(citas!=0)
	gra_mapacitas(mc);

	//si hay citas en el historico graba el mapa del histórico
	if(nhistorico!=0)
	gra_mapahistorico(mh);

	//graba el archivo de registros
	gra_altas(altas,bajas,citas,nhistorico);

	//Si existen huecos en el vector de pacientes los graba en un archivo
	if(!libres.empty())
	gra_vect(libres);

	//si existen huecos en el vector de citas los graba
	if(!citaslibres.empty())
	gra_vect_citas(citaslibres);

	return 0;
}
