//se le pasan dos l�mites como par�metros, devuelve un n�mero al azar entre los dos l�mites.
int azar(int min, int max){

	return (rand()%(max-min+1)+min);

}
