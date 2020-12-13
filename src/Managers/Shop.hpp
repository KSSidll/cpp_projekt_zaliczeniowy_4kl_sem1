#pragma once
#include "Player.hpp"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "unordered_map"

struct Item
{
    const char* unit;
    int level = 0;
    int itemCost = 0;

    std::unordered_map< std::string, int > stats;

    bool specialEffect = false;
    int specialEffectLevelReq;
    std::string specialEffectStat;
    int specialEffectStatIncrese;
};

class Shop
{
private:
    rapidjson::Value* json;
    Player* player;
    std::unordered_map< std::string, Item* > items;

public:
    Shop( Player* player, rapidjson::Value* json );
    ~Shop(){};

    Item* GetItem( const char* itemName ){ return items.at( itemName ); };
    void IncreaseLevel( const char* itemName ){ ++items.at( itemName )->level; };
    void Buy( const char* itemName );
    void Buy( const char* itemName, rapidjson::Value& json );
};