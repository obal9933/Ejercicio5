

//se le pasa el mapa de pacientes y el numero de altas
//generará 1000 pacientes y devolverá el numero generado en altas
void generar(mapapaciente &m, int &altas){

	FILE *pacientes;

	cout << "creo archivo" << endl;
	pacientes=fopen("C:\\archivos\\pacientes.bin","w+b");

	mipaciente paciente;

	m.clear();

	int i;
	string dias[30]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30"};
	string mes[12]={"01","02","03","04","05","06","07","08","09","10","11","12"};
	string nombresh[5]={"Paco","Benito","Lucas","Diego","Daniel"};
	string nombresf[5]={"Sonia","Lucia","Cristina","Sara","Pilar"};
	string apellidos[10]={"Garcia","Soriano","Sánchez","Pérez","Antón","González","Garrido","Del Valle","Gutiérrez","Escalona"};
	string sexo[2]={"M","F"};
	char ano[4];
	string nombrecom,fechas="",temp,sexos;

	altas=0;

	for(i=1;i<=1000;i++){
		paciente.registro=i;

		//generará codigos de pacientes mientras existan en el mapa
		do{
			paciente.numasegurado=azar(100000,999999);
		}while(m.find(paciente.numasegurado)!=m.end());



		fechas="";
		temp=dias[azar(0,29)]+"/";
		fechas=fechas+temp;
		temp=mes[azar(0,11)]+"/";
		fechas=fechas+temp;
		itoa(azar(1950,2015),ano,10);
		fechas=fechas+ano;

		strcpy(paciente.fechanac,fechas.c_str());
		strcpy(paciente.sexo,sexo[azar(0,1)].c_str());
		sexos=paciente.sexo;
		if(sexos=="M"){
			nombrecom=nombresh[azar(0,4)]+" "+apellidos[azar(0,9)];
		}else{
			nombrecom=nombresf[azar(0,4)]+" "+apellidos[azar(0,9)];
		}

		strcpy(paciente.nombre, nombrecom.c_str());

		m.insert(pair<int,int>(paciente.numasegurado,i));
		fwrite(&paciente,sizeof(mipaciente),1,pacientes);
		altas++;
	}

fclose(pacientes);

};

//se le pasa el mapa de pacientes, el mapa de citas y el numero de citas
//generará 5000 citas para los pacientes existentes en el mapa, las guardará en el mapa de citas y sumará las citas que vaya creando
//el histórico de citas se destruirá.
//el antiguo archivo de citas se destruirá
void generar_citas(mapapaciente m, mapacita &mc, int &citas){

	FILE* pacientes;
	FILE* filecitas;

	micita cita;
	mipaciente paciente;

	string dias[30]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30"};
	string mes[12]={"01","02","03","04","05","06","07","08","09","10","11","12"};
	string anos[4]={"2015","2016","2017","2018"};
	string motivos[9]={"Agudo dolor en el vientre","Jaquecas","Dolor de muelas","Migrañas","Resfriado","Cirugia menor","Análisis de sangre","Revisión anual","Recogida análisis"};
	int horas[8]={11,12,13,14,16,17,18,19};
	char horac[2];
	string fechas,temp,ano,messtring,dia,ids,horass;
	int i,id,total,numazar;

	total=m.size();

	pacientes=fopen("C:\\archivos\\pacientes.bin","r+b");

	//destruir historico
	filecitas=fopen("C:\\archivos\\historico.bin","w+b");
	fclose(filecitas);

	filecitas=fopen("C:\\archivos\\citas.bin","w+b");


	for(i=1;i<=5000;i++){
	fechas="";
	temp=dias[azar(0,29)]+"/";
	fechas=fechas+temp;
	temp=mes[azar(0,11)]+"/";
	fechas=fechas+temp;
	temp=anos[azar(0,3)];
	fechas=fechas+temp;

	strcpy(cita.fecha,fechas.c_str());

	cita.hora=horas[azar(0,7)];

	ids="";

	ano=fechas.substr(6,4);
	ids=ids+ano;

	messtring=fechas.substr(3,2);
	ids=ids+messtring;

	dia=fechas.substr(0,2);
	ids=ids+dia;

	itoa(cita.hora,horac,10);
	horass=horac;
	ids=ids+horass;
	id=atoi(ids.c_str());
	cita.idcita=id;

	strcpy(cita.motivo,motivos[azar(0,8)].c_str());


	numazar=azar(1,total)-1;

	fseek(pacientes,(numazar*sizeof(mipaciente)),0);
	fread(&paciente,sizeof(mipaciente),1,pacientes);

	cita.numasegurado=paciente.numasegurado;
	cita.registro=i;

	fwrite(&cita,sizeof(micita),1,filecitas);

	mc.insert(pair<int,int>(cita.idcita,cita.registro));

	citas++;
	}

fclose(filecitas);
fclose(pacientes);
}
