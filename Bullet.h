#pragma once
#include "Object.h"
class Bullet :
    public Object
{
public:
    Bullet(Vector2 pos);
    ~Bullet();

    bool isShot_;
    void BulletUpdate();

    void Init()override;
    void Update()override;
    void Draw()override;
};

