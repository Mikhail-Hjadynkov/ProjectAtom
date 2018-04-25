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
	POSITION_X,
	POSITION_Y,
	HEALTH,
	DEFENSE,
	OFFENSE,
	MONEY,
	BOBBYKEY,
	POWDRIVE,
	HEADGEAR,
	BODYGEAR,
	ATTANKASCHAKI,
	POSHKITCHI,
	VABRIKNILKI,
	BRIHTNIM,
	KOLDONODY,
	SHCHIRAMNIY,
	DAKINETSKAYA,
	TOGPALIYEV,
	RAYKUSTAYENI,
	LIDENKNIKH,
	BRIOSHK,
	AUTOMATIC_RIFLE,
	SHOTGUN,
	SUBMACHINE_GUN,
	BERHIRIYET,
	GRENADE_LAUNCHER,
	METATELNIYA,
	SONIC_REPEATER,
	SHOCKWAVE_EMITTER,
	LASER_PISTOL,
	DAGGER,
	TABANASHYN,
	SWORD,
	STABHAMMER,
	SAWEDSICKLE,
	ROUND,
	GAUGE,
	CALIBER,
	BEHNIT,
	GRENADE,
	SVAIKA,
	ARRAY,
	CORE,
	BATTERY,
	SOLDIER_HAT,
	POWER_HELMET,
	SHOCKTROOPER_FENDER,
	STEALTH_ARMET,
	GENERAL_CAP,
	SOLDIER_SUIT,
	POWER_ARMOR,
	ELECTRIFIED_EQUIPMENT,
	STEALTH_RIG,
	GENERAL_GARB,
	COMPUTER_UNLOCK,
	COMPUTER_BLOCK,
	SERVER_UNLOCK,
	SERVER_BLOCK,
	SYSTEM_UNLOCK,
	SYSTEM_BLOCK,
	DOOR_OPEN,
	DOOR_BROKEN,
	GATE_OPEN,
	GATE_BROKEN,
	SAFE_OPEN,
	SAFE_BROKEN,
	CORE_LIMIT,
};

struct Weapon
{
	string w_name = "none", w_ammo = "none", w_type = "none", w_key = "none";
	unsigned int w_supply = 0, w_id = 0, w_loss = 0, w_maxdmg = 0, w_mindmg = 0;
	bool w_obtained;
};

struct Garment
{
	string g_name = "none", g_key = "none", g_type = "none", g_ability = "none";
	unsigned int g_defense=0, g_id=0;
	bool g_obtained;
};

struct Food
{
	string f_name = "none", f_key = "none";
	unsigned int f_nutrition = 0, f_id = 0, f_quantity = 0;
};

class Player
{
public:
	string p_name{ "none" }, p_headgear{ "none" }, p_bodygear{ "none" };
	int p_health = 0, p_defense = 0, p_offense = 0, p_money = 0, p_bobbykey = 0, p_powdrive = 0, p_positionX = 0, p_positionY = 0;
	vector<Weapon> p_weaponry;
	vector<Garment> p_garmentry;
	vector<Food> p_groceries;
};

class Quadrant
{
public:
	string q_name{ "none" }, q_file{ "none" }, q_colony{ "none" };
	bool q_visit = false;
	unsigned int q_maxseed = 0, q_minseed = 0, q_ambushness = 0;
};

class Enemy
{
public:
	string e_name{ "none" }, e_file{ "none" };
	int e_health = 0, e_defense = 0, e_offense = 0, e_prize = 0;
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
	system("cls");
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
	else if (key == "main")
	{
		cout << "HELP" << endl;
		cout << "-This game is all command based, so be sure to check your spelling here." << endl;
		cout << "[1 COMMAND ACTIONS]." << endl;
		cout << "With this actions you don't need to input another word into the commandline." << endl;
		cout << "-INVENTORY		(Shows player's objects. And it can be pretty handy to know what you own)" << endl;
		cout << "-MAP			(Displays Pribet's region map. It helps you to see where you are)" << endl;
		cout << "-SAVE			(Saves current game. Beware! Creating does not save your game, you need save it)" << endl;
		cout << "-ANALYZE		(Makes you to admire the place, so a description can be available)" << endl;
		cout << "[2 COMMAND ACTIONS]." << endl;
		cout << "This actions need to be more specific to be executed, so they need to receive a certain command." << endl;
		cout << "<Always Available>" << endl;
		cout << "-GO...			(This basic command is used to move throughout. You can go in all cardinal points.)" << endl;
		cout << "-EQUIP...		(This command allows you to use your available armor for your defense)" << endl;
		cout << "-EAT...			(This command is for eating a meal that can replenish your health)" << endl;
		cout << "-EXIT GAME		(This may seem exagerated, but this can be a safe way to exit the game.)" << endl;
		cout << "<Available by Place>" << endl;
		cout << "-HACK...		(With this command you can try to hack certain electronic devices)" << endl;
		cout << "-LOCKPICK...		(This command grants the opportunity to try to unlock some keyholes)" << endl;
		cout << "-PLAY...		(This command gives the chance for you to play games in specific places)" << endl;
		cout << "-CONFRONT...		(This command engages a battle. There may be certain persons whose ass you wanna kick.)" << endl;
	}
	else if (key == "battle")
	{
		cout << "BATTLE" << endl;
		cout << "[1 COMMAND ACTIONS]" << endl;
		cout << "With this actions you don't need to input another word into the commandline." << endl;
		cout << "-INVENTORY		(Shows player's objects. And it can be pretty handy to know what you own)" << endl;
		cout << "[2 COMMAND ACTIONS]." << endl;
		cout << ">Remember to use only the word betweeen []" << endl;
		cout << "-USE...		(Makes use of the weapon only if you have enough ammo.)" << endl;
		cout << "-EQUIP...		(Equips the player with the specified armor. Be sure to own it)" << endl;
		cout << "-EAT...		(This command is for eating a meal that can replenish your health)" << endl;
		cout << "This actions need to be more specific to be executed, so they need to receive a certain command." << endl;
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
		cin.ignore();
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
		cin.ignore();
	}
}

//Inventory function
void inventory(Player player)
{
	vector<Weapon> f_Weapon, m_Weapon, p_Weapon, e_Weapon;
	vector<Garment> h_Garment, b_Garment;
	vector<Food> a_Food;

	system("cls");
	for (int i = 0; i < player.p_weaponry.size(); i++)
	{
		if (player.p_weaponry[i].w_type == "FW"&&player.p_weaponry[i].w_obtained == true)
		{
			f_Weapon.push_back(player.p_weaponry[i]);
		}
		else if (player.p_weaponry[i].w_type == "PW"&&player.p_weaponry[i].w_obtained == true)
		{
			p_Weapon.push_back(player.p_weaponry[i]);
		}
		else if (player.p_weaponry[i].w_type == "EW"&&player.p_weaponry[i].w_obtained == true)
		{
			e_Weapon.push_back(player.p_weaponry[i]);
		}
		else if (player.p_weaponry[i].w_type == "MW"&&player.p_weaponry[i].w_obtained == true)
		{
			m_Weapon.push_back(player.p_weaponry[i]);
		}
	}

	for (int i = 0; i < player.p_garmentry.size(); i++)
	{
		if (player.p_garmentry[i].g_type == "HG"&&player.p_garmentry[i].g_obtained == true)
		{
			h_Garment.push_back(player.p_garmentry[i]);
		}
		else if (player.p_garmentry[i].g_type == "BG"&&player.p_garmentry[i].g_obtained == true)
		{
			b_Garment.push_back(player.p_garmentry[i]);
		}
	}

	for (int i = 0; i < player.p_groceries.size(); i++)
	{
		if (player.p_groceries[i].f_quantity > 0)
		{
			a_Food.push_back(player.p_groceries[i]);
		}
	}

	cout << setw(20) << "<UTILITIES>" << endl;
	cout << "-------------------------------------" << endl;
	cout << setw(15) << "OBJECT" << setw(15) << "QUANTITY" << endl;
	cout << "-------------------------------------" << endl;
	cout << setw(15) << "Bobbykey" << setw(15) << player.p_bobbykey << endl;
	cout << setw(15) << "Powdrive" << setw(15) << player.p_powdrive << endl;
	cout << "-------------------------------------" << endl << endl;

	cout << setw(40) << "<WEAPONRY>" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "WEAPON" << setw(15) << "AMMO" << setw(15) << "SUPPLY" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	if (f_Weapon.size() == 0)
	{
		cout << "-No Fire Weapons-" << endl;
	}
	else
	{
		cout << "(FIRE WEAPONS)" << endl;
		for (int i = 0; i < f_Weapon.size(); i++)
		{
			cout << setw(25) << f_Weapon[i].w_name << setw(15) << f_Weapon[i].w_ammo << setw(15) << f_Weapon[i].w_supply << endl;
		}
	}
	cout << endl;
	if (p_Weapon.size() == 0)
	{
		cout << "-No Projectile Weapons-" << endl;
	}
	else
	{
		cout << "(PROJECTILE WEAPONS)" << endl;
		for (int i = 0; i < p_Weapon.size(); i++)
		{
			cout << setw(25) << p_Weapon[i].w_name << setw(15) << p_Weapon[i].w_ammo << setw(15) << p_Weapon[i].w_supply << endl;
		}
	}
	cout << endl;
	if (e_Weapon.size() == 0)
	{
		cout << "-No Energy Weapons-" << endl;
	}
	else
	{
		cout << "(ENERGY WEAPONS)" << endl;
		for (int i = 0; i < e_Weapon.size(); i++)
		{
			cout << setw(25) << e_Weapon[i].w_name << setw(15) << e_Weapon[i].w_ammo << setw(15) << e_Weapon[i].w_supply << endl;
		}
	}
	cout << endl;
	if (m_Weapon.size() == 0)
	{
		cout << "-No Melee Weapons-" << endl;
	}
	else
	{
		cout << "(MELEE WEAPONS)" << endl;
		for (int i = 0; i < m_Weapon.size(); i++)
		{
			cout << setw(25) << m_Weapon[i].w_name << setw(15) << m_Weapon[i].w_ammo << setw(15) << "-No Supply-" << endl;
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << setw(40) << "<GARMENTRY>" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "CLOTHING" << setw(15) << "DEFENSE" << setw(25) << "ABILITY" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if (h_Garment.size() == 0)
	{
		cout << "-No Headgear-" << endl;
	}
	else
	{
		cout << "(HEADGEAR)" << endl;
		for (int i = 0; i < h_Garment.size(); i++)
		{
			cout << setw(25) << h_Garment[i].g_name << setw(15) << h_Garment[i].g_defense << setw(25) << h_Garment[i].g_ability << endl;
		}
	}
	cout << endl;
	if (b_Garment.size() == 0)
	{
		cout << "-No Bodywear-" << endl;
	}
	else
	{
		cout << "(BODYGEAR)" << endl;
		for (int i = 0; i < b_Garment.size(); i++)
		{
			cout << setw(25) << b_Garment[i].g_name << setw(15) << b_Garment[i].g_defense << setw(25) << b_Garment[i].g_ability << endl;
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	cout << setw(40) << "<FOODSTUFF>" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << setw(25) << "MEAL" << setw(15) << "NUTRITION" << setw(15) << "PROVISIONS" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if (a_Food.size() == 0)
	{
		cout << "-No Food-" << endl;
	}
	else
	{
		for (int i = 0; i < a_Food.size(); i++)
		{
			cout << setw(25) << a_Food[i].f_name << setw(15) << a_Food[i].f_nutrition << setw(15) << a_Food[i].f_quantity << endl;
		}
	}
	cout << "--------------------------------------------------------------------------------" << endl << endl;

	f_Weapon.clear();
	e_Weapon.clear();
	m_Weapon.clear();
	p_Weapon.clear();
	h_Garment.clear();
	b_Garment.clear();
}

//Lockpicking
void door(Player&player, bool & open, bool & broken)
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
		cout << "Difficulty: Easy" << endl;
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

	while (open==false&&broken==false&&player.p_bobbykey>0)
	{
		cout << "<STATS>" << endl;
		cout << "Bobbykeys: " << player.p_bobbykey << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
		for (int t = 0; t < keypin; t++)
		{
			attempt += 1;
			player.p_bobbykey -= 1;
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
			cout << "You opened the Museum of the Fallen's storage back door." << endl;
			cout << "You unwapped a package and took the " << player.p_weaponry[5].w_name << " from the box. Now you can use it in the battlefield!." << endl;
			player.p_weaponry[5].w_obtained = true;
			open = true;
			stop();
		}
		if (attempt == limit)
		{
			cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the door is locked forever." << endl << endl;
			broken = true;
			stop();
		}
		if (player.p_bobbykey == 0 && open != true)
		{
			cout << endl << "You don't have more bobbykeys. You cannot try to open the door again." << endl << endl;
			stop();
		}
		hits = 0;
	}
}

void gate(Player&player, bool & open, bool & broken)
{
	bool trying = true;
	int attempt = 0, keypin = 5, randomizer, hits = 0, limit = 10;
	vector<string> keylock, intcommandline; //"int" prefix stands for "internal"
	string intcommand;

	system("cls");
	cout << "//GATE LOCKPICKING" << endl << endl;
	if (open == false && broken == false)
	{
		loader("door_c.gaf");
		cout << "This is a pretty common gate, it can't be that easy to unlock" << endl << endl;
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
		cout << "This gate has been lockpicked successfully!" << endl;
		stop();
	}
	else if (broken == true)
	{
		loader("door_b.gaf");
		cout << "This gate's keyhole is broken. It will be impossible to try to unlock it." << endl;
		stop();
	}

	while (open == false && broken == false && player.p_bobbykey>0)
	{
		cout << "<STATS>" << endl;
		cout << "Bobbykeys: " << player.p_bobbykey << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
		for (int t = 0; t < keypin; t++)
		{
			attempt += 1;
			player.p_bobbykey -= 1;
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
			cout << endl << "You surpassed all keypins and unlocked the gate!" << endl << endl;
			cout << "You unlocked the Pribetite Treasury gate and found Khaznatanvia's national treasure!" << endl;
			cout << "You now own the " << player.p_weaponry[13].w_name << ". You can use it in the battlefield!." << endl;
			player.p_weaponry[13].w_obtained = true;
			open = true;
			stop();
		}
		if (attempt == limit)
		{
			cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the gate is locked forever." << endl << endl;
			broken = true;
			stop();
		}
		if (player.p_bobbykey == 0 && open != true)
		{
			cout << endl << "You don't have more bobbykeys. You cannot try to open the gate again." << endl << endl;
			stop();
		}
		hits = 0;
	}
}

void safe(Player&player, bool & open, bool & broken)
{
	bool trying = true;
	int attempt = 0, keypin = 6, randomizer, hits = 0, limit = 10;
	vector<string> keylock, intcommandline; //"int" prefix stands for "internal"
	string intcommand;

	system("cls");
	cout << "//SAFE LOCKPICKING" << endl << endl;
	if (open == false && broken == false)
	{
		loader("door_c.gaf");
		cout << "This is a pretty common safe, it can be a pain to open" << endl << endl;
		cout << "<DATA>" << endl;
		cout << "Difficulty: High" << endl;
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
		cout << "This safe has been lockpicked successfully!" << endl;
		stop();
	}
	else if (broken == true)
	{
		loader("door_b.gaf");
		cout << "This safe's keyhole is broken. It will be impossible to try to unlock it." << endl;
		stop();
	}

	while (open == false && broken == false && player.p_bobbykey>0)
	{
		cout << "<STATS>" << endl;
		cout << "Bobbykeys: " << player.p_bobbykey << endl;
		cout << "Attempts: " << attempt << endl << endl;

		//Command input
		for (int t = 0; t < keypin; t++)
		{
			attempt += 1;
			player.p_bobbykey -= 1;
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
			cout << endl << "You surpassed all keypins and unlocked the gate!" << endl << endl;
			cout << "You opened the Arbintskaya Federal Barracks safe." << endl;
			cout << "You unveiled and took the " << player.p_weaponry[7].w_name << ". Now you can use it in the battlefield!." << endl;
			player.p_weaponry[7].w_obtained = true;
			open = true;
			stop();
		}
		if (attempt == limit)
		{
			cout << endl << "You didn't pass all the keypins. The keyhole is broken, and the safe is locked forever." << endl << endl;
			broken = true;
			stop();
		}
		if (player.p_bobbykey == 0 && open != true)
		{
			cout << endl << "You don't have more bobbykeys. You cannot try to open the safe again." << endl << endl;
			stop();
		}
		hits = 0;
	}
}

//Hacking
void computer(Player&player, bool&unlock, bool&blocked)
{
	bool trying = true;
	int attempt = 0, randomizer, limit = 6, possibilities = 5;
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
		cout << "Difficulty: Easy" << endl;
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
		cout << "This computer has been hacked already!" << endl;
		stop();
	}
	else if (blocked == true)
	{
		loader("computer_b.gaf");
		cout << "This computer has detected an access violation. It will be impossible to hack again" << endl;
		stop();
	}

	while (unlock == false && blocked == false && player.p_powdrive>0)
	{
		cout << "<STATS>" << endl;
		cout << "Powdrive: " << player.p_powdrive << endl;
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
				player.p_powdrive -= 1;
				pseudopass = intcommandline[1];
				if (pseudopass == password)
				{
					loader("monitor_d.gaf");
					cout << "You avoided the Monument to the Heroes' secret treasure chamber!" << endl;
					cout << "You stole the " << player.p_weaponry[2].w_name << " from one exhibit. Now you can use it in the battlefield!." << endl;
					player.p_weaponry[2].w_obtained = true;
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
							cout << "Computer reports that there is a similarity at index number " << c << endl;
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
			cout << endl << "You didn't guess the password. The computer is blocked, it can't be accessed again." << endl << endl;
			blocked = true;
			stop();
		}
		if (player.p_powdrive == 0 && unlock != true)
		{
			cout << endl << "You don't have more powdrives. You cannot try to hack the computer again." << endl << endl;
			stop();
		}
	}
}

void server(Player&player, bool&unlock, bool&blocked)
{
	bool trying = true;
	int attempt = 0, randomizer, limit = 5, possibilities = 5;
	vector<string> wordset{ "dearths","hardest","hatreds","threads","trashed" }, intcommandline; //"int" prefix stands for "internal"
	vector<int> similarities;
	string intcommand, word = "aedhrst", password, pseudopass;

	system("cls");
	cout << "//SERVER HACKING" << endl;
	if (unlock == false && blocked == false)
	{
		loader("computer_l.gaf");
		cout << "This is a server. It may be somewhat complex to hack." << endl << endl;

		cout << "<DATA>" << endl;
		cout << "Difficulty: Average" << endl;
		cout << "Possibilities: " << possibilities << endl;
		cout << "Limit: " << limit << endl << endl;
		cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

		loader("monitor_a.gaf");
		cout << "     |   |(Password hint: " << word << ")            |   |" << endl;
		loader("monitor_b.gaf");

		//Logic
		randomizer = rand() % 5 + 1;
		password = wordset[randomizer];
	}
	else if (unlock == true)
	{
		loader("computer_u.gaf");
		cout << "This server's system has been hacked already!" << endl;
		stop();
	}
	else if (blocked == true)
	{
		loader("computer_b.gaf");
		cout << "This server has detected an access violation. It will be impossible to hack again" << endl;
		stop();
	}

	while (unlock == false && blocked == false && player.p_powdrive>0)
	{
		cout << "<STATS>" << endl;
		cout << "Powdrive: " << player.p_powdrive << endl;
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
				player.p_powdrive -= 1;
				pseudopass = intcommandline[1];
				if (pseudopass == password)
				{
					loader("monitor_d.gaf");
					cout << "You shut down the complex's data servers and alarm system!" << endl;
					cout << "You stole the found the Shocktrooper Set from one secret room! Now you can use it in the battlefield!" << endl;
					player.p_garmentry[2].g_obtained = true;
					player.p_garmentry[7].g_obtained = true;
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
							cout << "Server reports that there is a similarity at index number " << c << endl;
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
		if (player.p_powdrive == 0 && unlock != true)
		{
			cout << endl << "You don't have more powdrives. You cannot try to hack the server again." << endl << endl;
			stop();
		}
	}
}

void system(Player&player, bool&unlock, bool&blocked)
{
	bool trying = true;
	int attempt = 0, randomizer, limit = 4, possibilities = 5;
	vector<string> wordset{ "restrain","retrains","strainer","terrains","trainers" }, intcommandline; //"int" prefix stands for "internal"
	vector<int> similarities;
	string intcommand, word = "aeinrrst", password, pseudopass;

	system("cls");
	cout << "//SYSTEM HACKING" << endl;
	if (unlock == false && blocked == false)
	{
		loader("screen_l.gaf");
		cout << "This is the government's Churniv Power Plant System. It may be pretty difficult to surpass." << endl << endl;

		cout << "<DATA>" << endl;
		cout << "Difficulty: High" << endl;
		cout << "Possibilities: " << possibilities << endl;
		cout << "Limit: " << limit << endl << endl;
		cout << "(!) Write 'help' if you don't know how to proceed." << endl << endl;

		loader("system_a.gaf");
		cout << "  | |(Password hint: " << word << ")     | |" << endl;
		loader("system_b.gaf");

		//Logic
		randomizer = rand() % 5 + 1;
		password = wordset[randomizer];
	}
	else if (unlock == true)
	{
		loader("screen_u.gaf");
		cout << "This system has been hacked already!" << endl;
		stop();
	}
	else if (blocked == true)
	{
		loader("screen_b.gaf");
		cout << "This system has detected an access violation. It will be impossible to hack again" << endl;
		stop();
	}

	while (unlock == false && blocked == false && player.p_powdrive>0)
	{
		cout << "<STATS>" << endl;
		cout << "Powdrive: " << player.p_powdrive << endl;
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
				player.p_powdrive -= 1;
				pseudopass = intcommandline[1];
				if (pseudopass == password)
				{
					loader("system_d.gaf");
					cout << "You deactivated the Churnivniy Power Plant!" << endl;
					cout << "Hjadynivia's Power Plant will autodestruct!" << endl;
					unlock = true;
					stop();
				}
				else
				{
					loader("system_a.gaf");
					cout << "  | |(Password hint: " << word << ")     | |" << endl;
					loader("system_c.gaf");
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
		if (player.p_powdrive == 0 && unlock != true)
		{
			cout << endl << "You don't have more powdrives. You cannot try to hack the server again." << endl << endl;
			stop();
		}
	}
}

//Equipping function
void equip(Player & player, string gear)
{
	bool found = false;
	int gearId;

	for (int i = 0; i < player.p_garmentry.size(); i++)
	{
		if (gear == player.p_garmentry[i].g_key)
		{
			found = true;
			gearId = player.p_garmentry[i].g_id;
		}
	}
	if (found == false)
	{
		cout << "You can't equip the '" << gear << "'. As it does not exist on your garmentry." << endl << endl;
	}
	else if (found == true && player.p_headgear == player.p_garmentry[gearId].g_name && player.p_bodygear == player.p_garmentry[gearId].g_name)
	{
		cout << "You already are equipped with the " << player.p_garmentry[gearId].g_name << endl << endl;
	}
	else if (found == true && player.p_headgear != player.p_garmentry[gearId].g_name && player.p_bodygear != player.p_garmentry[gearId].g_name)
	{
		cout << "You are now equipped with the " << player.p_garmentry[gearId].g_name << endl << endl;

		if (player.p_garmentry[gearId].g_type == "HG")
		{
			player.p_headgear = player.p_garmentry[gearId].g_name;
		}
		else if (player.p_garmentry[gearId].g_type == "BG")
		{
			player.p_bodygear = player.p_garmentry[gearId].g_name;
		}

		player.p_defense += player.p_garmentry[gearId].g_defense;

		if (player.p_headgear == "Soldier [Hat]"&&player.p_bodygear == "Soldier [Suit]")
		{
			cout << "You received a bonus +10% defense by using Soldier Set!" << endl;
			player.p_defense += (player.p_defense*.10);
		}
		else if (player.p_headgear == "Power [Helmet]"&&player.p_bodygear == "Power [Armor]")
		{
			cout << "You received a bonus +25% defense by using Power Set!" << endl;
			player.p_defense += (player.p_defense*.25);
		}
		else if (player.p_headgear == "Shocktrooper [Fender]"&&player.p_bodygear == "Electrified [Equipment]")
		{
			cout << "Now your enemies are damaged when they attack you!" << endl;
		}
		else if (player.p_headgear == "Stealth [Armet]"&&player.p_bodygear == "Stealth [Rig]")
		{
			cout << "Now it is easier to avoid enemy's ambushes!" << endl;
		}
		else if (player.p_headgear == "General [Cap]"&&player.p_bodygear == "General [Garb]")
		{
			cout << "Your intuition has grown! You now can see enemy's stats." << endl;
		}
	}
	stop();
}

//Eating function
void eat(Player&player, string food)
{
	bool found = false;
	int foodId;

	for (int i = 0; i < player.p_groceries.size(); i++)
	{
		if (food == player.p_groceries[i].f_key)
		{
			found = true;
			foodId = player.p_groceries[i].f_id;
		}
	}
	if (found == false)
	{
		cout << "<<You can't eat '" << food << "'. Hjadynivite food has strange names, but this doesn't exist at all..." << endl << endl;
	}
	else if (found == true && player.p_groceries[foodId].f_quantity<1)
	{
		cout << "You can't eat " << player.p_groceries[foodId].f_name << ". You don't have this meal!" << endl << endl;
	}
	else if (found == true && player.p_groceries[foodId].f_quantity>0)
	{
		cout << "You ate a big plate of " << player.p_groceries[foodId].f_name << endl;
		cout << "It was so yummy that you can feel how your health replenishes!" << endl << endl;
		player.p_health += player.p_groceries[foodId].f_nutrition;
		player.p_groceries[foodId].f_quantity -= 1;
	}
	stop();
}

void go(Player&player, string direction)
{
	if (direction == "north"&&player.p_positionX > 0)
	{
		player.p_positionX -= 1;
		cout << "You are on your way to the north." << endl;
	}
	else if (direction == "south"&&player.p_positionX < 7)
	{
		player.p_positionX += 1;
		cout << "You are on your way to the south." << endl;
	}
	else if (direction == "west"&&player.p_positionY > 0)
	{
		player.p_positionY -= 1;
		cout << "You are on your way to the west." << endl;
	}
	else if (direction == "east"&&player.p_positionY < 7)
	{
		player.p_positionY += 1;
		cout << "You are on your way to the east." << endl;
	}
	else
	{
		cout << "You can't go more to the " << direction << " from here." << endl << endl;
	}
}

//Map matrix
int map[8][8]
{
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 9, 10,11,12,13,14,15,16 },
	{ 17,18,19,20,21,22,23,24 },
	{ 25,26,27,28,29,30,31,32 },
	{ 33,34,35,36,37,38,39,40 },
	{ 41,42,43,44,45,46,47,48 },
	{ 49,50,51,52,53,54,55,56 },
	{ 57,58,59,60,61,62,63,64 },
};

//Quadrant assigner
void quadrantry(Player&player, Quadrant&quadrant)
{
	int quadrantValue = map[player.p_positionX][player.p_positionY];

	//(Name, Filename, Colony, Vistitance, MaxSeed, MinSeed, Ambushness)
	switch (quadrantValue)
	{
	case 1:
		quadrant.q_name = "-ATANA METRO STATION-";
		quadrant.q_colony = "< Northwestern Garvodnosht Locality >";
		quadrant.q_file = "station.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 0;
		break;
	case 2:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northern Garvodnosht Locality >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 3:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northeastern Garvodnosht Locality >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 4:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northwestern Arbtaniya Sector >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 5:
		quadrant.q_name = "-ARBTANIYA SUPPLY SHOP-";
		quadrant.q_colony = "< Northeastern Arbtaniya Sector >";
		quadrant.q_file = "shop.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 0;
		break;
	case 6:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northwestern Churnivniyn Enclave >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 7:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northern Churnivniyn Enclave >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 8:
		quadrant.q_name = "-CHURNIVNIY ATOMIC POWER CENTRAL-";
		quadrant.q_colony = "< Northeastern Churnivniyn Enclave >";
		quadrant.q_file = "plant.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 9:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Garvodnosht Locality >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 10:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southern Garvodnosht Locality >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 11:
		quadrant.q_name = "-GARVODNOSHT ARMOR & WEAPON STORE-";
		quadrant.q_colony = "< Southeastern Garvodnosht Locality >";
		quadrant.q_file = "store.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 0;
		break;
	case 12:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Western Arbtaniya Sector >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 13:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Eastern Arbtaniya Sector >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 14:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Western Churnivniyn Enclave >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 15:
		quadrant.q_name = "-HALL OF THE ATOM-";
		quadrant.q_colony = "< Central Churnivniyn Enclave >";
		quadrant.q_file = "hall.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 0;
		break;
	case 16:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Eastern Churnivniyn Enclave >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 17:
		quadrant.q_name = "-HJADYNIVITE ENERGY DEVELOPMENT COMPLEX-";
		quadrant.q_colony = "< Northwestern Federatskaya District >";
		quadrant.q_file = "complex.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 18:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northern Federatskaya District >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 19:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northeastern Federatskaya District >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 20:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Arbtaniya Sector >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 21:
		quadrant.q_name = "-NADZHENIYE CENTRALNIY METRO STATION-";
		quadrant.q_colony = "< Southeastern Arbtaniya Sector >";
		quadrant.q_file = "station.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 0;
		break;
	case 22:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Churnivniyn Enclave >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 23:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southern Churnivniyn Enclave >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 24:
		quadrant.q_name = "-TREASURY OF PRIBET-";
		quadrant.q_colony = "< Southeastern Churnivniyn Enclave >";
		quadrant.q_file = "treasury.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 25:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Western Federatskaya District >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 26:
		quadrant.q_name = "-PRIBET PALACE OF GOVERNMENT-";
		quadrant.q_colony = "< Central Federatskaya District >";
		quadrant.q_file = "palace.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 0;
		break;
	case 27:
		quadrant.q_name = "-ARBINTSKAYA FEDERAL BARRACKS-";
		quadrant.q_colony = "< Eastern Federatskaya District >";
		quadrant.q_file = "barracks.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 28:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northwestern Centralniyn Quadrant >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 29:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northeastern Centralniyn Quadrant >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 30:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northwestern Pribet Garden Neighboorhood >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 31:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northern Pribet Garden Neighboorhood >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 32:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northeastern Pribet Garden Neighboorhood >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 33:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Federatskaya District >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 34:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southern Federatskaya District >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 35:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southeastern Federatskaya District >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 91;
		quadrant.q_ambushness = 75;
		break;
	case 36:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Centralniyn Quadrant >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 37:
		quadrant.q_name = "-MONUMENT TO THE KHAZNATANVIAN HEROES-";
		quadrant.q_colony = "< Southeastern Centralniyn Quadrant >";
		quadrant.q_file = "monument.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 38:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Pribet Garden Neighborhood >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 39:
		quadrant.q_name = "-PRIBET GARDEN RESTAURANT-";
		quadrant.q_colony = "< Southern Pribet Garden Neighborhood >";
		quadrant.q_file = "restaurant.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 0;
		break;
	case 40:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southeastern Pribet Garden Neighborhood >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 41:
		quadrant.q_name = "-DARSHNAKOV METRO STATION-";
		quadrant.q_colony = "< Northwestern Ternbeliy Region >";
		quadrant.q_file = "station.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 0;
		break;
	case 42:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northern Ternbeliy Region >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 43:
		quadrant.q_name = "-MUSEUM OF THE FALLEN-";
		quadrant.q_colony = "< Northeastern Ternbeliy Region >";
		quadrant.q_file = "museum.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 44:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northwestern Rayubinev Territory >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 45:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northeastern Rayubinev Territory >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 46:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northwestern Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 25;
		break;
	case 47:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northern Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 25;
		break;
	case 48:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Northeastern Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 25;
		break;
	case 49:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Western Ternbeliy Region >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 50:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Central Ternbeliy Region >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 140;
		quadrant.q_minseed = 51;
		quadrant.q_ambushness = 50;
		break;
	case 51:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Eastern Ternbeliy Region >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 52:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Western Rayubinev Territory >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 53:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Eastern Rayubinev Territory >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 54:
		quadrant.q_name = "-TARNIBILSK METRO STATION-";
		quadrant.q_colony = "< Western Matkrubiyn Commune >";
		quadrant.q_file = "station.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 0;
		break;
	case 55:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Central Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 56:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Eastern Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 57:
		quadrant.q_name = "-TERNBELIY SLOTY CASINO-";
		quadrant.q_colony = "< Southwestern Ternbeliy Region >";
		quadrant.q_file = "casino.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 0;
		break;
	case 58:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southern Ternbeliy Region >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 59:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southeastern Ternbeliy Region >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 60:
		quadrant.q_name = "-RAYUBINEV BIRYULKI PLAYHOUSE-";
		quadrant.q_colony = "< Southwestern Rayubinev Territory >";
		quadrant.q_file = "place.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 61:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southeastern Rayubinev Territory >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 62:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southwestern Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 63:
		quadrant.q_name = "--";
		quadrant.q_colony = "< Southern Matkrubiyn Commune >";
		quadrant.q_file = "";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 120;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	case 64:
		quadrant.q_name = "-GREAT PRIBET GATE-";
		quadrant.q_colony = "< Southeastern Matkrubiyn Commune >";
		quadrant.q_file = "entrance.gaf";
		quadrant.q_visit = true;
		quadrant.q_maxseed = 150;
		quadrant.q_minseed = 1;
		quadrant.q_ambushness = 25;
		break;
	default:
		break;
	}
}

void analyze(int quadrantValue)
{
	system("cls");
	switch (quadrantValue)
	{
	case 1:
		cout << "-ATANA STATION-" << endl;
		cout << "The farthermost station of Pribet. It was constructed to reach certain" << endl;
		cout << "government complexes, and also to get easy access to all Pribet." << endl;
		cout << "Near the station is the commercial zone. Garvodnosht and Arbtaniya" << endl;
		cout << "are part of it, and there is easy to find an extensive amount of" << endl;
		cout << "weapons, armor and supplies." << endl;
		break;
	case 5:
		cout << "-ARBTANIYA SUPPLY SHOP-" << endl;
		cout << "One of the most recognized suppliers from all Pribet, what makes it" << endl;
		cout << "unique is the fact that their suplies are government-stocked. So it" << endl;
		cout << "is sure to find top-notch supplies and even some actually used by" << endl;
		cout << "the Pribet Guard itself. Without doubt the Arbtaniya Supply Shop is" << endl;
		cout << "a must for those who want to find a trustful and qualified supplier." << endl;
		break;
	case 8:
		cout << "-CHURNIVNIY ATOMIC POWER PLANT-" << endl;
		cout << "The newly constructed Churnivniy Atomic Power Plant, as the name implies," << endl;
		cout << "is the facility that the Hjadynivite and Khaznatanvian governments" << endl;
		cout << "constructed to implement atomic fision technology to create electricity." << endl;
		cout << "It is totally prohibited for any unrecognized strange to enter the facility." << endl;
		cout << "The system that constrols the whole is there and it may be breakable. " << endl;
		break;
	case 11:
		cout << "GARVODNOSHT WEAPON & ARMOR STORE" << endl;
		cout << "This store has an assortment of lots of weapons, some of them only seen" << endl;
		cout << "in Hjadynivia. The amazing thing about this store is that it is an" << endl;
		cout << "authorized retiler of army-grade armor and weapons. If you are the one" << endl;
		cout << "that wants to have the ultimate weapons and armor, this store is a must." << endl;
		cout << "The fatal flaw with this store is that it doesn't sell ammo at all." << endl;
		break;
	case 15:
		cout << "-HALL OF THE ATOM-" << endl;
		cout << "Constructed specially to conmemorate the Atomic Sciences, it is a goverment" << endl;
		cout << "building that hosts some of the most influent scientists and chieftains" << endl;
		cout << "of the Hjadynivite Union. This place is surrounded by dangerous soldiers." << endl;
		cout << "Some say that the Leader of the Hjadynivite Union actually is living here" << endl;
		cout << "as part of the celebration of the 'Accomplishment of the Atom'." << endl;
		break;

	case 24:
		cout << "TREASURY OF PRIBET" << endl;
		cout << "Not only the treasury is the storage of gold and other valuable resources, but" << endl;
		cout << "also the home of antique relics and other invaluable treasures that are kept" << endl;
		cout << "inside. The treasury is certainly well army protected, but its flaw is that there" << endl;
		cout << "are no alarms or electronic sensors or locks to protect their goods. Maybe since" << endl;
		cout << "they love old and outdated things, their protection system consists only of a gate." << endl;
		break;

	case 17:
		cout << "-HJADYNIVITE ENERGY DEVERLOPMENT COMPLEX-" << endl;
		cout << "This building's main purpose is to enhance the atomic fision energy extraction." << endl;
		cout << "Although Hjadynivia has marked a milestone in energy production, their" << endl;
		cout << "process is very prone to a meltdown. Also, this facility finds the way to use" << endl;
		cout << "energy to make deadly weapons and armor. Some say that somewhere on the inside" << endl;
		cout << "there is an experimental armor that is protected by a government server." << endl;
		break;

	case 21:
		cout << "NADZHENIYE CENTRALNIY METRO STATION" << endl;
		cout << "Recognized as one of the most important metro stations of Pribet, it is mainly" << endl;
		cout << "used by government members. Some call this station as the 'Heart of Pribet'" << endl;
		cout << "thanks to its closeness to government buldings. That also means that it is the" << endl;
		cout << "hell for a Barithronite spy, as it is surrounded by army officials. But if" << endl;
		cout << "you are strong enough to overcome the soldiers, then no problem." << endl;
		break;
	case 26:
		cout << "PRIBET PALACE OF GOVERNMENT" << endl;
		cout << "Residence of the chieftains of Pribet, this is place is infested with government" << endl;
		cout << "people. The General, as the head of state, has reinforced the borders fearing" << endl;
		cout << "an invasion from any rebel group. Pribetite officials may seem happy and proud" << endl;
		cout << "on the outside, but in the inside they are living freightened by paranoia." << endl;
		cout << "Maybe their achievement won't save them from their wickedness." << endl;
		break;
	case 27:
		cout << "ARBINTSKAYA FEDERAL BARRACKS" << endl;
		cout << "The Leader of the Hjadynivite not only wants Pribet to be an energy powerhouse" << endl;
		cout << "but he also wants the city to be one of the most important military conentation" << endl;
		cout << "camps. The Federal Barracks is also the home of one of the most advanced" << endl;
		cout << "weapons developed in the I Intraplanetary War of 1850. It is property of one" << endl;
		cout << "of the officials, but he isn't always here. Someone may take a peek at the safa." << endl;
		break;
	case 37:
		cout << "MONUMENT TO THE HEROES" << endl;
		cout << "The Monument to the Heroes is a tall tower with an observatory at the top of it," << endl;
		cout << "where some says that there is memorabilia conmemorating the Hjadynivite soldiers" << endl;
		cout << "that died on the I Intraplanetary Battle. Supossedly there is the weapon used by" << endl;
		cout << "Captain Senasy to kill Federat Edenstern on the Battle of Lazlitniy. But even" << endl;
		cout << "the weapon is too tempting to be exhibited, and it is kept door locked." << endl;
	case 41:
		cout << "DARSHNAKOV METRO STATION" << endl;
		cout << "Darshnakov Station's importance to Pribet is humongous since it is very tied" << endl;
		cout << "with Pribetite culture. Darshnakov Station provides the main gate to Ternbeliy" << endl;
		cout << "Region, and thus, one of the most beloved administative divisions of Pribet." << endl;
		cout << "Also known as 'Happiness Station', it is used by a lot of Churnivniy Power Plant" << endl;
		cout << "worker's families on weekends. Ternbeliy is the destination of Pribetite Families." << endl;
		break;
	case 43:
		cout << "MUSEUM OF THE FALLEN" << endl;
		cout << "This museum can be seen by foreigners like an hostile way to show Hjadynivia's" << endl;
		cout << "victories throughout history, since this museum is specifically purposed to show" << endl;
		cout << "the defeat of the enemies of Hjadynivia. And as well, it can be the treasure mine" << endl;
		cout << "of a scavenger that looks for imported weapons, but robbing the weapons isn't" << endl;
		cout << "as easy as said since the exhibits are locked under computer protection." << endl;
	case 39:
		cout << "PRIBET GARDEN RESTAURANT" << endl;
		cout << "The Pribet Garden Restaurant is, without doubt, the best restaurant in Khaznatanvia." << endl;
		cout << "Famous because of its traditional Hjadynivite meals, from Attankaschaki to Brioshk," << endl;
		cout << "its menu is widely recognized Naanda-wide and the best part is that they actually" << endl;
		cout << "serve the food in Void (TM) containers that keep the food warm even if you eat" << endl;
		cout << "it months later. Although the food has strange names, the flavor is nostalgic." << endl;
		break;
	case 54:
		cout << "TARNIBILSK METRO STATION" << endl;
		cout << "Tarnibilsk Mestro Station was built to transport visitors and locals easily from" << endl;
		cout << "near the Gate of Pribet to their destinations. It is also filled with Pribet," << endl;
		cout << "Khaznatanvia and Hjadynivia cultural references to welcome visitors and to" << endl;
		cout << "make locals feel proud of their homelands. This is also a great addition to the" << endl;
		cout << "city, showing Naanda that Hjadynivites have a big warm heart." << endl;
		break;
	case 57:
		cout << "TERNBELIY SLOTY CASINO" << endl;
		cout << "The Ternbeliy Sloty casino is the main tourist attraction for those who want" << endl;
		cout << "to win big. The casino was constructed on an ancient abandoned castle, and" << endl;
		cout << "now it is a classy place to win *waste* money. One of the most remarkable" << endl;
		cout << "things is that here is the only place in all Naanda where you can play Sloty," << endl;
		cout << "the Hjadynivite version of slots, also known asn the 'All or nothing' slots." << endl;
		break;
	case 60:
		cout << "RAYUBINEV BIRYULKI PLAYHOUSE" << endl;
		cout << "The Biryulki Playhouse is the place where townfolks from all around the city" << endl;
		cout << "gather to play a nice game of Biryulki. This game is practically a millionaire" << endl;
		cout << "maker since you have a 20% opportunity to win and the longer the game, the" << endl;
		cout << "prize is juicier! This playhouse is a demonstration of Khaznatanvian culture," << endl;
		cout << "this game has been played by generation and generations." << endl;
		break;
	case 64:
		cout << "-THE GREAT PRIBET GATE-" << endl;
		cout << "The great pribet gate is the main and only entrance to the city, since all the" << endl;
		cout << "city is surrounded by Pribet River. The gate was erected not much long ago," << endl;
		cout << "the city is not even a year old. Its main purpose according to informative" << endl;
		cout << "brochures is to 'Open Hjadynivia's arms to Naanda'. Pribet is privileged thanks " << endl;
		cout << "to their templated climate. So far it looks like the city everyone wants to live in." << endl;
		break;
	default:
		break;
		cout << endl;
	}
}

//Battle System
void battle(Player & player, Quadrant & quadrant)
{
	system("cls");
	string intcommand;
	bool run=false, found=false, playerTurn=true, actionTrigger=false;
	vector<string> intcommandline;
	int randomizer, h_rand, d_rand, o_rand, p_rand, weaponId, damage, loss, quadrantValue = map[player.p_positionX][player.p_positionY];
	Enemy enemy;

	if (quadrantValue == 15)
	{
		enemy.e_name = "-CAPTAIN TALBASHYN ARMESY-";
		enemy.e_file = "captain.gaf";
		enemy.e_health = 5000;
		enemy.e_defense = 500;
		enemy.e_offense = 750;
		enemy.e_prize = 5000;
	}
	else if (quadrantValue == 26)
	{
		enemy.e_name = "-GENERAL BASHTANYM KRISHINKOV-";
		enemy.e_file = "general.gaf";
		enemy.e_health = 2500;
		enemy.e_defense = 200;
		enemy.e_offense = 350;
		enemy.e_prize = 2500;
	}
	else
	{
		srand((int)time(0));
		randomizer = (rand() % quadrant.q_maxseed) + quadrant.q_minseed;
		//Enemy seed
		if (randomizer <= 50)
		{
			h_rand = (rand() % 150) + 100;
			d_rand = (rand() % 20) + 10;
			o_rand = (rand() % 25) + 15;
			p_rand = (rand() % 50) + 25;
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
	}

	while (enemy.e_health > 0 && player.p_health > 0 && run==false) 
	{
		cout << quadrant.q_colony << endl;
		cout << enemy.e_name << endl << endl;
		if (player.p_headgear == "General [Cap]"&&player.p_bodygear == "General [Garb]")
		{
			cout << setw(46) << "<ENEMY STATS>" << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << setw(20) << "Health: " << enemy.e_health << setw(20) << "Defense: " << enemy.e_defense << setw(20) << "Offense: " << enemy.e_offense << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		loader(enemy.e_file);

		cout << setw(46) << "<PLAYER STATS>" << endl;
		cout << "********************************************************************************" << endl;
		cout << setw(20) << "Health: " << player.p_health << setw(20) << "Defense: " << player.p_defense << endl;
		cout << "********************************************************************************" << endl << endl;

		if (playerTurn==true&&actionTrigger==false)
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
				if (intcommandline[0] == "run")
				{
					cout << "You managed to escape!" << endl;
					run = true;
					stop();
				}
				else if (intcommandline[0] == "help")
				{
					help("battle");
				}
				else if (intcommandline[0] == "inventory")
				{
					inventory(player);
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
							actionTrigger = true;
							weaponId = player.p_weaponry[i].w_id;
						}
					}
					if (found == true && player.p_weaponry[weaponId].w_supply >= player.p_weaponry[weaponId].w_loss)
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
					else if (found == true && player.p_weaponry[weaponId].w_supply < player.p_weaponry[weaponId].w_loss)
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
				else if (intcommandline[0] == "equip")
				{
					equip(player, intcommandline[1]);
				}
				else if (intcommandline[0] == "eat")
				{
					eat(player, intcommandline[1]);
				}
			}
		}
		else
		{
			cout << setw(46) << "---<EVENT>---" << endl;
			cout << "The " << enemy.e_name << " is bound to attack!" << endl;
			cout << "WHAM!" << endl;
			damage = enemy.e_offense - ((player.p_defense * (rand() % player.p_defense)/20));
			if (damage>0)
			{
				cout << "You lost " << damage << " health points!" << endl;
				player.p_health -= damage;
			}
			else
			{
				cout << "You weren't affected by his attack!" << endl;
			}

			if (player.p_headgear == "Shocktrooper [Fender]"&&player.p_bodygear == "Electrified [Equipment]")
			{
				cout << endl << "The "<<enemy.e_name<<" received an electric shock when attacked you!" << endl;
				enemy.e_health -= (damage / 5);
			}
			playerTurn = true;
			actionTrigger = false;
			stop();
		}
		//Value reinitializing
		intcommandline.clear();
		
		found = false;
	}
	if (enemy.e_health <= 0)
	{
		cout << setw(44) << "~~~<VICTORY>~~~" << endl;
		cout << "Congratulations, you killed the " << enemy.e_name << " !" << endl << endl;
		cout << "You receive: Rb$" << enemy.e_prize << endl;
		player.p_money += enemy.e_prize;
		stop();
	}
	else
	{
		cout << setw(44) << "...<DEFEAT>..." << endl;
		cout << "Damn... You were defeated by the " << enemy.e_name << "..." << endl << endl;
		stop();
	}
}

//Station manager
void station(Player&player, Quadrant&quadrant)
{
	int quadrantValue = map[player.p_positionX][player.p_positionY];
	string destination;

	switch (quadrantValue)
	{
	case 1:
		cout << endl << "[ATANA STATION]" << endl << endl;
		cout << "-Destinations" << endl;
		cout << ">>Nadzheniye Station" << endl;
		cout << ">>Darshnakov Station" << endl;
		cout << ">>Tarnibilsk Station" << endl << endl;
		cout << "Destination station>> ";
		cin >> destination;
		lower(destination);
		if (destination == "nadzheniye")
		{
			cout << "You are now traveling to Nadzheniye station" << endl;
			player.p_positionX = 2;
			player.p_positionY = 4;
		}
		else if (destination == "darshnakov")
		{
			cout << "You are now traveling to Darshnakov station" << endl;
			player.p_positionX = 5;
			player.p_positionY = 0;
		}
		else if (destination == "tarnibilsk")
		{
			cout << "You are now traveling to Tarnibilsk station" << endl;
			player.p_positionX = 6;
			player.p_positionY = 5;
		}
		break;
	case 21:
		cout << endl << "[NADZHENIYE CENTRALNIY STATION]" << endl << endl;
		cout << "-Destinations" << endl;
		cout << ">>Tarnibilsk Station" << endl;
		cout << ">>Darshnakov Station" << endl;
		cout << ">>Atana Station" << endl << endl;
		cout << "Destination station>> ";
		cin >> destination;
		lower(destination);
		if (destination == "atana")
		{
			cout << "You are now traveling to Atana station" << endl;
			player.p_positionX = 0;
			player.p_positionY = 0;
		}
		else if (destination == "tarnibilsk")
		{
			cout << "You are now traveling to Tarnibilsk station" << endl;
			player.p_positionX = 6;
			player.p_positionY = 5;
		}
		else if (destination == "darshnakov")
		{
			cout << "You are now traveling to Darshnakov station" << endl;
			player.p_positionX = 5;
			player.p_positionY = 0;
		}
		break;
	case 41:
		cout << endl << "[DARSHNAKOV STATION]" << endl << endl;
		cout << "-Destinations" << endl;
		cout << ">>Tarnibilsk Station" << endl;
		cout << ">>Nadzheniye Station" << endl;
		cout << ">>Atana Station" << endl << endl;
		cout << "Destination station>> ";
		cin >> destination;
		lower(destination);
		if (destination == "atana")
		{
			cout << "You are now traveling to Atana station" << endl;
			player.p_positionX = 0;
			player.p_positionY = 0;
		}
		else if (destination == "tarnibilsk")
		{
			cout << "You are now traveling to Tarnibilsk station" << endl;
			player.p_positionX = 6;
			player.p_positionY = 5;
		}
		else if (destination == "nadzheniye")
		{
			cout << "You are now traveling to Nadzheniye station" << endl;
			player.p_positionX = 2;
			player.p_positionY = 4;
		}
		break;
	case 54:
		cout << endl << "[TARNIBILSK STATION]" << endl << endl;
		cout << "-Destinations" << endl;
		cout << ">>Nadzheniye Station" << endl;
		cout << ">>Darshnakov Station" << endl;
		cout << ">>Atana Station" << endl << endl;
		cout << "Destination station>> ";
		cin >> destination;
		lower(destination);
		if (destination == "atana")
		{
			cout << "You are now traveling to Atana station" << endl;
			player.p_positionX = 0;
			player.p_positionY = 0;
		}
		else if (destination == "nadzheniye")
		{
			cout << "You are now traveling to Nadzheniye station" << endl;
			player.p_positionX = 2;
			player.p_positionY = 4;
		}
		else if (destination == "darshnakov")
		{
			cout << "You are now traveling to Darshnakov station" << endl;
			player.p_positionX = 5;
			player.p_positionY = 0;
		}
		break;
	default:
		break;
	}
	quadrantry(player, quadrant);
	cin.ignore();
	stop();
}

void shop(Player&player)
{
	string intcommand;
	vector<string> intcommandline;
	int bobbykey = 30, powdrive = 30, round = 50, gauge = 75, caliber = 100, behnit = 35,
		grenade = 85, svaika = 115, array = 120, core = 50, battery = 150;

	cout << endl << "-ARBTANIYA SUPPLY SHOP-" << endl;
	cout << "OBJECT			PRICE		DESCRIPTION" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "(x3)Bobbykey		Rb$30		Famous between burglars, it is used to unlock keyholes." << endl;
	cout << "(x3)Powdrive		Rb$30		As the name implies, it has the power to extract password digits." << endl << endl;

	cout << "AMMO			PRICE		DESCRIPTION" << endl;	
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "(x10) 5.56 mm [round]	Rb$50		This ammo is specifically used for its reliability" << endl;
	cout << "(x15) 12 [gauge]	Rb$75		This shell contains a lot of cadmium pellets on its inside" << endl;
	cout << "(x30) 10 mm [caliber]	Rb$100		The most sold and used ammo in all Pribet!" << endl;
	cout << "(x10) [Behnit]		Rb$35		This ancient arrow is special by its accuracy" << endl;
	cout << "(x12) 1 in [Grenade]	Rb$85		This little 1 inch grenades explode when collide" << endl;
	cout << "(x5) [Svaika]		Rb$115		Svaikas do a lot of damage if reachs its victim" << endl;
	cout << "(x3) Elctmgnt.[Array]	Rb$120		This is the ammo of experimental atomic army grade weaponry" << endl;
	cout << "(x1) Uranium [Core]	Rb$50		Smuggling this ammo is a reason to be in the Gobrinski" << endl;
	cout << "(x5) Lithium [Battery]	Rb$150		Hjadynivite officials and spies use this top-notch ammo" << endl << endl;

	cout << "Input a command>> ";
	getline(cin, intcommand);
	lower(intcommand);
	stringstream ss{ intcommand };
	for (string s; ss >> s; )
	{
		intcommandline.push_back(s);
	}

	if (intcommandline.size() == 2)
	{
		if (intcommandline[0] == "buy")
		{
			if (intcommandline[1] == "bobbykey" && (player.p_money - bobbykey) >= 0)
			{
				cout << "You bought some " << intcommandline[1] << "s. They will be added to your inventory." << endl;
				player.p_bobbykey += 3;
				player.p_money -= bobbykey;
				stop();
			}
			else if (intcommandline[1] == "powdrive" && (player.p_money - powdrive) >= 0)
			{
				cout << "You bought some " << intcommandline[1] << "s. They will be added to your inventory." << endl;
				player.p_groceries[1].f_quantity += 1;
				player.p_money -= powdrive;
				stop();
			}
			else if (intcommandline[1] == "round" && (player.p_money - round) >= 0)
			{
				cout << "You bought some 5.56 mm [round]s. They will be added to your inventory." << endl;
				player.p_weaponry[0].w_supply += 10;
				player.p_money -= round;
				stop();
			}
			else if (intcommandline[1] == "gauge" && (player.p_money - gauge) >= 0)
			{
				cout << "You bought some 12 [gauge]s. They will be added to your inventory." << endl;
				player.p_weaponry[1].w_supply += 15;
				player.p_money -= gauge;
				stop();
			}
			else if (intcommandline[1] == "caliber" && (player.p_money - caliber) >= 0)
			{
				cout << "You bought some 10 mm [caliber]s. They will be added to your inventory." << endl;
				player.p_weaponry[2].w_supply += 30;
				player.p_money -= caliber;
				stop();
			}
			else if (intcommandline[1] == "behnit" && (player.p_money - behnit) >= 0)
			{
				cout << "You bought some [Behnit]s. They will be added to your inventory." << endl;
				player.p_weaponry[3].w_supply += 10;
				player.p_money -= behnit;
				stop();
			}
			else if (intcommandline[1] == "grenade" && (player.p_money - grenade) >= 0)
			{
				cout << "You bought some 1 in [Grenade]s. They will be added to your inventory." << endl;
				player.p_weaponry[4].w_supply += 12;
				player.p_money -= grenade;
				stop();
			}
			else if (intcommandline[1] == "svaika" && (player.p_money - svaika) >= 0)
			{
				cout << "You bought some [Svaika]s. They will be added to your inventory." << endl;
				player.p_weaponry[5].w_supply += 5;
				player.p_money -= svaika;
				stop();
			}
			else if (intcommandline[1] == "array" && (player.p_money - array) >= 0)
			{
				cout << "You bought some Electromagnetite [Array]s. They will be added to your inventory." << endl;
				player.p_weaponry[6].w_supply += 3;
				player.p_money -= array;
				stop();
			}
			else if (intcommandline[1] == "core" && (player.p_money - core) >= 0)
			{
				cout << "You bought some Uranium [Core]s. They will be added to your inventory." << endl;
				player.p_weaponry[7].w_supply += 1;
				player.p_money -= core;
				stop();
			}
			else if (intcommandline[1] == "battery" && (player.p_money - battery) >= 0)
			{
				cout << "You bought some Lithium [Batteries]. They will be added to your inventory." << endl;
				player.p_weaponry[8].w_supply += 5;
				player.p_money -= battery;
				stop();
			}
			else
			{
				cout << "You can't buy " << intcommandline[1] << endl;
				cout << "(!) Please be sure that you have enough money or that the supply actually exists." << endl;
				stop();
			}
		}
	}
	else
	{
		cout << "<<Invalid command arguments." << endl;
		stop();
	}
}

void store(Player&player)
{
	string intcommand;
	vector<string> intcommandline;
	int sale_a, sale_b, rifle = 65, shotgun = 80, berhiriyet = 80, launcher = 125, repeater = 165, pistol = 240, tabanasyn = 30, sword = 65, hammer = 100,
		helmet = 250, armet = 150, cap = 300, armor = 350, rig = 250, garb = 450;

	cout << "-GARVODNOSHT ARMOR & WEAPON STORE-" << endl << endl;

	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "WEAPON				PRICE		DESCRIPTION" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if (player.p_weaponry[0].w_obtained == false)
	{
		cout << "Automatic [Rifle]		Rb$65		This weapon actually was developed by a Hjadynivite " << endl;
	}
	if (player.p_weaponry[1].w_obtained == false)
	{
		cout << "[Shotgun]			Rb$80		This weapon is deadly when used near the the victim " << endl;
	}
	if (player.p_weaponry[3].w_obtained == false)
	{
		cout << "[Berhiriyet]			Rb$80		This is an ancient bow-like weapon. Very used long ago. " << endl;
	}
	if (player.p_weaponry[4].w_obtained == false)
	{
		cout << "Grenade [Launcher]		Rb$125		This machine-gun-like weapon launches mid-ranged grenades. " << endl;
	}
	if (player.p_weaponry[6].w_obtained == false)
	{
		cout << "Sonic [Repeater]		Rb$165		When the weapon is triggered, it creates a destructive sonic wave. " << endl;
	}
	if (player.p_weaponry[8].w_obtained == false)
	{
		cout << "Laser [Pistol]			Rb$240		Shoots an accurate hot laser beam. It is very piercing. " << endl;
	}
	if (player.p_weaponry[10].w_obtained == false)
	{
		cout << "[Tabanasyn]			Rb$30		Ancient sharp knife used by the Tuvaknish tribe. " << endl;
	}
	if (player.p_weaponry[11].w_obtained == false)
	{
		cout << "Trooper [Sword]			Rb$65		One-handed sword used by Hjadynivites in the I Great War. " << endl;
	}
	if (player.p_weaponry[12].w_obtained == false)
	{
		cout << "Stab[Hammer]			Rb$100		Modified Hjadynivite hammer with a spike used to stab. " << endl;
	}

	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "GEAR				PRICE		DESCRIPTION" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	if (player.p_garmentry[1].g_obtained == false)
	{
		cout << "Power [Helmet]			Rb$250		Heavy metal helmet used by Hjadynivites 30 years ago. " << endl;
	}
	if (player.p_garmentry[3].g_obtained == false)
	{
		cout << "Stealth [Armet]			Rb$150		Armet used by spies. It makes almost no sound at all." << endl;
	}
	if (player.p_garmentry[4].g_obtained == false)
	{
		cout << "General [Cap]			Rb$300		Cap used by Hjadynivite generals. Somehow enhances intuition." << endl;
	}
	if (player.p_garmentry[1].g_obtained == false)
	{
		cout << "Power [Armor]			Rb$350		Heavy metal armor used by Hjadynivites 30 years ago. " << endl;
	}
	if (player.p_garmentry[3].g_obtained == false)
	{
		cout << "Stealth [Rig]			Rb$250		Rig used by spies. It makes almost no sound at all." << endl;
	}
	if (player.p_garmentry[4].g_obtained == false)
	{
		cout << "General [Garb]			Rb$450		Garb used by Hjadynivite generals. Somehow enhances intuition." << endl;
	}

	cout << "Input a command>> ";
	getline(cin, intcommand);
	lower(intcommand);
	stringstream ss{ intcommand };
	for (string s; ss >> s; )
	{
		intcommandline.push_back(s);
	}

	if (intcommandline.size() == 2)
	{
		if (intcommandline[0] == "buy")
		{
			if (intcommandline[1] == "rifle" && (player.p_money - rifle) >= 0 && player.p_weaponry[0].w_obtained == false)
			{
				cout << "You bought the " << player.p_weaponry[0].w_name << ". Now you can use it in the battlefield!." << endl;
				player.p_weaponry[0].w_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "shotgun" && (player.p_money - shotgun) >= 0 && player.p_weaponry[1].w_obtained == false)
			{
				cout << "You bought the " << player.p_weaponry[1].w_name << ". Now you can use it in the battlefield!." << endl;
				player.p_weaponry[1].w_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "berhiriyet" && (player.p_money - berhiriyet) >= 0 && player.p_weaponry[3].w_obtained == false)
			{
				cout << "You bought the " << player.p_weaponry[3].w_name << ". Now you can use it in the battlefield!." << endl;
				player.p_weaponry[3].w_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "launcher" && (player.p_money - launcher) >= 0 && player.p_weaponry[4].w_obtained == false)
			{
				cout << "You bought the " << player.p_weaponry[4].w_name << ". Now you can use it in the battlefield!." << endl;
				player.p_weaponry[4].w_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "repeater" && (player.p_money - repeater) >= 0 && player.p_weaponry[6].w_obtained == false)
			{
				cout << "You bought the " << player.p_weaponry[6].w_name << ". Now you can use it in the battlefield!." << endl;
				player.p_weaponry[6].w_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "pistol" && (player.p_money - pistol) >= 0 && player.p_weaponry[8].w_obtained == false)
			{
				cout << "You bought the " << player.p_weaponry[8].w_name << ". Now you can use it in the battlefield!." << endl;
				player.p_weaponry[8].w_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "helmet" && (player.p_money - helmet) >= 0 && player.p_garmentry[1].g_obtained == false)
			{
				cout << "You bought the " << player.p_garmentry[1].g_name << ". Now you can use it in the battlefield!." << endl;
				player.p_garmentry[1].g_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "armet" && (player.p_money - armet) >= 0 && player.p_garmentry[3].g_obtained == false)
			{
				cout << "You bought the " << player.p_garmentry[3].g_name << ". Now you can use it in the battlefield!." << endl;
				player.p_garmentry[3].g_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "cap" && (player.p_money - cap) >= 0 && player.p_garmentry[4].g_obtained == false)
			{
				cout << "You bought the " << player.p_garmentry[4].g_name << ". Now you can use it in the battlefield!." << endl;
				player.p_garmentry[4].g_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "armor" && (player.p_money - armor) >= 0 && player.p_garmentry[6].g_obtained == false)
			{
				cout << "You bought the " << player.p_garmentry[6].g_name << ". Now you can use it in the battlefield!." << endl;
				player.p_garmentry[6].g_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "rig" && (player.p_money - rig) >= 0 && player.p_garmentry[8].g_obtained == false)
			{
				cout << "You bought the " << player.p_garmentry[8].g_name << ". Now you can use it in the battlefield!." << endl;
				player.p_garmentry[8].g_obtained = true;
				stop();
			}
			else if (intcommandline[1] == "garb" && (player.p_money - garb) >= 0 && player.p_garmentry[9].g_obtained == false)
			{
				cout << "You bought the " << player.p_garmentry[9].g_name << ". Now you can use it in the battlefield!." << endl;
				player.p_garmentry[9].g_obtained = true;
				stop();
			}
			else
			{
				cout << "You can't buy " << intcommandline[1] << endl;
				cout << "(!) Please be sure that you have enough money or you may even own what you asked for." << endl;
				stop();
			}
		}
	}
	else
	{
		cout << "<<Invalid command arguments." << endl;
		stop();
	}
}

void restaurant(Player&player)
{
	string intcommand;
	vector<string> intcommandline;
	int attankaschaki = 10, poshkitchi = 15, vabriknilki = 25, brihtnim = 40, koldonody = 60, shchiramniy = 85,
		dakinetskaya = 115, togpaliyev = 150, raykustayeni = 190, lidenknikh = 235, brioshk = 285;

	cout << endl << "-PRIBET GARDEN RESTAURANT-" << endl;
	cout << "MEAL			PRICE		DESCRIPTION" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "Attankaschaki		Rb$10		Tuna & mayo with rice" << endl;
	cout << "Poshkitchi		Rb$15		Boiled wheat with minced meat and rice" << endl;
	cout << "Vabriknilki		Rb$25		Potato balls filled with chicken, herbs and cheese" << endl;
	cout << "Brihtnim		Rb$40		Meat dumplings with mushroom cream sauce" << endl;
	cout << "Koldonody		Rb$60		Egg noodle soup with cheese and bacon" << endl;
	cout << "Shchiramniy		Rb$85		Bean stew with tomato sauce and pork cutlets" << endl;
	cout << "Dakinetskaya		Rb$115		Fish sticks with cheese garlic bread and tartar sauce" << endl;
	cout << "Togpaliyev		Rb$150		Chicken, cheese, bacon, and dressing pastry pies" << endl;
	cout << "Raykustayeni		Rb$190		Cream with minced meat bits & herbs with fluff biscuits" << endl;
	cout << "Lidenknikh		Rb$235		Bacon-wrapped prawns with cheese and roasted veggies" << endl;
	//		Brioshk				Rb$285

	cout << "Input a command>> ";
	getline(cin, intcommand);
	lower(intcommand);
	stringstream ss{ intcommand };
	for (string s; ss >> s; )
	{
		intcommandline.push_back(s);
	}

	if (intcommandline.size() == 2) 
	{
		if (intcommandline[0] == "buy")
		{
			if (intcommandline[1] == "attankaschaki" && (player.p_money - attankaschaki) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[0].f_quantity += 1;
				player.p_money -= attankaschaki;
				stop();
			}
			else if (intcommandline[1] == "poshkitchi" && (player.p_money - poshkitchi) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[1].f_quantity += 1;
				player.p_money -= poshkitchi;
				stop();
			}
			else if (intcommandline[1] == "vabriknilki" && (player.p_money - vabriknilki) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[2].f_quantity += 1;
				player.p_money -= vabriknilki;
				stop();
			}
			else if (intcommandline[1] == "brihtnim" && (player.p_money - brihtnim) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[3].f_quantity += 1;
				player.p_money -= brihtnim;
				stop();
			}
			else if (intcommandline[1] == "koldonody" && (player.p_money - koldonody) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[4].f_quantity += 1;
				player.p_money -= koldonody;
				stop();
			}
			else if (intcommandline[1] == "shchiramniy" && (player.p_money - shchiramniy) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[5].f_quantity += 1;
				player.p_money -= shchiramniy;
				stop();
			}
			else if (intcommandline[1] == "dakinetskaya" && (player.p_money - dakinetskaya) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[6].f_quantity += 1;
				player.p_money -= dakinetskaya;
				stop();
			}
			else if (intcommandline[1] == "togpaliyev" && (player.p_money - togpaliyev) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[7].f_quantity += 1;
				player.p_money -= togpaliyev;
				stop();
			}
			else if (intcommandline[1] == "raykustayeni" && (player.p_money - raykustayeni) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[8].f_quantity += 1;
				player.p_money -= raykustayeni;
				stop();
			}
			else if (intcommandline[1] == "lidenknikh" && (player.p_money - lidenknikh) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[9].f_quantity += 1;
				player.p_money -= lidenknikh;
				stop();
			}
			else if (intcommandline[1] == "brioshk" && (player.p_money - brioshk) >= 0)
			{
				cout << "You bought a plate of " << intcommandline[1] << " . It will be added to your inventory." << endl;
				player.p_groceries[10].f_quantity += 1;
				player.p_money -= brioshk;
				stop();
			}
			else 
			{
				cout << "You can't buy " << intcommandline[1] << endl;
				cout << "(!) Please be sure that you have enough money or that the meal actually exists." << endl;
				stop();
			}
		}
	}
	else
	{
		cout << "<<Invalid command arguments." << endl;
		stop();
	}
}

int main()
{
	//Variable declarations
	vector<string> commandline, inicommandline, saves;
	string command, inicommand, infile, outfile, retriever, savefile;
	string core[CORE_LIMIT];
	int index=0, counter=0, randomizer, quadrantValue, intindex = 0;
	bool execute = true, comparator = false, initializer = false, win = false, computer_unlock, computer_block, server_unlock, server_block, system_unlock, system_block,
		door_open, door_broken, gate_open, gate_broken, safe_open, safe_broken;
	Player player;
	Quadrant quadrant;
	Weapon weaponData;
	Garment garmentryData;
	Food foodData;

	//Savefiles
	ifstream cmp{ "saves.gef" };
	while (getline(cmp, savefile))
	{
		saves.push_back(savefile);
	}


	//Trialout initial screen
	do
	{
		cout << "JOURNEY OF THE JUSTICE: Fall of the Atom (C) TCCPe 2018" << endl;
		loader("intro.gaf");
		cout << "Input 'create' to create a new game." << endl;
		cout << "Input 'load' to load a saved game." << endl;
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
			//Food Input (Name, Key, Nutrition, Id, Quantity)
			foodData = { "Attankaschaki","attankaschaki",50,player.p_groceries.size(),3 };
			player.p_groceries.push_back(foodData);

			foodData = { "Poshkitchi","poshkitchi",65,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Vabiknilki","vabriknilki",95,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Brihtnim","brihtnim",140,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Koldonody","koldonody",200,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Shchiramniy","shchiramniy",275,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Dakinetskaya","dakinetskaya",365,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Togpaliyev","togpaliyev",470,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Raykustayeni","raykustayeni",590,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Lidenknikh","lidenknikh",725,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			foodData = { "Brioshk","brioshk",875,player.p_groceries.size(),0 };
			player.p_groceries.push_back(foodData);

			//Weapon Input (Name, Ammo, Type, Key, Supply, Id, Loss, MaxDamage, MinDamage, Obtained)
			weaponData = { "Automatic [Rifle]", "5.56 mm round", "FW", "rifle", 0, player.p_weaponry.size(), 1, 40, 25, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "[Shotgun]", "12 gauge", "FW", "shotgun", 0, player.p_weaponry.size(), 3, 50, 30, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "[Submachine] Gun", "10 mm caliber", "FW", "submachine", 0, player.p_weaponry.size(), 5, 80, 15, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "[Berhiriyet]", "Behnit", "PW", "berhiriyet", 0, player.p_weaponry.size(), 2, 45, 35, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Grenade [Launcher]", "1 in Grenade", "PW", "launcher", 0, player.p_weaponry.size(), 3, 100, 25, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "[Metatelniya]", "Svaika", "PW", "metatelniya", 0, player.p_weaponry.size(), 1, 75, 70, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Sonic [Repeater]", "Elctmgnt. Array", "EW", "repeater", 0, player.p_weaponry.size(), 1, 130, 90, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Shockwave [Emitter]", "Uranium Core", "EW", "emitter", 0, player.p_weaponry.size(), 1, 200, 100, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Laser [Pistol]", "Lithium Battery", "EW", "pistol", 0, player.p_weaponry.size(), 1, 110, 75, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Guardian's [Dagger]", "-No Ammo-", "MW", "dagger", 1, player.p_weaponry.size(), 0, 10, 5, true };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "[Tabanashyn]", "-No Ammo-", "MW", "tabanashyn", 1, player.p_weaponry.size(), 0, 25, 5, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Troop [Sword]", "-No Ammo-", "MW", "sword", 1, player.p_weaponry.size(), 0, 45, 20, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Stab[Hammer]", "-No Ammo-", "MW", "hammer", 1, player.p_weaponry.size(), 0, 50, 15, false };
			player.p_weaponry.push_back(weaponData);

			weaponData = { "Sawed[Sickle]", "-No Ammo-", "MW", "sickle", 1, player.p_weaponry.size(), 0, 75, 5, false };
			player.p_weaponry.push_back(weaponData);

			//Garment Input (Name, Key, Type, Ability, Defense, Id, Obtained)
			garmentryData = { "Soldier [Hat]", "hat", "HG", "+10% Defense Points", 10, player.p_garmentry.size(), true };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Power [Helmet]", "helmet", "HG", "+25% Defense Points", 25, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Shocktrooper [Fender]", "helmet", "HG", "Damages when attacked", 20, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Stealth [Armet]", "armet", "HG", "Lowers being ambushed", 15, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "General [Cap]", "cap", "HG", "Reveals enemy's stats", 30, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Soldier [Suit]", "suit", "BG", "+10% Defense Points", 15, player.p_garmentry.size(), true };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Power [Armor]", "armor", "BG", "+25% Defense Points", 35, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Electrified [Equipment]", "equipment", "BG", "Damages when attacked", 30, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "Stealth [Rig]", "rig", "BG", "Lowers being ambushed", 25, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

			garmentryData = { "General [Garb]", "garb", "BG", "Reveals enemy's stats", 45, player.p_garmentry.size(), false };
			player.p_garmentry.push_back(garmentryData);

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
					for (int index = 0; index < CORE_LIMIT; index ++)
					{
						switch (index)
						{
						case NAME:
							player.p_name = core[index];
							break;
						case POSITION_X:
							player.p_positionX = stoi(core[index]);
							break;
						case POSITION_Y:
							player.p_positionY = stoi(core[index]);
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
						case ATTANKASCHAKI:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case POSHKITCHI:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case VABRIKNILKI:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case BRIHTNIM:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case KOLDONODY:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case SHCHIRAMNIY:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case DAKINETSKAYA:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case TOGPALIYEV:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case RAYKUSTAYENI:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case LIDENKNIKH:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex++;
							break;
						case BRIOSHK:
							player.p_groceries[intindex].f_quantity = stoi(core[index]);
							intindex=0;
							break;
						case AUTOMATIC_RIFLE:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case SHOTGUN:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case SUBMACHINE_GUN:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case BERHIRIYET:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case GRENADE_LAUNCHER:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case METATELNIYA:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case SONIC_REPEATER:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case SHOCKWAVE_EMITTER:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case LASER_PISTOL:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case DAGGER:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case TABANASHYN:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case SWORD:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case STABHAMMER:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex++;
							break;
						case SAWEDSICKLE:
							player.p_weaponry[intindex].w_obtained = stob(core[index]);
							intindex=0;
							break;
						case ROUND:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case GAUGE:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case CALIBER:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case BEHNIT:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case GRENADE:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case SVAIKA:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case ARRAY:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case CORE:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex++;
							break;
						case BATTERY:
							player.p_weaponry[intindex].w_supply = stoi(core[index]);
							intindex=0;
							break;
						case SOLDIER_HAT:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case POWER_HELMET:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case SHOCKTROOPER_FENDER:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case STEALTH_ARMET:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case GENERAL_CAP:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case SOLDIER_SUIT:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case POWER_ARMOR:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case ELECTRIFIED_EQUIPMENT:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case STEALTH_RIG:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case GENERAL_GARB:
							player.p_garmentry[intindex].g_obtained = stob(core[index]);
							intindex++;
							break;
						case COMPUTER_UNLOCK:
							computer_unlock = stob(core[index]);
							break;
						case COMPUTER_BLOCK:
							computer_block = stob(core[index]);
							break;
						case SERVER_UNLOCK:
							server_unlock = stob(core[index]);
							break;
						case SERVER_BLOCK:
							server_block = stob(core[index]);
							break;
						case SYSTEM_UNLOCK:
							system_unlock = stob(core[index]);
							break;
						case SYSTEM_BLOCK:
							system_block = stob(core[index]);
							break;
						case DOOR_OPEN:
							door_open = stob(core[index]);
							break;
						case DOOR_BROKEN:
							door_broken = stob(core[index]);
							break;
						case GATE_OPEN:
							gate_open = stob(core[index]);
							break;
						case GATE_BROKEN:
							gate_broken = stob(core[index]);
							break;
						case SAFE_OPEN:
							safe_open = stob(core[index]);
							break;
						case SAFE_BROKEN:
							safe_broken = stob(core[index]);
							break;
						default:
							break;
						}
					}
					cout << endl << "Welcome again, " << player.p_name << ". Your game has been loaded successfully!";
					quadrantry(player, quadrant);
					initializer = true;
					delete (ifs);
					stop();
				}
			}
			else if (inicommandline[0] == "create")
			{
				cout << endl << "---CREATE---" << endl;
				cout << "Please write your name>> ";
				cin >> player.p_name;
				player.p_positionX = 7;
				player.p_positionY = 7;
				player.p_health = 500;
				player.p_defense = 10;
				player.p_offense = 0;
				player.p_money = 250;
				player.p_bobbykey = 3;
				player.p_powdrive = 3;
				player.p_headgear = "Nothing";
				player.p_bodygear = "Nothing";

				computer_unlock = false;
				computer_block = false;
				server_unlock = false;
				server_block = false;
				system_unlock = false;
				system_block = false;
				door_open = false;
				door_broken = false;
				gate_open = false;
				gate_broken = false;
				safe_open = false;
				safe_broken = false;
				cout << "All done, "<<player.p_name<<". Your game has been created successfully!" << endl;
				cout << "ADVICE: Remember to save continuosly. It is frustrating to lose all your progress." << endl << endl;
				stop();
				cout << "Hello, " << player.p_name << "." << endl;
				loader("story.gef");
				cout << endl << "Farewell and good luck, " << player.p_name << "." << endl;
				quadrantry(player, quadrant);
				initializer = true;
				stop();
			}
			else
			{
				cout << "<< Incorrect command" << endl << endl;
				stop();
				inicommandline.clear();
			}
		}
		else
		{
			cout << "<< Command Overload!" << endl << endl;
			stop();
			inicommandline.clear();
		}

	} while (initializer==false);

	cin.ignore();

	while (execute == true && player.p_health>0 && win != true)
	{
		//Trialout menu
		quadrantValue = map[player.p_positionX][player.p_positionY];
		cout << quadrant.q_colony << endl;
		cout << quadrant.q_name << endl;
		loader(quadrant.q_file);
		cout << endl;

		cout << endl << "---STATS---" << endl;
		cout << "Name: " << player.p_name << endl;
		cout << "Health: " << player.p_health << endl;
		cout << "Headgear: " << player.p_headgear << " equipped" << endl;
		cout << "Bodygear: " << player.p_bodygear << " equipped" << endl;
		cout << "Hjadynivite Rayubi: Rb$" << player.p_money << endl;

		cout << endl << "Input 'help' if you don't know what to do now." << endl;

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
				ofs << player.p_positionX << endl;
				ofs << player.p_positionY << endl;
				ofs << player.p_health << endl;
				ofs << player.p_defense << endl;
				ofs << player.p_offense << endl;
				ofs << player.p_money << endl;
				ofs << player.p_bobbykey << endl;
				ofs << player.p_powdrive << endl;
				ofs << player.p_headgear << endl;
				ofs << player.p_bodygear << endl;
				for (int o = 0; o < player.p_groceries.size(); o++)
				{
					ofs << player.p_groceries[o].f_quantity << endl;
				}
				for (int o = 0; o < player.p_weaponry.size(); o++)
				{
					ofs << btos(player.p_weaponry[o].w_obtained) << endl;
				}
				for (int o = 0; o < player.p_weaponry.size() - 5; o++)
				{
					ofs << player.p_weaponry[o].w_supply << endl;
				}
				for (int o = 0; o < player.p_garmentry.size(); o++)
				{
					ofs << btos(player.p_garmentry[o].g_obtained) << endl;
				}
				ofs << btos(computer_unlock) << endl;
				ofs << btos(computer_block) << endl;
				ofs << btos(server_unlock) << endl;
				ofs << btos(server_block) << endl;
				ofs << btos(system_unlock) << endl;
				ofs << btos(system_block) << endl;
				ofs << btos(door_open) << endl;
				ofs << btos(door_broken) << endl;
				ofs << btos(gate_open) << endl;
				ofs << btos(gate_broken) << endl;
				ofs << btos(safe_open) << endl;
				ofs << btos(safe_broken) << endl;
				
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
			else if (commandline[0] == "inventory")
			{
				inventory(player);
			}
			else if (commandline[0] == "help")
			{
				help("main");
			}
			else if (commandline[0] == "map")
			{
				system("cls");
				cout << "-<MAP OF PRIBET>-" << endl << endl;
				loader("map.gaf");
				cout << endl;
			}
			else if (commandline[0] == "analyze")
			{
				analyze(quadrantValue);
			}
			else
			{
				cout << "<<You cannot do that. It is an invalid action/command." << endl << endl;
				stop();
			}
		}
		else if (commandline.size() == 2)
		{
			if (commandline[0] == "play")
			{
				if (commandline[1] == "sloty"&& quadrantValue == 57)
				{
					slots(player.p_money);
				}
				else if (commandline[1] == "biryulki"&& quadrantValue == 60)
				{
					biryulki(player.p_money);
				}
				else
				{
					cout << "<<You cannot play " << commandline[1] << " here." << endl;
					stop();
				}
			}
			else if (commandline[0] == "lockpick")
			{
				if (commandline[1] == "door" && quadrantValue==37)
				{
					door(player, door_open, door_broken);
				}
				else if (commandline[1] == "gate"&& quadrantValue == 24)
				{
					gate(player, gate_open, gate_broken);
				}
				else if (commandline[1] == "safe"&& quadrantValue == 27)
				{
					safe(player, safe_open, safe_broken);
				}
				else
				{
					cout << "<<You cannot lockpick a " << commandline[1] << " here." << endl;
					stop();
				}
			}
			else if (commandline[0] == "hack")
			{
				if (commandline[1] == "computer"&& quadrantValue == 8)
				{
					computer(player, computer_unlock, computer_block);
				}
				else if (commandline[1] == "server"&& quadrantValue == 17)
				{
					server(player, server_unlock, server_block);
				}
				else if (commandline[1] == "system"&& quadrantValue == 43)
				{
					system(player, system_unlock, system_block);
				}
				else
				{
					cout << "<<You cannot hack a " << commandline[1] << " here." << endl;
					stop();
				}
			}
			else if (commandline[0] == "confront")
			{
				if (commandline[1] == "captain"&& quadrantValue == 15)
				{
					cout << "You confronted Captain Talbashyn!" << endl << endl;
					battle(player, quadrant);
					stop();
				}
				if (commandline[1] == "general"&& quadrantValue == 26)
				{
					cout << "You confronted General Hjadynkov!" << endl << endl;
					battle(player, quadrant);
					stop();
				}
				else
				{
					cout << "You can't confront "<< commandline[1] <<" here." << endl;
					stop();
				}
			}
			else if (commandline[0] == "exit")
			{
				if (commandline[1] == "game")
				{
					cout << "Ok. Goodbye, see you later!" << endl << endl;
					execute=false;
					stop();
				}
				else
				{
					cout << "Please specify that you wanna exit the game..." << endl;
					stop();
				}
			}
			else if (commandline[0] == "equip")
			{
				equip(player, commandline[1]);
			}
			else if (commandline[0] == "eat")
			{
				eat(player, commandline[1]);
			}
			else if (commandline[0] == "go")
			{
				go(player, commandline[1]);
				quadrantry(player, quadrant);

				srand((int)time(0));
				randomizer = (rand() % 100) + 1;
				if (player.p_headgear == "Stealth [Armet]"&&player.p_bodygear == "Stealth [Rig]" && randomizer <= (quadrant.q_ambushness-10))
				{
					cout << "-<EVENT>-" << endl;
					cout << "You have been ambushed by an enemy!" << endl << endl;
					stop();
					battle(player, quadrant);
				}
				else if (randomizer <= quadrant.q_ambushness)
				{
					cout << "-<EVENT>-" << endl;
					cout << "You have been ambushed by an enemy!" << endl << endl;
					stop();
					battle(player, quadrant);
				}
				else
				{
					stop();
				}
			}
			else if (commandline[0] == "enter")
			{
				if (commandline[1] == "shop"&&quadrantValue==5)
				{
					shop(player);
				}
				else if (commandline[1] == "store"&&quadrantValue == 11)
				{
					store(player);
				}
				else if (commandline[1] == "restaurant"&&quadrantValue == 39)
				{
					restaurant(player);
				}
				else if (commandline[1] == "station"&&quadrantValue == 1 || quadrantValue == 21 || quadrantValue == 41 || quadrantValue == 54)
				{
					station(player, quadrant);
				}
			}
			else
			{
				cout << "<<Please input an invalid command. Surely you did input a mess." << endl << endl;
				stop();
			}
		}
		else
		{
			cout << "<<Invalid arguments!" << endl;
			stop();
		}

		if (system_unlock == true)
		{
			win = true;
		}
		if (system_block == true)
		{
			player.p_health = 0;
		}

		commandline.clear();
	}
	if (player.p_health <= 0)
	{
		cout << "GAME OVER" << endl;
		stop();
	}
	if (win==true)
	{
		cout << "<CONGRATULATIONS>" << endl;
		cout << "You destroyed the Churnivniy Power Plant!" << endl << endl;
		loader("end.gef");
		stop();
	}
	return 0;
}