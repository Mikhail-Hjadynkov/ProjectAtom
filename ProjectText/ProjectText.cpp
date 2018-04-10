#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

enum TOKEN
{
	JEWEL=1,
	LEAF,
	DOLL,
	CROWN,
	BALL,
};

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

//Help
void help(string key)
{
	if (key == "lockpick")
	{
		cout << endl;
		cout << "LOCKPICKING INSTRUCTIONS" << endl;
		cout << "-Lockpicking requires bobbykeys to try to unlock" << endl;
		cout << "-All unlockables have a number of keypins to break" << endl;
		cout << "-To lockpick you need to input 'thrust' plus a direction" << endl;
		cout << "EXAMPLE:" << endl;
		cout << "(Command: thrust up)" << endl;
		cout << "This thrusts the lock upwards and registers the movement" << endl;
		cout << "-Finish all your movements and see how many movements you got right" << endl;
		cout << "-If you don't break the lock within the limit attempts, it will break" << endl;
		cout << " and you won't be able to try to unlock it again" << endl;
		cout << endl;
	}
	else if (key == "hacking")
	{
		cout << endl;
		cout << "HACKING INSTRUCTIONS" << endl;
		cout << "-Hacking a system needs a powdrive to try to unlock" << endl;
		cout << "-The powdrive obtains all the letters of the password, you need to write the word." << endl;
		cout << "-To input a password you need to write 'type' plus the word" << endl;
		cout << "EXAMPLE:" << endl;
		cout << "(Command: type password)" << endl;
		cout << "This makes the system receive the input and check if it is the password" << endl;
		cout << "-Write the exact password and the system will be unlocked" << endl;
		cout << "-If you don't input the correct password within the limit attempts, it will be blocked" << endl;
		cout << " and you won't be able to try to unlock it again" << endl;
		cout << endl;
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
			loader("slot_a.gaf");
			cout << "       | [" << slot[0] << "] [" << slot[1] << "] [" << slot[2] << "] |(  )" << endl;
			loader("slot_b.gaf");
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
				cout << "What a pity..." << endl;
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
	int bet, randomizer, turn=0;
	bool play = true, win = false;
	while (play == true)
	{
		vector<int>count{0,0,0,0,0};
		vector<string>names{ "jewel","leaf","doll","crown","ball" };
		string option = "void", token;
		system("cls");
		cout << "	     ---BIRYULKI---" << endl;
		cout << "***Be the first in getting all your tokens and win!***" << endl;
		cout << "      ++The longer the game, the more you earn!++ " << endl << endl;
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
			loader("tokens.gaf");
			while (token != "jewel"&&token != "leaf"&&token != "crown"&&token != "ball"&&token != "doll")
			{
				cout << "Choose a token: ";
				cin >> token;
				lower(token);
				if (token == "jewel" || token == "leaf" || token == "crown" || token == "ball" || token == "doll")
				{
					cout << "Ok! Your token will be the " << token << endl;
				}
				else
				{
					cout << "That's an invalid token name... Be sure to write the token name." << endl << endl;
				}
			}
			srand((int)time(0));
			while (count[0] != 5 && count[1] != 5 && count[2] != 5 && count[3] != 5 && count[4] != 5)
			{
				turn++;
				randomizer = (rand() % 5)+1;
				switch (randomizer)
				{

				case JEWEL:
					loader("jewel.gaf");
					cout << "The token number " << turn << " is a Jewel!" << endl << endl;
					count[0]++;
					break;
				case LEAF:
					loader("leaf.gaf");
					cout << "The token number " << turn << " is a Leaf!" << endl << endl;
					count[1]++;
					break;
				case DOLL:
					loader("doll.gaf");
					cout << "The token number " << turn << " is a Doll!" << endl << endl;
					count[2]++;
					break;
				case CROWN:
					loader("crown.gaf");
					cout << "The token number " << turn << " is a Crown!" << endl << endl;
					count[3]++;
					break;
				case BALL:
					loader("ball.gaf");
					cout << "The token number " << turn << " is a Ball!" << endl << endl;
					count[4]++;
					break;
				}
				cout << "TURN'S RESULTS" << endl;
				cout << "The jewel has " << count[0] << " tokens!" << endl;
				cout << "The leaf has " << count[1] << " tokens!" << endl;
				cout << "The doll has " << count[2] << " tokens!" << endl;
				cout << "The crown has " << count[3] << " tokens!" << endl;
				cout << "The ball has " << count[4] << " tokens!" << endl << endl;

				cout << "Press 'Enter' to advance to continue... " << endl;
				cin.ignore();
			}
			for (int p = 0; p < count.size(); p++)
			{
				if (count[p] == 5 && names[p] == token)
				{
					win = true;
				}
			}
			if (win == true)
			{
				bet*=turn;
				money += bet;
				cout << "CONGRATULATIONS!" << endl;
				cout << "Your bet will be multiplied by " << turn << "!" << endl;
				cout << "You win Rb$" << bet << "!" << endl << endl;
				cout << ">> FINANCES" << endl;
				cout << "Balance: Rb$" << money << endl;
			}
			else
			{
				
				money -= bet;
				cout << "What a pity..." << endl;
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

//Door lockpicking
void door(int & bobbykey)
{
	bool open = false, broken = false, trying=true;
	int attempt=0, keypin = 4, randomizer, hits=0, limit=10;
	vector<string> keylock, intcommandline; //"int" prefix stands for "internal"
	string intcommand;

	system("cls");
	cout << "//DOOR LOCKPICKING" << endl << endl;
	if (open == false)
	{
		loader("door_c.gaf");
	}
	else if (open == true)
	{
		loader("door_o.gaf");
	}
	else if (broken = true)
	{
		loader("door_b.gaf");
	}
	cout << "This is a pretty common door" << endl << endl;
	cout << "<DATA>" << endl;
	cout << "Difficulty: Average" << endl;
	cout << "Keypins: " << keypin << endl;
	cout << "Limit: " << limit << endl << endl;
	cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

	//Logic
	for (int k = 0; k < keypin; k++)
	{
		randomizer = rand() % 4 + 1;
		switch (randomizer)
		{
		case 1:
			keylock.push_back("up");
			break;
		case 2:
			keylock.push_back("down");
			break;
		case 3:
			keylock.push_back("right");
			break;
		case 4:
			keylock.push_back("left");
			break;
		}
	}

	while (open==false&&broken==false&&bobbykey>0)
	{
		cout << "<STATS>" << endl;
		cout << "Bobbykeys: " << bobbykey << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
		attempt += 1;
		bobbykey -= 1;
		for (int t = 0; t < keypin; t++)
		{
			cout << "Input a command>> ";
			getline(cin, intcommand);
			lower(intcommand);
			stringstream ss{ intcommand };
			for (string s; ss >> s; )
			{
				intcommandline.push_back(s);
			}

			if (intcommandline.size() == 1)
			{
				if (intcommandline[0] == "help")
				{
					help("lockpick");
				}
			}
			else if (intcommandline.size() == 2)
			{
				if (intcommandline[0] == "thrust")
				{
					if (intcommandline[1] == keylock[t])
					{
						hits += 1;
						cout << "You got over keypin number " << t << "!" << endl;
					}
					else
					{
						cout << "You didn't overpass this keypin. Try thrusting in other direction." << endl;
					}
				}
				else
				{
					cout << "Hey! You entered an invalid command. Be sure to get it right" << endl;
					t--;
				}
			}
			else
			{
				cout << "<< Command Overload!" << endl;
				t--;
			}
			intcommandline.clear();
		}

		if (hits < keypin)
		{
			cout << endl << "You have surpassed " << hits << " keypins out of " << keypin << endl;
		}
		else if (hits == keypin)
		{
			cout << endl << "You surpassed all keypins and unlocked the door!" << endl << endl;
			open = true;
		}
		else if (attempt == limit)
		{
			cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the door is locked forever." << endl << endl;
			broken = true;
		}
		if (bobbykey == 0 && open != true)
		{
			cout << endl << "You don't have more bobbykeys. You cannot try to open the door again." << endl << endl;
		}
		hits = 0;
	}
}

void computer(int&powdrive)
{
	bool unlock = false, blocked = false, trying = true;
	int attempt = 0, randomizer, limit = 5;
	vector<string> wordset{"parses","passer","spares","sparse","spears"}, intcommandline; //"int" prefix stands for "internal"
	string intcommand, word="aeprss", password;

	system("cls");
	cout << "//COMPUTER HACKING" << endl;
	if (unlock == false)
	{
		loader("computer_l.gaf");
	}
	else if (unlock == true)
	{
		loader("computer_u.gaf");
	}
	else if (blocked = true)
	{
		loader("computer_b.gaf");
	}
	cout << "This is a pretty common computer" << endl << endl;
	cout << "<DATA>" << endl;
	cout << "Difficulty: Average" << endl;
	cout << "Powdrive: " << powdrive << endl;
	cout << "Limit: " << limit << endl << endl;
	cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

	loader("monitor_a.gaf");
	cout << "     |   |(Password hint: " << word << ")             |   |" << endl;
	loader("monitor_b.gaf");

	//Logic
	randomizer = rand() % 5 + 1;
	password = wordset[randomizer];

	while (unlock == false && blocked == false && powdrive>0)
	{
		cout << "<STATS>" << endl;
		cout << "Powdrive: " << powdrive << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
		attempt += 1;
		powdrive -= 1;
		cout << "Input a command>> ";
		getline(cin, intcommand);
		lower(intcommand);
		stringstream ss{ intcommand };
		for (string s; ss >> s; )
		{
			intcommandline.push_back(s);
		}

		if (intcommandline.size() == 1)
		{
			if (intcommandline[0] == "help")
			{
				help("hacking");
			}
		}
		else if (intcommandline.size() == 2)
		{
			if (intcommandline[0] == "type")
			{
				if (intcommandline[1] == password)
				{
					loader("monitor_d.gaf");
					unlock = true;
				}
				else
				{
					loader("monitor_a.gaf");
					cout << "     |   |(Password hint: " << word << ")             |   |" << endl;
					loader("monitor_c.gaf");
				}
			}
			else
			{
				cout << "Hey! You entered an invalid input. Be sure to get it right" << endl;
			}
		}
		else
		{
			cout << "<< Command Overload!" << endl;
		}
		intcommandline.clear();

		if (attempt == limit)
		{
			cout << endl << "You didn't pass all the keypins. The system is blocked, it can't be accessed again." << endl << endl;
			blocked = true;
		}
		if (powdrive == 0 && unlock != true)
		{
			cout << endl << "You don't have more powdrives. You cannot try to hack the computer again." << endl << endl;
		}
	}
}

int main()
{
	//Variable declarations
	vector<string> commandline, inicommandline;
	string command, inicommand, infile, outfile, retriever;
	string core[3];
	int money, bobbykey, powdrive, index=0;

	//Trialout initial screen
	cout << "PROJECT ATOM (C) TCCPe 2018" << endl << endl;
	cout << "Input 'create' to create a new game." << endl;
	cout << "Input 'load' to load a saved game." << endl;
	cout << "Input a command>> ";
	
	//Initial command input
	getline(cin, inicommand);
	lower(inicommand);
	stringstream is{ inicommand };
	for (string i; is >> i; )
	{
		inicommandline.push_back(i);
	}

	//Initial executor
	if (inicommandline.size() == 1)
	{
		if (inicommandline[0] == "load")
		{
			cout << endl << "---LOAD---" << endl;
			cout << "Current save files:" << endl;
			loader("saves.gef");
			cout << "Input the file name>> ";
			cin >> infile;
			ifstream ifs{ infile };
			while (getline(ifs, retriever))
			{
				core[index]=retriever;
				index++;
			}
			for (index=0; index < core->size(); index++)
			{
				switch (index)
				{
				case 0:
					money = stoi(core[index]);
					break;
				case 1:
					bobbykey = stoi(core[index]);
					break;
				case 2:
					powdrive = stoi(core[index]);
					break;
				default:
					break;
				}
			}
			cout << "Loaded Successfully!" << endl << endl;
			cin.ignore();
		}
		else if (inicommandline[0] == "create")
		{
			cout << endl << "---CREATE---" << endl;
			money = 100;
			bobbykey = 3;
			powdrive = 3;
			cout << "Created a new game successfully!" << endl;
			cout << "ADVICE: Remember to save continuosly. It is frustrating to lose all your progress." << endl;
		}
		else
		{
			cout << "<< Incorrect command" << endl;
		}
	}
	else
	{
		cout << "<< Command Overload!" << endl;
	}

	cin.ignore();
	system("cls");

	//Trialout menu
	cout << "---MENU---" << endl;
	cout << "<play>" << endl;
	cout << "-Sloty" << endl;
	cout << "-Gorodki" << endl;
	cout << "-Biryulki" << endl;
	cout << "<lockpick>" << endl;
	cout << "-Door" << endl;
	cout << "<hack>" << endl;
	cout << "-Computer" << endl;
	cout << endl << "---STATS---" << endl;
	cout << "Hjadynivite Rayubi: " << money << endl;
	cout << "Bobbykeys: " << bobbykey << endl;
	cout << "Powdrives: " << powdrive << endl;
	cout << endl << "Input a command>> ";

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
		if (commandline[0] == "save")
		{
			cout << endl << "---SAVE---" << endl;
			cout << "BEWARE! You will overwrite a savefile if you write an already existing file name!" << endl;
			cout << "Input the file name>> ";
			cin >> outfile;
			ofstream ofs{ outfile };
			ofs << money << endl;
			ofs << bobbykey << endl;
			ofs << powdrive << endl;
			cout << "Saved successfully as " << outfile << "!" << endl << endl;
		}
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
		else if (commandline[0] == "lockpick")
		{
			if (commandline[1] == "door")
			{
				door(bobbykey);
			}
			else
			{
				cout << "You cannot lockpick a " << commandline[1] << " :(" << endl;
			}
		}
		else if (commandline[0] == "hack")
		{
			if (commandline[1] == "computer")
			{
				computer(powdrive);
			}
			else
			{
				cout << "You cannot lockpick a " << commandline[1] << " :(" << endl;
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