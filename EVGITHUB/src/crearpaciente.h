

//se le pasa como par�metros el mapa de pacientes, las altas, bajas y el vector de pacientes libres
//Comprueba que el paciente no exista
//despu�s pide datos
//Si existen huecos libres para el paciente el n� de registro del paciente ser� el dado por el vector de huecos
//si no, a�adir� un paciente m�s y ser� su registro
void crear_paciente(mapapaciente &m, vector<int> libres, int &altas, int &bajas){

	FILE *pacientes;

	mipaciente pacienteaux;

	string entrada;
	char nombrec[30];

	int numasegurado;

	char fechanacc[10];

	int registro;

	char sexo[1];

	cout << "Existen " << altas << " pacientes dados de alta en el sistema" << endl;

	entrada=leer("Introduce nombre de paciente");
	strcpy(nombrec,entrada.c_str());

	do{
		entrada=leer("Introduce fecha de nacimiento // formato 99/99/9999");
	}while(!val_fecha(entrada));

	strcpy(fechanacc,entrada.c_str());

	do{
		entrada=leer("Introduce sexo");
	}while(!val_sexo(entrada));

	strcpy(sexo,entrada.c_str());

	do{
		numasegurado=leernumero("Introduce el numero de asegurado");
	}while(!val_asegurado(m,numasegurado));



	if(bajas>0){

		registro=libres.back();
		libres.pop_back();
		bajas--;
		altas++;
	}else{

		altas++;
		registro=altas;
	}

	cout << "El paciente tendr� el registro n "<< registro << endl;

	strcpy(pacienteaux.fechanac,fechanacc);
	strcpy(pacienteaux.nombre,nombrec);
	pacienteaux.numasegurado=numasegurado;
	strcpy(pacienteaux.sexo,sexo);
	pacienteaux.registro=registro;

	pacientes=fopen("C:\\archivos\\pacientes.bin","r+b");
	fseek(pacientes,(registro-1)*sizeof(mipaciente),0);
	fwrite(&pacienteaux,sizeof(mipaciente),1,pacientes);
	fclose(pacientes);
	m.insert(pair<int,int>(numasegurado,registro));
};
