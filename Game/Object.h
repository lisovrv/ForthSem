#ifndef MY_GAME_OBJECT_H
#define MY_GAME_OBJECT_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace sf;


class Object
{
public:
    float x, y, dx, dy, speed;
    int direction;
    Image image;
    Texture texture;
    Sprite sprite;

    Object(String file__, Vector2f init_position__, Vector2f init_scale__,
            Vector2i init_size__, std::vector<Color> colors_for_mask__);
    virtual void Update(float time_);
    FloatRect getRect();

};

#endif //MY_GAME_OBJECT_H
