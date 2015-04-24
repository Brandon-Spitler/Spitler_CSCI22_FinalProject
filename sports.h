#ifndef SPORTS_H
#define SPORTS_H
#include <vector>;
#include <iostream>;
#include <fstream>;
#include <sstream>;
#include <cmath>;
using namespace std;
struct playerstat;
struct player;
struct game;
struct playerstat {
	string label;
	double stat;
	bool isRed;
	int rank;
	player * leftplayer;
	player * rightplayer;
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
public:
	sport();
	void addStatstoinsteredplayer(string name);
	void treesipalyrangeofstats(int, int, int);
	//vector <player*> root;
	//void createPlayer(string, int);
	void addfixup(player *, int);
	void leftrotate(player *, int);
	void addStattoPlayer(player *, string, double);
	void rightrotate(player*, int);
	void addStatToTree(player *, int);
	player * findPlayer(string);
	void printAPlayer(string);
	void printPlayers();
	void findandaddstat(string, string, double);
	void recursiveRangeRank(player*, int, int, int);
	void recursiveRangestats(player*, double, double, int);
	int assignRanks(int index, player * cur, int prevRank);
	void insertPlayer(string);
	void callrankassign();
	//void printall(player* cur, int index);
	//void callprintall();
	int findindexofstat(string );
	void callrecursiveRank(string, int, int);
	void callrecursivestats(string, double, double);
	void printplayersstats(player *);
	//void changeAllOfAPlayersStats(string);
	//void changeaPlaysSingleStat(string, string);
	void calculateMeanPlayernstandarddeveation();
	void calculateStandardDeviatoinPlayer(player* ,int);
	int recursiveMean(player*, int);
	void displayMean();
	void dsiplaystanarddevation();
protected:
private:
	player * mean;
	player * standardDevation;
	int indexat(string);
	player * tnil;
	vector <player *> root;
	int numberOfStats;
	playerstat * statnill;
	player *hashTable[10];
};

#endif // GRAPH_H

