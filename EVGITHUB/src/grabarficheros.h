//se le pasa como parámetro el mapa de pacientes y lo vuelca a un fichero
void gra_mapapaciente(mapapaciente m){

FILE *mapapacientes;

mapapacientes=fopen("C:\\archivos\\mapapacientes.bin","w");

mapapaciente::iterator i;

cout << "grabo mapa pacientes " << endl;

for(i = m.begin() ; i != m.end(); i++){
	fprintf(mapapacientes,"%d %d\n",(*i).first,(*i).second);
}
fclose(mapapacientes);
};

//se le pasan como parámetros las altas, bajas, citas y citas del histórico y las graba en un archivo.
void gra_altas(int altas, int bajas, int citas,int nhistorico){

FILE *alta;

alta=fopen("C:\\archivos\\altas.bin","w");

cout << "grabo altas y bajas " << endl;

	fprintf(alta,"%d \n",altas);
	fprintf(alta,"%d \n",bajas);
	fprintf(alta,"%d \n",citas);
	fprintf(alta,"%d \n",nhistorico);

fclose(alta);
}

//se le pasa el vector de pacientes libres y lo graba en un fichero
void gra_vect(vector <int> libres){

	FILE *vector;
	unsigned int i;

	vector=fopen("C:\\archivos\\vectorhuecos.bin","w");

	 for(i=0;i<=libres.size();i++){
			 fprintf(vector,"%d \n",libres[i]);
		 };
	 cout << "vector pacientes libres guardado"<<endl;
	 fclose(vector);
}

//se le pasa el vector de citas libres y lo graba en un fichero
void gra_vect_citas(vector <int> citaslibres){

	FILE *vector;
	unsigned int i;

	vector=fopen("C:\\archivos\\vectorcitas.bin","w");

	 for(i=0;i<=citaslibres.size();i++){
		fprintf(vector,"%d \n",citaslibres[i]);
		};
	 cout << "vector citas libres guardado"<<endl;
	 fclose(vector);
}

//se le pasa el mapa de citas y lo graba en un fichero
void gra_mapacitas(mapacita mc){

FILE *mapacita;

mapacita=fopen("C:\\archivos\\mapacitas2.bin","w");

mapacita::iterator i;

cout << "grabo mapa citas " << endl;

for(i = mc.begin() ; i != mc.end(); i++){
	fprintf(mapacita,"%d %d\n",(*i).first,(*i).second);
}
fclose(mapacita);
};


//se le pasa el mapa del histórico y lo graba en un fichero
void gra_mapahistorico(mapahistorico mh){

FILE *mapahistorico;

mapahistorico=fopen("C:\\archivos\\mapahistorico.bin","w");

mapahistorico::iterator i;

cout << "grabo mapa histórico " << endl;

for(i = mh.begin() ; i != mh.end(); i++){
	fprintf(mapahistorico,"%d %d\n",(*i).first,(*i).second);
}
fclose(mapahistorico);
};
