#include "Enemy2.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Dice.hpp"

void Enemy2::Start(Vec2 _pos) {
    m_character = 'H';
    m_position = _pos;
}

void Enemy2::Update() {
    //while(request_char("hit w to continue: ") != 'w') {}
     Vec2 direction(0.0f);
    int x = random_int(1, 20);

    switch (x)
    {
    if (x < 5) {
        direction = {0.0f, -1.0f};
        break;
    }
    if (x > 5 && x < 10) {
        direction = {-1.0f, 0.0f};
        break;
    }
    if (x > 10 && x < 15) {
        direction = {0.0f, 1.0f};
        break;
    }
    if (x > 15) {
        direction = {1.0f, 0.0f};
        break;
    }
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    Vec2 tryPos = m_position + direction;
    
    if (room->GetLocation(tryPos) == ' ') {
        m_position = tryPos;
    }
}