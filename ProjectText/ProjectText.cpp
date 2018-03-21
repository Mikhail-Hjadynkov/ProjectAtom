#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

//Map matrix
string map [10][10]
{
	{ "A0","A1","A2","A3","A4","A5","A6","A7","A8","A9" }, // 0
	{ "B0","B1","B2","B3","B4","B5","B6","B7","B8","B9" }, // 1
	{ "C0","C1","C2","C3","C4","C5","C6","C7","C8","C9" }, // 0
	{ "D0","D1","D2","D3","D4","D5","D6","D7","D8","D9" }, // 0
	{ "E0","E1","E2","E3","E4","E5","E6","E7","E8","E9" }, // 0
	{ "F0","F1","F2","F3","F4","F5","F6","F7","F8","F9" }, // 0
	{ "G0","G1","G2","G3","G4","G5","G6","G7","G8","G9" }, // 0
	{ "H0","H1","H2","H3","H4","H5","H6","H7","H8","H9" }, // 0
	{ "I0","I1","I2","I3","I4","I5","I6","I7","I8","I9" }, // 0
	{ "J0","J1","J2","J3","J4","J5","J6","J7","J8","J9" }, // 0
};

//Art loader
int loader(string file)
{
	string printer;

	ifstream ifs{ file };
	while (getline(ifs, printer))
	{
		cout << printer << endl;
	}
	return 0;
}

//Lower converter
void lower(string & word)
{
	for (int i = 0; i < word.size(); i++)
	{
		word[i] = tolower(word[i]);
	}
}

//Slots
void slots(int & money)
{
	vector<char> slot{'?','?','?'};
	int bet, randomizer;
	bool play = true;
	while (play == true)
	{
		string option = "void";
		system("cls");
		cout << "	      ---SLOTY---" << endl;
		cout << "***Get the same icons and you'll win!***" << endl;
		cout << " ++Just input your bet and get lucky!++ " << endl << endl;
		cout << ">> FINANCES" << endl;
		cout << "Balance: Rb$" << money << endl;
		cout << "Bet: Rb$";
		cin >> bet;
		if (bet > money)
		{
			cout << endl << "STOP! You cannot bet that quantity! You don't own that much money." << endl << endl;
		}
		else if (bet == 0)
		{
			cout << endl << "WAIT! You cannot bet nothing! You gotta input a real bet" << endl << endl;
		}
		else
		{
			srand((int)time(0));
			for (int c = 0; c < slot.size(); c++)
			{
				randomizer = (rand() % 150)+1;
				if (randomizer <= 50)
				{
					slot[c] = '%';
				}
				else if (randomizer > 50 && randomizer <= 90)
				{
					slot[c] = '&';
				}
				else if (randomizer > 90 && randomizer <= 120)
				{
					slot[c] = '@';
				}
				else if (randomizer > 120 && randomizer <= 140)
				{
					slot[c] = '#';
				}
				else if (randomizer > 140 && randomizer <= 150)
				{
					slot[c] = '$';
				}
			}

			cout << endl;
			loader("slot_a.txt");
			cout << "       | [" << slot[0] << "] [" << slot[1] << "] [" << slot[2] << "] |(  )" << endl;
			loader("slot_b.txt");
			cout << endl;
			if (slot[0] == slot[1] && slot[1] == slot[2])
			{
				switch (slot[0])
				{
				case '%':
					bet *= 2;
					break;
				case '#':
					bet *= 25;
					break;
				case '@':
					bet *= 10;
					break;
				case '&':
					bet *= 5;
					break;
				case '$':
					bet *= 50;
					break;
				}
				money += bet;
				cout << "CONGRATULATIONS!" << endl;
				cout << "You win Rb$" << bet << "!" << endl << endl;
				cout << ">> FINANCES" << endl;
				cout << "Balance: Rb$" << money << endl;

			}
			else
			{
				money -= bet;
				cout << "What a pity!" << endl;
				cout << "You lose Rb$" << bet << "..." << endl << endl;
				cout << ">> FINANCES" << endl;
				cout << "Balance: Rb$" << money << endl << endl;
			}
		}
		while (option != "yes" && option != "no")
		{
			cout << "Wanna play again?: ";
			cin >> option;
			lower(option);
			if (option == "yes")
			{
				play = true;
			}
			else if (option == "no")
			{
				play = false;
			}
			else
			{
				cout << "What?" << endl;
			}
		}
	}
}

//Biryulki
void biryulki(int & money)
{
	int bet, randomizer;
	string token;
	bool play = true;
	while (play == true)
	{
		string option = "void";
		system("cls");
		cout << "	      ---BIRYULKI---" << endl;
		cout << "***Be the first in getting all your tokens and win!***" << endl;
		cout << "  ++Write the number of the box and get the token!++ " << endl << endl;
		cout << ">> FINANCES" << endl;
		cout << "Balance: Rb$" << money << endl;
		cout << "Bet: Rb$";
		cin >> bet;
		
		if (bet > money)
		{
			cout << endl << "STOP! You cannot bet that quantity! You don't own that much money." << endl << endl;
		}
		else if (bet == 0)
		{
			cout << endl << "WAIT! You cannot bet nothing! You gotta input a real bet" << endl << endl;
		}
		else
		{
			cout << endl;
			loader("tokens.txt");
			while (token != "jewel"&&token != "leaf"&&token != "bread"&&token != "ball"&&token != "doll")
			{
				cout << "Choose a token: ";
				cin >> token;
				lower(token);
				if (token == "jewel" || token == "leaf" || token == "bread" || token == "ball" || token == "doll")
				{
					cout << "Ok! Your token will be the " << token << endl;
				}
				else
				{
					cout << "That's an invalid token name... Be sure to write the token name." << endl;
				}
			}
		}
		while (option != "yes" && option != "no")
		{
			cout << "Wanna play again?: ";
			cin >> option;
			lower(option);
			if (option == "yes")
			{
				play = true;
			}
			else if (option == "no")
			{
				play = false;
			}
			else
			{
				cout << "What?" << endl;
			}
		}
	}
}

int main()
{
	//Variable declarations
	vector<string> commandline;
	string command;
	int money = 100;

	//Trialout menu
	cout << "---MENU---" << endl;
	cout << "<Play>" << endl;
	cout << "-Sloty" << endl;
	cout << "-Arkadiya" << endl;
	cout << "-Gorodki" << endl;
	cout << "-Biryulki" << endl;
	cout << "-Svaika" << endl;
	cout << endl << "---STATS---" << endl;
	cout << "Hjadynivite Rayubi: " << money << endl;
	cout << endl << "Insert a command: ";

	//Command input
	getline(cin, command);
	lower(command);
	stringstream ss{ command };
	for (string s; ss >> s; )
	{
		commandline.push_back(s);
	}
	
	//Command executor
	if (commandline.size() == 1)
	{
		//Still blank
	}
	else if (commandline.size() == 2)
	{
		if (commandline[0] == "play")
		{
			if (commandline[1] == "sloty")
			{
				slots(money);
			}
			else if (commandline[1] == "biryulki")
			{
				biryulki(money);
			}
			else
			{
				cout << "You cannot play " << commandline[1] << " :(" << endl;
			}
		}
	}
	else
	{
		cout << ">> Command Overload!" << endl;
	}

	system("pause");
	return 0;
}