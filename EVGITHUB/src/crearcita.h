

//se le pasa como parámetros el mapa de citas, el mapa de pacientes, las citas y el vector de citas libres
//Comprueba que la cita no esté ocupada ya.
//después pide datos
//Si existen huecos libres para la cita el registro de la cita será el dado por el vector de huecos
//si no, añadirá una cita más y será su registro
void crear_cita(mapacita &mc, mapapaciente m ,int &citas,vector<int> citasLibres){

	FILE *citafile;

		micita cita;

		string dia, mes, ano,  ids, fechas, horas;

		char horac[2];

		string motivo;

		int id,registro;

		int numasegurado;

		int hora;

		do{
			numasegurado=leernumero("Introduce el numero de asegurado // 0 para salir");
			if(numasegurado==0){
				return;
			}
		}while(!existe_asegurado(m,numasegurado));

		do{
			ids="";
			do{
				fechas=leer("Introduce la fecha de la cita, 00 para salir // formato 99/99/9999");
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

			cout << "ID de cita: " << id << endl;

		}while(!val_idcita(id,mc));

		motivo=leer("Introduzca motivo de la cita // máximo 100 carácteres, el resto se desecharán");

		 citas++;

		 if(citasLibres.empty()){
			 registro=citas;
		 }else{
			 registro=citasLibres.back();
			 citasLibres.pop_back();
		 }

		 cita.numasegurado=numasegurado;
		 cita.idcita=id;
		 cita.registro=registro;
		 cita.numasegurado=numasegurado;
		 strcpy(cita.motivo,motivo.c_str());
		 cita.hora=hora;
		 strcpy(cita.fecha,fechas.c_str());

		 citafile=fopen("C:\\archivos\\citas.bin","r+b");
		 fseek(citafile,(registro-1)*sizeof(micita),0);
		 fwrite(&cita,sizeof(micita),1,citafile);
		 fclose(citafile);
		 mc.insert(pair<int,int>(cita.idcita,registro));
}
