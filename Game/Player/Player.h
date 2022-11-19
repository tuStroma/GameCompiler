#pragma once

#include <iostream>
#include <string>
#include <list>

class Player
{
private:
	std::string player_type;
	int player_id;

public:
	Player(std::string player_type, int player_id);

	int getId();
	std::string getType();

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
	Player* getCurrentPlayer();

	void print();
};