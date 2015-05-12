void recorrer(mapa m){

mapa::iterator i;
mialumno alumno;

FILE *alumnosaux;

alumnosaux=fopen("C:\\Users\\usuario\\Desktop\\alumnos.bin","r+b");

	 int registro;

	 for (i = m.begin(); i!=m.end();i++){

			 registro=(*i).second;

			 fseek(alumnosaux,(registro-1)*sizeof(mialumno),0);
			 fread(&alumno,sizeof(mialumno),1,alumnosaux);

			 cout << "----------------------------" << endl;
			 cout << "Media: " << ((alumno.nota1+alumno.nota2+alumno.nota3)/3) << endl;
			 cout << "DNI: " << alumno.DNI << endl;
			 cout << "Nombre: "<< alumno.apellido << endl;
			 cout << "Registro: "<< alumno.clase << endl;
			 cout << "Nota1: "<< alumno.nota1 << endl;
			 cout << "Nota2: "<< alumno.nota2 << endl;
			 cout << "Nota3: "<< alumno.nota3 << endl;
			 cout << "----------------------------" << endl;
	 }
	 fclose(alumnosaux);
}
