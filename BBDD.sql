DROP DATABASE IF EXISTS BBDDJuego;
CREATE DATABASE BBDDJuego;

USE BBDDJuego;

CREATE TABLE Jugadores (
 	
	username VARCHAR(60),
	IDj INT,
	contraseña VARCHAR(60)
	

)ENGINE=InnoDB;

CREATE TABLE Partidas (

	fecha VARCHAR(60),
	duracion FLOAT,
	IDp INT,
	ganador VARCHAR(60)
	
)ENGINE=InnoDB;

CREATE TABLE Participacion (

	Jugador INT NOT NULL,
	Partida INT NOT NULL,
	Posicion INT NOT NULL

)ENGINE=InnoDB;
				
INSERT INTO Jugadores VALUES ('Pedro', 1, 'pedro1234');
INSERT INTO Jugadores VALUES ('Juan', 2, 'juan1234');
INSERT INTO Jugadores VALUES ('Marta', 3, 'marta1234');
INSERT INTO Jugadores VALUES ('Maria', 4, 'maria1234');


INSERT INTO Partidas VALUES ('Lunes', 10, 1, 'Pedro');
INSERT INTO Partidas VALUES ('Martes', 25, 2, 'Marta');
INSERT INTO Partidas VALUES ('Sabado', 32, 3, 'Pedro');
INSERT INTO Partidas VALUES ('Domingo', 12, 4, 'Juan');

INSERT INTO Participacion VALUES (1,1,1);
INSERT INTO Participacion VALUES (2,3,3);
INSERT INTO Participacion VALUES (3,2,2);
INSERT INTO Participacion VALUES (1,2,3);
INSERT INTO Participacion VALUES (2,2,4);
INSERT INTO Participacion VALUES (4,3,2);
INSERT INTO Participacion VALUES (3,3,4);
INSERT INTO Participacion VALUES (1,3,1);
INSERT INTO Participacion VALUES (2,4,3);












