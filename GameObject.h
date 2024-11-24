#pragma once
#include "BitmapHandler.h"
#include "PrimitiveRenderer.h"
#include "Shapes.h"
#include "Point2D.h"

class UpdatableObject
{
public:
	virtual void update();
};

class DrawableObject 
{
protected:
	PrimitiveRenderer* prender;
public:
	virtual void Draw();
};

class TransformableObject
{
protected:
	void _translate(Point2D* p, int x, int y0);//przesuniêcei o wektor
	void _rotate(Point2D *p, float a);//obrót w radianach
	void _rotate(Point2D *p, float a, int x, int y);//obrót w radianach wzglêdem punktu (x,y)
	void _scale(Point2D *p, float scale);//skaluje wzglêdem œrodka obiektu
	void _scale(Point2D* p, float scale, int x, int y);//skaluje wzglêdem punktu (x,y)

public:
	virtual void translate(int x, int y);
	virtual void rotate(float a);
	virtual void rotate(float a, int x, int y);
	virtual void scale(float scale);
	virtual void scale(float scale, int x, int y);
};

class AnimatedObject 
{
public:
	virtual void animate();
};

class GameObject : public DrawableObject, public TransformableObject
{};

class ShapeObject : public GameObject
{};

class LineSegmentP : public ShapeObject
{
public:
	virtual void translate(int x, int y);
	virtual void rotate(float a);
	virtual void rotate(float a, int x, int y);
	virtual void scale(float scale);
	virtual void scale(float scale, int x, int y);
	virtual void Draw();
	LineSegmentP(PrimitiveRenderer* pr, Point2D* p1, Point2D* p2);
	Point2D* p1, * p2;
};

class BitmapObject : public TransformableObject, public DrawableObject {
protected:
    BitmapHandler bh;
    long usedBitmap;
    void _translate(int x, int y);

public:
    int PosX, PosY;
    virtual void draw();
    virtual void translate(int x, int y);
    virtual void rotate(float a);
    virtual void rotate(float a, int x, int y);
    virtual void scale(float scale);
    virtual void scale(float scale, int x, int y);

    void setBitmap(long index);
    void addBitmap(const char* src);
};

class Sprite : public BitmapObject, public AnimatedObject {
protected:
    unsigned MaxRange = 0;
    unsigned MaxTypes = 0;
    unsigned uType = 0, uRange = 0;
    long* animationIndex;
    unsigned fpa = 10; // Frames Per Animation

public:

    Sprite(unsigned MaxRange, unsigned MaxTypes);
    virtual void draw();
    virtual void animate();
    virtual void translate(int x, int y);
    virtual void rotate(float a);
    virtual void rotate(float a, int x, int y);
    virtual void scale(float scale);
    virtual void scale(float scale, int x, int y);

    void next();
    void nextSector();
    void setSector(unsigned sector);
    void setFPA(unsigned amm);
    void newBmp(const char* src, unsigned range, unsigned type);
    virtual void afterAnimation();
};