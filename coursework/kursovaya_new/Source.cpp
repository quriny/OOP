#include "Header.h"
// Функция для преобразования строки в матрицу
vector<vector<int>> stringToMatrix(string input) {
    vector<vector<int>> matrix;
    istringstream iss(input);

    // Пропуск открывающей квадратной скобки
    iss.ignore(1);

    string line;

    // Построчное считывание строки и преобразование в матрицу
    while (getline(iss, line, ';')) {
        istringstream rowStream(line);
        vector<int> row;

        // Чтение чисел из строки и добавление их в текущую строку матрицы
        int num;
        while (rowStream >> num) {
            row.push_back(num);
        }

        // Добавление текущей строки в матрицу
        matrix.push_back(row);
    }

    return matrix;
}
// Функция для вывода матрицы
void printMatrix(vector<vector<int>> matrix) {
    for (auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}
