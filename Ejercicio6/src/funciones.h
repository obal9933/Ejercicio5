
string encriptaclave(string clave){
int i, final=clave.length();
char letra;

string resultado;

for(i=0;i<final;i++){
	letra=clave[i]+2;
	resultado=resultado+letra;
}

return resultado;
}

string desencriptaclave(string clave){
int i, final=clave.length();
char letra;

string resultado;

for(i=0;i<final;i++){
	letra=clave[i]-2;
	resultado=resultado+letra;
}

return resultado;
}

bool valida_clave(string clave){
	string validos="QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

	int i, final, busqueda;

	final=clave.length();

	for(i=0;i<final;i++){
		busqueda=validos.find(clave[i]);

		if(busqueda==-1){
			return false;
		}
	}

	return true;

}

bool existencia_usuario(mapa_acceso mapa_claves, string usuario){

	if(mapa_claves.find(usuario)==mapa_claves.end()){
		return false;
	}else{
		return true;
	}

}

bool validar_clavedeusuario(mapa_acceso mapa_claves, string usuario, string clave){
	mapa_acceso::iterator i;

	i=mapa_claves.find(usuario);

	clave=encriptaclave(clave);

	if((*i).second==clave){
		return true;
	}else{
		return false;
	}

}

void introducir_usuario(mapa_acceso& mapa_claves){

string usuario, clave;

do{
	usuario=leer("Introduce el nombre de usuario");
}while(existencia_usuario(mapa_claves, usuario));

do{
	clave=leer("Introduce contraseña // Solo puede contener, mayúsculas, minúsculas y números");
}while(!valida_clave(clave));

clave=encriptaclave(clave);

mapa_claves.insert(pair<string, string>(usuario,clave));

}

void borrar_usuario(mapa_acceso& mapa_claves){

	string usuario, clave;
	bool flag;

	do{
		flag=true;

		usuario=leer("Introduce el nombre de usuario // 00 para salir");
		clave=leer("Introduce contraseña // Solo puede contener, mayúsculas, minúsculas y números");

		if(!valida_clave(clave)){
			cout << "clave no válida" << endl;
			flag=false;
		}

		if(!existencia_usuario(mapa_claves, usuario)){
			cout << "El usuario no existe" << endl;
			flag=false;
		}


		if (!validar_clavedeusuario(mapa_claves,usuario,clave)) {
			cout << "El usuario o la contraseña introducidos no son correctos" << endl;
			flag=false;
		}

	}while(!flag && usuario!="00");

	if(flag){
	mapa_claves.erase(usuario);
	cout << "usuario eliminado con éxito" << endl;
	}
}


void modificar_contrasena(mapa_acceso& mapa_claves){

	string usuario, clave, clave1;
	bool flag;

	do{
		flag=true;

		usuario=leer("Introduce el nombre de usuario // 00 para salir");
		clave=leer("Introduce contraseña actual // Solo puede contener, mayúsculas, minúsculas y números");

		if(!valida_clave(clave)){
			cout << "clave no válida" << endl;
			flag=false;
		}

		if(!existencia_usuario(mapa_claves, usuario)){
			cout << "El usuario no existe" << endl;
			flag=false;
		}

		if (!validar_clavedeusuario(mapa_claves,usuario,clave)) {
			cout << "El usuario o la contraseña introducidos no son correctos" << endl;
			flag=false;
		}

	}while(!flag && usuario!="00");

	if(flag){

		do{
			clave=leer("Introduce nueva contrasena");
			clave1=leer("Introduce otra vez la nueva contrasena // debe coincidir");
		}while(clave!=clave1);

		mapa_acceso::iterator i;

		i=mapa_claves.find(usuario);

		clave=encriptaclave(clave);

		(*i).second=clave;

		cout << "Contraseña modificada con éxito" << endl;

		}
}

void validaraunusuario(mapa_acceso mapa_claves){

	string usuario, clave;

			usuario=leer("Introduce el nombre de usuario // 00 para salir");
			clave=leer("Introduce contraseña // Solo puede contener, mayúsculas, minúsculas y números");

			if(!valida_clave(clave)){
				cout << "clave no válida" << endl;
			}

			if(!existencia_usuario(mapa_claves, usuario)){
				cout << "El usuario no existe" << endl;
			}

			if (!validar_clavedeusuario(mapa_claves,usuario,clave)) {
				cout << "El usuario o la contraseña introducidos no son correctos" << endl;

			}


}
