#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;



namespace coup{
    class Player;
    class Game{
private:
    
public:
    bool start_game = false;
    int place_coup =0;
    bool add_player_sign = false;
    bool end_turn = false;
    bool regular_coup = false;
    string last_player_coup;
    Player* last_coup;
    vector<string> play;
    vector<Player*> Players;
    vector<Player*> Players_begin;
    unsigned int to_play =0;
    Game(/* args */);
    ~Game();
    string turn();
    void setturn();
    vector<string> players()const;
    void addplayers(Player *player);
    string winner();
    vector<Player*> get_players()const;
    void setplayes(const string& name);
    void removeplayer(Player& player);
    void addname(const string& name);
    void add_player(Player*,int);
    };
}


    
