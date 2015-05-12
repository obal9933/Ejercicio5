
void mostrar(mapa m){

mapa::iterator y;

mialumno alumno;

string DNI="";

DNI=leer("Por favor, introduzca el DNI del alumno que desea mostrar // 0 salir");

if(DNI != "0"){

	FILE *alumnosaux;
	alumnosaux=fopen("C:\\Users\\usuario\\Desktop\\alumnos.bin","r+b");

	 y = m.find(DNI);

	 if(y != m.end() ){

		 fseek(alumnosaux,((*y).second-1)*sizeof(mialumno),0);
		 fread(&alumno,sizeof(mialumno),1,alumnosaux);

		 cout << "----------------------------"<< endl;
		 cout << "DNI: " << alumno.DNI << endl;
		 cout << "Registro: " << alumno.clase << endl;
		 cout << "Nombre: " << alumno.apellido << endl;
		 cout << "No1 : " << alumno.nota1 << endl;
		 cout << "No2 : " << alumno.nota2 << endl;
		 cout << "No3 : " << alumno.nota3 << endl;
		 cout << "----------------------------"<< endl;

	 }else{
		 cout << "El alumno no existe" << endl;
	 }

	fclose(alumnosaux);
}
}
