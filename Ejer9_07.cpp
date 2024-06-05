#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

/// Ejercicio 9.7
/// En una olimp�ada estudiantil compiten N alumnos en 3 pruebas (1: matem�ticas, 2:
/// f�sica y 3: computaci�n). Se ingresan por cada inscripto el DNI y su n�mero
/// asignado para la competencia (entre 1 y N). Luego, sin orden alguno, se van
/// ingresando ternas con los puntajes de cada prueba: n�mero de participante, c�digo
/// de prueba, y puntaje en la actividad. Escriba un algoritmo que determine:
/// a) El DNI del ganador de la competencia y el puntaje total obtenido.
/// b) El DNI del estudiante que ocup� el 2do lugar y su puntaje.
/// c) �Qu� puntaje obtuvo en Computaci�n el ganador de la competencia?

pair<pair<int,int>, pair<int,int>> ganadores(const matrix<int> &M) {
	pair<int, int> g1, g2;
	pair<pair<int,int>, pair<int,int>> G;
	
	int p1 = 0, m1;
	int p2 = 0, m2;
	for(int i=0;i<M.size(0);i++) {
		int puntaje = 0;
		for(int j=0;j<M.size(1);j++) {
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
			// 3er paso, actualizar s�lo el segundo mayor
			m2 = i;
			p2 = puntaje;
		}
	}
	
	g1.first = m1;
	g1.second = p1;
	g2.first = m2;
	g2.second = p2;
	
	G.first = g1;
	G.second = g2;
	
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
	
	return 0;
}

