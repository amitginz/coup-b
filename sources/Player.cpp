#include "Player.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
namespace coup{
   
    Player::Player(Game &_game,const string& name){
        this->alive = true;
        this->name = name;
        this->salary = 0;
        game = &_game;
        game->addplayers(this);
        game->setplayes(name);
        if(this->game->get_players().size()>6){
            throw runtime_error("there is too many players...");
        }
        if(this->game->start_game){
            throw runtime_error("game already start");
        }

    }

    Player::~Player(){}
    void Player::income(){
        if(this->game->get_players().size()<2){
            throw runtime_error("there is too little players...");
        }
        if(this->salary >= 10){
            throw runtime_error("must make coup...");
        }
        if(this->name == this->game->turn()){
            this->salary++;
            this->game->setturn();
            this->game->start_game = true;
        }
        else{
            throw runtime_error("it is not player turn");
        }
            
    }
    void Player::foreign_aid(){
        if(this->game->get_players().size()<2){
            throw runtime_error("there is too little players...");
        }
        if(this->salary >= 10){
            throw runtime_error("must make coup...");
        }
        if(this->name != this->game->turn()){
            throw runtime_error("it is not player turn");
        }
        if(this->name == this->game->turn()){
            this->salary = this->salary +2;
            this->game->setturn();
            this->game->start_game = true;
            this->last_action = "foreign aid";
        }
        // else{
            
        // }
    }
    void Player::coup(Player &pl){
        
        const int bound = 7;
        if(this->salary >= bound && pl.alive == true){
            this->game->setturn();
            this->salary = this->salary-bound;
            pl.alive = false;
            this->game->start_game = true;
            this->game->last_player_coup = pl.name;
            this->last_action = "coup";
            this->game->last_coup = &pl;
            // pl.last_action = "coup";
            this->game->removeplayer(pl);
        }
        else{
            throw runtime_error("don't have enough money");
        }
    }
    int Player::coins(){
        int income = this->salary;
        return income;}
        
    string Player::role(){
        return this->role_pl;}

    void Player::setcoin(int num){
        this->salary = this->salary -num;
    }
}
