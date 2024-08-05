#include "Source.cpp"
int main() {
    // Пример строки с числами, заключенными в квадратные скобки и разделенными ;
    string inputString = "[1 2 3; 4 5 6; 7 8 9]";

    cout << inputString << endl;
    // Преобразование строки в матрицу
    vector<vector<int>> resultMatrix = stringToMatrix(inputString);

    // Вывод полученной матрицы
    printMatrix(resultMatrix);

    return 0;
}
