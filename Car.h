//
// Created by Oskar Trawiński on 11/06/2021.
//

#ifndef PROJECT_PSIO_CAR_H
#define PROJECT_PSIO_CAR_H

//biblioteki:
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

class Car : public sf::Sprite {
public:
    Car() : sf::Sprite() {
        //default
    };
    float _speed;
    float _horizontal_position;
    float _vertical_position;

    void Spawn_opponent();
    void Animation_down(sf::Time &elapsed);
    void Show_cars(std::vector <sf::Sprite> &vector);

protected:
    float _random;
    bool _tmp = 0;
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::VertexArray _vertex;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(_sprite, states);
        states.texture = &_texture;
        target.draw(_vertex, states);
    }
};


#endif //PROJECT_PSIO_CAR_H
