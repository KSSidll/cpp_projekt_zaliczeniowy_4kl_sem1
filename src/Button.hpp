#pragma once
#include <SDL2/SDL.h>
#include "rapidjson/document.h"

enum state{ nothing = 0, hover = 1, press = 2 };

class Button
{
private:
    SDL_Renderer* renderer;
    state state;
    int xPos, yPos;
    int width, height;

public:
    Button(rapidjson::Value& json, SDL_Renderer* renderer);
    ~Button();

    void Render();
};