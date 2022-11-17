#include "Player.h"

Player::Player(std::string player_type, int player_id)
	: player_type(player_type), player_id(player_id)
{}

void Player::print()
{
	std::cout << player_type << " " << player_id << '\n';
}
