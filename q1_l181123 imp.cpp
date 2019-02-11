#include<iostream>
#include"cricketteam.h"
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

cricketteam::cricketteam()
{

	membernames=nullptr;
	no_of_members=-1;
	teamname=nullptr;
	for(int i=0;i<10;i++)
	{
		scoreinlast10matches[i]=-1;
	}
	rank=-1;
	captain="noname";

}
cricketteam::cricketteam(string teamname1, int members)
{
	membernames=nullptr;
	no_of_members=members;
	teamname=teamname;
	for(int i=0;i<10;i++)
	{
		scoreinlast10matches[i]=-1;
	}
	rank=-1;
	captain="noname";

}
cricketteam::cricketteam(string filename)
{
	char check,arr[1000];
	string temp;
	int tempi=0;
	ifstream fin(filename);
	getline(fin,temp,':');
	getline(fin,temp);
	cout<<temp;
	tempi=strlen(temp.c_str());
	teamname= new char[tempi];//i tried strlen but that was  not working
	strcpy(teamname,temp.c_str());

	getline(fin,temp,':');
	getline(fin,temp);
	no_of_members= stoi(temp);
	membernames=new string[no_of_members];
	for(int i=0; i<11;i++){
		getline(fin,membernames[i]);
	}
	getline(fin,temp,':');
	rank=stoi(temp);
	getline(fin,temp,':');
	captain=temp;
	getline(fin,temp,':');
	for(int i=0;i<10;i++)
	{
		getline(fin,temp,',');
		scoreinlast10matches[i]=stoi(temp);
	}

}



string cricketteam::getteamname()
{
	string team;
	if(teamname!=nullptr)
		team = *teamname;
	return team;

}

void cricketteam::setteamname(string name)
{
	if(teamname!=nullptr){

		strcpy(teamname,name.c_str());
	}
	else {
		teamname=new char(strlen(name.c_str()));

		strcpy(teamname,name.c_str());
	}
}
void cricketteam::setcaptain(string name)
{
	captain=name;

}
string cricketteam::getcaptain()
{
	if(captain!="\0")
		return captain;
}
void cricketteam::setrank(int rank1)
{
	if(rank1>-1)
		rank =rank1;
}
int cricketteam::getrank()
{
	if(rank>-1)
		return rank;
}
void cricketteam::setno_of_members(int no)
{
	if(no_of_members>11)
		no_of_members=no;
}
int cricketteam::getno_of_members()
{
	if(no_of_members>-1)
		return no_of_members;
}
void cricketteam::inputteammembers(string name)
{
	if(no_of_members<11)
	{
		membernames[no_of_members+1]=name;
	}
	else
		cout<<"no space in team";
}
void cricketteam::inputscore(int score)
{

	for(int i =9;i>=0;i--)
		scoreinlast10matches[i-1]=scoreinlast10matches[i];
	scoreinlast10matches[9]=score;
}
int cricketteam::avglast10()
{
	int total=scoreinlast10matches[0],avg;
	for(int i=1;i<10;i++)
	{
		total=total+scoreinlast10matches[i];
	}
	avg=total/10;
	return avg;
}
void cricketteam::print()
{
	cout<<"latest score"<<scoreinlast10matches[9]<<endl;
	cout<<"captain:"<<captain<<endl;
	
	cout<<"teamname:"<<*teamname<<endl;
}
void cricketteam::printteam()
{
	cout<<"teamname:"<<*teamname<<endl;
	cout<<"captain:"<<captain<<endl;
	cout<<"latest score"<<scoreinlast10matches[9]<<endl;
	cout<<"members of the team are";
	for(int i =0;i<no_of_members;i++)
		cout<<membernames[i]<<endl;


}
bool cricketteam::compare(cricketteam otherteam)
{
	if(avglast10()>otherteam.avglast10())
		return false;
	return true;
}
cricketteam::~cricketteam()
{
	delete[] teamname;
	delete[] membernames;
}