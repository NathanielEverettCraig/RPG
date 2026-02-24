#pragma once

#include "fogpi/Math.hpp"

class Room;

class Entity {
    public:
        Room* room;

        virtual void Start(Vec2 _pos);
        virtual void Update();

    protected:
        Vec2 m_position;
        char m_character;
};