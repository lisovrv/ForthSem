#ifndef MY_GAME_ENGINE_H
#define MY_GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>

#include "Player.h"

using namespace sf;

class Engine
{
public:
    Engine();
    void Init();

    void My_input();
    void My_draw();
    void My_logic();

    unsigned int X_size;
    unsigned int Y_size;

    sf::RenderWindow window;

    sf::Texture mapTexture;
    sf::Sprite background;
    sf::Clock clock;
    float CurrentFrame;
    Player player;
    Player player2;
    Music music;

    Image quest_image;
    Texture quest_texture;
    Sprite s_quest;

    Image little_image;
    Texture little_texture;
    Sprite s_quest2;

    bool isMove;


};


#endif //MY_GAME_ENGINE_H
