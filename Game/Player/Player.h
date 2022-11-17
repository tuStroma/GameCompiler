#pragma once

#include <iostream>
#include <string>

class Player
{
private:
	std::string player_type;
	int player_id;

public:
	Player(std::string player_type, int player_id);

	void print();
};

