#include "../Managers/TextureManager.hpp"
#include "../Engine/Game.hpp"
#include "../Objects/SceneObject.hpp"
#include "MainMenu.hpp"
#include "Button.hpp"
#include "UILabel.hpp"

MainMenu::MainMenu()
{
    this->game = nullptr;
    this->renderer = nullptr;
}

MainMenu::~MainMenu()
{
    this->renderer = nullptr;
    this->game = nullptr;
}

MainMenu::MainMenu( SDL_Renderer* renderer, TextureManager* textureManager, Game* game )
{
    this->game = game;
    this->renderer = renderer;

    background = new SceneObject( textureManager->GetTexture( "darkBackground" ), renderer );

    mainMenuLabel = new UILabel( renderer, 0, 20, "assets/fonts/Sans.ttf", 72, "Defend The Castle", {255,255,255}, 1024 );

    buttons.push_back({
        Button( textureManager->GetButtonTexture( "button1" ), newGameButtonPos, renderer, []( Game* game ){ game->NewGame(); } ),
        {{"", UILabel( renderer, newGameButtonPos.x, newGameButtonPos.y, "assets/fonts/Sans.ttf", 48, "New Game", {255,255,255}, newGameButtonPos.w, newGameButtonPos.h )}}
    });
    buttons.push_back({
        Button( textureManager->GetButtonTexture( "button1" ), continueButtonPos, renderer, []( Game* game ){ game->Load(); } ),
        {{"", UILabel( renderer, continueButtonPos.x, continueButtonPos.y, "assets/fonts/Sans.ttf", 48, "Continue", {255,255,255}, continueButtonPos.w, continueButtonPos.h )}}
    });
    buttons.push_back({
        Button( textureManager->GetButtonTexture( "button1" ), quitButtonPos, renderer, []( Game* game ){ game->Quit(); } ),
        {{"", UILabel( renderer, quitButtonPos.x, quitButtonPos.y, "assets/fonts/Sans.ttf", 32, "Quit", {255,255,255}, quitButtonPos.w, quitButtonPos.h )}}
    });
}

void MainMenu::Render()
{
    background->Render();
    mainMenuLabel->Render();
    for( auto& button : buttons )
    {
        button.Render();
    }
}

void MainMenu::HandleEvents( SDL_Event* event )
{
    for( auto& button : buttons )
    {
        if( button.HandleEvents( event ) )
            button.button.game( game );
    }
}