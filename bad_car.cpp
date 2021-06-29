//
// Created by Oskar Trawiński on 18/05/2021.
//

#include "bad_car.h"

bad_car::bad_car() {
    if (!_texture.loadFromFile("textures/cars/truck.png")) {
        std::cout << "Opponent car texture loading error!" << std::endl;
    }

    _sprite.setTexture(_texture);
    _sprite.setPosition(20.0, 20.0);
    _sprite.setScale(1.3, 1.3);
    _sprite.setRotation(180.0);
    _sprite.setOrigin(100.0, 100.0);

    _vertical_position = 0;
    _speed = (rand()%5)*25.0 + 200.0;
    _random = rand()%5+1;
    _tmp = 0;
    Spawn_opponent();
}

bool bad_car::Check_Collision(float left, float top) {
//right down corner of player car:
    if ((this->_vertical_position >= top) && (this->_vertical_position < top + 90) && (this->_horizontal_position <= left) && (this->_horizontal_position > left - 50)){
        return true;
    }
    //right top corner of player car:
    if ((this->_vertical_position <= top) && (this->_vertical_position > top - 90) && (this->_horizontal_position <= left) && (this->_horizontal_position > left - 50)){
        return true;
    }
}




