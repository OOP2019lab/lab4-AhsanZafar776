#include<iostream>
using namespace std;

class cricketteam
{

	string * membernames;
	int no_of_members;
	char *teamname;
	int scoreinlast10matches[10];
	int rank;
	string captain;
	
	public:
	cricketteam();
	cricketteam(string teamname1, int members);
	cricketteam(string filename);
    ~cricketteam();
	void setcaptain(string capname);
	string getcaptain();
	void setrank(int rank1);
	int getrank();
	void setteamname(string name);
	string getteamname();
	void setno_of_members(int noofmembers);
	int getno_of_members();
	void inputteammembers(string name);
	void inputscore(int score);
	int avglast10();
	void print();
	void printteam();
	bool compare(cricketteam otherteam);
	

};