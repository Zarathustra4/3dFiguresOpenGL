#include "EdgeFigureUtil.h"
#include "EdgeTypeEnum.h"
#include "PlaneTypeEnum.h"
#include "Plane.h"
#include "PlaneFigure.h"


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

void setCubePoints(Matrix& cube) {
    cube.setRow(0, vector <double>({ 0, 0, 0, 1 }));
    cube.setRow(1, vector <double>({ 1, 0, 0, 1 }));
    cube.setRow(2, vector <double>({ 1, 1, 0, 1 }));
    cube.setRow(3, vector <double>({ 0, 1, 0, 1 }));
    cube.setRow(4, vector <double>({ 0, 0, 1, 1 }));
    cube.setRow(5, vector <double>({ 0, 1, 1, 1 }));
    cube.setRow(6, vector <double>({ 1, 1, 1, 1 }));
    cube.setRow(7, vector <double>({ 1, 0, 1, 1 }));
}

PlaneFigure EdgeFigureUtil::getCube() {
    //TODO: do something with it!!!
    float green[3] = { 0, 1, 0 };
    float red[3] = { 1, 0, 0 };
    float blue[3] = { 0, 0, 1 };
    float yellow[3] = { 1, 1, 0 };
    float black[3] = { 0, 0, 0 };
    float purple[3] = { 1, 0 , 1 };


    Matrix cube = Matrix(8, 4);
    setCubePoints(cube);


    Point A = Point("A", 0, black);
    Point B = Point("B", 1, black);
    Point C = Point("C", 2, black);
    Point D = Point("D", 3, black);
    Point E = Point("E", 4, black);
    Point F = Point("F", 5, black);
    Point G = Point("G", 6, black);
    Point J = Point("J", 7, black);


    vector<Point> points = vector<Point>({
            A, B, C, D, E, F, G, J
        });

    vector<Plane> planes = vector<Plane>(
        {
            Plane(vector<Point>({A, E, J, B}), green),
            Plane(vector<Point>({E, F, G, J}), purple),
            Plane(vector<Point>({A, E, F, D}), yellow),
            Plane(vector<Point>({D, F, G, C}), green),
            Plane(vector<Point>({A, B, C, D}), purple),
            Plane(vector<Point>({B, J, G, C}), yellow)
        }
    );

    return PlaneFigure(planes, cube, points);
}

PlaneFigure EdgeFigureUtil::getPlanePiramid() {
    Matrix piramid = Matrix(6, 4);
    setPiramidPoints(piramid);

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

    vector<Plane> planes = vector<Plane>(
        {
            Plane(vector<Point>({A, B, C, D}), black, MULTI_COLOR),
            Plane(vector<Point>({A, B, H}), black, MULTI_COLOR),
            Plane(vector<Point>({A, D, H}), black, MULTI_COLOR),
            Plane(vector<Point>({D, C, H}), black, MULTI_COLOR),
            Plane(vector<Point>({C, B, H}), black, MULTI_COLOR),
        }
    );

    return PlaneFigure(planes, piramid, vector<Point>());
}