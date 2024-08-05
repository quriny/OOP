#include "Header.h"
// ������� ��� �������������� ������ � �������
vector<vector<int>> stringToMatrix(string input) {
    vector<vector<int>> matrix;
    istringstream iss(input);

    // ������� ����������� ���������� ������
    iss.ignore(1);

    string line;

    // ���������� ���������� ������ � �������������� � �������
    while (getline(iss, line, ';')) {
        istringstream rowStream(line);
        vector<int> row;

        // ������ ����� �� ������ � ���������� �� � ������� ������ �������
        int num;
        while (rowStream >> num) {
            row.push_back(num);
        }

        // ���������� ������� ������ � �������
        matrix.push_back(row);
    }

    return matrix;
}
// ������� ��� ������ �������
void printMatrix(vector<vector<int>> matrix) {
    for (auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}
