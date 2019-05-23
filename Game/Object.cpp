#include "Object.h"

Object::Object(String file__, Vector2f init_position__, Vector2f init_scale__, Vector2i init_size__, std::vector<Color> colors_for_mask__):
    direction(0), speed(0), x(init_position__.x), y(init_position__.y), dx(0), dy(0)
{
    image.loadFromFile(file__);

    for(int i = 0; i < colors_for_mask__.size(); i++)
        image.createMaskFromColor(colors_for_mask__[i]);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, init_size__.x, init_size__.y));
    sprite.setScale(init_scale__);
}

void Object::Update(float time_)
{
    switch (direction)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
    {
        case 0: dx = speed; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
        case 1: dx = -speed; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
        case 2: dx = 0; dy = speed;   break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
        case 3: dx = 0; dy = -speed;   break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
    }

    x += dx * time_;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
    y += dy * time_;//аналогично по игреку

    speed = 0;//зануляем скорость, чтобы персонаж остановился.
    sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
}

FloatRect Object::getRect()
{
    return FloatRect(x, y, sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y);
}