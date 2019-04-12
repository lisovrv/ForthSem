#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "perfect_gas.h"


void perfect_gas()
{
    float X_size = 1200;
    float Y_size = 800;
    sf::RenderWindow window(sf::VideoMode(X_size, Y_size), "Runner");
    window.setFramerateLimit(60);


    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(150, 50, 250));
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(250, 150, 100));


    sf::Clock clock;

    sf::Vector2f scl = circle.getScale();
    float sz = 2 * circle.getRadius();

    sf::Vector2f point1 = {0, Y_size / 3};
    sf::Vector2f point2 = {X_size,  Y_size / 2};




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
                    /*
                     * if(event.key.code == sf::Keyboard::Left)
                     */

                default:
                    break;
            }


        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}

Ball::Ball():
            position(200, 200), velocity(10, 20),
            radius(50), mass(100) {}

Ball::~Ball()
{
    velocity = {0, 0};
}

sf::Vector2f Ball::GetImpulse() const
{
    sf::Vector2f impulse = {velocity.x * mass, velocity.y * mass};
    return impulse;
}





