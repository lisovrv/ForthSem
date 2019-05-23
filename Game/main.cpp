#include "Engine.h"

bool Init()
{
    Engine engine;
    while(engine.window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; }
        engine.My_draw();
        engine.My_input();
        engine.My_logic();
    }
}

void gameRunning()
{
    if(Init())
    {
        gameRunning();
    }
}


int main()
{
    gameRunning();
    return 0;
}

