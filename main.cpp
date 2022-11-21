#include <iostream>

#include "Game/Compiler.h"


class consolePlayer : public IPlayer
{
private:
	std::string name;

public:
	consolePlayer(std::string name)
	{
		this->name = name;
	}

	std::string makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map) override {
		state_data->print();

		DataSet* move = moves_map.at("m");
		int stack, amount;

		std::cout << name << ": Stack: ";
		std::cin >> stack;

		std::cout << name << ": Amount: ";
		std::cin >> amount;

		move->setInt("stack", stack);
		move->setInt("amount", amount);

		std::cout << "\n\n";

		return "m";
	}

	void Payoff(int payoff) override {
		std::cout << name << ": " << payoff << '\n';
	}
};

int main(int argc, char* argv[])
{
	consolePlayer* player_a = new consolePlayer("a");
	consolePlayer* player_b = new consolePlayer("b");
	Game* game = Compiler().createGame("Source/source.txt");
	game->setPlayer(player_a, "player", 0);
	game->setPlayer(player_b, "player", 1);
	game->startGame();

	return 0;
}