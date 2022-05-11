#include <stdexcept>
#include "Assassin.hpp"
#include "Player.hpp" 
#include <iostream>
using namespace std;
coup::Assassin::Assassin(Game &game, const string& name):Player(game,name){
    this->role_pl = "Assassin";
}
coup::Assassin::~Assassin(){
    
}
namespace coup{
    void Assassin::coup(Player &pl){
        const int bound = 7;
        const int bound1 = 3;
        bool seven = true;
        if(!pl.alive){
            throw runtime_error("player is not alive...");
        }
        if(this->game->turn() != this->name){
            throw runtime_error("it is not player turn");
        }
        
        if(this->salary >= bound){
            this->game->setturn();
            this->salary = this->salary-bound;
            pl.alive = false;
            this->game->last_player_coup = pl.name;
            this->game->removeplayer(pl);
            seven = false;
            this->last_action = "coup";
            this->game->last_coup = &pl;
            this->game->start_game = true;
        }
        else if(this->salary >= bound1 && seven){
            this->game->setturn();
            this->salary = this->salary-bound1;
            pl.alive = false;
            this->game->last_player_coup = pl.name;
            this->game->last_coup = &pl;
            this->game->removeplayer(pl);
            this->last_action = "coup";
            this->game->start_game = true;
        }
        else{
            throw runtime_error("don't have enough money or player is not alive...");
        }
        
    }
    string Assassin::role(){
        return this->role_pl;
    }
}