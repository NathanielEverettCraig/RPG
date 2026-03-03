#pragma once

#include "Entity.hpp"


class Enemy1 : public Entity
{
public:
    void Start(Vec2 _pos);
    void Update();
    int difficulty = 0;
private:
    int m_health = 5 + difficulty;
    int m_coins = 2;
};