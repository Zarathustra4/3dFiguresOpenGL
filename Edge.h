#include "Point.h"
#include "Matrix.h"
#pragma once

class Edge
{
private:
	Point startPoint;
	Point endPoint;
	float color[3];

public:
	Edge() {
		startPoint = Point();
		endPoint = Point();
		color[0] = 0;
		color[1] = 0;
		color[1] = 0;
	};

	Edge(Point startPoint, Point endPoint, float color[3]) {
		this->startPoint = startPoint;
		this->endPoint = endPoint;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}

	Edge(Point startPoint, Point endPoint) {
		//default color is red
		this->startPoint = startPoint;
		this->endPoint = endPoint;
		this->color[0] = 1;
		this->color[1] = 0;
		this->color[2] = 0;
	}

	Point getStartPoint() {
		return startPoint;
	}

	Point getEndPoint() {
		return endPoint;
	}

	void setEdgePoints(Point startPoint, Point endPoint) {
		this->startPoint = startPoint;
		this->endPoint = endPoint;
	}

	float* getColor() {
		return color;
	}

	void getColor(float color[3]) {
		color[0] = this->color[0];
		color[1] = this->color[1];
		color[2] = this->color[2];
	}

	void setColor(float color[3]) {
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}
};

