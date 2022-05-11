#pragma once
#include "Game.hpp" 
#include <string>
using namespace std;
namespace coup{
    class Game;
class Player{
private:
    string role_pl;
public:
    string name;
    bool alive;
    int salary;
    string last_action;
    Game* game;
    Player(Game &_game, const string& name);
    ~Player();
    void income();
    void foreign_aid();
    virtual void coup(Player &pl);
    int coins() const;
    void setcoin(int num);
    virtual string role();
};
}

