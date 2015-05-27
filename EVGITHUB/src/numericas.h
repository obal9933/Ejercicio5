//se le pasan dos límites como parámetros, devuelve un número al azar entre los dos límites.
int azar(int min, int max){

	return (rand()%(max-min+1)+min);

}
