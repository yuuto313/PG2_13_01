#pragma once
#include "Vector2.h"
#include "vector"
#include "Novice.h"
class Object
{
protected:
	Vector2 pos_;
	Vector2 vel_;
	float radius_;
	int coolDown_;

	
public:
	Object();
	~Object();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	Vector2 GetPos()const;
	float GetRadius()const;

};

