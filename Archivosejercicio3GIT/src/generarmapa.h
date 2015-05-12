
void generar_partirfichero(mapa &m){

	FILE *mapaalumnos;
	int registro;

	string DNI;
	char DNIC[9];

	mapaalumnos=fopen("C:\\Users\\usuario\\Desktop\\mapaalumnos.bin","r");

	while( feof(mapaalumnos)== 0)
		{
		     fscanf(mapaalumnos,"%s %d \n",DNIC,&registro);

		     m.insert(pair<string,int>(DNIC,registro));
		};
	fclose(mapaalumnos);

	};


void mostrar_mapa(mapa m){
	mapa::iterator i;

	for(i=m.begin();i!=m.end();i++){

		cout << (*i).first << "_____" << (*i).second << endl;
	}
}


