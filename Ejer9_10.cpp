#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

/// Ejercicio 9.10
/// Se leen los datos de una matriz o tabla de 5x12 que contiene los valores en mm de
/// lluvias producidas en 5 departamentos de la provincia durante los 12 meses de
/// 2005. Se sabe que en algunos departamentos tienen datos faltantes por lo que
/// aparecen valores negativos (-1) en cada uno de esos casos. Escriba un programa
/// C++ que: a) complete los datos de lluvia faltantes con el promedio anual de
/// precipitación en el departamento correspondiente. Cada promedio debe obtenerse
/// con los datos reales existentes (no contar los -1). b) Amplíe la matriz agregando
/// una nueva columna con los totales de mm caídos en todo el año en cada
/// departamento. Informe: 1) la matriz original de datos, 2) la matriz modificada y 3)
/// los totales anuales de lluvia por departamento.

int main() {
	matrix<int> Lluvias(5,13,-1);
	int dpto, mes;
	
	cout << "Ingrese el cod. dpto. [1-5]: ";
	cin >> dpto;
	while(dpto !=0) {
		cout << "Ingrese el mes [1-12]: ";
		cin >> mes;
		
		cout << "Ingrese la cantidad de mm de lluvia: ";
		cin >> Lluvias[dpto-1][mes-1];
		
		cout << "Ingrese el cod. dpto. [1-5]: ";
		cin >> dpto;
	}
	
	cout << "Matriz original: " << endl;
	for(int i=0;i<Lluvias.size(0);i++) {
		for(int j=0;j<Lluvias.size(1)-1;j++) {
			cout << Lluvias[i][j] << " ";
		}
		cout << endl;
	}
	
	/// a)
	for(int i=0;i<Lluvias.size(0);i++) {
		// paso 1 >>> obtener el promedio
		int suma = 0;
		int cont = 0;
		for(int j=0;j<Lluvias.size(1);j++) {
			if (Lluvias[i][j] != -1) {
				suma += Lluvias[i][j];
				cont++;
			}
		}
		int prom = suma / cont;
		/// b)
		Lluvias[i][12] = suma;
		
		// paso 2 >>> reemplazar -1 por el promedio departamental
		for(int j=0;j<Lluvias.size(1);j++) {
			if (Lluvias[i][j] == -1) {
				Lluvias[i][j] = prom;
			}
		}
	}
	
	cout << "Matriz modificada: " << endl;
	for(int i=0;i<Lluvias.size(0);i++) {
		for(int j=0;j<Lluvias.size(1)-1;j++) {
			cout << Lluvias[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Totales anuales de lluvia por dpto: " << endl;
	for(int i=0;i<Lluvias.size(0);i++) {
		cout << Lluvias[i][12] << endl;
	}
	
	return 0;
}

