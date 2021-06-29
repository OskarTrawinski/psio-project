//
// Created by Oskar Trawiński on 18/05/2021.
//

#ifndef PROJECT_PSIO_BAD_CAR_H
#define PROJECT_PSIO_BAD_CAR_H

#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Car.h"

class bad_car: public Car {
public:
    bad_car();
    bool Check_Collision(float x, float top);

private:
    float _random;
};



#endif //PROJECT_PSIO_BAD_CAR_H
