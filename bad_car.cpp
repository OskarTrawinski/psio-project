//
// Created by Oskar Trawiński on 18/05/2021.
//

#include "bad_car.h"


bad_car::bad_car() {
    if (!_bad_car_texture.loadFromFile("textures/cars/car5.png"))
    {
        std::cout << "Opponent car texture loading error!" << std::endl;
    }

    _bad_car_sprite.setTexture(_bad_car_texture);
    _bad_car_sprite.setPosition(20.0, 20.0);
    _bad_car_sprite.setRotation(180.0);
    _bad_car_sprite.setOrigin(100.0, 100.0);

    _vertical_position = 0;
    _speed = (rand()%5)*25.0 + 200.0;
    _random = rand()%5+1;
    _tmp = 0;
    Spawn_opponent();
}
void bad_car::Set_Speed(sf::Time &elapsed) {
    srand(time(NULL));

}
void bad_car::Spawn_opponent() {
    _vertical_position = 0;
    _random = std::rand() % 5 + 1;

    if (_random == 1) {
        _horizontal_position = 100.0;
    }
    if (_random == 2){
        _horizontal_position = 210.0;
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

    _bad_car_sprite.setPosition(_horizontal_position, _vertical_position);
}

void bad_car::Animation_down(sf::Time &elapsed) {
    _vertical_position = _bad_car_sprite.getPosition().y;

    if (_vertical_position < 600){
        _tmp = 0;

        _bad_car_sprite.move(0.0, _speed*elapsed.asSeconds());
    }
    if (_vertical_position >= 598){
        Spawn_opponent();
        if (_tmp == 0){
//            Points_counting();
            _tmp = 1;
        }
    }
}

//void bad_car::Points_counting() {
//    _points = _points + 1;
//}

bool bad_car::Check_Collision(float x, float y) {
    if ((this->_vertical_position >= y) && (this->_vertical_position < y+90) && (this->_horizontal_position < x) && (this->_horizontal_position > x-50)){
        return true;
    }
}