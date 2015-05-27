//se le pasa el mapa de pacientes, pide un codigo y mostrará la información del paciente asociada a ese código
//0 salir
//1 muestra el mapa de pacientes completo
void mostrar_paciente(mapapaciente m){

	int codigo;
	mapapaciente::iterator i;

	mipaciente paciente;

	FILE *pacientes;



	//se repite mientras el codigo no sea valido o no sea 0
	do{
		codigo=leernumero("Introduce el código del paciente a mostrar // entre 100000 y 999999 // 0 para salir, 1 para mostrar lista de pacientes");

		//si el codigo es 1 muestra el mapa entero y vuelve a pedir codigo
		if(codigo==1){
			for(i=m.begin();i!=m.end();i++){
				cout << "CODIGO: " << (*i).first << "  " << "REGISTRO: " << (*i).second << endl;
			}
		}

	}while(!val_codigo(codigo) && codigo != 0);

	cls();

	if(val_codigo(codigo)){

		i=m.find(codigo);

		if(i!=m.end()){

			cout << "mostrando registro " << (*i).second << endl;
			pacientes=fopen("C:\\archivos\\pacientes.bin","r+b");

			fseek(pacientes,((*i).second-1)*sizeof(mipaciente),0);
			fread(&paciente,sizeof(mipaciente),1,pacientes);

			cout << "---------------------------" << endl;
			cout << "Registro: "<< paciente.registro << endl;
			cout << "Codigo asegurado: "<< paciente.numasegurado << endl;
			cout << "Nombre y Apellidos: "<< paciente.nombre << endl;
			cout << "Sexo: "<< paciente.sexo << endl;
			cout << "Fecha de nacimiento: "<< paciente.fechanac << endl;
			cout << "---------------------------" << endl;
			leer("Pulse intro para continuar");
		}else{
			cout << "El codigo introducido no se corresponde con un paciente" << endl;
		}
	}

};

//se le pasan los mapas de pacientes y citas
//pide una fecha y comprueba que sea valida
//muestra todas las citas correspondientes a esa fecha
void mostrar_paciente_fecha(mapapaciente m, mapacita mc){

	mapacita::iterator i;
	mapapaciente::iterator k;

	mipaciente paciente;

	FILE *filecita;
	FILE *pacientes;

	string ids,fechas,dia,mes,ano;
	micita cita;
	int id;
	int idaux,j;

	ids="";

				do{
					fechas=leer("Introduce la fecha de la cita // formato 99/99/9999 //00 para salir");
					if(fechas=="00"){
						return;
					}
				}while(!val_fecha(fechas));

				ano=fechas.substr(6,4);
				ids=ids+ano;

				mes=fechas.substr(3,2);
				ids=ids+mes;

				dia=fechas.substr(0,2);
				ids=ids+dia;

				ids=ids+"00";

				id=atoi(ids.c_str());

				filecita=fopen("C:\\archivos\\citas.bin","r+b");
				pacientes=fopen("C:\\archivos\\pacientes.bin","r+b");

				int horas[8]={11,12,13,14,16,17,18,19};

				//recorre el vector de horas, las cuales suma a la fecha que se la introducido por teclado,
				//si la fecha con la hora del vector existe, la muestra
				for(j=0;j<8;j++){
					idaux=0;
					idaux=id+horas[j];

					i=mc.find(idaux);

					if(i!=mc.end()){


						fseek(filecita,(((*i).second)-1)*sizeof(micita),0);

						fread(&cita,sizeof(micita),1,filecita);

						k=m.find(cita.numasegurado);

						fseek(pacientes,((*k).second-1)*sizeof(mipaciente),0);
						fread(&paciente,sizeof(mipaciente),1,pacientes);

						cout << endl;
						cout << "====================================="<<endl;
						cout << "Registro cita: "<< cita.registro << endl;
						cout << "Fecha cita: "<< cita.fecha << endl;
						cout << "Hora cita: "<< cita.hora<<" h."<< endl;
						cout << "Motivo cita: "<< cita.motivo << endl;
						cout << "------------------------------------" << endl;
						cout << "Registro paciente: "<< paciente.registro << endl;
						cout << "Codigo asegurado: "<< paciente.numasegurado << endl;
						cout << "Nombre y Apellidos: "<< paciente.nombre << endl;
						cout << "Sexo: "<< paciente.sexo << endl;
						cout << "Fecha de nacimiento: "<< paciente.fechanac << endl;
						cout << "====================================="<<endl;
					}
				}
				fclose(filecita);
				fclose(pacientes);
				leer("Pulse intro para continuar");
			fclose(filecita);
			fclose(pacientes);
};

