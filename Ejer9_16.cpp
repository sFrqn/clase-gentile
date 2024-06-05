#include <iostream>
using namespace std;

/// Ejercicio 9.16
/// a) Defina un struct para guardar notas de parciales de un alumno: apellido y
/// nombre, notas de dos parciales y sus respectivos recuperatorios (las instancias
/// que no rindió tendrán -1).
/// b) Defina otro struct para guardar el resultado final del cursado de un alumno:
/// apellido y nombre, condición final ("libre", "promocionado" o "regular") y nota final
/// (de 1 a 10, solo si promociona, será -1 en caso contrario).
/// c) Escriba una función que reciba una instancia del primer struct y retorne una del
/// segundo. La función debe calcular la condición y la nota final (redondeando el
/// promedio) según las reglas de esta materia.
/// d) Escriba un programa cliente para probar la función.

/// a)
struct Alumno {
	string apellido;
	string nombre;
	int nota_p1 = -1;
	int nota_p2 = -1;
	int nota_r1 = -1;
	int nota_r2 = -1;
};

struct Condicion {
	string apellido;
	string nombre;
	string resultado;
	int nota = -1;
};

int mayor(int a, int b) {
	if (a > b) return a;
	
	return b;
}

Condicion obtenerCondicion(Alumno A) {
	// Libre >>> no rindió alguna instancia o su promedio es 0-39
	// Regular >> rindió ambas instancias y su promedio es 40-69
	// Promovido >> rindió ambas instancias y su promedio es 70-100
	string resultado;
	int promedio = 0;
	if ((A.nota_p1 == -1 && A.nota_r1 == -1) || (A.nota_p2 == -1 && A.nota_r2 == -1)) {
		resultado = "libre";
	} else {
		int nota1 = mayor(A.nota_p1, A.nota_r1);
		int nota2 = mayor(A.nota_p2, A.nota_r2);
		promedio = (nota1 + nota2) / 2;
		
		if (promedio < 40) {
			resultado = "libre";
		} else if (promedio >= 40 && promedio < 70) {
			resultado = "regular";
		} else {
			resultado = "promocionado";
		}
	}
	
	Condicion C;
	C.apellido = A.apellido;
	C.nombre = A.nombre;
	C.resultado = resultado;
	C.nota = promedio;
	
	return C;
}

int main() {
	Alumno A;
	A.apellido = "Perez";
	A.nombre = "Juan";
	
	Condicion C = obtenerCondicion(A);
	
	cout << C.apellido << ", " << C.nombre << " - " << C.resultado << " (" << C.nota << ")" << endl;
	
	Alumno B;
	int p1,r1,p2,r2;
	B.apellido = "Pedro";
	B.nombre = "Gonzalez";
	
	cout << "Ingrese nota p1: ";
	cin >> p1;
	
	cout << "Ingrese nota r1: ";
	cin >> r1;
	
	cout << "Ingrese nota p2: ";
	cin >> p2;
	
	cout << "Ingrese nota r2: ";
	cin >> r2;
	
	B.nota_p1 = p1;
	B.nota_r1 = r1;
	B.nota_p2 = p2;
	B.nota_r2 = r2;
	
	C = obtenerCondicion(B);
	
	cout << C.apellido << ", " << C.nombre << " - " << C.resultado << " (" << C.nota << ")" << endl;
	
	return 0;
}

