#ifndef MY_GAME_ENGINE_H
#define MY_GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>

#include <vector>
#include <list>

#include "Object.h"
#include "Hero.h"
#include "Zombie.h"
#include "Health_bar.h"
#include "Menu.h"

using namespace sf;

class Engine
{
public:
///----------------------------FUNCTIONS-----------------------

    Engine();
    //bool Init();
    //void gameRunning();

    void My_input();
    void My_draw();
    void My_logic();
///----------------------------WINDOW-----------------------

    sf::RenderWindow window;

    sf::Texture mapTexture;
    sf::Sprite background;
    sf::Clock clock;
    float CurrentFrame;
    Music music;
///----------------------------MOUSE-----------------------

    bool isMove;
    float dX;
    float dY;

///----------------------------OBJECTS-----------------------
    Hero sonic_hero;
    Object little_table;
    Health_bar bar;

    std::list<Hero*>  sonic_heroes;
    std::list<Hero*>::iterator it_hero;

    std::list<Zombie*>  zombies;
    std::list<Zombie*>::iterator it;
///----------------------------MENU-----------------------
    bool stop_game;
    float number_of_zomb;
    int number_of_heroes;

    SoundBuffer buffer;
    Sound sound;

};


#endif //MY_GAME_ENGINE_H
