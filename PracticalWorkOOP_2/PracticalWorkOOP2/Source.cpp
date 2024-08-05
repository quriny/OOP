// PracticalWorkOOP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "matrix.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

    int button = -1;
    int tmp = -1;
    int rows1 = 0; int cols1 = 0;
    int rows2 = 0; int cols2 = 0;
    int answer = -1;
    int** matrix1 = 0;
    int** matrix2 = 0;
    while (button != 4) {
        cout << "Выберите действие: " << endl << "1 - Вывод матрицы (или вектора) на консоль."
            << endl << "2 -  Ввод матрицы (или вектора) с консоли."
            << endl << "3 - Поэлементное умножение матриц."
            << endl << "4 - закончить работу."
            << endl;
        cin >> button;
        if (cin.fail()) {
            cout << "Вы ввели не число или произошла ошибка чтения." << endl;
            break;
        }
        switch (button) {
        case 1:
            if (rows1 != 0 && cols1 != 0 && rows2 != 0 && cols2 != 0) {
                cout << "Первая матрица: " << endl;
                ShowMatrix(matrix1, rows1, cols1);
                cout << "Вторая матрица: " << endl;
                ShowMatrix(matrix2, rows2, cols2);
            }
            else if(rows1 != 0 && cols1 != 0 && rows2 == 0 && cols2 == 0) {
                cout << "Первая матрица: " << endl;
                ShowMatrix(matrix1, rows1, cols1);
            }
            else if (rows1 == 0 && cols1 == 0 && rows2 != 0 && cols2 != 0) {
                cout << "Вторая матрица: " << endl;
                ShowMatrix(matrix2, rows2, cols2);
            }
            else if (rows1==0 && cols1==0 && rows2 == 0 && cols2 == 0) {
                cout << "Вы не ввели ни одной матрицы" << endl;
            }
            break;
        case 2:
            for (int i = 0; i < rows1; ++i) {
                delete[] matrix1[i];
            }
            delete[] matrix1;
            for (int i = 0; i < rows2; ++i) {
                delete[] matrix2[i];
            }
            delete[] matrix2;
            rows1 = 0; cols1 = 0;
            rows2 = 0; cols2 = 0;
            answer = -1;
            cout << "Хотите ввести первую матрицу? 1 - Да/2 - Нет" << endl;
            cin>>answer;
            if (cin.fail()) {
                cout << "Вы ввели не число или произошла ошибка чтения." << endl;
                break;
            }
            if (answer == 1) {
                cout << "Введите количество строк в первой матрице: " << endl;
                cin >> rows1;
                cout << "Введите количество столбцов в первой матрице: " << endl;
                cin >> cols1;
                matrix1 = new int* [rows1];
                for (int i = 0; i < rows1; ++i) {
                    matrix1[i] = new int[cols1];
                }
                InputMatrix(matrix1, rows1, cols1);
                answer = -1;
            }
            cout << "Хотите ввести вторую матрицу? 1 - Да/2 - Нет" << endl;
            cin >> answer;
            if (answer == 1) {
                cout << "Введите количество строк во второй матрице: " << endl;
                cin >> rows2;
                cout << "Введите количество столбцов во второй матрице: " << endl;
                cin >> cols2;
                matrix2 = new int* [rows2];
                for (int i = 0; i < rows2; ++i) {
                    matrix2[i] = new int[cols2];
                }
                InputMatrix(matrix2, rows2, cols2);
                answer = -1;
            }
            break;
        case 3:
            if (rows1==rows2 && cols1==cols2) {
                ElementMultiplication(matrix1, matrix2, rows1, cols1);
                cout << "Результат: " << endl;
                ShowMatrix(matrix1, rows1, cols1);
            }
            else {
                cout << "Операция невозможна." << endl;
            }
        }
    }
    for (int i = 0; i < rows1; ++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    for (int i = 0; i < rows2; ++i) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    rows1 = 0; cols1 = 0;
    rows2 = 0; cols2 = 0;
}
