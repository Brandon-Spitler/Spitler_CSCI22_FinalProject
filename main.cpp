#include <iostream>;
#include <vector>;
#include "sports.h";
#include <fstream>;
#include <sstream>;
#include <vector>;
#include <string>;
using namespace std;

int printmenu() {
	string answer;
	int nanswer;
	cout << "======Main Menu=====" << endl;
	cout << "1. Add a Player" << endl;
	cout << "2. print range of ranks" << endl;
	cout << "3. print range of stats" << endl;
	cout << "4. print players" << endl;
	cout << "5. Print a players stat" << endl;
	cout << "6 show mean for players" << endl;
	cout << "7 show standard deveation for players" << endl;
	cout << "8. Quit" << endl;
	getline(std::cin, answer);
	stringstream ss(answer);
	ss >> nanswer;
	//nanswer = stoi(answer);
	return nanswer;
}


int main(int argc, char* argv[])
{
	fstream myfile;
	myfile.open("TextFile1.txt");
	string city;
	bool firstline = true;
	int appendTo;
	bool hit = true;
	string temp;
	sport * g = new sport;
	vector <string> stats;
	int count;
	string curStat;
	double stat;
	string curPlayername;
	for (int i = 0; !myfile.eof(); i++) {
		getline(myfile, city);
		//cout << city << endl;
		if (firstline == true) {
			appendTo = city.find(",", 0);
			city.erase(0, appendTo + 1);  //ending what is need for object
			while (hit == true) {
				appendTo = city.find(",", 0);
				if (appendTo == -1) {
					hit = false;
				}
				temp = city.substr(0, appendTo);
				stats.push_back(temp);
				city.erase(0, appendTo + 1);
			}
			firstline = false;
			hit = true;
		}
		else {
			count = 0;
			appendTo = city.find(",", 0);
			curStat = city.substr(0, appendTo);
			temp = city.substr(0, appendTo);

			g->insertPlayer(temp);
			curPlayername = temp;
			city.erase(0, appendTo + 1);
			hit = true;
			while (hit == true) {
				appendTo = city.find(",", 0);
				if (appendTo == -1) {
					hit = false;
				}
				temp = city.substr(0, appendTo);
				if (temp != "-1") {

					stringstream(temp) >> stat;
					g->findandaddstat(curPlayername,stats[count], stat);
					//cout << stat << endl;
				}
				city.erase(0, appendTo + 1);
				count++;
			}
		}
	}
	int answer;
	int high;
	string shigh;
	string slow;
	int low;
	string anser;
	//g->callprintall();
	g->callrankassign();
	g->calculateMeanPlayernstandarddeveation();
	double dhigh;
	double dlow;
	do {
		answer = printmenu();
		switch (answer) {
		case 1:
			cout << "Enter player name" << endl;
			getline(std::cin, curPlayername);
			g->insertPlayer(curPlayername);
			g->addStatstoinsteredplayer(curPlayername);
			g->callrankassign();
			g->calculateMeanPlayernstandarddeveation();
			break;
		case 2:
			cout << "enter stat to rank by" << endl;
			getline(std::cin, temp);

			cout << "high" << endl;
			getline(std::cin, shigh);
			high = stoi(shigh);
			//stringstream ss(answer);
			//ss >> high;

			cout << "low" << endl;
			getline(std::cin, slow);
			low = stoi(slow);
			//stringstream ss(answer); 
			//stringstream(answer) >> low;
			//ss >> low;
			g->callrecursiveRank(temp, high, low);

			break;

		case 3:
			cout << "enter stat to find" << endl;
			getline(std::cin, temp);

			cout << "high" << endl;
			getline(std::cin, shigh);

			dhigh = stod(shigh);

			//stringstream ss(answer);
			//ss >> high;
			cout << "low" << endl;
			//stringstream ss(answer); 
			getline(std::cin, slow);
			//stringstream(slow) >> dlow;
			dlow = stod(slow);
			//ss >> low;
			g->callrecursivestats(temp, dhigh, dlow);


			break;

		case 4:
			g->printPlayers();
			break;
		case 5:
			cout << "which player do you want to print" << endl;
			getline(std::cin, temp);
			g->printAPlayer(temp);
			break;
		case 6:
			g->displayMean();
			break;
		case 7:
			g->dsiplaystanarddevation();
			break;
		}
	} while (answer!=8);


	return 0;
}
