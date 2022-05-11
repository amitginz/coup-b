
#include "Ambassador.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

coup::Ambassador::Ambassador(Game &game,const string& name):Player(game,name){
    this->role_pl = "Ambassador";
}
coup::Ambassador::~Ambassador(){
    
}
namespace coup{
    void Ambassador::transfer(Player &player1,Player &player2){
        if(player1.salary <1){
            throw runtime_error("don't have enough money");
        }
        if(!player1.alive || !player2.alive){
            throw runtime_error("player isn't alive");
        }
        if(this->salary >= 10){
            throw runtime_error("must make coup..");
        }
            this->game->setturn();
            player1.salary--;
            player2.salary++;
            this->last_action = "transfer";
            this->game->start_game = true;
    }
    void Ambassador::block(Player &pl){
        if(!pl.alive){
            throw runtime_error("player isn't alive");
        }
        if(pl.last_action != "steal"){
            throw runtime_error("the player wasn't steal");
        }
        this->last_action = "block";
        pl.setcoin(-2);
    }
    string Ambassador::role(){
        return this->role_pl;
    }
}