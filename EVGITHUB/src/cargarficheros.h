
//se le pasa el mapa de pacientes y vuelca el contenido del archivo sobre él
void car_mapapacientes(mapapaciente &m){

FILE *mapapacientes;

mapapacientes=fopen("C:\\archivos\\mapapacientes.bin","r");

int numasociado, registro;

while(feof(mapapacientes)==0)
	{
         fscanf(mapapacientes,"%d %d \n",&numasociado, &registro);

         m.insert(pair<int,int>(numasociado,registro));

  };
cout << "mapa pacientes cargado con éxito" << endl;
fclose(mapapacientes);

};

//se le pasa el mapa de citas y vuelca el contenido del archivo sobre él
void car_mapacitas(mapacita &mc){

FILE *mapacita;
mapacita=fopen("C:\\archivos\\mapacitas2.bin","r");

int idcita, registro;

while(feof(mapacita)==0)
	{
         fscanf(mapacita,"%d %d \n",&idcita, &registro);
         mc.insert(pair<int,int>(idcita,registro));
  };
cout << "mapa pacientes cargado con éxito" << endl;
fclose(mapacita);

};

//se le pasan las altas, bakas citas e historicos y vuelca el contenido del archivo sobre ellos en orden
void car_altas(int &altas, int &bajas, int &citas, int &nhistorico){

FILE *alta;

alta=fopen("C:\\archivos\\altas.bin","r");

         fscanf(alta,"%d \n",&altas);
         fscanf(alta,"%d \n",&bajas);
         fscanf(alta,"%d \n",&citas);
         fscanf(alta,"%d \n",&nhistorico);

cout << "Altas y bajas cargadas con éxito" << endl;
fclose(alta);

};

//se le pasa el vector de huecos de pacientes y vuelca el contenido del archivo sobre él
void car_huecos(vector <int> libres){

FILE *vectorhuecos;
int libre;
vectorhuecos=fopen("C:\\archivos\\vectorhuecos.bin","r");
while( feof(vectorhuecos)== 0)
	{
	     fscanf(vectorhuecos,"%d \n",&libre);
	     libres.push_back(libre);
	};
fclose(vectorhuecos);
};

//se le pasa el vector de huecos de citas y vuelca el contenido del archivo sobre él
void car_libres_citas(vector <int> citaslibres){
FILE *vectorhuecos;
int libre;
vectorhuecos=fopen("C:\\archivos\\vectorcitas.bin","r");
while( feof(vectorhuecos)== 0)
	{
	     fscanf(vectorhuecos,"%d \n",&libre);
	     citaslibres.push_back(libre);
	};
fclose(vectorhuecos);
};


//se le pasa el mapa del historico como parámetro y vuelca el contenido del archivo sobre el
void car_mapahistorico(mapahistorico &mh){

FILE *mapapacientes;
mapapacientes=fopen("C:\\archivos\\mapahistorico.bin","r");

int id, registro;

	while( feof(mapapacientes)== 0)
		{
		     fscanf(mapapacientes,"%d %d\n",&id, &registro);
		     mh.insert(pair<int,int>(id,registro));
		};
	fclose(mapapacientes);

};
