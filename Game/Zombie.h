#ifndef MY_GAME_ZOMBIE_H
#define MY_GAME_ZOMBIE_H

#include "Object.h"

class Zombie: public Object
{
public:
    int number_of_road;
    float health;
    bool life;
    Zombie(String file__, Vector2f init_position__, Vector2f init_scale__,
         Vector2i init_size__, std::vector<Color> colors_for_mask__, int number):
            Object(file__, init_position__, init_scale__, init_size__, colors_for_mask__)
    {
        number_of_road = number;
        health = 10.0;
        life = true;
        y = y + number_of_road * 140;
        speed = 0.01;
        sprite.setOrigin(0, init_size__.y/2);

    }
    void Update(float time_) override
    {

        dx = speed;
        x -= dx * time_;
        sprite.setPosition(x, y);
        if ((this)->health < 0)
        {
            life = false;
            delete this;
        }
    }



};



#endif //MY_GAME_ZOMBIE_H
