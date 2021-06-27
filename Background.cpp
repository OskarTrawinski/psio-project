//
// Created by Oskar Trawiński on 27/06/2021.
//

#include "Background.h"

Background::Background(sf::RenderWindow &window, int &points) {
    srand(time(NULL));
    _number = rand()%2;

    //set road texture:
    if (_number == 0) {
        if(!_texture.loadFromFile("textures/roads/road1.png")) {
            std::cout << "Backgroung texture (road1) not loaded!" << std::endl;
        }
    }
    if (_number == 1) {
        if(!_texture.loadFromFile("textures/roads/road2.png")) {
            std::cout << "Backgroung texture (road2) not loaded!" << std::endl;
        }
    }

    _sprite.setTexture(_texture);
    std::cout << " Background created!" << std::endl;

    //font load:
    if (!_font.loadFromFile("Bebas-Regular.ttf")) {
        std::cout << " Can not load font!" << std::endl;
    }
}

void Background::Points_display(sf::RenderWindow &window, int &points) {
    _Points_text.setFont(_font);
    _Points_text.setFillColor(sf::Color::Black);
    _Points_text.setCharacterSize(25);
    _Points_text.setString("points: \n" + std::to_string(points/2));
    _Points_text.setPosition(720.0, 20.0);

    window.draw(_Points_text);
}

void Background::Game_over(sf::RenderWindow &window, int &points) {
    _Game_over_text.setFont(_font);
    _Game_over_text.setFillColor(sf::Color::Red);
    _Game_over_text.setCharacterSize(100);
    _Game_over_text.setString("Game over");
    _Game_over_text.setPosition(200.0, 150.0);

    _Points_text.setString("points: " + std::to_string(points/2));
    _Points_text.setFillColor(sf::Color::White);
    _Points_text.setPosition(250.0, 300.0);
    _Points_text.setCharacterSize(60);

    window.clear(sf::Color::Black);
    window.draw(_Game_over_text);
    window.draw(_Points_text);
}

void Background::You_win(sf::RenderWindow &window, int &points) {
    _Win_text.setFont(_font);
    _Win_text.setFillColor(sf::Color::Green);
    _Win_text.setCharacterSize(100);
    _Win_text.setString("you win!!!");
    _Win_text.setPosition(200.0, 150.0);

    _Points_text.setString("points: " + std::to_string(points/2));
    _Points_text.setFillColor(sf::Color::White);
    _Points_text.setPosition(250.0, 300.0);
    _Points_text.setCharacterSize(60);

    window.clear(sf::Color::Black);
    window.draw(_Win_text);
    window.draw(_Points_text);
}


