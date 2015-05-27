
void crearalumnos(int &altas, mapa &m){

int i,j;
mialumno alumno;
int aleatorio;
char numero;
string DNI;
FILE *alumnos;

string nombres[]={"Paco","Benito","Lucas","Diego","Daniel","Sonia","Lucia","Cristina","Sara","Pilar"};

alumnos=fopen("C:\\Users\\usuario\\Desktop\\alumnos.bin","w+b");

			for(i=1;i<=DIM;i++){
				alumno.clase=i;

				aleatorio=azar(0,9);

				strcpy( alumno.apellido, nombres[aleatorio].c_str() );

				alumno.nota1=(float)(azar(0,1000))/100;
				alumno.nota2=(float)(azar(0,1000))/100;
				alumno.nota3=(float)(azar(0,1000))/100;

				DNI="";

				for(j=0;j<8;j++){
					numero=azar(48,57);
					DNI=DNI+numero;
				}
				numero=azar(65,90);
				DNI=DNI+numero;

				strcpy(alumno.DNI, DNI.c_str());

				m.insert(pair<string,int>(alumno.DNI,alumno.clase));

				fwrite(&alumno,sizeof(mialumno),1,alumnos);

}
			fclose(alumnos);
cout << "Terminado de crear alumnos"<< endl;

}
