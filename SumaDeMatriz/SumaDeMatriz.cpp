#include <iostream>
using std::cout;

const int M = 15; // M es la cantidad de filas
const int N = 15; // N es la cantidad de columnas
int find_max();

/*int matriz[M][N] = {
		{  7,  53, 183, 439, 863 },
		{ 497, 383, 563,  79, 973 },
		{ 287,  63, 343, 169, 583 },
		{ 627, 343, 773, 959, 943 },
		{ 767, 473, 103, 699, 303 }
};*/

int matriz[M][N] = {
		{  7,  53, 183, 439, 863, 497, 383, 563,  79, 973, 287,  63, 343, 169, 583 },
		{ 627, 343, 773, 959, 943, 767, 473, 103, 699, 303, 957, 703, 583, 639, 913 },
		{ 447, 283, 463,  29,  23, 487, 463, 993, 119, 883, 327, 493, 423, 159, 743 },
		{ 217, 623,   3, 399, 853, 407, 103, 983,  89, 463, 290, 516, 212, 462, 350 },
		{ 960, 376, 682, 962, 300, 780, 486, 502, 912, 800, 250, 346, 172, 812, 350 },
		{ 870, 456, 192, 162, 593, 473, 915,  45, 989, 873, 823, 965, 425, 329, 803 },
		{ 973, 965, 905, 919, 133, 673, 665, 235, 509, 613, 673, 815, 165, 992, 326 },
		{ 322, 148, 972, 962, 286, 255, 941, 541, 265, 323, 925, 281, 601,  95, 973 },
		{ 445, 721,  11, 525, 473,  65, 511, 164, 138, 672,  18, 428, 154, 448, 848 },
		{ 414, 456, 310, 312, 798, 104, 566, 520, 302, 248, 694, 976, 430, 392, 198 },
		{ 184, 829, 373, 181, 631, 101, 969, 613, 840, 740, 778, 458, 284, 760, 390 },
		{ 821, 461, 843, 513,  17, 901, 711, 993, 293, 157, 274,  94, 192, 156, 574 },
		{  34, 124,   4, 878, 450, 476, 712, 914, 838, 669, 875, 299, 823, 329, 699 },
		{ 815, 559, 813, 459, 522, 788, 168, 586, 966, 232, 308, 833, 251, 631, 107 },
		{ 813, 883, 451, 509, 615,  77, 281, 613, 459, 205, 380, 274, 302,  35, 805 }
};

int aux[M][N];

const int O = M > N ? N : M; // O es el valor mas pequeño entre M y N
int nums_max[O], sum_max = 0, nums[O], forbidden[O], max = find_max();

void make0() {
	for (int i = 0; i < O; i++) {
		forbidden[i] = 0;
	}
}

/*void show_aux() {

	for (int i = 0; i < O; i++) {
		for (int j = 0; j < O; j++) {
			int flag = -1;
			for (int k = 0; k < O; k++) {
				if (nums_max[k] == matriz[i][j]) {
					flag = k;
				}
			}
			if (flag != -1) aux[i][j] = nums_max[flag];
			else aux[i][j] = 0;
		}
	}
	cout << "\n";
	for (int i = 0; i < O; i++) {
		for (int j = 0; j < O; j++) {
			cout << aux[i][j] << " ";
		}
		cout << "\n";
	}
}*/

int find_max() {
	for (int i = 0; i < O; i++)
		for (int j = 0; j < O; j++) 
			if (max < matriz[i][j]) max = matriz[i][j];
	return max;
}

void calculate(int n, int sum) {
	//cout << "Enter\n";
	if (n == O) return; // Caso base

	for (int i = 0; i < N; i++) {
		//cout << "\n";
		if (forbidden[i]) continue; // Si es una columna prohibida se salta
		if (sum + (max * (N - n)) < sum_max) continue;
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
	make0();
	calculate(0, 0);
	cout << "Suma Maxima: " << sum_max << "\n";
	for (int j = 0; j < N; j++) {
		cout << nums_max[j] << " ";
	}

}