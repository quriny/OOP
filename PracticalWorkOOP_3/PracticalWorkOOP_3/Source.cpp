#include "Header.h"
#include "Triangle.h"
double getDistance(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
// Ќайти все тройки точек массива, через которые можно провести пр€мую линию. 
// ¬озвращаемое значение - число найденных троек, 
// indices - двумерный массив с индексами точек (indices[1][2] - треть€ точка второй линии).
int countLines(Point* points, int size, int** indices) {

	return 0;
}
// Ќайти такую точку, сумма рассто€ний от которой до остальных точек множества минимальна.
Point getClosestPoint(Point* points, int size) {
	if (size == 0) {
		return {0, 0};
	}
	Point resp;
	int resDistance = 0;
	int sumDistance = 0;

	for (int i = 0;i<size;++i) {
		sumDistance = 0;
		for (int j = 0;j<size;++j) {
			if (i!=j) {
				sumDistance += getDistance(points[i], points[j]);
			}
		}
		if (resDistance==0) {
			resDistance = sumDistance;
			resp = points[i];
		}
		else if(resDistance > sumDistance) {
			resDistance = sumDistance;
			resp = points[i];
		}
	}
	return resp;
}
// Ќайти три точки, образующие треугольник наименьшего периметра. 
// ¬озвращаетс€ периметр найденного треугольника. 
int getMinLengthTriangle(Point* points, int size, Triangle& triangle) {
	int resPerimeter=0;
	Point p1, p2, p3;
	for (int i = 0;i<size-2;++i) {
		for (int j = i + 1;j<size-1;++j) {
			for (int k = j + 1;k<size;++k) {
				triangle = Triangle(points[i], points[j], points[k]);
				if (resPerimeter == 0 && triangle.getSquare() > 0) {
					resPerimeter = triangle.getPerimeter();
				}
				if (resPerimeter != 0 && resPerimeter > triangle.getPerimeter()) {
					resPerimeter = triangle.getPerimeter();
					p1 = points[i];
					p2 = points[j];
					p3 = points[k];
				}
			}
		}

	}
	triangle = Triangle(p1, p2, p3);
	return resPerimeter;
}