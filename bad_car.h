//
// Created by Oskar Trawiński on 18/05/2021.
//

#ifndef PROJECT_PSIO_BAD_CAR_H
#define PROJECT_PSIO_BAD_CAR_H

#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

class bad_car: public sf::Drawable {
public:
    bad_car();
    sf::Texture _bad_car_texture;
    sf::Sprite _bad_car_sprite;
    float _horizontal_position;
    float _vertical_position;
    float _speed;
    int _points = 0;
    float _random;
    bool _tmp = 0;

    void Animation_down(sf::Time &elapsed);
    void Spawn_opponent();
    void Set_Speed(sf::Time &elapsed);
    bool Check_Collision(float x, float y);


private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::VertexArray m_vertices;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(m_sprite, states);
        states.texture = &m_texture;
        target.draw(m_vertices, states);
    }
};


#endif //PROJECT_PSIO_BAD_CAR_H
