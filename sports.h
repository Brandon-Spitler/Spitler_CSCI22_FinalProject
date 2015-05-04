#ifndef SPORTS_H
#define SPORTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
struct playerstat;
struct player;
struct game;
//each playerstat works like a node in a binary tree
struct playerstat {
	string label;
	double stat;
	bool isRed;
	int rank;
	player * leftplayer;
	player * rightplayer;
	player * parent;
};
//creates a player
//stats are saved in binary tree all players are saved in hash table
struct player {
	string name;//players name
	std::vector <playerstat*> playerstats;//list of players stats this has to be the same for very player right now
	player *hashTableNextPlayer;//calls the next player in hash table
	player *hashTablePerviousePlayer;//calls the perviouse player in hash table
};
//struct team not used for currently in program built in case any one wanted to build on to program
struct team {
	string name;
	string teamName;
	vector <game> gamesPlayed;

};

//struct game not used for currently in program built in case any one wanted to build on to program
struct game {
	team * playedAgisnt;
	int score;
	string winningteam;
	string hometeam;
};

class sport
{
public:
	sport();//cunstructs basic things
	void addStatstoinsteredplayer(string name);
	void treesipalyrangeofstats(int, int, int);
	//vector <player*> root;
	//void createPlayer(string, int);

	void addStatToTree(player *, int);

	void printAPlayer(string);
	void printPlayers();
	void findandaddstat(string, string, double);

	
	void insertPlayer(string);
	void callrankassign();
	//void printall(player* cur, int index);
	//void callprintall();
	
	void callrecursiveRank(string, int, int);
	void callrecursivestats(string, double, double);
	void printplayersstats(player *);
	//void changeAllOfAPlayersStats(string);
	//void changeaPlaysSingleStat(string, string);
	void calculateMeanPlayernstandarddeveation();
	void calculateStandardDeviatoinPlayer(player* ,int);
	
	void displayMean();
	void dsiplaystanarddevation();
protected:
private:
	int recursiveMean(player*, int);
	int findindexofstat(string );
	int assignRanks(int index, player * cur, int prevRank);
	int recursiveMean(player*, int);
	player * findPlayer(string);
	void recursiveRangeRank(player*, int, int, int);
	void recursiveRangestats(player*, double, double, int);
	void addfixup(player *, int);
	void leftrotate(player *, int);
	player * mean;
	player * standardDevation;
	int indexat(string);
	player * tnil;
	vector <player *> root;
	int numberOfStats;
	playerstat * statnill;
	player *hashTable[10];
	void addStattoPlayer(player *, string, double);
	void rightrotate(player*, int);
};

#endif // GRAPH_H

