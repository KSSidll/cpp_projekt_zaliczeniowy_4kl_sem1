#include "PlayerSummon.hpp"
#include "Enemy.hpp"

PlayerSummon::PlayerSummon( SDL_Texture* objTexture, rapidjson::Value& object, SDL_Renderer* renderer ) : EntityObject( objTexture, object, renderer )
{
    cost = object["cost"].GetInt();
}

PlayerSummon::PlayerSummon( SDL_Texture* objTexture, rapidjson::Value& object, SDL_Renderer* renderer, int id ) : EntityObject( objTexture, object, renderer )
{
    cost = object["cost"].GetInt();
    this->id = id;
}

void PlayerSummon::Update()
{
    EntityObject::Update();

    if( isMoving ) Move();
    if( isAnimationDone && animationYpos == animationLengths.size() - 1 ) pendingKill = true;
}

void PlayerSummon::Render()
{
    EntityObject::Render();
}

void PlayerSummon::HandleCollision()
{
    EntityObject::HandleCollision();
}

void PlayerSummon::HandleCollision( Enemy* entity )
{
    Attack();
    if( isAnimationDone && attacking )
        entity->DoDamage( attackDamage );

}