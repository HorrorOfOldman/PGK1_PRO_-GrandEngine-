/*#pragma once
#include "UpdatableObject.h"
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "BitmapHandler.h"
#include "AnimatedObject.h"
#include <allegro5/allegro.h>

class Player : public UpdatableObject, public DrawableObject, public TransformableObject
{
private:
	float speed;
	BitmapHandler bit;
	AnimatedObject Ufps;
	AnimatedObject Lfps;
	AnimatedObject Dfps;
	AnimatedObject Rfps;

public:

	Player(float SX = 300, float SY = 100);//punkty startowe gracza
	virtual void Draw(ALLEGRO_DISPLAY* display) override;
	void trans(float x, float y) override;
	void rotate(float a) override;
	void scal(float k) override;
	
	void MV(char dir);
	void Update(float DT) override;
	void init() override;
	void del() override;


};
*/