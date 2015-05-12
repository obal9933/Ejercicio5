
void llenarvector(alumno lista[]){

	  int j;

	  string telefono;

	  string nombres[]={"alfredo","jose","juan","rafael","carmen","mar","eva","luis","carlos","miguel","Mario","Alejandro","Rubén","Adrián","Guillermo"};

	  string apellidos[]={"santos","sanchez","rojo","barral","botia","castro","gomez","perez","rodriguez","escario","Jiménez","castellá","Aguilar","Cristóbal","Arenzana"};

	  for (j=0;j<DIM;j++)
	          {
		  	  lista[j].nombre=nombres[rand()%15];
		  	  lista[j].apellido=apellidos[rand()%15];
		  	  lista[j].nota1=azar(0,10);
		  	  lista[j].nota2=azar(0,10);
		  	  lista[j].nota3=azar(0,10);
	          }

 }

void llenarmapa(mapa& notas, alumno lista[], int nota){

	int i;

	switch (nota){

	case 1:
	for(i=0;i<DIM;i++){
		notas.insert(pair<int, int>(lista[i].nota1,i));
	}
	break;

	case 2:

		for(i=0;i<DIM;i++){
			notas.insert(pair<int, int>(lista[i].nota2,i));
			}

		break;

	case 3:

		for(i=0;i<DIM;i++){

			notas.insert(pair<int, int>(lista[i].nota3,i));
			}

		break;
	}
}


void mostrarmapa(mapa notas, alumno lista[]){

	int j;

	mapa::iterator i;

	for(i=notas.begin();i!=notas.end();i++){
			j=(*i).second;
			cout << "-------------------------------"<< endl;
			cout << "nota: " << (*i).first << endl;

			cout << "Nombre:" << lista[j].nombre << endl;
			cout << "Apellidos:" << lista[j].apellido << endl;

			cout << "\n";
		}

}
