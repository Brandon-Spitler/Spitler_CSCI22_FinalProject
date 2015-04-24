#include "sports.h";
#include <sstream>;
sport::sport() {
	tnil = new player;
	tnil->name = "tnil";
	numberOfStats = 0;
	statnill = new playerstat;
	statnill->isRed = false;
	statnill->label = "statnill";
	statnill->leftplayer = tnil;
	statnill->rightplayer = tnil;
	statnill->parent = tnil;
	mean = new player;
	standardDevation = new player;
	for (int i = 0; i < 10; i++) {
		hashTable[i] = NULL;
	}
}
//code for player to hash table

/*
precondition
end point in hash table are marked a NULL pointers
string is short enough were acsiic value of al the charters is an int

$
finds and returns player in hash table with name = string name
if not in hash table it will display not found and will return NULL
$

postconditons returns the player is he is in the hash table if not it doesnt retrun anything; could cause problems in code if 
players is not in hash table
*/
player * sport::findPlayer(string name) {
	int index = indexat(name);
	player * cur = hashTable[index];
	while (cur != NULL) {
		if (cur->name == name) {
			break;
		}
		cur = cur->hashTableNextPlayer;
	}
	if (cur == NULL) {
		cout << "not found" << endl;
		return NULL;
	}
	else
	{
		return cur;
		cout << cur->name << endl;
	}
}
/*
precondition charters sumed into ascic values are short enough to be stored an an int

$
finds the returns index that string name will be located in the hash table
$

postcondition returns the placement index for the string name into the hash table of size ten as an int
*/
int sport::indexat(string name) {
	int sum = 0;
	for (int i = 0; i < name.length(); i++) {
		sum = sum + name[i];

	}
	sum = sum % 10;
	return sum;

}

/*
precondtions relies onf indexat precondtions being met

$
insterts player into hash table at the correct index for string na,e
player will be the first put into the first value of the hash table pushing all players back
$

postcondtion a player with string name will be added to the hash table no stats w2ill be added to him threw this method
*/
void sport::insertPlayer(string name) {
	int index;
	index = indexat(name);
	player * n1 = new player;
	n1->name = name;
	player* cur = hashTable[index];
	n1->hashTableNextPlayer = cur;
	hashTable[index] = n1;
}
/*
precondtion hashtable iss full of player data types or nothing
	-hashtable is size ten

$
prints all players and all of their stat in for all players in the HashTable
$

postcondition all players will be printed on screen
	-returns and chnages nothing withen the hash table
*/
void sport::printPlayers() {
	player * cur;
	bool isempty = true;
	for (int i = 0; i < 10; i++) {
		cur = hashTable[i];
		if (cur != NULL) {
			isempty = false;
		}
		while (cur != NULL) {
			printplayersstats(cur);
			cur = cur->hashTableNextPlayer;
		}
	}
	if (isempty == true) {
		cout << "empty" << endl;
	}
}
//end funtions for using the hash table of players here

/*
precondtions player with string name exists in the hash table;
	every athlese has a the same statlabel withen in the next vector position
		this is needed to keep parrel stqt vectors

$
finds player with name
adds stat to them with label statlebel and value n staat
$

postcondtions
	finds players and gives then a new stat called string stat label with the value of nstat
*/
void sport::findandaddstat(string name, string statlabel, double nstat) {
	player * cur = findPlayer(name);
	addStattoPlayer(cur, statlabel, nstat);

}


/*
precondtions
	-player incoming exists
	-incomings new vector postions for stat has the same index for the stat label that every other player has
	-mean,tnill,nillstat and standard devation player have been created
	-number os stat have been declared and assigned to how many values are in each players vector

$
adds stat to player incoming
creates new stat
if it is the first vector of this stat label 
	-it adds player incoming to the next place in vector
	-adds a statnill value to tnil
	-adds a 0 value with label stat label to mean and standard devatioin
	-increments numberofstats by 1;
makes incoming stat red
adds stat to tree
$

postconditons
	-creates new stat
	-add the new stat to players next aviable postion in vector stats with a value nstat and the stat is name statlabel
	-calls funtion to add stat to binary tree
	-if root size is smaller then the number of stat the athele has  then it adds another place to root with the new stat in the index place
	-adds a place older to tnil which is just statnill so we can have parrell array
	-adds stat of 0 to standard devaiation and mean players with label statlabel so that when we have a place setting for the variables latter
*/
void sport::addStattoPlayer(player * incoming, string statlabel, double nstat) {
	playerstat * newStat = new playerstat;
	incoming->playerstats.push_back(newStat);
	int index = incoming->playerstats.size() - 1;
	newStat->label = statlabel;
	newStat->isRed = true;
	newStat->stat = nstat;
	if (index + 1 > numberOfStats) {
		tnil->playerstats.push_back(statnill);
		root.push_back(incoming);
		tnil->playerstats.push_back(statnill);
		incoming->playerstats[index]->leftplayer = tnil;
		incoming->playerstats[index]->rightplayer = tnil;
		incoming->playerstats[index]->parent = tnil;
		numberOfStats++;
		playerstat * meanStat = new playerstat;
		meanStat->stat = 0;
		meanStat->label = statlabel;
		mean->playerstats.push_back(meanStat);
		playerstat * standardDeviationStat = new playerstat;
		standardDeviationStat->stat = 0;
		standardDeviationStat->label = statlabel;
		standardDevation->playerstats.push_back(standardDeviationStat);

	}

	addStatToTree(incoming, index);
}
/*
precondition
	-if it is a new stat label root has been added
	-every players vector contains the same stats label in every index of there vector
	-incoming stat at players index i in players vector is red

$
adds the perviouse created stat in add stat to player to the binary tree of index i
if its is a root value makes red false
calls treefixup
$

postcondition
	-correctly adds the stat to a tree of stats with index i
	-calls adfixup to balence tree after value is added
	-if its a root value of first value with that statlabel/index i the red will be changed to false
*/
void sport::addStatToTree(player * playertoadd, int i) {
	player * x;
	player * y;
	x = root[i];
	y = tnil;
	if (root[i] == playertoadd) {
		playertoadd->playerstats[i]->isRed = false;
	}
	else {
		while (x != tnil) {
			y = x;
			if (playertoadd->playerstats[i]->stat < x->playerstats[i]->stat) {
				x = x->playerstats[i]->leftplayer;
			}
			else {
				x = x->playerstats[i]->rightplayer;
			}

		}
		playertoadd->playerstats[i]->parent = y;
		if (playertoadd->playerstats[i]->stat < y->playerstats[i]->stat) {
			y->playerstats[i]->leftplayer = playertoadd;
		}
		else {
			y->playerstats[i]->rightplayer = playertoadd;
		}

		addfixup(playertoadd, i);
	}
} 
/*
precondition
	-previously balaenced tree
	-all players vector of stat at index contains the same statlabel
	-tnil vectors are statnills at postion i
	-statnills are black
$
balances red black tree;
resets root to black
$

postcondition
	-balences red black bianry tree of vector i
*/

void sport::addfixup(player* playeradded, int index) {
	player * uncle = NULL;
	playeradded->playerstats[index]->leftplayer = tnil;
	playeradded->playerstats[index]->rightplayer = tnil;

	while ((playeradded != root[index]) && (playeradded->playerstats[index]->parent->playerstats[index]->isRed)) {
		if (playeradded->playerstats[index]->parent == playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->leftplayer) {
			uncle = playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->rightplayer;

			if (uncle->playerstats[index]->isRed) {
				playeradded->playerstats[index]->parent->playerstats[index]->isRed = false;
				uncle->playerstats[index]->isRed = false;
				playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->isRed = true;
				playeradded = playeradded->playerstats[index]->parent->playerstats[index]->parent;
			}
			else {
				if (playeradded == playeradded->playerstats[index]->parent->playerstats[index]->rightplayer) {
					playeradded = playeradded->playerstats[index]->parent;
					leftrotate(playeradded, index);

				}

				playeradded->playerstats[index]->parent->playerstats[index]->isRed = false;
				playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->isRed = true;
				rightrotate(playeradded->playerstats[index]->parent->playerstats[index]->parent, index);

			}
		}
		else {
			uncle = playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->leftplayer;

			if (uncle->playerstats[index]->isRed) {
				playeradded->playerstats[index]->parent->playerstats[index]->isRed = false;
				uncle->playerstats[index]->isRed = false;
				playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->isRed = true;
				playeradded = playeradded->playerstats[index]->parent->playerstats[index]->parent;
			}
			else {
				if (playeradded == playeradded->playerstats[index]->parent->playerstats[index]->leftplayer) {
					playeradded = playeradded->playerstats[index]->parent;
					rightrotate(playeradded, index);

				}

				playeradded->playerstats[index]->parent->playerstats[index]->isRed = false;
				playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->isRed = true;
				leftrotate(playeradded->playerstats[index]->parent->playerstats[index]->parent, index);
			}

		}
	}
	root[index]->playerstats[index]->isRed = false;

	return;
}

/*
precondition
	-some players are already in the tree with stats
	-player with name exists
	-player has the same stat that evey other player has

$
creates player and adds stats to player looping through the stats that everyother player has
adds the stats to binary tree
$
postcondition
	-adds all stats that everyother player as to player with name name
	-keeps players vector parrel to each other

*/
void sport::addStatstoinsteredplayer(string name)
{
	string stat;
	double nstat;
	for (int i = 0; i < root.size(); i++) {
	
		
		cout << "Enter "<<root[i]->playerstats[i]->label <<" for player:" << endl;
		getline(std::cin, stat);
		stringstream (stat)>>nstat;
		this->findandaddstat(name, root[i]->playerstats[i]->label,nstat);
	}
}

/*
precondition
	-player is already added to vector tree
	-player as stat at vector player stats index
	-tree is a vali binary tree
$
left rotatate to balaence red black bianary tree and maintain bianary properties
$
postcondition
	-rotates the around x shift y to x postion and x up to y postion
	-maintains valid binary tree
*/

void sport::leftrotate(player * x, int index) {
	player * y = x->playerstats[index]->rightplayer;
	x->playerstats[index]->rightplayer = y->playerstats[index]->leftplayer;

	if (y->playerstats[index]->leftplayer != tnil)
		y->playerstats[index]->leftplayer->playerstats[index]->parent = x;


	y->playerstats[index]->parent = x->playerstats[index]->parent;

	if (x->playerstats[index]->parent == tnil)
		root[index] = y;

	else {
		if (x == (x->playerstats[index]->parent->playerstats[index]->leftplayer)) {
			x->playerstats[index]->parent->playerstats[index]->leftplayer = y;
		}
		else {
			x->playerstats[index]->parent->playerstats[index]->rightplayer = y;
		}

	}
	y->playerstats[index]->leftplayer = x;
	x->playerstats[index]->parent = y;
}
/*
precondition
	-player is already added to vector tree
	-player as stat at vector player stats index
	-tree is a vali binary tree

&
right rotatates to balaence red black bianary tree and maintain bianary properties
&

postcondition
	-rotates the around x shift y to x postion and x up to y postion
	-maintains valid binary tree
*/
void sport::rightrotate(player * x, int index) {
	player * y = x->playerstats[index]->leftplayer;
	x->playerstats[index]->leftplayer = y->playerstats[index]->rightplayer;
	if (y->playerstats[index]->rightplayer != tnil) {
		y->playerstats[index]->rightplayer->playerstats[index]->parent = x;
	}
	y->playerstats[index]->parent = x->playerstats[index]->parent;
	if (x->playerstats[index]->parent == tnil) {
		root[index] = y;
	}
	else {
		if (x == x->playerstats[index]->parent->playerstats[index]->leftplayer) {
			x->playerstats[index]->parent->playerstats[index]->leftplayer = y;
		}
		else {
			x->playerstats[index]->parent->playerstats[index]->rightplayer = y;
		}
	}

	y->playerstats[index]->rightplayer = x;
	x->playerstats[index]->parent = y;
}

/*
precondition
	-players have a stat at index
	-cur exists
	-preRank come in as 0 to begin with
$
gives each playeys stat at index i a rank with numbr 1 going to the lowest number
$
postcondition
	-give ranks to each player based on the stat value at index i lowest gets the number 1 ranks highest gets the last rank
*/
int sport::assignRanks(int index, player * cur, int prevRank) {
	int rank = prevRank;
	//cout << "3-" << rank << endl;
	if (cur->playerstats[index]->leftplayer != tnil) {
		//cout << "2-" << rank << endl;
		rank =assignRanks(index, cur->playerstats[index]->leftplayer, rank);
		//cout << "5"<<endl;
	}
	cur->playerstats[index]->rank = rank+1;
	rank = rank + 1;
	//cout <<cur->name <<" : " << index<<" : "<< cur->playerstats[index]->stat << " : " << cur->playerstats[index]->rank << endl;
	if (cur->playerstats[index]->rightplayer != tnil) {
		//cout << "1-" << rank << endl;
		rank = assignRanks(index, cur->playerstats[index]->rightplayer, rank);
		//cout << "4" << endl;
	}
	//cout << "6" << endl;
	return rank;

}
/*
precondition
	-players have been assined to root
	-vector of stats for players is the same size as root
	-valid binary tree
$
calls ranks assing for all bianary trees so that every stat a player has ahas a rank
$

postcondition
	-gives ever stat a player has a rank 
	-calls assignRanks /|\
*/
void sport::callrankassign() {
	for (int i = 0; i < root.size(); i++) {
		assignRanks(i,root[i],0);
	}
}

/*
precondition
	-root at index exists
$
calls then funtion to print range of ranks
$

postcondition
	-calls recusiverangeRank \|/ with starting values
*/
void sport::treesipalyrangeofstats(int index, int smalest, int largest) {
	player * cur = root[index];
	recursiveRangeRank(cur, largest, smalest, index);

}


/*
precondition
	-cur player exists
	-tnil exists
	-all players have the same stat label to compate at index i
$
prints all player with stats at index i stats between hght and low
$

postcondition
	-outputs all players with stat and index i that has a balue between hght and low

*/
void sport::recursiveRangestats(player* cur, double hght, double low, int index) {
	if (cur->playerstats[index]->leftplayer != tnil && cur->playerstats[index]->leftplayer->playerstats[index]->stat<hght) {
		recursiveRangestats(cur->playerstats[index]->leftplayer, hght, low, index);
	}
	if (cur->playerstats[index]->stat<hght && cur->playerstats[index]->stat>low) {
		printplayersstats(cur);
	}
	if (cur->playerstats[index]->rightplayer != tnil && cur->playerstats[index]->rightplayer->playerstats[index]->stat>low) {
		recursiveRangestats(cur->playerstats[index]->rightplayer, hght, low, index);
	}
}

/*
precondition
	-ranksAssing has been caled/|\ for stats at index i
	-cur player exists
	-all players have the same stat label to compate at index i
$
prints all player with stats at index i ranked between hght and low
$

postcondition
	-outputs all players that are ranked between hgih and low
*/
void sport::recursiveRangeRank(player* cur, int hght, int low, int index) {
	if (cur->playerstats[index]->leftplayer != tnil && cur->playerstats[index]->leftplayer->playerstats[index]->rank<hght) {
		recursiveRangestats(cur->playerstats[index]->leftplayer, hght, low, index);
	}
	if (cur->playerstats[index]->stat<hght && cur->playerstats[index]->stat<low) {
		printplayersstats(cur);
	}
	if (cur->playerstats[index]->rightplayer != tnil && cur->playerstats[index]->rightplayer->playerstats[index]->rank>low) {
		recursiveRangestats(cur->playerstats[index]->rightplayer, hght, low, index);
	}
}

//tester method have the hashtable method for printing players for when all players are printed
///////////////////////////////////////////////////////////////////////////////////////////////
/*
void sport::printall(player* cur,int index) {
	if (cur->playerstats[index]->leftplayer != tnil) {
		printall(cur->playerstats[index]->leftplayer, index);
	}
	cout << cur->name << endl;
	if (cur->playerstats[index]->rightplayer != tnil) {
		printall(cur->playerstats[index]->rightplayer, index);
	}
}

void sport::callprintall() {
	printall(root[0], 0);
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////

/*
precondtion
	-root has the same number of elemeents as playersttats do
	-all player stats have labels
	-playerstats are all parrrel to each other for each player
	-root has elements in it
$
finds asnd returns the index where statlabel of stattofind is
$

postcondtion
	-returns the index of player stats that the stat occurs at

*/
int sport::findindexofstat(string stattofind) {
	for (int i = 0; i < root.size(); i++) {
		if (root[i]->playerstats[i]->label==stattofind) {
			return i;
		}
	}
	cout << "not found" << endl;
	return -1;
}

/*
precondtion
	-root has players in it

$
find the index of stattofind and calls recrusiveRangeRang to print all players between the two values of
$

postcondtion
	-calls recursiveRangeRank /|\ with specific start values

*/
void sport::callrecursiveRank(string stattofind, int high, int low) {
	int f = findindexofstat(stattofind);
	if (f != -1) {
		recursiveRangeRank(root[f], high, low, f);
	}
}

/*
precondtion
	-root has players in it

$
finds the index where stattofind occurs at and the print off all stats between hgh and low
$

postcondtion
	-calls recursiveRangeStats/|\ with spcific stat values
*/

void sport::callrecursivestats(string stattofind, double high, double low) {
	int f = findindexofstat(stattofind);
	if (f != -1) {
		recursiveRangestats(root[f], high, low, f);
	}
}

/*
precondtion
	-player cur exists and has at leat one stat
$
prints cur players stats
in the form
	"name of stat: value of stat ->...repteaed format for every stat"
$
postcondtion
	-prints players

*/

void sport::printplayersstats(player * cur) {
	cout << "Player: " << cur->name << endl;
	cout << cur->playerstats[0]->label << ": " << cur->playerstats[0]->stat;
	for (int i = 1; i < cur->playerstats.size(); i++) {
		cout <<" -> "<< cur->playerstats[i]->label << ": " << cur->playerstats[i]->stat;
	}
	cout << endl;
}

/*
precondtion
	-player with string name exists

$
finds a player with string name
and then prints all of his stats
$

postcondtion
	-doesnt effect a structure just prints;
*/
void sport::printAPlayer(string name) {
	player* cur = findPlayer(name);
	printplayersstats(cur);
}

/*
precondtion
	-mean player has been created;
	-has a parrell vector to all players with starting value at each stat 0
	-libabry math used for funtions called in this funtion
$
calcuated both meanplayer and stadard devatation player
$

postcondtion
	-mean player wil have the mean off all players stats created in the same index with the same label as the players stats

*/

void sport::calculateMeanPlayernstandarddeveation() {
	for (int i = 0; i < root.size(); i++) {
		mean->playerstats[i]->stat = 0;
		standardDevation->playerstats[i]->stat = 0;
		int count = recursiveMean(root[i],i);
		mean->playerstats[i]->stat = mean->playerstats[i]->stat / count;
		calculateStandardDeviatoinPlayer(root[i], i);
		standardDevation-> playerstats[i]->stat =sqrt( (standardDevation->playerstats[i]->stat / (count - 1)));
	}
}

/*
precondtion
	-calcualte MeanPlayernstandarddeviation /|\ has been called
	-root has value
$
displays all of the player means values
$
postcondtion
	-doenst change a structure just diplays the mean value of all players stats at each index

*/
void sport::displayMean() {
	cout << "Mean for the player's stats is" << endl;
	for (int i = 0; i < mean->playerstats.size(); i++) {
		cout<< mean->playerstats[i]->label << " : " << mean->playerstats[i]->stat << endl;
	}
}

/*
precondtion
	-calcualte MeanPlayernstandarddeviation /|\ has been called
	-root has values
$
displays all of players standard devations values and stats
$
postcondtion
	-doenst change a structure just diplays the standard devation value of all players stats at each index

*/

void sport::dsiplaystanarddevation() {
	cout << "standard devation for the players stats is " << endl;
	for (int i = 0; i < mean->playerstats.size();i++) {
		cout << standardDevation->playerstats[i]->label << " : " << standardDevation->playerstats[i]->stat<<endl;
	}
}

/*
precondtion
	-cur player exists
	-root has values at index
	-mean player has been put to 0
$
sums up all of the players values and stores them in the index they came from in player m then returns total number of players

$

postcondtion
	-returns the number of athlets
	-assigns mean player stats at index with the sum of all players stats at index i
*/

int sport::recursiveMean(player * cur,int index) {
	int leftcount=0;
	int rightcount=0;
	int count = 1;
	if (cur->playerstats[index]->leftplayer!=tnil) {
		leftcount=recursiveMean(cur->playerstats[index]->leftplayer, index);
	}
	mean->playerstats[index]->stat+= cur->playerstats[index]->stat;
	if (cur->playerstats[index]->rightplayer != tnil) {
		rightcount = recursiveMean(cur->playerstats[index]->rightplayer, index);
	}
	return count + rightcount + leftcount;
}

/*
precondtion
	-cur player exists
	-root has values at index
	-standard devation player has been put to 0
	-uses math libary
$
takes the stat of mean at index index and subtacts the by the cur playrs stat at index i then squares the value and sums all of them up; 
$
postcondtion
	-assigns standardDevation player stats at index with the sum of all mena stats at index i value- the value of the players stats at index squared
*/

void sport::calculateStandardDeviatoinPlayer(player * cur, int index) {
	if (cur->playerstats[index]->leftplayer!=tnil) {
		calculateStandardDeviatoinPlayer(cur->playerstats[index]->leftplayer, index);
	}
	standardDevation->playerstats[index]->stat += pow(cur->playerstats[index]->stat - mean->playerstats[index]->stat,2);
	if (cur->playerstats[index]->rightplayer != tnil) {
		calculateStandardDeviatoinPlayer(cur->playerstats[index]->rightplayer, index);
	}
}
