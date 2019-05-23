#include <zconf.h>
#include "Menu.h"




///---------------------------------------------------MENU----------------------------------------------------

void My_menu(RenderWindow & window)
{
    Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4,
            aboutTexture, menuBackground, startBackground;
    menuTexture1.loadFromFile("menu1.png");
    menuTexture2.loadFromFile("menu2.png");
    menuTexture3.loadFromFile("menu3.png");
    menuTexture4.loadFromFile("after_pause.png");
    aboutTexture.loadFromFile("menu_about.png");
    menuBackground.loadFromFile("menu_back.jpg");
    startBackground.loadFromFile("start_game1.jpg");

    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),
            about(aboutTexture), menuBg(menuBackground), startBg(startBackground), ater_pause(menuTexture4);
    bool isMenu = true;
    int menuNum = 0;
    menu1.setPosition(100, 30);
    ater_pause.setPosition(100, 90);
    menu2.setPosition(100, 220);
    menu3.setPosition(100, 270);
    ater_pause.setScale(0.1, 0.1);
    menuBg.setScale(0.75, 0.75);
    startBg.setScale(1.9, 1.4);
    about.setScale(1.5, 1.5);
    menuBg.setPosition(345, 0);

    //////////////////////////////МЕНЮ///////////////////
    while (isMenu) {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        ater_pause.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Blue);
            menuNum = 1;
        }
        if (IntRect(100, 90, 100, 100).contains(Mouse::getPosition(window))) {
            ater_pause.setColor(Color::Blue);
            menuNum = 4;
        }
        if (IntRect(100, 220, 300, 50).contains(Mouse::getPosition(window))) {
            menu2.setColor(Color::Blue);
            menuNum = 2;
        }
        if (IntRect(100, 270, 300, 50).contains(Mouse::getPosition(window))) {
            menu3.setColor(Color::Blue);
            menuNum = 3;
        }

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                isMenu = false;
            }

            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menuNum == 1) {
                    window.draw(startBg);
                    window.display();
                    SoundBuffer buffer;
                    buffer.loadFromFile("start_game1.ogg");
                    Sound sound(buffer);
                    sound.play();
                    while (!((Keyboard::isKeyPressed(Keyboard::Escape)) ||
                             (Keyboard::isKeyPressed(Keyboard::Space))));
                    isMenu = false;
                }
                if (menuNum == 2) {
                    window.draw(about);
                    window.display();
                    while (!Keyboard::isKeyPressed(Keyboard::Escape));
                }
                if (menuNum == 3) {
                    window.close();
                    isMenu = false;
                }
                if (menuNum == 4) {
                    isMenu = false;
                }
            }
        }
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(ater_pause);
        window.display();
    }
    ////////////////////////////////////////////////////
}