#pragma once

#include "Entity.hpp"


class Enemy2 : public Entity
{
public:
    void Start(Vec2 _pos);
    void Update();
    int difficulty = 0;
private:
    int m_health = 10 + difficulty;
    int m_coins = 4 + difficulty;
};