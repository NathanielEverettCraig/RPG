#include "Player.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Dice.hpp"
#include "Enemy1.hpp"

void Player::Start(Vec2 _pos) {
    m_character = 'P';
    m_position = _pos;
}

void Player::Update() {
    //while(request_char("hit w to continue: ") != 'w') {}

    char directionInput;

    do {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd');
    
    Vec2 direction(0.0f);

    switch (directionInput)
    {
    case 'w':
        direction = {0.0f, -1.0f};
        break;
    case 'a':
        direction = {-1.0f, 0.0f};
        break;
    case 's':
        direction = {0.0f, 1.0f};
        break;
    case 'd':
        direction = {1.0f, 0.0f};
        break;
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    Vec2 tryPos = m_position + direction;
    if (m_health == 0) {
        exit;
    }
    
    if (room->GetLocation(tryPos) == 'K') {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    if (room->GetLocation(tryPos) == 'C') {
        if (m_keyCount != 0) {
        m_keyCount--;
        m_coins++;
        room->ClearLocation(tryPos);
        }
    }

    if (room->GetLocation(tryPos) == 'L') {
        if (m_keyCount != 0) {
            m_keyCount--;
            
            int h = random_int(1, 20);
        if (m_health < 100) {
            m_health += h;
        }
        if (m_health > 100) {
            m_health += 100;
        }
            room->OpenDoor(tryPos);    
        }
    }

    if (room->GetLocation(tryPos) == ' ') {
        m_position = tryPos;
    }

    if (room->GetLocation(tryPos) == 'D') {
        int h = random_int(1, 20);
        if (m_health < 100) {
            m_health += h;
        }
        if (m_health > 100) {
            m_health += 100;
        } 
        

        room->OpenDoor(tryPos);
    }

    if (room->GetLocation(tryPos) == 'E') {
        int atk = random_int(1, 20);
        int dmg = random_int(1, 20);
        m_health -= dmg;
        request_char("m_health");
        if (atk > 5) {
        room->ClearLocation(tryPos);
        }
    }
    if (room->GetLocation(tryPos) == 'H') {
        int atk = random_int(1, 20);
        int dmg = random_int(1, 20);
        m_health -= dmg;
        request_char("m_health");
        if (atk > 10) {
        room->ClearLocation(tryPos);
        }
    }

}