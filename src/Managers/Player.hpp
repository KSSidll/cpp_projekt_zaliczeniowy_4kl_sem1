#pragma once
#include "../Engine/Global.hpp"

class Player
{
private:
    int frameCounter = 0;

    // resource used to summon
    int fujika = 0;
    int fujikaGain = 2;
    int fujikaLimit = 20;

    // resource used to buy equipement
    int fuko = 0;
    int fukoGain = 1;
    int fukoLimit = 1000;

public:
    Player(){};
    ~Player(){};

    bool Summon( int cost );

    void Update();
    void Reset();
};