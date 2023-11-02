#include "Point.h"
#include "Edge.h"
#include "EdgeFigure.h"
#include "EdgeTypeEnum.h"
#include "PlaneTypeEnum.h"
#include "PlaneFigure.h"
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

			if (edge.getType() == DASHED) {
				glEnable(GL_LINE_STIPPLE);
				glLineStipple(1, 0x00FF); 
			}

			glBegin(GL_LINES);
			glVertex3d(
				coordinates[0], coordinates[1], coordinates[2]
			);

			coordinates = pointsMatrix.getRow(endPoint.getIndex());
			glVertex3d(
				coordinates[0], coordinates[1], coordinates[2]
			);
			
			glEnd();

			if (edge.getType() == DASHED) {
				glDisable(GL_LINE_STIPPLE);
			}
		}
	}

	static void drawPoints(vector<Point>& points, Matrix& pointsMatrix) {
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

	static void drawMultiColorPlane(Plane& plane, Matrix &pointsMatrix) {
		vector<double> coordinates;
		float color[3] = { 1, 0, 0 };
		glBegin(GL_POLYGON);
		for (Point point : plane.getPlanePoints()) {
			coordinates = coordinates = pointsMatrix.getRow(point.getIndex());
			point.getColor(color);
			glColor3f(color[0], color[1], color[2]);
			glVertex3f(coordinates[0], coordinates[1], coordinates[2]);
		}
		glEnd();
	}

	static void drawSingleColorPlane(Plane& plane, Matrix& pointsMatrix) {
		vector<double> coordinates;
		glBegin(GL_POLYGON);
		for (Point point : plane.getPlanePoints()) {
			coordinates = pointsMatrix.getRow(point.getIndex());
			glVertex3d(coordinates[0], coordinates[1], coordinates[2]);
		}
		glEnd();
	}

	static void drawPlanes(vector<Plane>& planes, Matrix& pointsMatrix) {
		vector<double> coordinates;
		float color[3] = { 1, 0, 0 };

		for (Plane plane : planes) {
			plane.getColor(color);
			glColor3f(color[0], color[1], color[2]);

			switch (plane.getType())
			{
			case SINGLE_COLOR:
				drawSingleColorPlane(plane, pointsMatrix);
				break;
			case MULTI_COLOR:
				drawMultiColorPlane(plane, pointsMatrix);
				break;
			}
			
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

	static void drawPlaneFigure(PlaneFigure figure) {
		glPushMatrix();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		vector<Plane> planes = figure.getPlanes();
		Matrix pointsMatrix = figure.getPointsMatrix();

		drawPlanes(planes, pointsMatrix);
	}
};

