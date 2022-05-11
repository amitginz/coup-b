
#include "Game.hpp"
#include "Player.hpp"
using namespace coup;
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
Game::Game(/* args */){
    this->last_player_coup = "";
    this->last_coup = NULL;
}
Game::~Game(){}

string Game::turn(){
    if(this->Players.empty()){
        throw runtime_error("we don't have players in the game");
    }
    string turn = Players.at((unsigned int)this->to_play)->name;
    return turn;
}

void Game::setturn(){
    this->to_play = (((unsigned int)this->to_play+1) % (this->get_players().size()));
    const int start = 0;
    if(this->to_play == start){
        bool end_turn = true;
    }
    else{
        bool end_turn = false;
    }
    if(!(this->Players.at((unsigned)this->to_play)->alive)){
        this->setturn();
    }
}

vector<string> Game::players()const{
    return this->play;
}
string Game::winner(){
    if(!start_game){
        throw runtime_error("didn't start the game");
    }
    if(play.size()>1){
        throw runtime_error("game didn't end");
    }
    string win = this->play[0];
    return win;
}

void Game::addplayers(Player *player){
   Players.push_back(player);
   Players_begin.push_back(player);
}

void Game::setplayes(const string& name){
    this->play.push_back(name);
}

void Game::removeplayer(Player& player){
    for(uint i =0 ;i < get_players().size();i++){
        if(!this->Players.at(i)->alive){
            this->place_coup = (int)i;
            this->Players.erase(Players.begin()+i);
            this->play.erase(play.begin()+i);
        }
    }
}
void Game::addname(const string& name){
    vector<string> players;
    players.push_back(name);
    for(uint i =0 ; i<this->play.size();i++){
        players.push_back(this->play.at(i));
    }
    this->play = players;
}

void Game::add_player(Player*player,int num){
    // vector<Player*> players;
    // for(uint i = 0 ; i<this->Players.size()+1;i++){
    //     if(this->Players_begin.at(i)->alive){
    //         players.push_back(Players_begin.at(i));
    //     }
    // }
    // this->Players = players;
    this->Players.insert(this->Players.begin()+num,player);
    
}
vector<Player*> Game::get_players()const{
    return this->Players;
}

