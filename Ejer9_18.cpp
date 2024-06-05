#include <iostream>
#include <vector>
using namespace std;

/// Ejercicio 9.18
/// Un hospital lleva un registro de los pacientes internados: nombre, DNI, diagnóstico,
/// número de habitación. a) Defina un struct paciente con los datos mencionados. b)
/// Lea en un arreglo de pacientes los datos de N pacientes. Informe: c) En qué
/// habitación se encuentra internado el paciente "Cosme Fulanito" d) Cuántos
/// pacientes están internados con diagnóstico de "Apendicitis". e) Los datos del
/// paciente internado en la habitación 101.

/// a)
struct Paciente {
	string nombre = "";
	int dni = -1;
	string diagnostico = "";
	int habitacion = -1;
};

/// c)
int buscarHabitacion(const vector<Paciente> &v, string nombre) {
	for(int i=0;i<v.size();i++) { 
		if (v[i].nombre == nombre) {
			return v[i].habitacion;
		}
	}
	
	return -1;
}

/// d)
int cantidadPorDiagnostico(const vector<Paciente> &v, string diagnostico) {
	int cant = 0;
	for(int i=0;i<v.size();i++) { 
		if (v[i].diagnostico == diagnostico) {
			cant++;
		}
	}
	
	return cant;
}

/// e)
Paciente buscarPaciente(const vector<Paciente> &v, int habitacion) {
	Paciente aux;
	for(int i=0;i<v.size();i++) {
		if (v[i].habitacion == habitacion) {
			aux = v[i];
			break;
		}
	}
	
	return aux;
}

int main() {
	int N;
	cout << "Cantidad de pacientes: ";
	cin >> N;
	
	vector<Paciente> P;
	Paciente aux;
	
	/// b)
	for(int i=0;i<N;i++) { 
		cout << "Nombre: ";
		cin >> aux.nombre;
		cout << "DNI: ";
		cin >> aux.dni;
		cout << "Diagnostico: ";
		cin >> aux.diagnostico;
		cout << "Habitacion: ";
		cin >> aux.habitacion;
	}
	
	/// c)
	int hab = buscarHabitacion(P, "Cosme Fulanito");
	if (hab != -1) {
		cout << "Cosme Fulanito esta en la habitacion nro. " << hab << endl;
	} else {
		cout << "Cosme Fulanito no esta internado en este hospital." << endl;
	}
	
	/// d)
	cout << "Cantidad de pacientes con apendicitis: " << cantidadPorDiagnostico(P, "apendicitis") << endl;
	
	/// e)
	Paciente h101 = buscarPaciente(P,101);
	if (h101.dni != -1) {
		cout << "Paciente de la hab. 101: " << endl;
		cout << "Nombre: " << h101.nombre << endl;
		cout << "DNI: " << h101.dni << endl;
		cout << "Diagnostico: " << h101.diagnostico << endl;
	} else {
		cout << "No hay pacientes en la habitacion 101" << endl;
	}
	
	return 0;
}

