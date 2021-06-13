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
