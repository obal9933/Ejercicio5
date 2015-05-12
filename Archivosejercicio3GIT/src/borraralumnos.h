void borrar(mapa m, vector<int> libres, int &bajas, int &altas){

	mapa::iterator i;

	string DNI;
	char DNIC[9];

	if(altas<=0){
		cout << "fichero de alumnos vacio" << endl;

	}else{

		do{

			DNI=leer("Introduzca DNI del alumno a borrar");

			strcpy(DNIC, DNI.c_str());

		}while(m.find(DNIC) == m.end() );

		i=m.find(DNIC);

		altas=altas-1;
		bajas=bajas+1;

		libres.push_back((*i).second);
		m.erase(DNIC);

	}
	fclose(huecos);
}
