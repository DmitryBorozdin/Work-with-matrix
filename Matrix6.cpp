//Дана матрица размером N*M, необходимо посчитать суммы элементов в каждой строке и столбце.Вывести суммы строк в конце каждой строки,
//аналогично для столбцов: сумму под каждым стобцом
#include <iostream>
using namespace std;
int N, M;     //размер матрицы
int **arr;
int sum = 0, sum1 = 0;         //переменные для сумм строк и столбцов матрицы
void summi_strok_i_stolbcov();
int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите количество строк матрицы: ";        //ввод размера матрицы
	cin >> N;
	cout << "Введите количество столбцов матрицы: ";       
	cin >> M;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {                 //создание двумерного массива(матрицы)
		arr[i] = new int[M];
	}
	summi_strok_i_stolbcov();
	system("pause");
}

void summi_strok_i_stolbcov() {
	cout << "Матрица:" << endl << endl;
	for (int i = 0; i < N; i++) {               //заполнение матрицы рандомными числами и вывод её на экран
		for (int j = 0; j < M; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "Матрица с суммами:" << endl << endl;
	for (int i = 0; i < N; i++) {                   //подсчёт суммы в каждой строке и вывод её на экран
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << "\t";
			sum += arr[i][j];
		}
		cout << "\t" << sum << endl << endl;
		sum = 0;
	}
	cout << endl;
	for (int i = 0; i < M; i++) {                  //подсчёт суммы в каждом столбце и вывод её на экран
		for (int j = 0; j < N; j++) {
			sum1 += arr[j][i];
		}
		cout << sum1 << "\t";
		sum1 = 0;
	}
	cout << endl << endl;
}