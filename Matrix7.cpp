//Дана квадратная матрица размером N, необходимо поменять местами её главную и побочную диагонали
#include <iostream>
using namespace std;
int N;      //размер матрицы
int **arr;  
int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер матрицы: ";        //ввод размера матрицы
	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {                 //создание двумерного массива(матрицы)
		arr[i] = new int[N];
	}
	cout << "Матрица:" << endl << endl;
	for (int i = 0; i < N; i++) {               //заполнение матрицы рандомными числами
		for (int j = 0; j < N; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < N; i++) {                     //перестановка главной и побочной диагоналей
		for (int j = 0; j < N; j++) {
			if (i == j) {
				swap(arr[i][j], arr[i][N - 1 - j]);
			}
		}
	}
	cout << "Матрица - результат: " << endl << endl;
	for (int i = 0; i < N; i++) {                                //вывод матрицы - результата на экран
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	system("pause");
}
