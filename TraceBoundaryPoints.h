#pragma once
#include<iostream>
#include<vector>
struct Point2D
{
	int X;
	int Y;
	Point2D()
	{
		X = 0;
		Y = 0;
	}
	Point2D(int X_i, int Y_i)
	{
		X = X_i;
		Y = Y_i;
	}
};
class TraceBoundaryPoints
{
public:
	TraceBoundaryPoints();
	~TraceBoundaryPoints();
	void GetContinousBoundaryPoints(unsigned char* InputImage, int Width_i, int Height_i, std::vector<Point2D>& BoundaryPoints);
};
