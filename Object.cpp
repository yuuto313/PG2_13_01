#include "Object.h"

Object::Object()
{
	pos_ = {};
	vel_ = {};
	radius_ = {};
	coolDown_ = {};
	
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
	return pos_;
}

float Object::GetRadius() const
{
	return radius_;
}

