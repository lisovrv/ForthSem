#ifndef MY_GAME_HERO_H
#define MY_GAME_HERO_H

#include "Object.h"

class Hero: public Object
{
public:
    bool Is_on_the_field;
    float health;
    bool life;

    Hero(String file__, Vector2f init_position__, Vector2f init_scale__,
         Vector2i init_size__, std::vector<Color> colors_for_mask__):
         Object(file__, init_position__, init_scale__, init_size__, colors_for_mask__)
    {
        Is_on_the_field = false;
        health = 100.0;
        life = true;
        sprite.setOrigin(init_size__.x/2, init_size__.y/2);
    }

    void Update(float time_) override
    {
        switch (direction)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
        {
            case 0: dx = speed; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
            case 1: dx = -speed; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
            case 2: dx = 0; dy = speed;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
            case 3: dx = 0; dy = -speed;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
        }

        x += dx * time_;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
        y += dy * time_;//аналогично по игреку

        speed = 0;//зануляем скорость, чтобы персонаж остановился.
        sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно
    }

};


#endif //MY_GAME_HERO_H
