#include <iostream>
using namespace std;
int **arr;
int N;
void sort();
int main() {
	setlocale(LC_ALL, "rus");
	cout << "¬ведите размер матрицы: ";
	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = -999 + (rand() % 2000);
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	sort();
	system("pause");
}
void sort() {
	int *arr1 = new int[N];
	for (int j = 0; j < N; j++) {
		arr1[j] = arr[0][j];
		cout << arr1[j] << " ";
	}
}