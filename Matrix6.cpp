//���� ������� �������� N*M, ���������� ��������� ����� ��������� � ������ ������ � �������.������� ����� ����� � ����� ������ ������,
//���������� ��� ��������: ����� ��� ������ �������
#include <iostream>
using namespace std;
int N, M;     //������ �������
int **arr;
int sum = 0, sum1 = 0;         //���������� ��� ���� ����� � �������� �������
void summi_strok_i_stolbcov();
int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ���������� ����� �������: ";        //���� ������� �������
	cin >> N;
	cout << "������� ���������� �������� �������: ";       
	cin >> M;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {                 //�������� ���������� �������(�������)
		arr[i] = new int[M];
	}
	summi_strok_i_stolbcov();
	system("pause");
}

void summi_strok_i_stolbcov() {
	cout << "�������:" << endl << endl;
	for (int i = 0; i < N; i++) {               //���������� ������� ���������� ������� � ����� � �� �����
		for (int j = 0; j < M; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "������� � �������:" << endl << endl;
	for (int i = 0; i < N; i++) {                   //������� ����� � ������ ������ � ����� � �� �����
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << "\t";
			sum += arr[i][j];
		}
		cout << "\t" << sum << endl << endl;
		sum = 0;
	}
	cout << endl;
	for (int i = 0; i < M; i++) {                  //������� ����� � ������ ������� � ����� � �� �����
		for (int j = 0; j < N; j++) {
			sum1 += arr[j][i];
		}
		cout << sum1 << "\t";
		sum1 = 0;
	}
	cout << endl << endl;
}