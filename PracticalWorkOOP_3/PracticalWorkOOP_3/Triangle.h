#pragma once
#include "Point.h"
#include <cmath>

class Triangle {
private: 
	Point p1, p2, p3;
public:
	//конструктор
	Triangle() {

	}
	Triangle(Point input_p1, Point input_p2, Point input_p3) {
		p1 = input_p1;
		p2 = input_p2;
		p3 = input_p3;
	}
	//считаем расстояние между точками по их координатам
	double getDistance(Point p1, Point p2) {
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	//считаем периметр
	double getPerimeter() {
		double a = getDistance(p1, p2);
		double b = getDistance(p2, p3);
		double c = getDistance(p3, p1);
		return a + b + c;
	}
	//считаем площадь
	double getSquare() {
		double a = getDistance(p1, p2);
		double b = getDistance(p2, p3);
		double c = getDistance(p3, p1);
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};
