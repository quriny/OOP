#pragma once
#include "Point.h"
#include <cmath>

class Triangle {
private: 
	Point p1, p2, p3;
public:
	//�����������
	Triangle() {

	}
	Triangle(Point input_p1, Point input_p2, Point input_p3) {
		p1 = input_p1;
		p2 = input_p2;
		p3 = input_p3;
	}
	//������� ���������� ����� ������� �� �� �����������
	double getDistance(Point p1, Point p2) {
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	//������� ��������
	double getPerimeter() {
		double a = getDistance(p1, p2);
		double b = getDistance(p2, p3);
		double c = getDistance(p3, p1);
		return a + b + c;
	}
	//������� �������
	double getSquare() {
		double a = getDistance(p1, p2);
		double b = getDistance(p2, p3);
		double c = getDistance(p3, p1);
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};
