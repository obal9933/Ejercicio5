
string leer(string enunciado){
	string entrada;

	cout << enunciado << endl;
	fflush(stdin);
	getline(cin,entrada);

	return entrada;
}

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
