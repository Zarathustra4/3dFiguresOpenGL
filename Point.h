#include <string>
#include <iostream>
#pragma once

using std::string;

class Point
{
private:
	string name;
	int index; //index in matrix.
	float color[3]; //rgb values

public:
	Point() {
		name = "";
		index = -1;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}

	Point(string name, int index, float color[3]) {
		this->name = name;
		this->index = index;
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}

	inline string getName() {
		return name;
	}

	inline int getIndex() {
		return index;
	}

	inline float* getColor() {
		return color;
	}

	inline void getColor(float color[3]) {
		color[0] = this->color[0];
		color[1] = this->color[1];
		color[2] = this->color[2];
	}

	inline void setName(string name) {
		this->name = name;
	}

	inline void setName(char name) {
		this->name = name;
	}

	inline void setIndex(int index) {
		this->index = index;
	}

	inline void setColor(float color[3]) {
		this->color[0] = color[0];
		this->color[1] = color[1];
		this->color[2] = color[2];
	}

	void printPoint() {
		std::cout << "[ " << name << "; " << index
			<< "; (" << color[0] << ", " << color[1] << ", " << color[2] << ") ]" << std::endl;
	}
};

