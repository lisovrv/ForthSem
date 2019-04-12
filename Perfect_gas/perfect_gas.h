#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#ifndef FORTH_SEM_PERFECT_GAS_H
#define FORTH_SEM_PERFECT_GAS_H

void perfect_gas();

class Ball
{
public:
    Ball();
    virtual ~Ball();

    //virtual void UpdatePosition(float dt);
    sf::Vector2f GetImpulse() const;

    sf::Vector2f position;
    sf::Vector2f velocity;
    float radius;
    float mass;

};



#endif //FORTH_SEM_PERFECT_GAS_H
