//se le pasa como parámetros todos los componentes del programa y muestra el menú principal de opciones mientras no se introduxzca un 0 u otra entrada
void mostrar_menu(mapapaciente &m, vector<int> libres,int &altas,int &bajas, int &citas, mapacita &mc, vector<int> &citaslibres,mapahistorico &mh,int &historico){
	int opcion;
	mapacita::iterator i;

	do{

	cls();

	cout << "-------------------------------" << endl;
	cout << "1.- Citar paciente" << endl;
	cout << "2.- Cancelar Cita" << endl;
	cout << "3.- Listar pacientes por fecha" << endl;
	cout << "4.- Consultar histórico" << endl;
	cout << "5.- Crear paciente" << endl;
	cout << "6.- Dar de baja paciente" << endl;
	cout << "7.- Mostrar paciente" << endl;
	cout << "8.- Pasar citas atrasadas a histórico" << endl;
	cout << "9.- |Reiniciar pacientes y citas|" << endl;
	cout << "0.- Salir" << endl;
	cout << "-------------------------------" << endl;
	opcion=leernumero("");


	switch(opcion){

	case 1:
			crear_cita(mc,m,citas,citaslibres);
		break;

	case 2:
			borrar_cita(mc,citaslibres,citas,m);
	break;

	case 3:
			cout << "Existen " << citas << " citas en el sistema" << endl;
			mostrar_paciente_fecha(m,mc);
		break;

	case 4:
		consultar_historico(mh,m);
	break;

	case 5:
		crear_paciente(m,libres,altas,bajas);

	break;

	case 6:
		baja_paciente(m,libres,altas,bajas);

	break;

	case 7:
		mostrar_paciente(m);
	break;

	case 8:
		pasar_historico(mc,citaslibres,citas,mh,historico);
	break;

	case 9:
		//reinicia todos los mapas y vectores, borra archivos y vuelve a crear 1000 pacientes y 5000 citas asociadas a pacientes
		citaslibres.clear();
		libres.clear();
		bajas=0;
		citas=0;
		historico=0;
		mh.clear();
		generar(m,altas);
		generar_citas(m,mc,citas);
		cout << "Todos los mapas y archivos han sido reiniciados" << endl;
		leer("Pulse intro para continuar");
	break;

	}
	}while(opcion!=0);
}
