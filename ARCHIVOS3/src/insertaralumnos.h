void insertar(mapa m, vector <int> huecos, int &altas, int bajas){

	int n=altas;

	FILE *alumnos;
	alumnos=fopen("C:\\Users\\usuario\\Desktop\\alumnos.bin","w+b");

	if(altas>=DIM){
		cout << "fichero de alumnos completo" << endl;
	}else{
	string apellido;// apellidos del alumno
	float nota1;//nota primera eval
	float nota2;// idem segunda
	float nota3;// idem tercera
	string DNI;

	mialumno alumno;

	apellido=leer("Introduce Nombre del alumno");
	nota1=leerfloat("Introduce la nota de la primera evaluación");
	nota2=leerfloat("Introduce la nota de la segunda evaluación");
	nota3=leerfloat("Introduce la nota de la tercera evaluación");
	DNI=leer("Introduce DNI");

	strcpy(alumno.DNI,DNI.c_str());
	strcpy(alumno.apellido,apellido.c_str());
	alumno.nota1=nota1;
	alumno.nota2=nota2;
	alumno.nota3=nota3;

	if(bajas!=0){
		n=huecos[huecos.size()-1];
		huecos.pop_back();
	};

		fseek(alumnos,(n)*sizeof(mialumno),0);
		fwrite(&alumno,sizeof(mialumno),1,alumnos);
	}

	altas=altas+1;

	fclose(alumnos);
	}

