#pragma once

#include <iostream>
#include <string>
#include <list>

class Player
{
private:
	std::string player_type;
	int player_id;

	int payoff = 0;	// Payoff for game (to refactor)

public:
	Player(std::string player_type, int player_id);

	int getId();
	std::string getType();

	void setPayoff(int payoff);

	void print();
};


class PlayersSet
{
private:
	std::list<Player*> players;
	Player* on_move;

public:
	PlayersSet(std::list<Player*> players);

	void setNextPlayer(std::string type, int id);
	void setNextPlayer(Player* player);
	Player* getCurrentPlayer();
	std::list<Player*> getPlayersList();

	void print();
};