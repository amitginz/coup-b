
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
    // if(this->to_play == this->Players.size()-1){
    //     this->to_play = 0;
    // }
    // else{
    //     this->to_play++;
    // }
    if(!(this->Players.at((unsigned)this->to_play)->alive)){
        this->setturn();
    }
}

vector<string> Game::players(){
    // vector<string> player_name;
    // for(Player *p: Players){
    //     if(p->alive){
    //         play.push_back(p->name);
    //     }
    // }
    return this->play;
    // return player_name;
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
}

void Game::setplayes(const string& name){
    this->play.push_back(name);
}

void Game::removeplayer(Player& player){
    vector<string> players;
    vector<Player*> Play;
    for(uint i =0 ;i < get_players().size();i++){
        if(!this->Players.at(i)->alive){
            // players.push_back(this->play.at(i));
            // Play.push_back(this->Players.at(i));
            this->Players.erase(Players.begin()+i);
            this->play.erase(play.begin()+i);
        }
        // this->play = players;
        // this->Players = Play;
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
vector<Player*> Game::get_players(){
    return this->Players;
}

