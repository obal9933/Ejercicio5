
//recibirá como parámetro el mapa de citas, el vector de citas libres, citas y el mapa de pacienetes
//si el numero de citas es menor o igual a 0 saldrá
//pedirá la fecha de la fita y la hora y comprobará que exista,
//Mostrará la cita correspondiente y preguntará si se desea borrar
//Si pulsa 1 añadira su registro al vector de libres, restará una cita y la borrará del mapa
void borrar_cita(mapacita &mc, vector<int> &citaslibres,int &citas, mapapaciente m){

	string fechas,ano,ids,mes,dia,horas,entrada;
	int hora,id;
	micita cita;
	char horac[2];
	mapacita::iterator i;

	mapapaciente::iterator k;

		mipaciente paciente;

		FILE *filecita;
		FILE *pacientes;


	if(citas<=0){
		cout << "No existen citas para borrar" << endl;
		return;
	}

	do{
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

					do{
						hora=leernumero("Introduce la hora de la cita // formato 99 // de 11 a 14 y de 16 a 19");
					}while(val_hora(hora));

					itoa(hora,horac,10);

					horas=horac;

					ids=ids+horas;

					id=atoi(ids.c_str());
		cout <<"Comprobando id: " << id << endl;
	}while(val_idcita(id,mc));


	i=mc.find(id);

	filecita=fopen("C:\\archivos\\citas.bin","r+b");
	pacientes=fopen("C:\\archivos\\pacientes.bin","r+b");

	fseek(filecita,((*i).second-1)*sizeof(micita),0);
	fread(&cita,sizeof(micita),1,filecita);
	k=m.find(cita.numasegurado);

	fseek(pacientes,((*k).second-1)*sizeof(mipaciente),0);
	fread(&paciente,sizeof(mipaciente),1,pacientes);

							cout << "------------------------------------" << endl;
							cout << "Registro cita: "<< cita.registro << endl;
							cout << "Fecha cita: "<< cita.fecha << endl;
							cout << "Motivo cita: "<< cita.motivo << endl;
							cout << "------------------------------------" << endl;
							cout << "Registro paciente: "<< paciente.registro << endl;
							cout << "Codigo asegurado: "<< paciente.numasegurado << endl;
							cout << "Nombre y Apellidos: "<< paciente.nombre << endl;
							cout << "Sexo: "<< paciente.sexo << endl;
							cout << "Fecha de nacimiento: "<< paciente.fechanac << endl;
							cout << "---------------------------" << endl;

	entrada=leer("¿Es ésta la cita que desea borrar?// 1 si ; cualquier tecla salir");

	if(entrada!="1"){
		return;
	};

	citas--;
	citaslibres.push_back((*i).second);
	mc.erase(i);
	cout << "Cita borrada con éxito"<< endl;
}
