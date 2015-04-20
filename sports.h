Enter file contents here#ifndef SPORTS_H
#define SPORTS_H
#include <vector>
#include <iostream>
using namespace std;

struct playerstat {
	string label;
	int stat;
	bool isRed;
	player *leftplayer;
	player *rightplayer;
	player * parent;
};

struct player {
	string name;
	std::vector <playerstat*> playerstats;


	//for team
	player *hashTableNextPlayer;
	player *hashTablePerviousePlayer;
};

struct team {
	string name;
	string teamName;
	vector <game> gamesPlayed;

};


struct game {
	team * playedAgisnt;
	int score;
	string winningteam;
	string hometeam;
};

class sport
{
	sport();
	void treesipalyrangeofstats(int, int, int);
	vector <player*> root;
	void createPlayer(string, int);
	void addfixup(player *,int);
	void leftrotate(player *,int);
	void addStattoPlayer(player *, string, int);
	void rightrotate(player*,int);
	void addStatToTree(player *, int);
	player * findPlayer(string);
	void printPlayers();
	void findandaddstat(string,string,int);
public:

protected:
private:
	void insertPlayer(string);
	int indexat(string);
	player * tnil;
	vector <player *> root;
	int numberOfStats;
	playerstat * statnill;
	player *hashTable[10];
};

#endif // GRAPH_H

