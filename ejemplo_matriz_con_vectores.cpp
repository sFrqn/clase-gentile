#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> M;
	
	// guardamos una fila
	vector<int> fila0(10,0); M.push_back(fila0);
	vector<int> fila1(8,1); M.push_back(fila1);
	vector<int> fila2(10,2); M.push_back(fila2);
	vector<int> fila3(6,3); M.push_back(fila3);
	vector<int> fila4(10,4); M.push_back(fila4);
	
	for(int i=0;i<M.size();i++) { 
		for(int j=0;j<M[i].size();j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

