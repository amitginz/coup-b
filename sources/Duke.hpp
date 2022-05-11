#ifndef DUKE_HPP
#define DUKE_HPP
#include "Player.hpp" 
#include "Game.hpp"
#endif
#include <string>
using namespace std;
#pragma once
namespace coup{
class Duke:public Player
{
private:
    string role_pl;
public:
    Duke(Game &game,const string& name);
    ~Duke();
    void block(Player& play);
    void tax();
    virtual string role();
};
}

