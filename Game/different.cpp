#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "different.h"

void First_try()
{
    unsigned int X_size = 1200;
    unsigned int Y_size = 800;
    sf::RenderWindow window(sf::VideoMode(X_size, Y_size), "Runner");
    window.setFramerateLimit(60);

    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("football.png")) {
        std::cout << "Can't load texture\n";
    }
    mapTexture.setSmooth(true);
    sf::Sprite background;
    background.setTexture(mapTexture);
    sf::Vector2u bgnd_sz = background.getTexture()->getSize();
    background.setScale((float) X_size / bgnd_sz.x, (float) Y_size / bgnd_sz.y);
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color(150, 50, 250));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(250, 150, 100));
    shape.setPosition(300, 300);*/
    sf::Vector2u mp_sz = mapTexture.getSize();
    sf::View gameView(sf::FloatRect(0.0f, 0.0f, mp_sz.x, mp_sz.y));
    window.setView(gameView);
    //sf::View initialiView = gameView;
    float scale = 1.0f;

    sf::Texture texture;
    texture.loadFromFile("hasard.png");
    sf::Sprite circle(texture);
    circle.setScale(0.3, 0.3);
    circle.setPosition(300, 300);

    sf::Vector2f scl = circle.getScale();
    sf::Vector2u sz = circle.getTexture()->getSize();

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time time = clock.getElapsedTime();
        //shape.setPosition(100 + 10 * time.asSeconds(), 500);

        sf::Event event;
        while (window.pollEvent(event)) {
            sf::Vector2f pst = circle.getPosition();

            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        circle.move(-10, 0);
                        if (pst.x <= 0)
                            circle.setPosition(0, pst.y);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        circle.move(10, 0);

                        if (pst.x >= X_size - scl.x * sz.x)
                            circle.setPosition(X_size - scl.x * sz.x, pst.y);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        circle.move(0, -10);
                        if (pst.y <= 0)
                            circle.setPosition(pst.x, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        circle.move(0, 10);
                        if (pst.y >= Y_size - scl.y * sz.y)
                            circle.setPosition(pst.x, Y_size - scl.y * sz.y);

                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) && scale <= 4.0f) {
                        scale *= 1.04f;
                        //std::cout << scale << "\n";


                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) && scale >= 0.25f) {
                        scale /= 1.04f;
                    }
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    }
                    break;
                    /*
                     * if(event.key.code == sf::Keyboard::Left)
                     */
                default:
                    break;
            }

            /* ROTATION
             *
            sf::Vector2u circleSize = circle.getTexture()->getSize();
            circle.setOrigin(circleSize.x / 2, circleSize.y / 4);

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f center = circle.getPosition();
            sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

            const float Pi = 3.14159f;
            circle.setRotation(90 + atan2f(d.y, d.x) * 180 / Pi);*/

            //gameView = initialiView;
            gameView.zoom(scale);
            //std::cout << scale << "\n";
            window.setView(gameView);

        }

        window.clear(sf::Color::White);
        //window.draw(shape);
        window.draw(background);
        window.draw(circle);
        window.display();
    }

}
/*

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>


int main()
{
    float X_size = 1200;
    float Y_size = 800;
    sf::RenderWindow window(sf::VideoMode(X_size, Y_size), "Runner");
    window.setFramerateLimit(60);


    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color(150, 50, 250));
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(250, 150, 100));


    sf::Clock clock;

    sf::Vector2f scl = circle.getScale();
    float sz = 2 * circle.getRadius();

    sf::Vector2f point1 = {0, Y_size / 3};
    sf::Vector2f point2 = {X_size,  Y_size / 2};

    sf::Vertex line[] =
            {
                    sf::Vertex(point1),
                    sf::Vertex(point2)
            };



    circle.setPosition(point1.x, point1.y - sz);
    sf::Vector2f initial_position = circle.getPosition();

    while (window.isOpen())
    {
        sf::Time time = clock.getElapsedTime();
        circle.setPosition(initial_position.x + 90 * time.asSeconds(),
                           initial_position.y + 10 * time.asSeconds());

        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2f pst = circle.getPosition();

            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        circle.move(-10, 0);
                        if(pst.x <= 0)
                            circle.setPosition(0, pst.y);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        circle.move(10, 0);

                        if(pst.x >= X_size - scl.x * sz)
                            circle.setPosition(X_size - scl.x * sz, pst.y);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        circle.move(0, -10);
                        if(pst.y <= 0)
                            circle.setPosition(pst.x, 0);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        circle.move(0, 10);
                        if(pst.y >= Y_size - scl.y * sz)
                            circle.setPosition(pst.x, Y_size - scl.y * sz);

                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {

                    }
                    break;

                default:
                    break;
            }

            //ROTATION

            sf::Vector2u circleSize = circle.getTexture()->getSize();
            circle.setOrigin(circleSize.x / 2, circleSize.y / 4);

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::Vector2f center = circle.getPosition();
            sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

            const float Pi = 3.14159f;
            circle.setRotation(90 + atan2f(d.y, d.x) * 180 / Pi);


        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(line, 2, sf::Lines);
        window.display();
    }

    return 0;
}*/
