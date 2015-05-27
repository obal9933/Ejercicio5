
//se le pasa como parámetro el mapa de citas, el vector de citas libres, el numero de citas, el mapa historico y el numero de citas en el historico
//si no existen citas saldrá
//pedirá una fecha, se validará, y se pasarán al histórico las citas anteriores a la fecha, por cada cita sumará uno al numero del hisotrico y restará una cita.
void pasar_historico(mapacita &mc, vector<int> citaslibres, int &citas,mapahistorico &mh, int &nhistorico){

FILE* historico;
FILE* filecitas;

historico=fopen("C:\\archivos\\historico.bin","r+b");

filecitas=fopen("C:\\archivos\\citas.bin","rb");

micita cita;

mapacita::iterator i;
mapacita::iterator ult;

string fechas,ano,ids,mes,dia;

int id;

if(citas<=0){
	cout << "No existen citas"<<endl;
	leer("Pulse intro para continuar");
	return;
}

do{
	fechas=leer("Introduce la fecha de la cita, se eliminarán las citas anteriores a la fecha y se traspasarán al histórico // 00 para salir // formato 99/99/9999");
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

	ids=ids+"19";

	id=atoi(ids.c_str());

	cout << "La ID usada para la fecha es " << id << endl;


//desde el principio del mapa de citas, (la fecha más antigua) hasta la última fecha del dia seleccionado se pasarán al histórico.
	for(i=mc.begin();i!=mc.upper_bound(id);i++){

		fseek(filecitas,((((*i).second)-1)*sizeof(micita)),0);
		fread(&cita,sizeof(micita),1,filecitas);

		nhistorico++;

		fseek(historico,(((nhistorico)-1)*sizeof(micita)),0);
		fwrite(&cita,sizeof(micita),1,historico);

		mh.insert(pair<int,int>(cita.idcita,nhistorico));

		citas--;

		citaslibres.push_back((*i).second);

		mc.erase(i);
}

fclose(filecitas);
fclose(historico);
cout << "Se han traspasado las citas al histórico correctamente" << endl;
leer("Pulse intro para continuar");
};


//se le pasa como parámetros el mapa del histórico y el mapa de pacientes
//pedirá una fecha y se mostrarán todas las citas del histórico desde la fecha hasta la más reciente
//0 para mostrarlo entero
void consultar_historico(mapahistorico mh, mapapaciente m){

FILE* historico;
FILE* pacientes;
historico=fopen("C:\\archivos\\historico.bin","rb");
pacientes=fopen("C:\\archivos\\pacientes.bin","rb");

micita cita;
mipaciente paciente;

string fechas,ano,mes,dia,ids;

int id;

mapahistorico::iterator i;

mapapaciente::iterator k;

//se repite mientras la fecha no sea correcta o se le pase 0
do{
	fechas=leer("Introduce una fecha para mostrar desde ella hasta la fecha más reciente, 0 para mostrarlo entero// formato 99/99/9999");
}while(!val_fecha(fechas) && fechas!="0");


//si se le ha pasado un 0 muestra desde el principio del mapa del histórico hasta el final
//si se le ha pasado una fecha concreta, muestra desde el principio del mapa hasta la fecha.
if(fechas=="0"){

	for(i=mh.begin();i!=mh.end();i++){

		fseek(historico,((((*i).second)-1)*sizeof(micita)),0);
		fread(&cita,sizeof(micita),1,historico);


		k=m.find(cita.numasegurado);

		fseek(pacientes,((*k).second-1)*sizeof(mipaciente),0);
		fread(&paciente,sizeof(mipaciente),1,pacientes);

		cout << endl;
		cout << "====================================="<<endl;
		cout << "Registro cita: "<< cita.registro << endl;
		cout << "Fecha cita: "<< cita.fecha << endl;
		cout << "Motivo cita: "<< cita.motivo << endl;
		cout << "------------------------------------" << endl;
		cout << "Registro paciente: "<< paciente.registro << endl;
		cout << "Codigo asegurado: "<< paciente.numasegurado << endl;
		cout << "Nombre y Apellidos: "<< paciente.nombre << endl;
		cout << "Sexo: "<< paciente.sexo << endl;
		cout << "Fecha de nacimiento: "<< paciente.fechanac << endl;
		cout << "====================================="<<endl;

	}

	leer("Pulse intro para continuar");
}else{

	ano=fechas.substr(6,4);
	ids=ids+ano;

	mes=fechas.substr(3,2);
	ids=ids+mes;

	dia=fechas.substr(0,2);
	ids=ids+dia;

	ids=ids+"19";

	id=atoi(ids.c_str());


	for(i=mh.begin();i!=mh.upper_bound(id);i++){

	fseek(historico,((((*i).second)-1)*sizeof(micita)),0);
	fread(&cita,sizeof(micita),1,historico);


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
	leer("Pulse intro para continuar");



}



}
