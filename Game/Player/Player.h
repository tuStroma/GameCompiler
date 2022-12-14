#pragma once

#include <iostream>
#include <string>
#include <list>

#include "IPlayer.h"

class Player
{
private:
	std::string player_type;
	int player_id;

	IPlayer* player;
	int payoff = 0;	// Payoff for game (to refactor)

public:
	Player(std::string player_type, int player_id);

	int getId();
	std::string getType();

	void setPlayer(IPlayer* player);
	void setPayoff(int payoff);

	std::string makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map);

	void print();
};


class PlayersSet
{
private:
	std::list<Player*> players;
	Player* on_move;

	Player* getPlayer(std::string type, int id);

public:
	PlayersSet(std::list<Player*> players);

	void setNextPlayer(std::string type, int id);
	void setNextPlayer(Player* player);
	Player* getCurrentPlayer();
	std::list<Player*> getPlayersList();

	void setPlayer(IPlayer* i_player, std::string player_class, int player_id);

	std::string makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map);

	void print();
};
