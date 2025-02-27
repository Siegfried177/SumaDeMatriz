#include <iostream>
using std::cout;

const int M = 5; // M es la cantidad de filas
const int N = 5; // N es la cantidad de columnas
//int matriz[N][N] = { {1,2}, {3,4} };
//int matriz[N][N] = { {1,2,3}, {4,5,6}, {7,8,9} };
int matriz[M][N] = {
		{  7,  53, 183, 439, 863 },
		{ 497, 383, 563,  79, 973 },
		{ 287,  63, 343, 169, 583 },
		{ 627, 343, 773, 959, 943 },
		{ 767, 473, 103, 699, 303 }
};
const int O = M > N ? N : M; // O es el valor mas pequeño entre M y N
int nums_max[O], sum_max = 0, nums[N], forbidden[N] = { 0, 0, 0 };

void calculate(int n, int sum) {
	//cout << "Enter\n";
	if (n == O) return; // Caso base

	for (int i = 0; i < N; i++) {
		if (forbidden[i]) continue; // Si es una columna prohibida se salta
		sum += matriz[n][i];
		//cout << "Suma: " << sum << "\n";
		//cout << "Actual: " << matriz[n][i] << "\n";
		//cout << "Se prohibe " << i << "\n";
		forbidden[i] = 1;
		nums[n] = matriz[n][i];

		if (sum > sum_max) { // Si la suma actual es mayor a la suma máxima
			sum_max = sum;
			for (int j = 0; j < N; j++) 
				nums_max[j] = nums[j]; // Se actualiza el array de números que generan la suma máxima
		}

		calculate(n + 1, sum); // Siguiente iteración

		forbidden[i] = 0;
		nums[n] = 0;
		sum -= matriz[n][i];
		//cout << "Back\n";
		//cout << "Se libera " << i << "\n";
	}
}

int main()
{
	calculate(0, 0);
	cout << "Suma Maxima: " << sum_max;
	for (int j = 0; j < N; j++) {
		cout << " " << nums_max[j];
	}
}