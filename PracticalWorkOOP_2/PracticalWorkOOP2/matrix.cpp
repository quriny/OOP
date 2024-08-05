#include "matrix.h"
#include <iostream>
using namespace std;
void InputMatrix(int* array[], int rows, int cols){
	for (int i = 0;i<rows;++i) {
		for (int j = 0;j<cols;++j) {
				cout << "������� �������� ������ ������� [" << i << "][" << j << "]" << endl;
				cin >> array[i][j];
				if (cin.fail()) {
					cout << "�� ����� �� ����� ��� ��������� ������ ������." << endl;
					break;
				}
		}
	}
}
void ShowMatrix(int* array[], int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << *(*(array+i)+j) << " ";
		}
		cout << endl;
	}
}
void ElementMultiplication(int* array1[], int* array2[], int rows, int cols) {
	for (int i = 0;i<rows;++i) {
		for (int j = 0;j<cols;++j) {
			array1[i][j] = array1[i][j] * array2[i][j];
		}
	}
}

//������� �������� ��� ��������� ��������
//������� ����������� ���������� ������