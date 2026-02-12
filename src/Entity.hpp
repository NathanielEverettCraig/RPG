#pragma once

#include "fogpi/Math.hpp"

class Room;

class Entity {
    public:
        Room* room;

        virtual void Start();
        virtual void Update();

    protected:
        Vec2 m_position;
        char m_character;
};