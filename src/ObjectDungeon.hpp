#include "GameObject.hpp"

class ObjectDungeon
{
    private:
        std::deque<GameObject>objectArray;

    public:
        ObjectDungeon();
        ~ObjectDungeon();

        void summonObject(rapidjson::Value& object, SDL_Renderer* renderer);
};