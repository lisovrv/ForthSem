#include "Engine.h"

Engine::Engine():
        X_size(1800),
        Y_size(800),
        window(sf::VideoMode(X_size, Y_size), "Plants vs Zombies"),
        clock(sf::Clock()),
        player("man_run.png",250,250, 271, 356),
        player2("man_run.png",250,250, 271, 356),
        CurrentFrame(0)
{
    window.setFramerateLimit(60);

    mapTexture = sf::Texture();
    if (!mapTexture.loadFromFile("field2.jpg")) {
        std::cout << "Can't load texture\n";
    }
    mapTexture.setSmooth(true);
    background = sf::Sprite();
    background.setTexture(mapTexture);
    sf::Vector2u bgnd_sz = background.getTexture()->getSize();
    background.setScale((float) X_size / bgnd_sz.x, (float) Y_size / bgnd_sz.y);

    music.openFromFile("plants_vs_zombies_sound.ogg");//загружаем файл
    //music.play();//воспроизводим музыку

    quest_image.loadFromFile("book.jpg");
    quest_image.createMaskFromColor(Color(204, 204, 204));
    quest_image.createMaskFromColor(Color(255, 255, 255));
    quest_texture.loadFromImage(quest_image);
    s_quest.setTexture(quest_texture);
    //s_quest.setTextureRect(IntRect(0, 0, 340, 510));  //приведение типов, размеры картинки исходные
    s_quest.setScale(0.6f, 0.6f);//чуть уменьшили картинку, => размер стал меньше

    little_image.loadFromFile("man_run.png");
    little_image.createMaskFromColor(Color(255, 255, 255));
    little_texture.loadFromImage(little_image);
    s_quest2.setTexture(little_texture);
    s_quest2.setTextureRect(IntRect(271, 0, 271, 356));  //приведение типов, размеры картинки исходные
    s_quest2.setScale(0.4f, 0.4f);
    s_quest2.setPosition(45, 30);

    isMove = false;


}

void Engine::My_input()
{
    float time_ = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time_ = time_ / 550;

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

    }

    if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
    {
        player.dir = 0;
        player.speed = 0.8;
        CurrentFrame += 0.004 * time_;
        if (CurrentFrame > 10)
            CurrentFrame -= 10;
        if(int(CurrentFrame) < 5)
            player.sprite.setTextureRect(IntRect(271 * int(CurrentFrame), 0, 271, 356));
        if(int(CurrentFrame) >= 5 && int(CurrentFrame) < 11)
            player.sprite.setTextureRect(IntRect(271 * (int(CurrentFrame) - 5), 356, 271, 356));
    }

    if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
    {
        player.dir = 1;
        player.speed = 0.2;
        CurrentFrame += 0.004 * time_;
        if (CurrentFrame > 10)
            CurrentFrame -= 10;
        if(int(CurrentFrame) <= 4)
            player.sprite.setTextureRect(IntRect(271 * (int(CurrentFrame) + 1), 356, -270, 356));
        if(int(CurrentFrame) > 4 && int(CurrentFrame) <= 10)
            player.sprite.setTextureRect(IntRect(271 * (int(CurrentFrame) - 4), 712, -270, 356));

    }

    player.Update(time_);


}

void Engine::My_logic()
{

}


void Engine::Init()
{
    while(window.isOpen())
    {
        My_draw();
        My_input();
        My_logic();
    }
}

void Engine::My_draw()
{
    window.clear(sf::Color::Black);
    window.draw(background);
    window.draw(player.sprite);
   // window.draw(player2.sprite);
    window.draw(s_quest);
    window.draw(s_quest2);
    window.display();
}