#include "sports.h"
#include <sstream>
sport::sport() {
	tnil = new player;
	tnil->name = "tnil";
	numberOfStats = 0;
	statnill= new playerstat;
	statnill->isRed = false;
	statnill->label = "statnill";
	for (int i = 0; i < 10; i++) {
		hashTable[i] = NULL;
	}
}
//code for player to has table

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
	}
	else
	{
		return cur;
		cout << cur->name << endl;
	}
}

int sport::indexat(string name) {
	int sum = 0;
	for (int i = 0; i < name.length(); i++) {
		sum = sum + name[i];

	}
	sum = sum % 10;
	return sum;

}

void sport::insertPlayer(string name) {
	int index;
	index = indexat(name);
	player * n1 = new player;
	n1->name = name;
	player* cur = hashTable[index];
	n1->hashTableNextPlayer = cur;
	hashTable[index] = n1;
}

void sport::printPlayers() {
	player * cur;
	bool isempty = true;
	for (int i = 0; i < 10; i++) {
		cur = hashTable[i];
		if (cur != NULL) {
			isempty = false;
		}
		while (cur != NULL) {
			cout << cur->name << endl;
			cur = cur->hashTableNextPlayer;
		}
	}
	if (isempty == true) {
		cout << "empty" << endl;
	}
}

void sport:: findandaddstat(string name,string statlabel,int nstat) {
	player * cur = findPlayer(name);
	addStattoPlayer(cur, statlabel, nstat);

}

void sport:: addStattoPlayer(player * incoming, string statlabel, int nstat) {
	playerstat * newStat = new playerstat;
	incoming->playerstats.push_back(newStat);
	int index = incoming->playerstats.size()-1;
	newStat->label = statlabel;
	newStat->isRed = true;
	newStat->stat = nstat;
	if (index+1 > numberOfStats) {
		tnil->playerstats.push_back(statnill);
		root.push_back(incoming);
		incoming->playerstats[index]->leftplayer = tnil;
		incoming->playerstats[index]->rightplayer = tnil;
		numberOfStats++;
	}

	addStatToTree(incoming, index);
}


void sport:: addStatToTree(player * playertoadd, int i) {
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
					x = x->playerstats[i]->rightplayer;
				}
				else {
					x = x->playerstats[i]->leftplayer;
				}
				
			}
			playertoadd->playerstats[i]->parent = y;
			if (playertoadd->playerstats[i]->stat < y->playerstats[i]->stat) {
				y->playerstats[i]->leftplayer = playertoadd;
			}
			else {
				y->playerstats[i]->rightplayer = playertoadd;
			}

			addfixup(playertoadd,i);
		}
}

void sport::addfixup(player* playeradded, int index) {
	player * uncle = NULL;
	playeradded->playerstats[index]->leftplayer = tnil;
	playeradded->playerstats[index]->rightplayer = tnil;

	while ((playeradded != root[index]) && (playeradded->playerstats[index]->isRed)) {
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
					leftrotate(playeradded,index);//add code later

				}

				playeradded->playerstats[index]->parent->playerstats[index]->isRed = false;
				playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->isRed = true;
				rightrotate(playeradded->playerstats[index]->parent->playerstats[index]->parent,index);//add code later

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
					rightrotate(playeradded,index);//add code later

				}

				playeradded->playerstats[index]->parent->playerstats[index]->isRed = false;
				playeradded->playerstats[index]->parent->playerstats[index]->parent->playerstats[index]->isRed = true;
				leftrotate(playeradded->playerstats[index]->parent->playerstats[index]->parent, index);//add code later
			}

		}
	}
	root[index]->playerstats[index]->isRed = false;

	return;
}

void sport::leftrotate(player * x, int index) {
	player * y = x->playerstats[index]->rightplayer;
	x->playerstats[index]->rightplayer = y->playerstats[index]->leftplayer;

	if (y->playerstats[index]->leftplayer != tnil) {
		y->playerstats[index]->parent = x;
	}
	y->playerstats[index]->parent = x->playerstats[index]->parent;

	if (x->playerstats[index]->parent == tnil) {
		root[index] = y;
	}

	else {
		if (x == (x->playerstats[index]->leftplayer)) {
			x->playerstats[index]->parent->playerstats[index]->leftplayer = y;
		}
		else {
			x->playerstats[index]->parent->playerstats[index]->rightplayer = y;
		}

	}
	y->playerstats[index]->leftplayer = x;
	x->playerstats[index]->parent = y;
}

void sport::rightrotate(player * x, int index) {
	player * y = x->playerstats[index]->leftplayer;
	x->playerstats[index]->leftplayer = y->playerstats[index]->rightplayer;
	if (y->playerstats[index]->rightplayer != tnil) {
		y->playerstats[index]->parent = x;
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

	y->playerstats[index]->rightplayer=x;
	x->playerstats[index]->parent = y;
}

void sport:: treesipalyrangeofstats(int index, int smalest, int largest) {
	player * cur = root[index];


}

void recursiveRange(player* cur, int hght, int low, int index) {
	if (cur->playerstats[index]->stat < cur->playerstats[index]->leftplayer->playerstats[index]->stat) {

	}

}
