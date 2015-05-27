void mapa_vacio(mapa& lista){

	persona temporal;

	  clave j, k;

	  string telefono;
	  char numero;

	  string nombres[]={"alfredo","jose","juan","rafael","carmen","mar","eva","luis","carlos","miguel","Mario","Alejandro","Rubén","Adrián","Guillermo"};

	  string apellidos[]={"santos","sanchez","rojo","barral","botia","castro","gomez","perez","rodriguez","escario","Jiménez","castellá","Aguilar","Cristóbal","Arenzana"};

	  for (j=0;j<20;j++)
	          {
	          // insertamos mediante la función miembro m.insert
		  	  telefono="";
		  	  for(k=0;k<9;k++){
		  		  numero=azar(48,57);
		  		  telefono=telefono+numero;
		  	  }

		  	  temporal.clave=j;
		  	  temporal.nombre=nombres[rand()%15]+" "+apellidos[rand()%15];
		  	  temporal.tfno=telefono;

	          	  lista.insert(pair<clave,persona>(j,temporal));

	          }

 }

int buscar(mapa lista, clave key){
int veces;

	veces=lista.count(key);

return veces;
}


void insertar(mapa& lista, clave key){
	string nombre;
	string tlf;

	nombre=leer("Introduce nombre");

	do{
	tlf=leernumero("Introduce numero de teléfono");
	}while(tlf.length() != 9);
	persona temporal;

	temporal.clave=key;
	temporal.nombre=nombre;
	temporal.tfno=tlf;

	lista.insert(pair<clave,persona>(key,temporal));
}


void eliminar(mapa& lista, clave key){
	lista.erase(key);
}

void eliminar(mapa& lista){

mapa::iterator i;
for(i=lista.begin();i!=lista.end();i++){
	lista.erase(i);
}

}


void mostrar(mapa& lista, clave key){

	mapa::iterator i;

	i=lista.find(key);

	cout << "Clave: " <<(*i).second.clave << endl;
	cout << "Nombre: " <<(*i).second.nombre << "\n";
	cout << "Teléfono: " <<(*i).second.tfno << "\n";
	cout << "\n";
}

