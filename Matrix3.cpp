//���������� ������������ ������� �������� N*M �� ��������� ����� � ��������� [0;999], ����� ����������:
//1) ������� ��� ������� �� �����
//2) ��������� ���������� 2-������� ��������� �������
//3) ��������� ���������� 3-������� ��������� �������
//4) ����� ������� �������������� 2-������� ��������� �������
//5) ����� ������� �������������� 3-������� ��������� �������
#include <iostream>
using namespace std;
int kolichestvo_dva_znaka = 0, kolichestvo_tri_znaka = 0;   //�������� ���������� 2-������� � 3-������� ��������� �������
int sum_dva_znaka = 0, sum_tri_znaka = 0;       //���������� ��� ����� 2 � 3-������� ���������
int sredn_dva_znaka, sredn_tri_znaka;     //���������� ��� �������� ��������������� 2 � 3-������� ���������
int N, M;        //������� �������
int **arr;        //��������� ������ ��� �������
int *dva_znaka_arr;  //������ ��� 2-������� ��������� �������
int *tri_znaka_arr;    //������ ��� 3-������� ��������� �������
void objavlenie_massivov();
void operacii_nad_matricey();

int main() {
	setlocale(LC_ALL, "rus");
	cout << "������� ������ �������: ";             //���� �������� ������� � ����������
	cin >> N >> M;
	objavlenie_massivov();
	operacii_nad_matricey();
	for (int i = 0; i < N; i++) {    //������� ����������� ������ �� ���������� ������ ��� �������
		delete[] arr[i];
	}
	delete[] arr;
	delete[] dva_znaka_arr;
	delete[] tri_znaka_arr;
	system("pause");
}
//////////////////////////////////////////////////////////////////////////////////////////
void objavlenie_massivov() {    //������� ���������� ��������
	arr = new int*[N];            //�������� ���������� �������(�������)
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
	}
	/////////////////////////////////////
	dva_znaka_arr = new int[N*M];             //�������� ������� ��� �������� 2-������� ��������� �������
	for (int i = 0; i < N*M; i++) {
		dva_znaka_arr[i] = 0;
	}
	////////////////////////////////////
	tri_znaka_arr = new int[N*M];               //�������� ������� ��� �������� 3-������� ��������� �������
	for (int i = 0; i < N*M; i++) {
		tri_znaka_arr[i] = 0;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void operacii_nad_matricey() {       //������� �������� ��� ��������
	cout << "�������: " << endl << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {         //���������� ���������� �������(�������) ���������� ������� [0;999] � ����� ���� �������
			arr[i][j] = rand() % 999;         //�� �����
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] / 10 >= 0 && arr[i][j] / 10 < 10) {            //����� 2-������� ��������� ������� � ��������� �� ������
				dva_znaka_arr[kolichestvo_dva_znaka] = arr[i][j];        //��� 2-������� ���������
				kolichestvo_dva_znaka++;
			}
			else if (arr[i][j] / 10 >= 10 && arr[i][j] / 10 < 100) {     //����� 3-������� ��������� ������� � ��������� �� ������
				tri_znaka_arr[kolichestvo_tri_znaka] = arr[i][j];        //��� 3-������� ���������
				kolichestvo_tri_znaka++;;
			}
		}
	}
	for (int i = 0; i < kolichestvo_dva_znaka; i++) {
		sum_dva_znaka += dva_znaka_arr[i];                //���������� ����� 2-������� ��������� �������
	}
	sredn_dva_znaka = sum_dva_znaka / kolichestvo_dva_znaka;        //���������� �������� ��������������� 2-������� ��������� �������
	for (int i = 0; i < kolichestvo_tri_znaka; i++) {
		sum_tri_znaka += tri_znaka_arr[i];                         //���������� ����� 3-������� ��������� �������
	}
	sredn_tri_znaka = sum_tri_znaka / kolichestvo_tri_znaka;    //���������� �������� ��������������� 2-������� ��������� �������
	cout << "������� �������������� 2-������� ��������� �������: " << sredn_dva_znaka << endl;
	cout << "������� �������������� 3-������� ��������� �������: " << sredn_tri_znaka << endl;
	cout << endl;
}