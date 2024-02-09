#pragma once
#include "Object.h"
class Enemy :
    public Object
{
public:
    Enemy(float x,float y);
    ~Enemy();

    static bool isAlive;
    int downTime_;
    void EnemyMove();

    void Init()override;
    void Update()override;
    void Draw()override;
};

