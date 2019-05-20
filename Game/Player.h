#ifndef MY_GAME_PLAYER_H
#define MY_GAME_PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;


class Player
{
public:
    float x, y, w, h, dx, dy, speed;
    int dir;
    String File; //файл с расширением
    Image image;//сфмл изображение
    Texture texture;//сфмл текстура
    Sprite sprite;//сфмл спрайт

    Player(String file_, float x_, float y_, float w_, float h_);
    void Update(float time_);

};

#endif //MY_GAME_PLAYER_H
