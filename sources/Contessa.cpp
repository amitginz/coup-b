

#include "Contessa.hpp"
#include "Player.hpp" 
using namespace std;
coup::Contessa::Contessa(Game &game, const string& name):Player(game,name){
    this->role_pl = "Contessa";
}
coup::Contessa::~Contessa(){
    
}
namespace coup{
    void Contessa::block(Player &pl){
        if(pl.role() != "Assassin"){
            throw runtime_error("can block only assassin...");
        }
        if(!pl.alive || !this->alive){
            throw runtime_error("player is already dead");
        }
        if(pl.last_action != "coup"){
            throw runtime_error("coup wasn't last action...");
        }
        if(this->game->regular_coup){
            throw runtime_error("can't block after regular assassin");
        }
        this->game->last_coup->alive = true;
        this->game->addname(this->game->last_player_coup);
        this->game->add_player(this->game->last_coup,this->game->place_coup);
        this->last_action = "block";
        this->game->start_game = true;
    }
    string Contessa::role(){
        return this->role_pl;
    }
}