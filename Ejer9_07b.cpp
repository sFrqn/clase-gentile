#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

/// Ejercicio 9.7
/// En una olimpíada estudiantil compiten N alumnos en 3 pruebas (1: matemáticas, 2:
/// física y 3: computación). Se ingresan por cada inscripto el DNI y su número
/// asignado para la competencia (entre 1 y N). Luego, sin orden alguno, se van
/// ingresando ternas con los puntajes de cada prueba: número de participante, código
/// de prueba, y puntaje en la actividad. Escriba un algoritmo que determine:
/// a) El DNI del ganador de la competencia y el puntaje total obtenido.
/// b) El DNI del estudiante que ocupó el 2do lugar y su puntaje.
/// c) ¿Qué puntaje obtuvo en Computación el ganador de la competencia?

vector<int> ganadores(const matrix<int> &M) {
	vector<int> G;
	int p1 = 0, m1;
	int p2 = 0, m2;
	for(size_t i=0;i<M.size(0);i++) {
		int puntaje = 0;
		for(size_t j=0;j<M.size(1);j++) {
			puntaje += M[i][j];
		}
		
		if (puntaje > p1) {
			// 1er paso, el mayor 1 pasa al mayor 2 actual
			m2 = m1;
			p2 = p1;
			// 2do paso, actualizamos el mayor 1
			m1 = i;
			p1 = puntaje;
		} else if (puntaje > p2) {
			// 3er paso, actualizar sólo el segundo mayor
			m2 = i;
			p2 = puntaje;
		}
	}
	
	G.push_back(m1); // pos 0 >> cod participante ganador
	G.push_back(p1); // pos 1 >> puntaje ganador
	G.push_back(m2); // pos 2 >> cod participante segundo
	G.push_back(p2); // pos 3 >> puntaje segundo
	
	return G;
}

int main() {
	int N, dni;
	int ncomp, npart, punt;
	
	cout << "Ingrese la cantidad de inscriptos: ";
	cin >> N;
	
	vector<int> Documentos;
	matrix<int> Puntajes(N,3,0);

	for(int i=0;i<N;i++) {
		cout << "DNI " << i+1 << ": ";
		cin >> dni;
		Documentos.push_back(dni);
	}
	
	// Si se ingresa competicion 100, se sale
	cout << "Ingrese el nro. competicion: ";
	cin >> ncomp;
	while(ncomp != 100) {
		cout << "Ingrese el nro. participante: ";
		cin >> npart;
		cout << "Ingrese el puntaje: ";
		
		cin >> punt;
		
		Puntajes[npart][ncomp] += punt;
		
		cout << "Ingrese el nro. competicion: ";
		cin >> ncomp;
	}
	
	/// a)
	vector<int> G = ganadores(Puntajes);
	
	cout << "Ganador: " << Documentos[G[0]] << ", puntaje: " << G[1] << endl;
	
	/// b)
	cout << "Segundo: " << Documentos[G[2]] << ", puntaje: " << G[3] << endl;
	
	/// c)
	cout << "Puntaje en comp. del ganador: " << Puntajes[G[0]][2];
	
	/// c bis)
	cout << "Puntaje en fisica del segundo: " << Puntajes[G[2]][1];
	
	return 0;
}

