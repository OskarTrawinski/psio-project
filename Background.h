//
// Created by Oskar Trawiński on 27/06/2021.
//

#ifndef PROJECT_PSIO_BACKGROUND_H
#define PROJECT_PSIO_BACKGROUND_H

//biblioteki:
#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

class Background : public sf::Drawable {
public:
    Background(sf::RenderWindow &window, int &points);
    void Points_display(sf::RenderWindow &window, int &points);
    void Game_over(sf::RenderWindow &window, int &points);
    void You_win(sf::RenderWindow &window, int &points);

protected:
    int _number;
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::VertexArray _vertex;
    sf::Font _font;
    sf::Text _Game_over_text, _Win_text, _Points_text;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(_sprite, states);
        states.texture = &_texture;
        target.draw(_vertex, states);
    }
};


#endif //PROJECT_PSIO_BACKGROUND_H
