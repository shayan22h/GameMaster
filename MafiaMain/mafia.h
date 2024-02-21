#include <iostream>
#include<random>
#include <string>

using namespace std;
class mafia {

	public:
		~mafia();
		mafia(int _seed);

		void EnterUserSeed(void);
		void ShuffleDeck(void);
		void SudoDisplay(void);
		void ClearConsole(void);
		void ShowRole(string& _refToName) const;


	private:
		int seed;
		string Names[4] = { "shayan", "naimeh", "amir", "maryam"};
		string Roles[4] = { " Mafia ", "Shahr", "Kane" , "Karagah"};
		int NoOfPlayers = 4;
};