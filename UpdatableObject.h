#pragma once
#include "GameObject.h"

class UpdatableObject : public virtual GameObject {
public:
	virtual void Update(float DT) = 0;
};