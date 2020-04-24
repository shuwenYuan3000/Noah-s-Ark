#include <iostream>
#include <string>
using namespace std;

void print_background() {
	cout << left;
	cout << "Welcome to the ship of crime, the Noah's Ark." << endl;
	cout << "----------------------------------------------" << endl;
	cout << "You will have to play games with each other." << endl;
	cout << endl;
	cout << "Those who win the game can get off the ship," << endl; 
	cout << "while the losers will have to be locked on board for the rest of their life." << endl;	
	cout << "----------------------------------------------" << endl;
	cout << "Here are the rules:" << endl;
	cout << "  You will play with 5 different players." << endl;
	cout << "  With each opponent, there will be 5 rounds." << endl;
	cout << endl;
	cout << "  In a round, you and your opponent can choose either cooperate or cheat." << endl;
	cout << "  The outcome concerning the option will be shown in the table following:" << endl;
	cout << "  Player1/Player2     Cooperate     Cheat" << endl;
	cout << "  Cooperate            +2/+2        +0/+4" << endl;
	cout << "  Cheat                +4/+0        -1/-1" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Those who finally win more than 50 coins can get off the board." << endl;
	cout << "\"So if in all rounds we choose Cooperate then we all can get off the board!\", the smart said."<< endl;
	cout << endl;
	cout << "But for the rest of the coins other than 50, each one coin can change into a million dollars in the real world." << endl;
}


int main() {
	print_background();
	string start_game;
	bool play=false;
	while (!play) {
		cout << "Type \"Yes\" if you would like to proceed:";
	    cin >> start_game;
	    if (start_game == "Yes") {
	    	play = true;
		gameplay();
	    } 
	    if (start_game == "No") {
			cout << "If you don't play the game, you will be taken for human trials right away.  Think again!" << endl;
	    }
	    if (start_game != "Yes" && start_game != "No"){
	    	cout << "Invalid Choice!" << endl;
		}
	} 

	return 0;
}
