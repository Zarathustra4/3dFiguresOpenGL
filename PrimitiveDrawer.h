#include "Point.h"
#include "Edge.h"
#include "EdgeFigure.h"
#include <GL/glut.h>
#include <iostream>
#pragma once

class PrimitiveDrawer
{
private:
	static void drawLines(vector<Edge> &edges, Matrix &pointsMatrix) {
		Point startPoint, endPoint;
		vector<double> coordinates;
		float color[3] = { 1, 0, 0 };
		
		for (Edge edge : edges) {
			startPoint = edge.getStartPoint();
			endPoint = edge.getEndPoint();
			edge.getColor(color);

			coordinates = pointsMatrix.getRow(startPoint.getIndex());
			glColor3f(color[0], color[1], color[2]);

			glBegin(GL_LINES);
			glVertex3d(
				coordinates[0], coordinates[1], coordinates[2]
			);

			coordinates = pointsMatrix.getRow(endPoint.getIndex());
			glVertex3d(
				coordinates[0], coordinates[1], coordinates[2]
			);
			glEnd();
		}
	}

	void static drawPoints(vector<Point>& points, Matrix& pointsMatrix) {
		vector<double> coordinates;
		float color[3] = { 1, 0, 0 };

		for (Point point : points) {
			point.getColor(color);
			coordinates = pointsMatrix.getRow(point.getIndex());

			glColor3f(color[0], color[1], color[2]);
			glPointSize(10.0f);

			glBegin(GL_POINTS);
			glVertex3d(
				coordinates[0], coordinates[1], coordinates[2]
			);
			glEnd();
		}
	}
public:

	static void drawEdgeFigure(EdgeFigure edgeFigure) {
		glPushMatrix();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		vector<Edge> edges = edgeFigure.getEdges();

		Matrix pointsMatrix = edgeFigure.getPointsMatrix();
		vector<Point> points = edgeFigure.getPoints();

		drawPoints(points, pointsMatrix);

		drawLines(edges, pointsMatrix);
	}
};

