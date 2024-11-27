#include "Shapes.h"

Triangle::Triangle(Point2D* p1, Point2D* p2, Point2D* p3) 
{
	this->p[0] = p1;
	this->p[1] = p2;
	this->p[2] = p3;
}

Rectangle::Rectangle(Point2D* p1, Point2D* p2) 
{
	this->a = p1;
	this->b = p2;
}

Circle::Circle(Point2D* p1, unsigned int r) 
{
	this->a = p1;
	this->r = r;
}

Ellipse::Ellipse(Point2D* p1, unsigned int rx, unsigned int ry)
{
	this->a = p1;
	this->rx = rx;
	this->ry = ry;
}