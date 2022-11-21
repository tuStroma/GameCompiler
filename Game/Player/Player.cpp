#include "Player.h"

Player::Player(std::string player_type, int player_id)
	: player_type(player_type), player_id(player_id), player(NULL)
{}

int Player::getId()
{
	return player_id;
}

std::string Player::getType()
{
	return player_type;
}

void Player::setPlayer(IPlayer* player)
{
	this->player = player;
}

void Player::setPayoff(int payoff)
{
	player->Payoff(payoff);
	this->payoff = payoff;
}

std::string Player::makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map)
{
	return player->makeMove(state_data, moves_map);
}

void Player::print()
{
	std::cout << player_type << " " << player_id << " payoff: " << payoff << '\n';
}

Player* PlayersSet::getPlayer(std::string type, int id)
{
	// OPTIMIZATION: add map to avoid linear searching
	for (Player* p : players)
		if (p->getId() == id && p->getType() == type)
			return p;

	return NULL;
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
	Player* player = getPlayer(type, id);
	if (player)
	{
		on_move = player;
		return;
	}

	std::cout << "Execution Error: Player does not exist: " << type << '[' << id << "]\n";
	on_move = NULL;
}

void PlayersSet::setNextPlayer(Player* player)
{
	on_move = player;
}

Player* PlayersSet::getCurrentPlayer()
{
	return on_move;
}

std::list<Player*> PlayersSet::getPlayersList()
{
	return players;
}

void PlayersSet::setPlayer(IPlayer* i_player, std::string player_class, int player_id)
{
	Player* player = getPlayer(player_class, player_id);
	if (player)
	{
		player->setPlayer(i_player);
		return;
	}

	std::cout << "Execution Error: Player does not exist: " << player_class << '[' << player_id << "]\n";
	on_move = NULL;
}

std::string PlayersSet::makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map)
{
	return on_move->makeMove(state_data, moves_map);
}

void PlayersSet::print()
{
	on_move->print();
	std::cout << '\n';

	for (Player* p : players) p->print();
}
