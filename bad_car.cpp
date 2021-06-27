//
// Created by Oskar Trawiński on 18/05/2021.
//

#include "bad_car.h"

bad_car::bad_car() {
    if (!_texture.loadFromFile("textures/cars/truck.png"))
    {
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

void bad_car::Spawn_opponent() {
    _vertical_position = 0;
    _random = std::rand() % 5 + 1;

    if (_random == 1) {
        _horizontal_position = 90.0;
    }
    if (_random == 2){
        _horizontal_position = 200.0;
    }
    if (_random == 3){
        _horizontal_position = 320.0;
    }
    if (_random == 4){
        _horizontal_position = 460.0;
    }
    if (_random == 5){
        _horizontal_position = 570.0;
    }

    _sprite.setPosition(_horizontal_position, _vertical_position);
}

void bad_car::Animation_down(sf::Time &elapsed) {
    _vertical_position = _sprite.getPosition().y;

    if (_vertical_position < 600){
        _tmp = 0;

        _sprite.move(0.0, _speed*elapsed.asSeconds());
    }
    if (_vertical_position >= 598){
        Spawn_opponent();
        if (_tmp == 0){
            _tmp = 1;
        }
    }
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

