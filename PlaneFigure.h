#pragma once
#include "Plane.h"
#include "Point.h"
#include "Matrix.h"
#include <vector>

using std::vector;

class PlaneFigure
{
private:
	vector<Plane> planes;
	vector<Point> points;
	Matrix pointsMatrix;

public:
	PlaneFigure() {
		planes = vector<Plane>();
		pointsMatrix = Matrix();
	}

	PlaneFigure(vector<Plane> planes, Matrix pointsMatrix, vector<Point> points) {
		this->planes = planes;
		this->pointsMatrix = pointsMatrix;
		this->points = points;
	}

	vector<Plane> getPlanes() {
		return planes;
	}

	Matrix getPointsMatrix() {
		return pointsMatrix;
	}

	vector<Point> getPoints() {
		return points;
	}

	void setMatrix(Matrix matrix) {
		if (matrix.getShape() == pointsMatrix.getShape())
			this->pointsMatrix = matrix;
	}
};

