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
	: players(players), on_move(NULL)
{
	if (players.size() == 0)
	{
		std::cout << "Warning: Players set is empty\n";
		return;
	}

	on_move = players.front();
}

void PlayersSet::setNextPlayer(std::string type, int id)
{
	// OPTIMIZATION: add map to avoid linear searching
	for (Player* p : players)
	{
		if (p->getId() == id && p->getType() == type)
		{
			on_move = p;
			return;
		}
	}

	std::cout << "Execution Error: Player does not exist: " << type << '[' << id << "]\n";
	on_move = NULL;
}

Player* PlayersSet::getCurrentPlayer()
{
	return on_move;
}

void PlayersSet::print()
{
	on_move->print();
	std::cout << '\n';

	for (Player* p : players) p->print();
}
