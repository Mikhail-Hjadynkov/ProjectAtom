#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <iomanip>
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

enum LOADER
{
	NAME,
	POSITION,
	HEALTH,
	DEFENSE,
	OFFENSE,
	MONEY,
	BOBBYKEY,
	POWDRIVE,
	HEADGEAR,
	BODYGEAR,
	COMPUTER_UNLOCK,
	COMPUTER_BLOCK,
	DOOR_OPEN,
	DOOR_BROKEN,
	CORE_LIMIT,
};

struct Weapon
{
	string w_name="none", w_ammo="none", w_type="none", w_key="none";
	int w_supply=0, w_id=0, w_loss=0, w_maxdmg=0, w_mindmg=0;
};

struct Garment
{
	string g_name;
	int g_defense;
};

class Player
{
public:
	string p_name{ "none" }, p_position{ "none" }, p_headgear{ "none" }, p_bodygear{ "none" };
	int p_health = 0, p_defense = 0, p_offense = 0, p_money = 0, p_bobbykey = 0, p_powdrive = 0;
	vector<Weapon>p_weaponry, p_garmentry;
};

class Enemy
{
public:
	string e_name{ "none" }, e_file{ "none" };
	int e_health = 0, e_defense = 0, e_offense = 0, e_prize = 0;
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

//Stop function
void stop()
{
	system("pause");
	system("cls");
}

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

//String to boolean
bool stob(string x)
{
	if (x == "false")
	{
		return false;
	}
	else if (x == "true")
	{
		return true;
	}
}

//Boolean to string
string btos(bool y)
{
	if (y == false)
	{
		return "false";
	}
	else if (y == true)
	{
		return "true";
	}
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
		cout << " and you won't be able to try to unlock it again" << endl << endl;
		cout << "INFORMATION" << endl;
		cout << "There are a variety of keyholes types throughout Pribet. Some require more effort to lockpick." << endl;
		cout << "-(Difficulty) can range from easy to difficult depending on the door's protection" << endl;
		cout << "-(Limit) depends on the fact of how many times the keyhole can be lockpicked before wearing out" << endl;
		cout << "-(Keypins) can tell you how many movements you need to make if you wanna break the lock" << endl << endl;
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
		cout << " and you won't be able to try to unlock it again" << endl << endl;
		cout << "INFORMATION" << endl;
		cout << "Not all systems have the same level of protection. Some are more forgiving than others" << endl;
		cout << "-(Difficulty) can range from easy to difficult depending on the system's protection" << endl;
		cout << "-(Limit) depends on the system's ability to find threatening hardware, such as powdrives" << endl;
		cout << "-(Possibilities) can tell you a clue of how many words can be made with the password hint" << endl << endl;
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
				stop();
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
				stop();
			}
			else
			{
				cout << "What?" << endl;
			}
		}
	}
}

//Door lockpicking
void door(int & bobbykey, bool & open, bool & broken)
{
	bool trying=true;
	int attempt=0, keypin = 4, randomizer, hits=0, limit=10;
	vector<string> keylock, intcommandline; //"int" prefix stands for "internal"
	string intcommand;

	system("cls");
	cout << "//DOOR LOCKPICKING" << endl << endl;
	if (open == false && broken == false)
	{
		loader("door_c.gaf");
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
	}
	else if (open == true)
	{
		loader("door_o.gaf");
		cout << "This door has been lockpicked successfully!" << endl;
		stop();
	}
	else if (broken == true)
	{
		loader("door_b.gaf");
		cout << "This door's keyhole is broken. It will be impossible to try to unlock it." << endl;
		stop();
	}

	while (open==false&&broken==false&&bobbykey>0)
	{
		cout << "<STATS>" << endl;
		cout << "Bobbykeys: " << bobbykey << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
		for (int t = 0; t < keypin; t++)
		{
			attempt += 1;
			bobbykey -= 1;
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
						cout << "You didn't overpass this keypin. Try thrusting in other direction next time." << endl;
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
		if (hits == keypin)
		{
			cout << endl << "You surpassed all keypins and unlocked the door!" << endl << endl;
			open = true;
			stop();
		}
		if (attempt == limit)
		{
			cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the door is locked forever." << endl << endl;
			broken = true;
			stop();
		}
		if (bobbykey == 0 && open != true)
		{
			cout << endl << "You don't have more bobbykeys. You cannot try to open the door again." << endl << endl;
			stop();
		}
		hits = 0;
	}
}

//Computer hacking
void computer(int&powdrive, bool&unlock, bool&blocked)
{
	bool trying = true;
	int attempt = 0, randomizer, limit = 5, possibilities = 5;
	vector<string> wordset{"parses","passer","spares","sparse","spears"}, intcommandline; //"int" prefix stands for "internal"
	vector<int> similarities;
	string intcommand, word="aeprss", password, pseudopass;

	system("cls");
	cout << "//COMPUTER HACKING" << endl;
	if (unlock == false && blocked == false)
	{
		loader("computer_l.gaf");
		cout << "This is a pretty common computer. It may be kinda easy to hack." << endl << endl;

		cout << "<DATA>" << endl;
		cout << "Difficulty: Average" << endl;
		cout << "Possibilities: " << possibilities << endl;
		cout << "Limit: " << limit << endl << endl;
		cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

		loader("monitor_a.gaf");
		cout << "     |   |(Password hint: " << word << ")             |   |" << endl;
		loader("monitor_b.gaf");

		//Logic
		randomizer = rand() % 5 + 1;
		password = wordset[randomizer];
	}
	else if (unlock == true)
	{
		loader("computer_u.gaf");
		cout << "This computer's system has been hacked already!" << endl;
		stop();
	}
	else if (blocked == true)
	{
		loader("computer_b.gaf");
		cout << "This computer has detected an access violation. It will be impossible to hack again" << endl;
		stop();
	}

	while (unlock == false && blocked == false && powdrive>0)
	{
		cout << "<STATS>" << endl;
		cout << "Powdrive: " << powdrive << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
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
			else
			{
				cout << "Wrong or incomplete command. Be sure to enter the correct command or input 'help'" << endl << endl;
			}
		}
		else if (intcommandline.size() == 2)
		{
			if (intcommandline[0] == "type")
			{
				attempt += 1;
				powdrive -= 1;
				pseudopass = intcommandline[1];
				if (pseudopass == password)
				{
					loader("monitor_d.gaf");
					unlock = true;
					stop();
				}
				else
				{
					loader("monitor_a.gaf");
					cout << "     |   |(Password hint: " << word << ")             |   |" << endl;
					loader("monitor_c.gaf");
					for (int c = 0; c < password.size(); c++)
					{
						if (password[c] == pseudopass[c])
						{
							cout << "System reports that there is a similarity at index number " << c << endl;
						}
					}
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
			cout << endl << "You didn't guess the password. The system is blocked, it can't be accessed again." << endl << endl;
			blocked = true;
			stop();
		}
		if (powdrive == 0 && unlock != true)
		{
			cout << endl << "You don't have more powdrives. You cannot try to hack the computer again." << endl << endl;
			stop();
		}
	}
}

//Battle System
void battle(Player & player)
{
	system("cls");
	string intcommand;
	bool run=false, found=false, playerTurn=true;
	vector<string> intcommandline;
	vector<Weapon> f_Weapon, m_Weapon, p_Weapon, e_Weapon;
	int randomizer, h_rand, d_rand, o_rand, p_rand, weaponId, damage;
	srand((int)time(0));
	randomizer = (rand() % 150) + 1;
	Enemy enemy;

	//Enemy seed
	if (randomizer <= 50)
	{
		h_rand = (rand() % 150) + 100;
		d_rand = (rand() % 20) + 10;
		o_rand = (rand() % 25) + 15;
		p_rand= (rand() % 50) + 25;
		enemy.e_name = "SOLDIER OF THE PRIPNIY PATROL";
		enemy.e_file = "soldier_a.gaf";
		enemy.e_health = h_rand;
		enemy.e_defense = d_rand;
		enemy.e_offense = o_rand;
		enemy.e_prize = p_rand;
	}
	else if (randomizer > 50 && randomizer <= 90)
	{
		h_rand = (rand() % 250) + 150;
		d_rand = (rand() % 35) + 20;
		o_rand = (rand() % 50) + 25;
		p_rand = (rand() % 100) + 50;
		enemy.e_name = "PRIBET SQUADRON PRIVATE";
		enemy.e_file = "soldier_b.gaf";
		enemy.e_health = h_rand;
		enemy.e_defense = d_rand;
		enemy.e_offense = o_rand;
		enemy.e_prize = p_rand;
	}
	else if (randomizer > 90 && randomizer <= 120)
	{
		h_rand = (rand() % 400) + 250;
		d_rand = (rand() % 55) + 35;
		o_rand = (rand() % 80) + 50;
		p_rand = (rand() % 250) + 100;
		enemy.e_name = "SERGEANT OF THE KORSHKOV FORCES";
		enemy.e_file = "soldier_c.gaf";
		enemy.e_health = h_rand;
		enemy.e_defense = d_rand;
		enemy.e_offense = o_rand;
		enemy.e_prize = p_rand;
	}
	else if (randomizer > 120 && randomizer <= 140)
	{
		h_rand = (rand() % 650) + 400;
		d_rand = (rand() % 85) + 55;
		o_rand = (rand() % 120) + 80;
		p_rand = (rand() % 500) + 250;
		enemy.e_name = "CADET OF THE KHAZNATANVIAN ARMY";
		enemy.e_file = "soldier_d.gaf";
		enemy.e_health = h_rand;
		enemy.e_defense = d_rand;
		enemy.e_offense = o_rand;
		enemy.e_prize = p_rand;
	}
	else if (randomizer > 140 && randomizer <= 150)
	{
		h_rand = (rand() % 1000) + 650;
		d_rand = (rand() % 125) + 85;
		o_rand = (rand() % 100) + 500;
		p_rand = (rand() % 1000) + 500;
		enemy.e_name = "HJADYNIVITE FEDERAL COMMANDANT";
		enemy.e_file = "soldier_e.gaf";
		enemy.e_health = h_rand;
		enemy.e_defense = d_rand;
		enemy.e_offense = o_rand;
		enemy.e_prize = p_rand;
	}

	while (enemy.e_health > 0 && player.p_health > 0 && run==false) 
	{
		cout << enemy.e_name << endl << endl;
		if (player.p_headgear == "General [Cap]"&&player.p_bodygear == "General [Garb]")
		{
			cout << setw(46) << "<ENEMY STATS>" << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << setw(20) << "Health: " << enemy.e_health << setw(20) << "Defense: " << enemy.e_defense << setw(20) << "Offense: " << enemy.e_offense << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		loader(enemy.e_file);
		
		//Information spreader
		for (int i = 0; i < player.p_weaponry.size(); i++)
		{
			if (player.p_weaponry[i].w_type == "FW")
			{
				f_Weapon.push_back(player.p_weaponry[i]);
			}
			else if (player.p_weaponry[i].w_type == "PW")
			{
				p_Weapon.push_back(player.p_weaponry[i]);
			}
			else if (player.p_weaponry[i].w_type == "EW")
			{
				e_Weapon.push_back(player.p_weaponry[i]);
			}
			else if (player.p_weaponry[i].w_type == "MW")
			{
				m_Weapon.push_back(player.p_weaponry[i]);
			}
		}

		cout << setw(46) << "<PLAYER STATS>" << endl;
		cout << "********************************************************************************" << endl;
		cout << setw(20) << "Health: " << player.p_health << endl;
		cout << "********************************************************************************" << endl << endl;

		if (playerTurn==true)
		{
			cout << setw(46) << "<INFORMATION>" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			cout << setw(25) << "WEAPON" << setw(15) << "AMMO" << setw(15) << "SUPPLY" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;

			if (f_Weapon.size() == 0)
			{
				cout << "-No Fire Weapons-" << endl << endl;
			}
			else
			{
				cout << "(FIRE WEAPONS)" << endl;
				for (int i = 0; i < f_Weapon.size(); i++)
				{
					cout << setw(25) << f_Weapon[i].w_name << setw(15) << f_Weapon[i].w_ammo << setw(15) << f_Weapon[i].w_supply << endl;
				}
				cout << endl;
			}

			if (p_Weapon.size() == 0)
			{
				cout << "-No Projectile Weapons-" << endl << endl;
			}
			else
			{
				cout << "(PROJECTILE WEAPONS)" << endl;
				for (int i = 0; i < p_Weapon.size(); i++)
				{
					cout << setw(25) << p_Weapon[i].w_name << setw(15) << p_Weapon[i].w_ammo << setw(15) << p_Weapon[i].w_supply << endl;
				}
				cout << endl;
			}

			if (e_Weapon.size() == 0)
			{
				cout << "-No Energy Weapons-" << endl << endl;
			}
			else
			{
				cout << "(ENERGY WEAPONS)" << endl;
				for (int i = 0; i < e_Weapon.size(); i++)
				{
					cout << setw(25) << e_Weapon[i].w_name << setw(15) << e_Weapon[i].w_ammo << setw(15) << e_Weapon[i].w_supply << endl;
				}
				cout << endl;
			}

			if (m_Weapon.size() == 0)
			{
				cout << "-No Melee Weapons-" << endl << endl;
			}
			else
			{
				cout << "(MELEE WEAPONS)" << endl;
				for (int i = 0; i < m_Weapon.size(); i++)
				{
					cout << setw(25) << m_Weapon[i].w_name << setw(15) << m_Weapon[i].w_ammo << setw(15) << "-Not Used-" << endl;
				}
				cout << endl;
			}

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
				if (intcommandline[0] == "run")
				{
					cout << "You managed to escape!" << endl;
					run = true;
				}
				else if (intcommandline[0] == "help")
				{
					help("battle");
				}
				else
				{
					cout << "Invalid action. Be sure to write a valid command." << endl;
					stop();
				}
			}
			else if (intcommandline.size() == 2)
			{
				if (intcommandline[0] == "use")
				{
					for (int i = 0; i < player.p_weaponry.size(); i++)
					{
						if (intcommandline[1] == player.p_weaponry[i].w_key)
						{
							found = true;
							weaponId = player.p_weaponry[i].w_id;
						}
					}
					if (found == true && (player.p_weaponry[weaponId].w_supply - player.p_weaponry[weaponId].w_loss) >= 0)
					{
						cout << setw(46) << "---<EVENT>---" << endl;
						cout << "You used the " << player.p_weaponry[weaponId].w_name << " against the " << enemy.e_name << "!" << endl;
						player.p_offense = (rand() % player.p_weaponry[weaponId].w_maxdmg) + player.p_weaponry[weaponId].w_mindmg;
						player.p_weaponry[weaponId].w_supply -= player.p_weaponry[weaponId].w_loss;
						damage = player.p_offense - (enemy.e_defense / 10);

						if (damage>0)
						{
							if (damage == player.p_weaponry[weaponId].w_maxdmg)
							{
								cout << "CRITICAL DAMAGE!" << endl;
							}
							cout << "The " << enemy.e_name << " has lost " << damage << " health points!" << endl;
							enemy.e_health -= damage;
						}
						else
						{
							cout << "The " << enemy.e_name << " wasn't affected by your attack!" << endl;
						}
					}
					else if (found == true && (player.p_weaponry[weaponId].w_supply - player.p_weaponry[weaponId].w_loss) < 0)
					{
						cout << "You don't have enough ammo to use the " << player.p_weaponry[weaponId].w_name << "!" << endl;
					}
					else if (found == false)
					{
						cout << "<<You can't use that in battle! Beware on input your actions." << endl;
					}
					playerTurn = false;
					stop();
				}
			}
		}
		else
		{
			cout << setw(46) << "---<EVENT>---" << endl;
			cout << "The " << enemy.e_name << " is bound to attack!" << endl;
			cout << "WHAM!" << endl;
			damage = enemy.e_offense - ((player.p_defense * (rand() % player.p_defense)/10));
			if (damage>0)
			{
				cout << "You lost " << damage << " health points!" << endl;
				player.p_health -= damage;
			}
			else
			{
				cout << "You weren't affected by your attack!" << endl;
			}
			stop();
			playerTurn = true;
		}
		//Value reinitializing
		intcommandline.clear();
		f_Weapon.clear();
		e_Weapon.clear();
		m_Weapon.clear();
		p_Weapon.clear();
		found = false;
	}
	if (enemy.e_health <= 0)
	{
		cout << setw(44) << "~~~<VICTORY>~~~" << endl;
		cout << "Congratulations, you killed the " << enemy.e_name << " !" << endl << endl;
		cout << "You receive: Rb$" << enemy.e_prize << endl;
		player.p_money += enemy.e_prize;
	}
	else
	{
		cout << setw(44) << "...<DEFEAT>..." << endl;
		cout << "Damn... You were defeated by the " << enemy.e_name << "..." << endl << endl;
	}
	stop();
}

int main()
{
	//Variable declarations
	vector<string> commandline, inicommandline, saves;
	string command, inicommand, infile, outfile, retriever, savefile;
	string core[CORE_LIMIT];
	int index=0, counter=0;
	bool execute = true, comparator = false, initializer = false, computer_unlock, computer_block, door_open, door_broken;
	Player player;
	Weapon weaponData;
	Garment garmentryData;

	//Savefiles
	ifstream cmp{ "saves.gef" };
	while (getline(cmp, savefile))
	{
		saves.push_back(savefile);
	}

	//Trialout initial screen
	cout << "JOURNEY OF THE JUSTICE: Fall of the Atom (C) TCCPe 2018" << endl;
	loader("intro.gaf");
	cout << "Input 'create' to create a new game." << endl;
	cout << "Input 'load' to load a saved game." << endl;
	do
	{
		cout << "Commandline>> ";

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
				if (saves.size() == 0)
				{
					cout << "There are no savefiles. You need to create a new game" << endl << endl;
				}
				else
				{
					cout << endl << "---LOAD---" << endl;
					do
					{
						cout << "Current save files:" << endl;
						loader("saves.gef");
						cout << endl << "Input the file name>> ";
						cin >> infile;
						lower(infile);
						for (int z = 0; z < saves.size(); z++)
						{
							if (saves[z] == infile)
							{
								comparator = true;
							}
							else
							{
								counter++;
							}
						}
						if (counter == saves.size())
						{
							cout << "File not found. Please input a valid savename." << endl << endl;
						}

					} while (comparator == false);
					ifstream *ifs = new ifstream { infile };
					while (getline(*ifs, retriever))
					{
						core[index] = retriever;
						index++;
					}
					for (index = 0; index < CORE_LIMIT; index++)
					{
						switch (index)
						{
						case NAME:
							player.p_name = core[index];
							break;
						case POSITION:
							player.p_position = core[index];
							break;
						case HEALTH:
							player.p_health = stoi(core[index]);
							break;
						case DEFENSE:
							player.p_defense = stoi(core[index]);
							break;
						case OFFENSE:
							player.p_offense = stoi(core[index]);
							break;
						case MONEY:
							player.p_money = stoi(core[index]);
							break;
						case BOBBYKEY:
							player.p_bobbykey = stoi(core[index]);
							break;
						case POWDRIVE:
							player.p_powdrive = stoi(core[index]);
							break;
						case HEADGEAR:
							player.p_headgear = core[index];
							break;
						case BODYGEAR:
							player.p_bodygear = core[index];
							break;
						case COMPUTER_UNLOCK:
							computer_unlock = stob(core[index]);
							break;
						case COMPUTER_BLOCK:
							computer_block = stob(core[index]);
							break;
						case DOOR_OPEN:
							door_open = stob(core[index]);
							break;
						case DOOR_BROKEN:
							door_broken = stob(core[index]);
							break;
						default:
							break;
						}
					}
					cout << endl << "Welcome again, " << player.p_name << ". Your game has been loaded successfully!";
					initializer = true;
					stop();
				}
			}
			else if (inicommandline[0] == "create")
			{
				cout << endl << "---CREATE---" << endl;
				cout << "Please write your name>> ";
				cin >> player.p_name;
				player.p_position = "J4";
				player.p_health = 500;
				player.p_defense = 10;
				player.p_offense = 0;
				player.p_money = 100;
				player.p_bobbykey = 0;
				player.p_powdrive = 0;
				player.p_headgear = "General [Cap]";
				player.p_bodygear = "General [Garb]";
				//Logger's Axe
				weaponData.w_name = "Guardian's [Dagger]";
				weaponData.w_key = "dagger";
				weaponData.w_ammo = "-No Ammo-";
				weaponData.w_type = "MW";
				weaponData.w_supply = 0;
				weaponData.w_loss = 0;
				weaponData.w_maxdmg = 25;
				weaponData.w_mindmg = 5;
				weaponData.w_id = player.p_weaponry.size();
				player.p_weaponry.push_back(weaponData);
				computer_unlock = false;
				computer_block = false;
				door_open = false;
				door_broken = false;
				cout << "All done, "<<player.p_name<<" your game has been created successfully!" << endl;
				cout << "ADVICE: Remember to save continuosly. It is frustrating to lose all your progress." << endl;
				initializer = true;
				stop();
			}
			else
			{
				cout << "<< Incorrect command" << endl << endl;
			}
		}
		else
		{
			cout << "<< Command Overload!" << endl << endl;
		}
		inicommandline.clear();
		cin.ignore();

	} while (initializer==false);

	while (execute == true)
	{
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
		cout << "<battle>" << endl;
		cout << "(Battle system isn't intended to be choosable. Instead it will be random whilst on the map)" << endl;
		cout << endl << "---STATS---" << endl;
		cout << "Name: " << player.p_name << endl;
		cout << "Position: " << player.p_position << endl;
		cout << "Health: " << player.p_health << endl;
		cout << "Defense: " << player.p_defense << endl;
		cout << "Offense: " << player.p_offense << endl;
		cout << "Headgear: " << player.p_headgear << " equipped" << endl;
		cout << "Bodygear: " << player.p_bodygear << " equipped" << endl;
		cout << "Hjadynivite Rayubi: Rb$" << player.p_money << endl;
		cout << "Bobbykeys: " << player.p_bobbykey << endl;
		cout << "Powdrives: " << player.p_powdrive << endl;
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
				counter = 0;
				cout << endl << "---SAVE---" << endl;
				cout << "Be sure to name your savefile with a different name to those already created." << endl;
				do
				{
					cout << "Current save files:" << endl;
					if (saves.size() == 0)
					{
						cout << "None" << endl << endl;
					}
					else
					{
						loader("saves.gef");
					}
					cout << endl << "We recommend you to save your files with extension (.gsf)" << endl;
					cout << endl << "Input the file name>> ";
					cin >> outfile;
					lower(outfile);
					for (int z = 0; z < saves.size(); z++)
					{
						if (saves[z] == outfile)
						{
							comparator = true;
							cout << "Beware! There is a savefile with the same name." <<
								endl << "To avoid confusions, please input another filename." << endl << endl;
						}
						else
						{
							counter++ ;
						}
					}
					if (counter == saves.size())
					{
						comparator=false;
					}
					counter = 0;
				} while (comparator == true);
				ofstream app{ "saves.gef", std::ofstream::app };
				app << endl << outfile;
				ofstream ofs{ outfile };
				ofs << player.p_name << endl;
				ofs << player.p_position << endl;
				ofs << player.p_health << endl;
				ofs << player.p_defense << endl;
				ofs << player.p_offense << endl;
				ofs << player.p_money << endl;
				ofs << player.p_bobbykey << endl;
				ofs << player.p_powdrive << endl;
				ofs << player.p_headgear << endl;
				ofs << player.p_bodygear << endl;
				ofs << btos(computer_unlock) << endl;
				ofs << btos(computer_block) << endl;
				ofs << btos(door_open) << endl;
				ofs << btos(door_broken) << endl;
				cout << "Saved successfully as " << outfile << "!" << endl << endl;
				stop();
				comparator = true;
			}
			else if (commandline[0] == "progress")
			{
				cout << endl << "---PROGRESS---" << endl;
				cout << "Computer Unlocked: " << btos(computer_unlock) << endl;
				cout << "Computer Blocked: " << btos(computer_block) << endl;
				cout << "Door Open: " << btos(door_open) << endl;
				cout << "Door Broken: " << btos(door_broken) << endl;
				stop();
			}
			else if (commandline[0] == "battle")
			{
				battle(player);
			}
			else
			{
				cout << "You cannot do that. It is an invalid action/command..." << endl << endl;
			}
		}
		else if (commandline.size() == 2)
		{
			if (commandline[0] == "play")
			{
				if (commandline[1] == "sloty")
				{
					slots(player.p_money);
				}
				else if (commandline[1] == "biryulki")
				{
					biryulki(player.p_money);
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
					door(player.p_bobbykey, door_open, door_broken);
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
					computer(player.p_powdrive, computer_unlock, computer_block);
				}
				else
				{
					cout << "You cannot hack a " << commandline[1] << " :(" << endl;
				}
			}
			else if (commandline[0] == "exit")
			{
				if (commandline[1] == "game")
				{
					cout << "Ok. Goodbye, see you later!" << endl << endl;
					execute=false;
				}
				else
				{
					cout << "Please specify that you wanna exit the game..." << endl;
				}
			}
		}
		else
		{
			cout << ">> Command Overload!" << endl;
		}
		commandline.clear();
		stop();
	}
	return 0;
}