#include "Object.h"

Object::Object()
{
	pos_ = {};
	vel_ = {};
	radius_ = {};
	coolDown_ = {};
	isAlive_ = {};
	range_ = {};
}

Object::~Object()
{
}

void Object::Init()
{
}

void Object::Update()
{
}

void Object::Draw()
{
}

Vector2 Object::GetPos() const
{
	return pos_
}

float Object::GetRadius() const
{
	return radius_;
}

float Object::GetRange() const
{
	return range_;
}

bool Object::ChackHitCircle()
{
	return isAlive_=false;
}
