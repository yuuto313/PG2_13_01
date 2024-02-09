#include "Player.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::PlayerMove(char* keys)
{
	if (keys[DIK_A]) {
		vel_.x -= 4;
	}
	if (keys[DIK_D]) {
		vel_.x += 4;
	}
	if (pos_.x <= radius_) {
		vel_.x += 4;
	}
	if (pos_.x >= 1280 - radius_) {
		vel_.x -= 4;
	}

	pos_.x += vel_.x;
	vel_.x = 0;
}

void Player::BulletUpdate(char* keys)
{
	if (keys[DIK_SPACE] && coolDown_ == 0) {
   		playerBullets_.push_back(new Bullet(pos_));
		coolDown_ = 20;
	}

	if (coolDown_ >= 1) {
		--coolDown_;
	}


	auto itr = playerBullets_.begin();
	while (itr!=playerBullets_.end())
	{
		(*itr)->Update();

		if (!(*itr)->isShot_) {
			itr = playerBullets_.erase(itr);
		}
		else {
			++itr;
		}
	}
}

void Player::Init()
{
	pos_ = { 640.f,500.f };
	vel_ = { 0.f,0.f };
	radius_ = 13;

	coolDown_ = 0;
}

void Player::Update(char *keys)
{
	PlayerMove(keys);
	BulletUpdate(keys);
}

void Player::Update()
{
}

void Player::Draw()
{
	for (auto itr = playerBullets_.begin(); itr != playerBullets_.end(); ++itr) {
		(*itr)->Draw();
	}
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.f, WHITE, kFillModeSolid);
}
