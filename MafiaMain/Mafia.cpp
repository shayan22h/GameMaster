
#include "mafia.h"
#include<random>



mafia::mafia(int _seed) : seed(_seed)
{

}
mafia::~mafia()
{

}

void mafia::EnterUserSeed(void)
{
	cout << " Enter a seed Value " << endl ;
	cin >> seed;
}

void mafia::ShuffleDeck(void)
{
	if (seed)
	{
		mt19937 rng(seed);

		shuffle(begin(Names), end(Names), rng);
		shuffle(begin(Roles), end(Roles), rng);
		cout << " Deck is Succesfully shuffled " << endl;
	}
	else
	{
		cout << " First Input the Seend " << endl;
	}
}

void mafia::SudoDisplay(void)
{
	for (int i = 0; i < NoOfPlayers; i++)
	{
		cout << " Name is " << Names[i] << " Role is " << Roles[i] << endl;
	}
}

void mafia::ClearConsole(void)
{
#ifdef _WIN32
	// For Windows
	system("cls");
#else
	// For Unix-based systems (Linux, macOS)
	system("clear");
#endif
}

void mafia::ShowRole(string& _refToName) const
{
	bool found = false;

	for (int i = 0; i < NoOfPlayers; i++)
	{
		if (_refToName == Names[i])
		{
			found = true;
			cout << " Name is " << Names[i] << " Role is " << Roles[i] << endl;
			break;
		}
	}

	if (!found)
	{
		cout << " Invalid Name Entered " << endl;
	}

}


