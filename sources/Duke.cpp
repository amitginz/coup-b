#include "Game.hpp" 
#include "Duke.hpp"
#include "Player.hpp" 
coup::Duke::Duke(Game &game,const string& name):Player(game,name){
    this->role_pl = "Duke";
}
coup::Duke::~Duke(){
    
}
namespace coup{
    void Duke::block(Player& play){
        if(play.last_action != "foreign aid"){
            throw runtime_error("can't block action that isn't foreign aid");
        }
        if(this->salary >= 10){
            throw runtime_error("must make coup..");
        }
        play.setcoin(2);
        this->last_action = "block";
    }
    void Duke::tax(){
        if(this->salary >= 10){
            throw runtime_error("must make coup..");
        }
        this->salary = this->salary +3;
        this->game->setturn();
        this->game->start_game = true;
    }
    string Duke::role(){
        return this->role_pl;
    }
};