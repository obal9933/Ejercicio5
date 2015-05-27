//despeja la pantalla
void cls(){
	cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
}

//se le pasa un enunciado que mostrar� por pantalla y pedir� una entrada que devolver�.
string leer(string enunciado){
	string entrada;

	cout << enunciado << endl;
	fflush(stdin);
	getline(cin,entrada);

	return entrada;
}

//se le pasa un enunciado que mostrar� por pantalla y pedir� una entrada que seguir� pidiendo mientras se le haya introducido un numero
//cuando sea correcto devolver� la entrada
string leerletra(string enunciado){
	string entrada;
	string numeros="0123456789";
	unsigned int i;
	int busqueda;
	bool flag;

	do{
		flag=true;
	cout << enunciado << endl;
	fflush(stdin);
	getline(cin,entrada);

	for(i=0;i<entrada.length();i++){
		busqueda=numeros.find(entrada[i]);

	if( busqueda != -1 ){
		flag=false;
	}
	}

	}while(!flag);
	return entrada;
}

//se le pasa un enunciado que mostrar� por pantalla y pedir� una entrada num�rica que seguir� pidiendo mientras no sea v�lido
//cuando sea correcto devolver� la entrada convertida a int
int leernumero(string enunciado){
	string entrada;
	string numeros="0123456789";
	unsigned int i;
	int busqueda;
	bool flag;

	do{
		flag=true;
		cout << enunciado << endl;
		fflush(stdin);
		getline(cin,entrada);

		for(i=0;i<entrada.length();i++){
			busqueda=numeros.find(entrada[i]);
			if(busqueda == -1 ){
				flag=false;
			}
		}

		}while(!flag);

		return atoi(entrada.c_str());
}

//se le pasa un enunciado que mostrar� por pantalla y pedir� una entrada num�rica, pudiendo tener un punto, que seguir� pidiendo mientras no sea v�lido
//cuando sea correcto devolver� la entrada convertida a float
float leerfloat(string enunciado){
	string entrada;
	string numeros="0123456789.";
	unsigned int i;
	int busqueda,contador=0;
	bool flag;

	do{
		flag=true;
		cout << enunciado << endl;
		fflush(stdin);
		getline(cin,entrada);

		for(i=0;i<entrada.length();i++){
			busqueda=numeros.find(entrada[i]);
			if(busqueda == -1 ){
				flag=false;
			}
			if(entrada[i]=='.'){
				contador++;
			}
		}
		if(contador>1){
			flag = true;
		}
		}while(!flag);

		return atof(entrada.c_str());
}
