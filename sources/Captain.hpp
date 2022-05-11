#ifndef CAPTAIN_HPP
#define CAPTAIN_HPP
#include "Player.hpp" 
#include "Game.hpp"
#endif
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace coup{
class Captain:public Player
{
private:
    string role_pl;
public:
    Captain(Game &game,const string& name);
    ~Captain();
    void block(Player &pl);
    void steal(Player &pl);
    virtual string role();
};
}

