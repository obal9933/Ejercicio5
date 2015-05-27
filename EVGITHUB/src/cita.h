//definicion de la estructura micita
typedef struct
 {
	 int idcita;
	 int registro;// numero de registro donde se almacena
	 int numasegurado;//Identificador de paciente
	 char motivo[100];//motivo de la consulta
	 int hora;//Hora de la cita
	 char fecha[10];//Fecha de la cita
 } micita;
