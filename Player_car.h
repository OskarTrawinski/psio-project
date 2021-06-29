//
// Created by Oskar Trawiński on 15/05/2021.
//

#ifndef PROJECT_PSIO_PLAYER_CAR_H
#define PROJECT_PSIO_PLAYER_CAR_H

#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Car.h"

class Player_car : public Car {
public:
    int _points;

    Player_car();
    void setSkin(float  x, float y);
    void Move_player(sf::Time &elapsed);
    void Points_counting();
    void Skin_select(sf::Vector2i &mouse_pos);

private:
    float _skin_x;
    float _skin_y;
};

#endif //PROJECT_PSIO_PLAYER_CAR_H
