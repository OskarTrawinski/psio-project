//
// Created by Oskar Trawiński on 15/05/2021.
//

#ifndef PROJECT_PSIO_PLAYER_CAR_H
#define PROJECT_PSIO_PLAYER_CAR_H

#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

class Player_car:public sf::Drawable{
public:
    sf::Texture Player_texture, m_texture;
    sf::Sprite Player_sprite, m_sprite;
    sf::VertexArray m_vertices;
    float _position, _skin_x, _skin_y, _speed, _points;
    int _top;

    Player_car();
    void setSkin();
    void Move_right(sf::Time &elapsed);
    void Move_left(sf::Time &elapsed);
    void Move_player(sf::Time &elapsed);
    void Points_counting();

private:
    int _left;
    int _right;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(m_sprite, states);
        states.texture = &m_texture;
        target.draw(m_vertices, states);
    }
};


#endif //PROJECT_PSIO_PLAYER_CAR_H
