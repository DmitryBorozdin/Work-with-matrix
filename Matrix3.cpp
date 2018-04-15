//Необходимо сформировать матрицу размером N*M из рандомных чисел в диапазоне [0;999], далее необходимо:
//1) Вывести эту матрицу на экран
//2) Посчитать количество 2-значных элементов матрицы
//3) Посчитать количество 3-значных элементов матрицы
//4) Найти среднее арифметическое 2-значных элементов матрицы
//5) найти среднее арифметическое 3-значных элементов матрицы
#include <iostream>
using namespace std;
int kolichestvo_dva_znaka = 0, kolichestvo_tri_znaka = 0;   //счётчики количества 2-значных и 3-значных элементов матрицы
int sum_dva_znaka = 0, sum_tri_znaka = 0;       //переменные для суммы 2 и 3-значных элементов
int sredn_dva_znaka, sredn_tri_znaka;     //переменные для среднего арифметического 2 и 3-значных элементов
int N, M;        //размеры матрицы
int **arr;        //двумерный массив для матрицы
int *dva_znaka_arr;  //массив для 2-значных элементов матрицы
int *tri_znaka_arr;    //массив для 3-значных элементов матрицы
void objavlenie_massivov();
void operacii_nad_matricey();

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер матрицы: ";             //ввод размеров матрицы с клавиатуры
	cin >> N >> M;
	objavlenie_massivov();
	operacii_nad_matricey();
	for (int i = 0; i < N; i++) {    //очистка оперативной памяти от выделенной памяти под массивы
		delete[] arr[i];
	}
	delete[] arr;
	delete[] dva_znaka_arr;
	delete[] tri_znaka_arr;
	system("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////
void objavlenie_massivov() {    //функция объявления массивов
	arr = new int*[N];            //создание двумерного массива(матрицы)
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
	}
	/////////////////////////////////////
	dva_znaka_arr = new int[N*M];             //создание массива для хранения 2-значных элементов матрицы
	for (int i = 0; i < N*M; i++) {
		dva_znaka_arr[i] = 0;
	}
	////////////////////////////////////
	tri_znaka_arr = new int[N*M];               //создание массива для хранения 3-значных элементов матрицы
	for (int i = 0; i < N*M; i++) {
		tri_znaka_arr[i] = 0;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void operacii_nad_matricey() {       //функция операций над матрицей
	cout << "Матрица: " << endl << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {         //заполнение двумерного массива(матрицы) рандомными числами [0;999] и вывод этой матрицы
			arr[i][j] = rand() % 999;         //на экран
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] >= 10 && arr[i][j] < 100) {            //поиск 2-значных элементов матрицы и занесение их массив
				dva_znaka_arr[kolichestvo_dva_znaka] = arr[i][j];        //для 2-значных элементов
				kolichestvo_dva_znaka++;
			}
			else if (arr[i][j] >= 100 && arr[i][j] < 1000) {     //поиск 3-значных элементов матрицы и занесение их массив
				tri_znaka_arr[kolichestvo_tri_znaka] = arr[i][j];        //для 3-значных элементов
				kolichestvo_tri_znaka++;;
			}
		}
	}
	for (int i = 0; i < kolichestvo_dva_znaka; i++) {
		sum_dva_znaka += dva_znaka_arr[i];                //вычисление суммы 2-значных элементов матрицы
	}
	sredn_dva_znaka = sum_dva_znaka / kolichestvo_dva_znaka;        //вычисление среднего арифметического 2-значных элементов матрицы
	for (int i = 0; i < kolichestvo_tri_znaka; i++) {
		sum_tri_znaka += tri_znaka_arr[i];                         //вычисление суммы 3-значных элементов матрицы
	}
	sredn_tri_znaka = sum_tri_znaka / kolichestvo_tri_znaka;    //вычисление среднего арифметического 2-значных элементов матрицы
	cout << "Среднее арифметическое 2-значных элементов матрицы: " << sredn_dva_znaka << endl;
	cout << "Среднее арифметическое 3-значных элементов матрицы: " << sredn_tri_znaka << endl;
	cout << endl;
}
