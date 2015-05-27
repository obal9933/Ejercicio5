//comrprueba que exista y sea accesible el archivo, si no, lo crea
void com_pacientes(){

FILE *pacientes;

if ((pacientes=fopen("C:\\archivos\\pacientes.bin","r+b"))==NULL){
     cout << "El fichero pacientes no existe, se creará\n" << endl;
     pacientes=fopen("C:\\archivos\\pacientes.bin","w+b");
     fclose(pacientes);
}else{
	cout << "El fichero pacientes existe, se cargará\n" << endl;
}

};

//comrprueba que exista y sea accesible el archivo, si es asi llama al afuncion para cargar el mapa, si no, lo crea
void com_mapapacientes(mapapaciente &m){

FILE *mapapacientes;

if ((mapapacientes=fopen("C:\\archivos\\mapapacientes.bin","r"))==NULL){
     cout << "El fichero mapa pacientes no existe, se creará\n" << endl;
     mapapacientes=fopen("C:\\archivos\\mapapacientes.bin","w");
     fclose(mapapacientes);
}else{
	cout << "El fichero mapa pacientes existe, se cargará\n" << endl;
	car_mapapacientes(m);

}

};

//comrprueba que exista y sea accesible el archivo de registros de altas, bajas, citas e historico, si no, lo crea
void com_altas() {

FILE *altas;

if ((altas=fopen("C:\\archivos\\altas.bin","r"))==NULL){
     cout << "El fichero altas no existe, se creará\n" << endl;
     altas=fopen("C:\\archivos\\altas.bin","w");
     fclose(altas);
}else{
	cout << "El fichero altas existe, se cargará\n" << endl;
}

};

//comrprueba que exista y sea accesible el archivo del vector de huecos de pacientes, si no, lo crea
void com_huecos(){

FILE *vectorhuecos;

if ((vectorhuecos=fopen("C:\\archivos\\vectorhuecos.bin","r"))==NULL){
     cout << "El fichero vectorhuecos no existe, se creará\n" << endl;
     vectorhuecos=fopen("C:\\archivos\\vectorhuecos.bin","w");
     fclose(vectorhuecos);
}else{
	cout << "El fichero vectorhuecos existe, se cargará\n" << endl;
}


};

//comrprueba que exista y sea accesible el archivo de vector de huecos de citas, si no, lo crea
void com_citasLibres(){

FILE *vectorhuecos;

if ((vectorhuecos=fopen("C:\\archivos\\vectorcitas.bin","r"))==NULL){
     cout << "El fichero vectorcitas no existe, se creará\n" << endl;
     vectorhuecos=fopen("C:\\archivos\\vectorcitas.bin","w");
     fclose(vectorhuecos);
}else{
	cout << "El fichero vectorhuecos existe, se cargará\n" << endl;
}


};


//comrprueba que exista y sea accesible el archivo del mapa de citas, si no, lo crea
void com_mapacitas(){

FILE *mapapacientes;

if ((mapapacientes=fopen("C:\\archivos\\mapacitas2.bin","r"))==NULL){
     cout << "El fichero mapa citas no existe, se creará\n" << endl;
     mapapacientes=fopen("C:\\archivos\\mapacitas2.bin","w");
     fclose(mapapacientes);
}else{
	cout << "El fichero mapa citas existe, se cargará\n" << endl;
}


};

//comrprueba que exista y sea accesible el archivo de citas, si no, lo crea
void com_citas(){

FILE *mapapacientes;

if ((mapapacientes=fopen("C:\\archivos\\citas.bin","r+b"))==NULL){
     cout << "El fichero citas no existe, se creará\n" << endl;
     mapapacientes=fopen("C:\\archivos\\citas.bin","w+b");
     fclose(mapapacientes);
}else{
	cout << "El fichero citas existe, se cargará\n" << endl;
}


};

//comrprueba que exista y sea accesible el archivo del mapa del historico y llama la funcion que carga el archivo en el mapa, si no, lo crea
void com_mapahistorico(mapahistorico &mh){

FILE *mapapacientes;

if ((mapapacientes=fopen("C:\\archivos\\mapahistorico.bin","r"))==NULL){
     cout << "El fichero mapa historico no existe, se creará\n" << endl;
     mapapacientes=fopen("C:\\archivos\\mapahistorico.bin","w");
     fclose(mapapacientes);
}else{
	cout << "El fichero mapa historico existe, se cargará\n" << endl;
	car_mapahistorico(mh);
}


};

//comrprueba que exista y sea accesible el archivo historico, si no, lo crea
void com_historico(){

FILE *mapapacientes;

if ((mapapacientes=fopen("C:\\archivos\\historico.bin","r+b"))==NULL){
     cout << "El fichero historico no existe, se creará\n" << endl;
     mapapacientes=fopen("C:\\archivos\\historico.bin","w+b");
     fclose(mapapacientes);
}else{
	cout << "El fichero historico existe, se cargará\n" << endl;
}


};

