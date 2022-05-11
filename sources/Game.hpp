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
    string last_player_coup;
    Player* last_coup;
    vector<string> play;
    vector<Player*> Players;
    unsigned int to_play =0;
    Game(/* args */);
    ~Game();
    string turn();
    void setturn();
    vector<string> players();
    void addplayers(Player *player);
    string winner();
    vector<Player*> get_players();
    void setplayes(const string& name);
    void removeplayer(Player& player);
    void addname(const string& name);
    };
}


    
