

//se le pasa como parámetro el mapa de paciente, el vector de huecos libres, altas y bajas
//si no existen pacientes dados de altas saldrá
//preguntará por el numero de asegurado, si existe añadirá su registro al vector de libres, añadirá una baja y restará un alta
void baja_paciente(mapapaciente &m, vector<int> libres, int &altas, int &bajas){

	mapapaciente::iterator i;

	string entrada;

	int numasegurado;

	cout << "Existen " << altas << " pacientes dados de alta en el sistema" << endl;

	if(altas==0){
		cout << "Debe existir por lo menos un paciente para poder darlo de baja";
		return;
	}

	do{
		numasegurado=leernumero("Introduce el numero de asegurado // 0 para salir");
		if(numasegurado==0){
			return;
		}
	}while(!existe_asegurado(m,numasegurado));

		i=m.find(numasegurado);

		libres.push_back((*i).second);

		bajas++;
		altas--;

		m.erase(numasegurado);

};
