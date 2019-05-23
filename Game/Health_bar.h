#ifndef MY_GAME_HEALTH_BAR_H
#define MY_GAME_HEALTH_BAR_H

#include "Object.h"

class Health_bar: public Object
{
public:
    int max;
    RectangleShape bar;
    Health_bar(String file__, Vector2f init_position__, Vector2f init_scale__,
           Vector2i init_size__, std::vector<Color> colors_for_mask__):
            Object(file__, init_position__, init_scale__, init_size__, colors_for_mask__)
    {

        sprite.setTextureRect(IntRect(init_position__.x, init_position__.y, init_size__.x, init_size__.y));
        bar.setFillColor(Color(0, 0, 0));//черный прямоугольник накладывается сверху и появляется эффект отсутствия здоровья
        max = 100;

    }

    void Update(int k)
    {
        if (k>0)
            if (k < max)
                bar.setSize(Vector2f(10, (max - k) * 70 / max));
    }

    void draw(RenderWindow &window)
    {
        Vector2f center = window.getView().getCenter();
        Vector2f size = window.getView().getSize();

        sprite.setPosition(center.x - size.x / 2 + 10, center.y - size.y / 2 + 10);//позиция на экране
        bar.setPosition(center.x - size.x / 2 + 14, center.y - size.y / 2 + 14);

        window.draw(sprite);//сначала рисуем полоску здоровья
        window.draw(bar);//поверх неё уже черный прямоугольник, он как бы покрывает её
    }



};


#endif //MY_GAME_HEALTH_BAR_H
