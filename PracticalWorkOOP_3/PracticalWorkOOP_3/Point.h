#pragma once
struct Point {
	double x;
	double y;
	Point(double xi, double yi){
		x = xi;
		y = yi;
	}
	Point() {
		x = 0;
		y = 0;
	}
};
