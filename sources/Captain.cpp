#include <iostream>
#include <vector>
#include <string>
#include "Captain.hpp"
#include "Player.hpp" 
#include "Game.hpp"
using namespace std;
coup::Captain::Captain(Game &game,const string& name):Player(game,name){
    this->role_pl = "Captain";
}
coup::Captain::~Captain(){
    
}
namespace coup{
    void Captain::block(Player &pl){
        if(!pl.alive){
            throw runtime_error("player is not alive...");
        }
        if(pl.last_action != "steal"){
            throw runtime_error("captain can block only steal");
        }
        pl.setcoin(2);
        this->game->last_coup->setcoin(-2);
        this->last_action = "block";
    }
    void Captain::steal(Player &pl){
        if(!(this->name == this->game->turn())){
            throw runtime_error("player not playing in his turn...");
        }
        if(!pl.alive){
            throw runtime_error("player is not alive...");
        }
        const int ten_coins = 10;
        if(this->salary >= ten_coins){
            throw runtime_error("must make coup..");
        }

        if(pl.salary>0){
            bool enter = true;
            if(pl.salary>=2){
                pl.setcoin(2);
                this->salary = this->salary +2;
                enter = false;
            }
            if(pl.salary>=1 && enter){
                pl.setcoin(1);
                this->salary = this->salary +1;
            }
             this->game->last_coup = &pl;
             this->game->setturn();
             this->last_action = "steal";
             this->game->start_game = true;
        }
        else{ 
            throw runtime_error("player doesn't have enough money");
        }
    }
    string Captain::role(){
        return this->role_pl;
    }
}