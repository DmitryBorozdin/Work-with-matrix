//���� ���������� ������� �������� N, ���������� �������� ������� � ������� � �������� ���������
//
#include <iostream>
using namespace std;
int N;      //������ �������
int **arr;  
int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ������ �������: ";        //���� ������� �������
	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {                 //�������� ���������� �������(�������)
		arr[i] = new int[N];
	}
	cout << "�������:" << endl << endl;
	for (int i = 0; i < N; i++) {               //���������� ������� ���������� �������
		for (int j = 0; j < N; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < N; i++) {                     //������������ ������� � �������� ����������
		for (int j = 0; j < N; j++) {
			if (i == j) {
				swap(arr[i][j], arr[i][N - 1 - j]);
			}
		}
	}
	cout << "������� - ���������: " << endl << endl;
	for (int i = 0; i < N; i++) {                                //����� ������� - ���������� �� �����
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	system("pause");
}