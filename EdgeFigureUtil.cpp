#include "EdgeFigureUtil.h"
#include "EdgeTypeEnum.h"


void setPiramidPoints(Matrix& piramid) {
    piramid.setRow(0, vector<double>({ .5,  -.5,    0, 1 }));
    piramid.setRow(1, vector<double>({ .5,  .5,     0, 1 }));
    piramid.setRow(2, vector<double>({ -.5, .5,     0, 1 }));
    piramid.setRow(3, vector<double>({ -.5, -.5,    0, 1 }));
    piramid.setRow(4, vector<double>({ 0,   0,      1, 1 }));
    piramid.setRow(5, vector<double>({ 0,   0,      0, 1 }));
}

EdgeFigure EdgeFigureUtil::getPiramid() {
    Matrix piramidPoints = Matrix(6, 4);
    setPiramidPoints(piramidPoints);

    float green[3] = { 0, 1, 0 };
    float red[3] = { 1, 0, 0 };
    float blue[3] = { 0, 0, 1 };
    float yellow[3] = { 1, 1, 0 };
    float black[3] = { 0, 0, 0 };

    Point A = Point("A", 0, green);
    Point B = Point("B", 1, blue);
    Point C = Point("C", 2, green);
    Point D = Point("D", 3, blue);
    Point H = Point("H", 4, red);
    Point O = Point("O", 5, black);

    vector<Point> points = vector<Point>({ A, B, C, D, H, O });

    vector<Edge> edges = vector<Edge>(
        {
            Edge(A, B, yellow),
            Edge(A, D, yellow),
            Edge(B, C, yellow),
            Edge(C, D, yellow),
            Edge(A, H, yellow),
            Edge(B, H, yellow),
            Edge(C, H, yellow),
            Edge(D, H, yellow),
            Edge(H, O, red, DASHED)
        }
    );

    return EdgeFigure(edges, piramidPoints, points);
}