//se le pasa un codigo, si está entre 100000 y 999999 devuelve true
bool val_codigo(int codigo){

	if(codigo<100000 || codigo > 999999)
		return false;

	return true;

}

//se le pasa una fecha y se descompone
//si la longitud no es 10 devuelve false
//si el dia no está entre 1 y 30 devuelve false
bool val_fecha(string fechanac){

	int dia,mes;

	if(fechanac.length()!=10){
		return false;
	}

	dia=atoi(fechanac.substr(0,2).c_str());
	mes=atoi(fechanac.substr(3,5).c_str());

	if(dia<1 || dia>30){
		return false;
	}

	if(mes<1 || mes>12){
		return false;
	}

	return true;

}

//si el parámetro no es M o F devuelve false
bool val_sexo(string entrada){

	if(entrada.length()!=1){
		return false;
	}
	string valido = "MF";
	int busqueda;
	busqueda=valido.find(entrada);
    if(busqueda==-1){
    	return false;
    }

	return true;

}

//se le pasa el mapa de pacientes y un codigo
//devuelve false si el codigo existe en el mapa o no es válido
//devuelve true si el codigo no existe en el mapa
bool val_asegurado(mapapaciente m, int entrada){

	mapapaciente::iterator i;

	i=m.find(entrada);

	if(i!=m.end()){
		cout << "El numero de asegurado existe" << endl;
		return false;
	}

	if(entrada<100000 || entrada > 999999){
		return false;
	}

	return true;

}

//se le pasa el mapa de pacientes y un codigo
//devuelve false si no existe o si no es válido
//devuelve true si existe
bool existe_asegurado(mapapaciente m, int entrada){

	mapapaciente::iterator i;

	i=m.find(entrada);

	if(i==m.end()){
		cout << "El numero de asegurado no existe" << endl;
		return false;
	}

	if(entrada<100000 || entrada > 999999){
		cout << "El numero de asegurado no es válido" << endl;
		return false;
	}

	cout << "El numero de asegurado es válido" << endl;
	return true;
}


bool val_hora(int hora){

	if((hora < 11 || hora > 14) || (hora < 16 || hora > 19)){
		return false;
	}
	return true;
}

//se le pasa una ID de cita y el mapa de cita
//devuelve false si la cita existe, true si no existe.
bool val_idcita(int idcita, mapacita mc){

	mapacita::iterator i;

	i=mc.find(idcita);

	if(i!=mc.end()){
		cout << "La cita ya existe" << endl;
		return false;
	}

	return true;

}
