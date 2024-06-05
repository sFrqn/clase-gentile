#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

/// Ejercicio 9.11
/// Declare un tipo struct con el nombre ficha_alumno indicando al menos 10 campos
/// de tipo simple o string correspondientes a los datos de un alumno de la UNL.
/// Luego declare 3 variables de ese tipo.

struct ficha_alumno {
	int documento;
	int fechaNacimento;
	string apellido;
	string nombre;
	string email;
	string domicilio;
};

struct Ganadores {
	int cod_ganador;
	int punt_ganador;
	int cod_segundo;
	int punt_segundo;
};

Ganadores buscarGanadores(matrix<int> Puntajes);

int main() {
	ficha_alumno F, F2, F3;
	
	F.documento = 12345678;
	F.fechaNacimento = 20000101;
	F.apellido = "Apellido";
	F.nombre = "Nombre";
	F.email = "test@test.com";
	F.domicilio = "Aca a la vuelta 123";
	
	matrix<int> M(10,3);
	Ganadores G = buscarGanadores(M);
	
	cout << G.cod_ganador << " " << G.punt_ganador;
	cout << G.cod_segundo << " " << G.punt_segundo;
	
	return 0;
}

