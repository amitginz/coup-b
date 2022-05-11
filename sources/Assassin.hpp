#ifndef ASSASSIN_HPP
#define ASSASSIN_HPP
#include "Player.hpp"
#include "Game.hpp"
#endif
#include <string>
using namespace std;
#pragma once
namespace coup{
class Assassin:public Player
{
private:
    string role_pl;
public:
    Assassin(Game &game,const string& name);
    ~Assassin();
    void coup(Player &pl);
    virtual string role();
};
}
