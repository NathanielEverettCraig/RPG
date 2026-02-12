#pragma once

#include <vector>

class Entity;
class Player;
class Monster;

class Room {
public:
    void Load(const char* _path);
    void Draw();
    void Update();
private:
    std::vector<Entity*> m_entities;
    Player* m_player;
    std::vector<Monster*> m_monsters;
};