//  Point, Triangle  L3, P3, T4

// L3
// Найти все тройки точек массива, через которые можно провести прямую линию. 
// Возвращаемое значение - число найденных троек, 
// indices - двумерный массив с индексами точек (indices[1][2] - третья точка второй линии).
// int countLines(Point* points, int size, int** indices);

// P3
// Найти такую точку, сумма расстояний от которой до остальных точек множества минимальна.
// Point getClosestPoint(Point* points, int size);

// T4
// Найти три точки, образующие треугольник наименьшего периметра. 
// Возвращается периметр найденного треугольника. 
// int getMinLengthTriangle(Point* points, int size, Triangle& triangle);

#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    int intV = (int('S') + int('K')) % 12;
    cout << intV << endl;

    Point p1(0, 0);
    Point p2(0, 3);
    Point p3(4, 0);
    Point p4(4, 3);

    Point* points = new Point[4];
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;

    Triangle result;
    int perimeter = getMinLengthTriangle(points, 4, result);
    cout << perimeter;


}

