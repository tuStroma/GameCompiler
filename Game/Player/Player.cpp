#include "Player.h"

Player::Player(std::string player_type, int player_id)
	: player_type(player_type), player_id(player_id)
{}

int Player::getId()
{
	return player_id;
}

std::string Player::getType()
{
	return player_type;
}

void Player::print()
{
	std::cout << player_type << " " << player_id << '\n';
}

PlayersSet::PlayersSet(std::list<Player*> players)
	: players(players), next_player(NULL)
{
	if (players.size() == 0)
	{
		std::cout << "Warning: Players set is empty\n";
		return;
	}

	next_player = players.front();
}

void PlayersSet::setNextPlayer(std::string type, int id)
{
	// OPTIMIZATION: add map to avoid linear searching
	for (Player* p : players)
	{
		if (p->getId() == id && p->getType() == type)
		{
			next_player = p;
			return;
		}
	}

	std::cout << "Execution Error: Player does not exist: " << type << '[' << id << "]\n";
	next_player = NULL;
}

Player* PlayersSet::getNextPlayer()
{
	return next_player;
}

void PlayersSet::print()
{
	next_player->print();
	std::cout << '\n';

	for (Player* p : players) p->print();
}
