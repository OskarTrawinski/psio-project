//
// Created by Oskar Trawiński on 11/06/2021.
//

#include "Car.h"

void Car::Show_cars(std::vector<sf::Sprite> &vector) {
    if (!_texture.loadFromFile("textures/cars/cars.png")) {
        std::cout << "No texture found!" << std::endl;
    }

    for (auto i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            float x = 75.0;
            float y = 200.0;

            _sprite.setTextureRect(sf::IntRect(0 + (j * 50.0), 0 + (i * 90.0), 50.0, 90.0));
            _sprite.setTexture(_texture);
            _sprite.setPosition(x + (j * 150.0), y + (i * 225.0));

            vector.emplace_back(_sprite);
        }
    }
}

void Car::Animation_down(sf::Time &elapsed) {
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

void Car::Spawn_opponent() {
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
