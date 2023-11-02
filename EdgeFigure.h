#include "Edge.h"
#include "Matrix.h"
#include "Point.h"
#include <vector>
#pragma once

using std::vector;

class EdgeFigure
{
private:
	vector<Edge> edges;
	vector<Point> points;
	Matrix pointsMatrix;

public:
	EdgeFigure() {
		edges = vector<Edge>();
		pointsMatrix = Matrix();
	}

	EdgeFigure(vector<Edge> edges, Matrix pointsMatrix, vector<Point> points) {
		this->edges = edges;
		this->pointsMatrix = pointsMatrix;
		this->points = points;
	}

	vector<Edge> getEdges() {
		return edges;
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