#pragma once
#include "Object.h"
#include "Bullet.h"
class Player :
    public Object
{
public:
    Player();
    ~Player();

    void PlayerMove(char *keys);
    void BulletUpdate(char* keys);

    void Init()override;
    void Update(char *keys);
    void Update()override;
    void Draw()override;

    std::vector<Bullet*>GetBullet() { return playerBullets_; };
private:
    std::vector<Bullet*>playerBullets_;

};

