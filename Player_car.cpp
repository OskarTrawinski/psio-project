//
// Created by Oskar Trawiński on 15/05/2021.
//

#include "Player_car.h"

Player_car::Player_car(){
    if (!_texture.loadFromFile("textures/cars/cars.png")){
        std::cout << "No texture found!" << std::endl;
    }

    _horizontal_position = 375.0;
    _vertical_position = 480;
    _speed = 100.0;
    _points = 0.0;
    _skin_x = 0.0;
    _skin_y = 0.0;

    _sprite.setTextureRect(sf::IntRect(_skin_x, _skin_y, 50, 90));
    _sprite.setTexture(_texture);
    _sprite.setPosition(_horizontal_position, _vertical_position);
    _sprite.setScale(1.2, 1.2);
}

void Player_car::Move_player(sf::Time &elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _horizontal_position = _sprite.getPosition().x;

        if (_sprite.getPosition().x+50 < 705.0) {
            _sprite.move(_speed*elapsed.asSeconds(), 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        _horizontal_position = _sprite.getPosition().x;

        if (_sprite.getPosition().x > 95.0){
            _sprite.move(-_speed*elapsed.asSeconds(), 0.0);
        }
    }
}

void Player_car::setSkin(float  x, float y) {
    _skin_x = x;
    _skin_y = y;

    _sprite.setTextureRect(sf::IntRect(_skin_x, _skin_y, 50, 90));
    _sprite.setPosition(_horizontal_position, _vertical_position);
}

void Player_car::Points_counting() {
    _points += 1.0;
}

