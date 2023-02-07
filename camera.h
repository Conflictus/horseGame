#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
View view;
void change_view(float x, float y) {
    if (x < 200)
    {
        x=200;
    }
    if (x>425)
    {
        x = 425;

    }
    if (y < 150)
    {
        y = 150;
    }
    if (y > 600)
    {
        y=600;
    }
    view.setCenter(x+10, y+10);
    
}
void move_map(float time) {
    if (Keyboard::isKeyPressed(Keyboard::Num6)) {
        view.rotate(0.01);
    }
    if (Keyboard::isKeyPressed(Keyboard::Num4)) {
        view.rotate(-0.01);
    }
    if (Keyboard::isKeyPressed(Keyboard::Num8)) {
        view.zoom(1.0001f);
    }
    if (Keyboard::isKeyPressed(Keyboard::Num2)) {
        view.zoom(0.9999f);
    }
    if (Keyboard::isKeyPressed(Keyboard::Num0)) 
    {
        view.setSize(700, 500);
    }
    
    {
        /* code */
    }
    
    
    
}