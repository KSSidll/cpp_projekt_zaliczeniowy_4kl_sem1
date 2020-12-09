#pragma once
#include "../Managers/SummonDungeon.hpp"
#include "../Managers/TextureManager.hpp"
#include "UILabel.hpp"

enum BUTTON_STATE{ MOUSE_OUT = 0, MOUSE_OVER = 1, MOUSE_DOWN = 2, MOUSE_UP = 3 };

class Button
{
private:
    BUTTON_STATE BUTTON_STATE = MOUSE_OUT;

    SDL_Renderer* renderer;
    SDL_Rect rect;

    UILabel* label;
    ButtonTextures textures;

public:
    Button( ButtonTextures textures, UILabel* label, SDL_Rect rect, SDL_Renderer* renderer );
    Button( ButtonTextures textures, UILabel* label, SDL_Rect rect, SDL_Renderer* renderer, void (*callback)( SummonDungeon* dungeon, rapidjson::Value& json ) );
    ~Button(){};

    void Render();
    bool HandleEvents( SDL_Event* event );

    void (*callback)( SummonDungeon* dungeon, rapidjson::Value& json );
};