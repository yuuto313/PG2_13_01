#include "Bullet.h"

Bullet::Bullet(Vector2 pos)
{
	pos_ = pos;
	vel_ = { 0,7 };
	radius_ = 5.f;
	coolDown_ = {};
	
	isShot_ = true;
}

Bullet::~Bullet()
{
}

void Bullet::BulletUpdate()
{
	pos_.y -= vel_.y;
	if (pos_.y <= 0) {
		isShot_ = false;
	}
}

void Bullet::Init()
{
}

void Bullet::Update()
{
	BulletUpdate();
}

void Bullet::Draw()
{
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, WHITE, kFillModeSolid);
}
