#include "Enemy.h"

bool Enemy::isAlive = true;

Enemy::Enemy(float x,float y)
{
	pos_ = {x,y};
	vel_ = { 6.f,0 };
	radius_ = 20.f; 

	coolDown_ = {};
	downTime_ = 120;
}

Enemy::~Enemy()
{
}

void Enemy::EnemyMove()
{
	pos_.x += vel_.x;
	if (pos_.x <= radius_ || pos_.x >= 1280 - radius_) {
		vel_.x *= -1;
	}

	if (isAlive == false) {
		--downTime_;
	}
	if (downTime_ <= 0) {
		isAlive = true;
		downTime_ = 120;
	}
}

void Enemy::Init()
{
	
}

void Enemy::Update()
{
	EnemyMove();
}

void Enemy::Draw()
{
	if (isAlive) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, RED, kFillModeSolid);
	}
}
