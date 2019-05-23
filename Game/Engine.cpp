#include "Engine.h"

Engine::Engine():
        window(sf::VideoMode(1750, 800), "Plants vs Zombies"),
        clock(sf::Clock()),
        little_table("little_table.jpg", {50,0}, {0.6f, 0.4f}, {728, 347}, {{255, 255, 255}, {204, 204, 204}}),
        sonic_hero("man_run.png", {75, 65} , {0.3f, 0.3f}, {271, 356}, {{255, 255, 255}}),
        bar("life.png", {783, 2} , {1.2f, 1.2f}, {15, 84}, {{50, 96, 166}}),
        CurrentFrame(0)
{
///-----------------------------------MENU--------------------------------------------
    music.openFromFile("plants_vs_zombies_sound.ogg");
    music.play();
    music.setLoop(true);

    stop_game = false;
    //My_menu(window);

    window.setFramerateLimit(60);

///------------------------------------BACKGROUND--------------------------------------
    mapTexture = sf::Texture();
    if (!mapTexture.loadFromFile("field2.jpg")) {
        std::cout << "Can't load texture\n";
    }
    mapTexture.setSmooth(true);
    background = sf::Sprite();
    background.setTexture(mapTexture);
    sf::Vector2u bgnd_sz = background.getTexture()->getSize();
    background.setScale((float) 1750 / bgnd_sz.x, (float) 800 / bgnd_sz.y);

///-------------------------------------OBJECTS-------------------------------------
    number_of_zomb = 7;
    for(int i = 0; i < int(number_of_zomb); i++)
    {
        float length = random() % 1200;
        zombies.push_back(new Zombie("zombie.png", {(1600 + length), 130},
                                                   {0.7f, 0.7f}, {256, 256}, {{0, 0, 0}}, random() % 5));
    }

    /*number_of_heroes = 3;
    for(int i = 0; i < int(number_of_heroes); i++)
    {
        sonic_heroes.push_back(new Hero("man_run.png", {75, 65} , {0.3f, 0.3f},
                                                       {271, 356}, {{255, 255, 255}}));
    }*/

///-------------------------------------OTHER-------------------------------------

    isMove = false;
    dX = 0;
    dY = 0;

    buffer.loadFromFile("rev-zombi.ogg");
    sound = Sound(buffer);

}

///---------------------------------------------------INPUT----------------------------------------------------


void Engine::My_input()
{
    float time_ = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time_ = time_ / 550;


    Vector2i pixelPos = Mouse::getPosition(window);
    Vector2f pos = window.mapPixelToCoords(pixelPos);

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                My_menu(window);
            }
        }
        if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
            if (event.key.code == Mouse::Left)//а именно левая
                if (sonic_hero.sprite.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
                {
                    dX = pos.x - sonic_hero.sprite.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
                    dY = pos.y - sonic_hero.sprite.getPosition().y;//тоже самое по игреку
                    isMove = true;//можем двигать спрайт
                }

        if (event.type == Event::MouseButtonReleased)//если отпустили клавишу
            if (event.key.code == Mouse::Left) //а именно левую
                isMove = false; //то не можем двигать спрай
            sonic_hero.sprite.setColor(Color::White);//и даем ему прежний цвет
    }

    if (isMove)
    {
        sonic_hero.sprite.setColor(Color::Green);//красим спрайт в зеленый
        sonic_hero.x = pos.x-dX;//двигаем спрайт по Х
        sonic_hero.y = pos.y-dY;
        sonic_hero.Is_on_the_field = true;
        sonic_hero.sprite.setScale(0.6,0.6);
    }



    if (sonic_hero.Is_on_the_field &&(Keyboard::isKeyPressed(Keyboard::Right)))
    {
        sonic_hero.direction = 0;
        sonic_hero.speed = 0.25;
        CurrentFrame += 0.004 * time_;
        if (CurrentFrame > 10)
            CurrentFrame -= 10;
        if(int(CurrentFrame) < 5)
            sonic_hero.sprite.setTextureRect(IntRect(271 * int(CurrentFrame), 0, 271, 356));
           // sonic_hero.sprite.setOrigin(270 * (int(CurrentFrame)) +270/2, 356/2);
        if(int(CurrentFrame) >= 5 && int(CurrentFrame) < 11)
            sonic_hero.sprite.setTextureRect(IntRect(271 * (int(CurrentFrame) - 5), 356, 271, 356));
            //sonic_hero.sprite.setOrigin(270 * (int(CurrentFrame) - 4) +270/2, 356/2);
    }

    if (sonic_hero.Is_on_the_field &&(Keyboard::isKeyPressed(Keyboard::Left)))
    {
        sonic_hero.direction = 1;
        sonic_hero.speed = 0.25;
        CurrentFrame += 0.004 * time_;
        if (CurrentFrame > 10)
            CurrentFrame -= 10;
        if(CurrentFrame < 5)
            sonic_hero.sprite.setTextureRect(IntRect(270 * (int(CurrentFrame) + 1), 0, -270, 356));
            //sonic_hero.sprite.setOrigin(270 * (int(CurrentFrame) + 1) +270/2, 356/2);
        if(CurrentFrame > 5 && CurrentFrame < 11)
            sonic_hero.sprite.setTextureRect(IntRect(270 * (int(CurrentFrame) - 4), 356, -270, 356));
          //  sonic_hero.sprite.setOrigin(270 * (int(CurrentFrame) - 4) + 270 / 2, 356/2);

    }

    for (it = zombies.begin(); it != zombies.end(); it++)
    {
        if (abs((*it)->x - sonic_hero.x) < 30 && abs((*it)->y - sonic_hero.y) < 100
            && sonic_hero.Is_on_the_field)
        {

            (*it)->health -= 0.001 * time_;
            sonic_hero.health -= 0.001 * time_;
            sonic_hero.speed = 0;
            (*it)->speed = 0;
            sound.play();
        }
    }

    ///----------------------------------UPDATE----------------------------------------------
    /*for (it_hero = sonic_heroes.begin(); it_hero != sonic_heroes.end(); it++)
    {
        (*it_hero)->Update(time_);
        CurrentFrame += 0.003 * time_ / number_of_heroes;
        if (CurrentFrame > 6)
            CurrentFrame -= 6;
        (*it)->sprite.setTextureRect(IntRect(256 * int(CurrentFrame), 0, 256, 256));
        if ((*it_hero)->health < 0)
        {
            it_hero = sonic_heroes.erase(it_hero);
        }
    }*/

    sonic_hero.Update(time_);
    if (sonic_hero.health < 0)
    {
        sonic_hero.life = false;
    }

    bar.Update(int(sonic_hero.health));


    for (it = zombies.begin(); it != zombies.end(); it++)
    {
        (*it)->Update(time_);
        CurrentFrame += 0.003 * time_ / number_of_zomb;
        if (CurrentFrame > 6)
            CurrentFrame -= 6;
        (*it)->sprite.setTextureRect(IntRect(256 * int(CurrentFrame), 0, 256, 256));
        if ((*it)->health < 0)
        {
            it = zombies.erase(it);
        }
    }


}

///---------------------------------------------------LOGIC----------------------------------------------------

void Engine::My_logic()
{

}

///---------------------------------------------------My_DRAW----------------------------------------------------

void Engine::My_draw()
{
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(little_table.sprite);

    for (it = zombies.begin(); it != zombies.end(); it++)
    {
        if((*it)->life) window.draw((*it)->sprite);
    }
    if(sonic_hero.life) window.draw(sonic_hero.sprite);
    bar.draw(window);
    window.display();
}