#include "raylib.h"
#include "state.hpp"
#ifndef HUMAN_HPP
#define HUMAN_HPP

class human {
private:
public:
    Vector2 position = {0, 0};
    char name[32] = "Johnny Mc Bug";
    nationality nationality = "Stateless";

    human();
    ~human();
};
human::human() {
}

human::~human() {
}

#endif