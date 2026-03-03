#include "Player.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Dice.hpp"

void Player::Start(Vec2 _pos) {
    m_character = 'E';
    m_position = _pos;
}

void Player::Update() {
    //while(request_char("hit w to continue: ") != 'w') {}

    int x = RollDice();

    switch (x)
    {
    case x < 5:
        direction = {0.0f, -1.0f};
        break;
    case x > 5 && x < 10:
        direction = {-1.0f, 0.0f};
        break;
    case x > 10 && x < 15:
        direction = {0.0f, 1.0f};
        break;
    case x > 15:
        direction = {1.0f, 0.0f};
        break;
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    Vec2 tryPos = m_position + direction;
    
    if (room->GetLocation(tryPos) == ' ') {
        m_position = tryPos;
    }
}