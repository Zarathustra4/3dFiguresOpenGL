#pragma once
#include "Point.h"
#include "PlaneTypeEnum.h"
#include <vector>
#include <iostream>

using std::vector;

class Plane
{
private:
	vector<Point> planePoints;
	float color[3];
	PlaneTypeEnum type;

public:
	Plane() {
		planePoints = vector<Point>();
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}

	Plane(vector<Point> planePoints, float color[3]) {
		this->planePoints = planePoints;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
		this->type = SINGLE_COLOR;
	}

	Plane(vector<Point> planePoints) {
		this->planePoints = planePoints;
		this->color[0] = 1;
		this->color[1] = 0;
		this->color[2] = 0;
		this->type = SINGLE_COLOR;
	}

	Plane(vector<Point> planePoints, float color[3], PlaneTypeEnum type) {
		this->planePoints = planePoints;
		this->type = type;
	}

	vector<Point> getPlanePoints() {
		return planePoints;
	}

	void getColor(float color[3]) {
		color[0] = this->color[0];
		color[1] = this->color[1];
		color[2] = this->color[2];
	}

	PlaneTypeEnum getType() {
		return type;
	}

	void printPlane() {
		std::cout << "[ " << color[0] << " " << color[1] << " " << color[2] << " ]" << std::endl;
	}
};

