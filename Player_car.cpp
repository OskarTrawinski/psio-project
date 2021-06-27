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
    _points += 1;
}

void Player_car::Skin_select(sf::Vector2i &mouse_pos) {
    //first row in the shop:
    //set playre_car texture as car1 texture:
    if (mouse_pos.x > 50.0 && mouse_pos.x < 150.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
        setSkin(0.0, 0.0);
    }
    //set playre_car texture as car2 texture:
    if (mouse_pos.x > 200.0 && mouse_pos.x < 300.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
        setSkin(50.0, 0.0);
    }
    //set playre_car texture as car3 texture:
    if (mouse_pos.x > 350.0 && mouse_pos.x < 450.0 && mouse_pos.y > 150.0 &&
        mouse_pos.y < 350.0) {
        setSkin(100.0, 0.0);
    }
    //set playre_car texture as car4 texture:
    if (mouse_pos.x > 500.0 && mouse_pos.x < 600.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
        setSkin(150.0, 0.0);
    }
    //set playre_car texture as car5 texture:
    if (mouse_pos.x > 650.0 && mouse_pos.x < 750.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
        setSkin(200.0, 0.0);
    }

    //second row in the shop:
    //set playre_car texture as car6 texture:
    if (mouse_pos.x > 50.0 && mouse_pos.x < 150.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
        setSkin(0.0, 90.0);
    }
    //set playre_car texture as car7 texture:
    if (mouse_pos.x > 200.0 && mouse_pos.x < 300.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
        setSkin(50.0, 90.0);
    }
    //set playre_car texture as car8 texture:
    if (mouse_pos.x > 350.0 && mouse_pos.x < 450.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
        setSkin(100.0, 90.0);
    }
    //set playre_car texture as car9 texture:
    if (mouse_pos.x > 500.0 && mouse_pos.x < 600.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
        setSkin(150.0, 90.0);
    }
    //set playre_car texture as car10 texture:
    if (mouse_pos.x > 650.0 && mouse_pos.x < 750.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
        setSkin(200.0, 90.0);
    }
}