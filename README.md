# Spitler_CSCI22_FinalProject

contributers
Brandon Spitler
zachkuzma not zachkuzma proeject he just added somestuff that wasnt need in visual studios but was needed where he was running it
installation guide
download main, header, cpp and text file into one file and then run main

if in codeblocks you need to right click the project name click build options then select the check box that says "have g++ follow the coming C++0x ISO C++ language standard [-std=c++0x]"

Project is a sports player handler
each player has a vector array of stats
stats are nodes with red black and left right property along with holding other things such as a double for the value of the stat and a label for what the stat is

each players vector array of stat is parallel to other players vectors so that the stats labels are the same at every index

for each new stat label each time a stat is being added for the first time to a tree a red black binary tree is made to hold all stats of the label/ occur at the vector index
The program then does things like calculate mean standard deviation for all index in the vector prints range; 

players are stored in hashtable for easy access]

Things i though about doing but didnt get to you
in the header you see a struct for a team I built head I never got to creating it but it would be cool if a graph of teams was added to by project with the edges connecting teams that have played against each other
curl downloader for players im still working on this i don’t know if ill have it up and running anytime soon however
a strut of positions that contains vector of sports so that you can separate out players better from which stats they will have and which stat they wont have

main funtions printed out by menu and what they do 
insertPlayer creates new player taking in name as string
findandadstat adds stat a player players name first parameter stat label second parameter and what the number for the stat is as third.
callrankassing llops through all of the stats assigning a rank based on where they fall for example the person with the fewest of some stats would be give rank 1 after this function the seconded what being given tank 2
calculatemeanplayenstadarddeveation calculates mean and standard deviation for all of the players on the team
addStatstoinsteredplayer()  makes sure all the stats that are in the old players are given to the new player
callrecursiverank prints the rang of players based on rank they are according to a certain stat for example callrecursiveRank(mins, 8 ,2) will print all players that are ranked between 8 and 2 according to mins
g->callrecursivestats(temp, dhigh, dlow) similar but instead prints the range of plays who actual stats fall in-between high and low
printplayers loops through hashtable printing all players in hash table
display mean displays the mean of each stat for all of the players
displaystandard devation displays the standard deviations of each stat for all the players


libraries used
iostream
vector
"sports.h"//header file included in GitHub respiratory
fstream
sstream
vector
string
using namespace std;
cmath

data structures used

red black trees
hashtable

created on visual studios 2015

dependencies
the textfile1 thats in the respiratory

works in c++11

email if you have any questions:
brsp7274@colorado.edu
