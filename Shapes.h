#pragma once
#include "Point2D.h"

class Triangle
{
public:
	Point2D* p[3];
	Triangle(Point2D* p1, Point2D* p2, Point2D* p3);
};

class Rectangle
{
public:
	Point2D* a, * b;
	Rectangle(Point2D* p1, Point2D* p2);
};

class Circle {
public:
	Point2D* a;
	unsigned int r;
	Circle(Point2D* p1, unsigned int r);
};

class Ellipse {
public:
	Point2D* a;
	unsigned int rx, ry;
	Ellipse(Point2D* p1, unsigned int rx, unsigned int ry);
};
/*
class Polygon
{
    enum : char { TO_FREE, FOR_FREE };
    struct list {
        Point2D* p;
        struct list* next;
        char alType;
    };
    struct list* current;
    struct list* list;
    struct list* createItem();

public:
    unsigned long len;
    Polygon();
    ~Polygon();
    void add(unsigned int x, unsigned int y);
    void add(Point2D* p);
    Point2D* getPoint();
    int next();
    void Reset();
    int isFree();
};
*/