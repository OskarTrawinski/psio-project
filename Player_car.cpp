//
// Created by Oskar Trawiński on 15/05/2021.
//

#include "Player_car.h"

Player_car::Player_car(){
    if (!Player_texture.loadFromFile("textures/cars/cars.png")){
        std::cout << "No texture found!" << std::endl;
    }

    _left = 375.0;
    _top = 480.0;
    _right = _left+50.0;
    _speed = 100.0;
    _points = 0.0;
   _skin_x = 0.0;
    _skin_y = 0.0;

    Player_sprite.setTextureRect(sf::IntRect(_skin_x, _skin_y, 50, 90));
    Player_sprite.setTexture(Player_texture);
    Player_sprite.setPosition(_left,_top);
}

void Player_car::Move_right(sf::Time &elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _position = Player_sprite.getPosition().x;

        if (Player_sprite.getPosition().x+50 < 705.0) {
            Player_sprite.move(_speed*elapsed.asSeconds(), 0);
        }
    }
}

void Player_car::Move_left(sf::Time &elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        _position = Player_sprite.getPosition().x;

        if (Player_sprite.getPosition().x > 95.0){
            Player_sprite.move(-15.0*elapsed.asSeconds(), 0.0);
        }
    }
}

void Player_car::Move_player(sf::Time &elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _position = Player_sprite.getPosition().x;

        if (Player_sprite.getPosition().x+50 < 705.0) {
            Player_sprite.move(_speed*elapsed.asSeconds(), 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        _position = Player_sprite.getPosition().x;

        if (Player_sprite.getPosition().x > 95.0){
            Player_sprite.move(-_speed*elapsed.asSeconds(), 0.0);
        }
    }
}

void Player_car::setSkin() {
    Player_sprite.setTextureRect(sf::IntRect(_skin_x, _skin_y, 50, 90));
}

void Player_car::Points_counting() {
    _points += 1.0;
}