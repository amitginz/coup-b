#ifndef Contessa_HPP
#define Contessa_HPP
#include "Player.hpp"
#include "Game.hpp" 
#endif
#include <string>
using namespace std;
namespace coup{
class Contessa:public Player
{
private:
    string role_pl;
public:
    Contessa(Game &game, const string& name);
    ~Contessa();
    void block(Player &pl);
    virtual string role();
};
}



