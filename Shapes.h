#ifndef __SHAPES__
#define __SHAPES__
// Bo¿e ale¿ ja kocham robienie obiektów tam gdzie struktury by³y by lepsze
// moje hobby wrêcz
// OOP to by³ b³¹d za który wszyscy p³acimy (-:
class Point2D {
public:
    int x, y;
    Point2D(const unsigned int x, const unsigned int y);
    void moveBy(const int x, const int y);
    void moveTo(const unsigned int x, const unsigned int y);
    void GetCoordinates(int& outX, int& outY) const;
    void SetCoordinates(int newX, int newY);
    void DisplayCoordinates() const;
};
class LineSegment {
public:
    Point2D* a, * b;
    LineSegment(Point2D* a, Point2D* b);
};
class Triangle {
public:
    Point2D* points[3];
    Triangle(Point2D* p1, Point2D* p2, Point2D* p3);
};
class RightTriangle {
public:
    Point2D* a, * b;
    RightTriangle(Point2D* p1, Point2D* p2);
};
class Rectangle {
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
class Polygon {
    enum : char { TO_FREE, FOR_FREE };
    struct list {
        Point2D* p;
        struct list* next;
        char alType; // alType ~ allocation Type
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
#endif
