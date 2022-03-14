#include <stdio.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	
	MYSQL *conn;
	int err;
	char consulta [80];
	conn = mysql_init(NULL);
	
	if (conn==NULL)
	{
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "BBDDJuego",0, NULL, 0);
	if (conn==NULL)
	{
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	// Numero de partidas ganadas por el jugador pasado por pantalla
	
	char jugador[80];
	
	//Recibir identificador de la partida donde ha ganado
	
	printf(" Nombre del jugador \n");
	scanf("%s", jugador);
	strcpy (consulta,"SELECT Partidas.IDp FROM (Jugadores,Partidas,Participacion) WHERE Jugadores.username = '"); 
	strcat (consulta, jugador);
	strcat (consulta,"' AND Jugadores.IDj = Participacion.Jugador AND Participacion.Partida = Partias.IDp");
	
	err=mysql_query (conn, consulta);
	
	if (err!=0)
	{
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//recogemos el resultado de la consulta 
	resultado = mysql_store_result (conn); 
	row = mysql_fetch_row (resultado);
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
	{
		int i = 0;
		int cont = 0;
		while (row[i] != NULL)
		{
			cont = cont + 1;
			i = i + 1;
		}
		
		printf(" El numero de partidas ganadas por %s es: %d \n", jugador, &contador);
	}
	
	
	
	// cerrar la conexion con el servidor MYSQL 
	mysql_close (conn);
	exit(0);
	
}

