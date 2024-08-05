#pragma once
#include "Point.h"
#include "Triangle.h"
int countLines(Point* points, int size, int** indices);
Point getClosestPoint(Point* points, int size);
int getMinLengthTriangle(Point* points, int size, Triangle& triangle);
double getDistance(Point p1, Point p2);