#ifndef AMBASSADOR_HPP
#define AMBASSADOR_HPP
#include "Player.hpp" 
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#endif
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace coup{
class Ambassador:public Player
{
private:
    string role_pl;
public:
    Ambassador(Game &game,const string& name);
    ~Ambassador();
    void transfer(Player &player1,Player &player2);
    void block(Player &pl);
    virtual string role();
    
};
}

