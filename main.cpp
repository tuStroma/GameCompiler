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

void printBoard(DataSet* board)
{
	int o_x = *(int*)board->getValuePtr("o_x");
	int o_y = *(int*)board->getValuePtr("o_y");
	int w_x[4];
	int w_y[4];

	for (int i = 0; i < 4; i++) w_x[i] = *(int*)board->getValuePtr("w" + std::to_string(i) + "_x");
	for (int i = 0; i < 4; i++) w_y[i] = *(int*)board->getValuePtr("w" + std::to_string(i) + "_y");

	for(int j = 7; j >= 0; j--)
	{
		std::cout << "  " << j;
		for (int i = 0; i < 8; i++)
		{
			if (o_x == i && o_y == j) std::cout << 'O';
			else if (w_x[0] == i && w_y[0] == j ||
				w_x[1] == i && w_y[1] == j ||
				w_x[2] == i && w_y[2] == j ||
				w_x[3] == i && w_y[3] == j) std::cout << 'W';

			else if (i % 2 == j % 2) std::cout << (char) 219;
			else std::cout << ' ';
		}
		std::cout << '\n';
	}
	std::cout << "   ";
	for (int i = 0; i < 8; i++) std::cout << i;
	std::cout << "\n\n";
}

class Owca : public IPlayer
{
public:
	Owca() {}

	std::string makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map) override {
		printBoard(state_data);

		DataSet* move = moves_map.at("owca");
		int x, y;

		std::cout << "  X: ";
		std::cin >> x;

		std::cout << "  Y: ";
		std::cin >> y;

		move->setInt("move_x", x);
		move->setInt("move_y", y);

		std::cout << "\n\n";

		return "owca";
	}

	void Payoff(int payoff) override {
		std::cout << "Owca: " << payoff << '\n';
	}
};
class Wilki : public IPlayer
{
public:
	Wilki() {}

	std::string makeMove(DataSet* state_data, std::unordered_map<std::string, DataSet*> moves_map) override {
		printBoard(state_data);

		DataSet* move = moves_map.at("wilki");
		int index, x, y;

		std::cout << "  Wilk: ";
		std::cin >> index;

		std::cout << "  X: ";
		std::cin >> x;

		std::cout << "  Y: ";
		std::cin >> y;

		move->setInt("wilk_indeks", index);
		move->setInt("move_x", x);
		move->setInt("move_y", y);

		std::cout << "\n\n";

		return "wilki";
	}

	void Payoff(int payoff) override {
		std::cout << "Owca: " << payoff << '\n';
	}
};

void wioTest()
{
	Owca* owca = new Owca();
	Wilki* wilki = new Wilki();
	Game* game = Compiler().createGame("Source/wio.txt");
	game->setPlayer(owca, "owca", 0);
	game->setPlayer(wilki, "wilki", 0);
	game->startGame();
}

int main(int argc, char* argv[])
{
	//
	wioTest();

	/*/
	consolePlayer* player_a = new consolePlayer("a");
	consolePlayer* player_b = new consolePlayer("b");
	Game* game = Compiler().createGame("Source/source.txt");
	game->setPlayer(player_a, "player", 0);
	game->setPlayer(player_b, "player", 1);
	game->startGame();
	//*/

	return 0;
}