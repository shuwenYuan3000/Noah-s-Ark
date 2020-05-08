#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "judge.h"
using namespace std;
//we use the judge, the head file to jugde who will win the coins in each round

// This function prints the game background and the rules. 
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
	cout << "Those who finally win more than 40 coins can get off the board." << endl;
	cout << "\"So if in all rounds we choose Cooperate then we all can get off the board!\", the smart said."<< endl;
	cout << endl;
	cout << "But for the rest of the coins other than 40, each one coin can change into a million dollars in the real world." << endl;
}

// This function provides the player with a trial of the game, in which the opponent's first choice is "Yes" and the second one is "No".
// It helps player get familiar with how to play.
void trial() {
	int tscore=0, rscore=0;
	string choice;
	cout << "----------------------------------------------" << endl;
	cout << "In case you are not clear with the rule, Let\'s start with a little trial." << endl;
	cout << "You now have " << tscore << " coins." << endl;
	cout << "Your rival now have " << rscore << " coins." << endl;
	cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
	cout << "You: ";
	cin >> choice;
	cout << "Your rival: Yes" << endl;
	if (choice == "Yes" || choice == "yes") {
		tscore += 2;
		rscore += 2;
	}
	else {
		tscore += 4;
	}
	cout << "You now have " << tscore << " coins." << endl;
	cout << "Your rival now have " << rscore << " coins." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "You: ";
	cin >> choice;
	cout << "Your rival: No" << endl;
	if (choice == "Yes" || choice == "yes") {
		rscore += 4;
	}
	else {
		tscore -= 1;
		rscore -= 1;
	}
	cout << "You now have " << tscore << " coins." << endl;
	cout << "Your rival now have " << rscore << " coins." << endl;
	cout << "Now ended the trial. Good luck and wish you an enjoyable voyage! HAHAHAHAHAHA..." << endl;
	cout << "----------------------------------------------" << endl;
}

// This function calls opponent "girl", who always choose "Yes".
// The parameters are the variable "score" and the array "record". It changes the value of "score" and elements in record according to player's inputs of each round.  
void girl(int& score, int record[7][5][2]) {
	cout << "----------------------------------------------" << endl;
	cout << "There is a little girl in her pink hat." << endl;
	cout << "With her innocent eyes filled with fear." << endl;
	cout << "Little Lamb God bless thee. " << endl;
	for (int i = 0; i < 5;++i) {
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "You now have " << score << " coins." << endl;
		cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
		cout << "You: ";
		string choice;
		cin >> choice;
		cout << "Your rival: Yes" << endl;
		if (choice == "Yes" || choice == "yes") {
			judge(score, 1, 1);
			record[0][i][0] = 1;
			record[0][i][1] = 1;
		}
		else if (choice == "No" || choice == "no") {
			judge(score, 0, 1);
			record[0][i][0] = 0;
			record[0][i][1] = 1;
		}
		cout << "You now have " << score << " coins." << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "THE END OF ROUND" << endl;
	cout << "You now have " << score << " coins." << endl;
}

// This function calls opponent "black", who always choose "No".
// The parameters are the variable "score" and the array "record". It changes the value of "score" and elements in record according to player's inputs of each round. 
void black(int& score, int record[7][5][2]) {
	cout << "----------------------------------------------" << endl;
	cout << "There is a middle-aged man in tidy suit." << endl;
	cout << "With sophisticated smile on his face." << endl;
	cout << "Trust no Kings. Kings put Girls in Towers." << endl;
	for (int i = 0; i < 5;++i) {
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "You now have " << score << " coins." << endl;
		cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
		cout << "You: ";
		string choice;
		cin >> choice;
		cout << "Your rival: No" << endl;
		if (choice == "Yes" || choice == "yes") {
			judge(score, 1, 0);
			record[1][i][0] = 1;
			record[1][i][1] = 0;
		}
		else if (choice == "No" || choice == "no") {
			judge(score, 0, 0);
			record[1][i][0] = 0;
			record[1][i][1] = 0;
		}
		cout << "You now have " << score << " coins." << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "THE END OF ROUND" << endl;
	cout << "You now have " << score << " coins." << endl;
}

// This function calls opponent "godfather", who starts with "Yes", but changes to "No" once player chooses "No". 
// The parameters are the variable "score" and the array "record". It changes the value of "score" and elements in record according to player's inputs of each round. 
void godfather(int& score, int record[7][5][2]) {
	cout << "----------------------------------------------" << endl;
	cout << "There sits a godfather." << endl;
	cout << "Cigarattee at hand." << endl;
	cout << "Never hate your enemies.It affects your judgement." << endl;
	int coop = 1;
	for (int i = 0; i < 5;++i) {
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "You now have " << score << " coins." << endl;
		cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
		cout << "You: ";
		string choice;
		cin >> choice;
		if (coop==1)
			cout << "Your rival: Yes" << endl;
		else
			cout << "Your rival: No" << endl;
		if (choice == "Yes" || choice == "yes") {
			judge(score, 1, coop);
			record[2][i][0] = 1;
			record[2][i][1] = coop;
		}
		else if (choice == "No" || choice == "no") {
			judge(score, 0, coop);
			record[2][i][0] = 0;
			record[2][i][1] = coop;
			coop = 0;
		}
		cout << "You now have " << score << " coins." << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "THE END OF ROUND" << endl;
	cout << "You now have " << score << " coins." << endl;
}

// This function calls opponent "copycat", whose first choice is "Yes", but other choices are the same as player's last one. 
// The parameters are the variable "score" and the array "record". It changes the value of "score" and elements in record according to player's inputs of each round. 
void copycat(int &score, int record[7][5][2]) {
	cout << "----------------------------------------------" << endl;
	cout << "There is a young man in a blue hat." << endl;
	cout << "With a kind smile on his face." << endl;
	cout << "Sometimes, others may treat you the way you treat them." << endl;
	for (int i=0; i<5; i++) {
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "You now have " << score << " coins." << endl;
		cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
		cout << "You: ";
		string choice;
		cin >> choice;
		
		if (i==0) {
			cout << "Your rival: Yes" << endl;
			if (choice == "Yes" || choice == "yes") {
				judge(score, 1, 1);
				record[3][0][0] = 1;
				record[3][0][1] = 1;
			}
			else if(choice == "No" || choice == "no") {
				judge(score, 0, 1);
				record[3][0][0] = 0;
				record[3][0][1] = 1;
			}
			cout << "You now have " << score << " coins." << endl;
		}
		else {
			if (record[3][i-1][0]==1) {
				cout << "Your rival: Yes" << endl;
			}
			else {
				cout << "Your rival: No" << endl;
			}
			
			if (choice =="Yes" || choice == "yes") {
				judge(score, 1, record[3][i-1][0]);
				record[3][i][0] = 1;
				record[3][i][1] = record[3][i-1][0];
			}
			else if (choice =="No" || choice =="no") {
				judge(score, 0, record[3][i-1][0]);
				record[3][i][0] = 0;
				record[3][i][1] = record[3][i-1][0];
			}
			cout << "You now have " << score << " coins." << endl;
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "THE END OF ROUND" << endl;
	cout << "You now have " << score << " coins." << endl;
}

// This function calls opponent "random", who choices are randomly generated. 
// The parameters are the variable "score" and the array "record". It changes the value of "score" and elements in record according to player's inputs of each round. 
void random(int &score, int record[7][5][2]) {
	cout << "----------------------------------------------" << endl;
	cout << "There sits a guy in a red hat." << endl;
	cout << "Whose facial expression is dull." << endl;
	cout << "Chances are that human hearts are really unpredictable." << endl;
	for (int i=0; i<5; i++) {
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "You now have " << score << " coins." << endl;
		cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
		cout << "You: ";
		string choice;
		cin >> choice;
		
		srand(time(NULL));
		record[4][i][1] = rand() % 2;
		if (record[4][i][1] == 1) {
			cout << "Your rival: Yes" << endl;
		}
		if (record[4][i][1] == 0) {
			cout << "Your rival: No" << endl;
		}
		
		if (choice == "Yes" || choice == "yes") {
			judge(score, 1, record[4][i][1]);
			record[4][i][0] = 1;
		}
		else if (choice =="No" || choice =="no") {
			judge(score, 0, record[4][i][1]);
			record[4][i][0] = 0;
		}
		cout << "You now have " << score << " coins." << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << "THE END OF ROUND" << endl;
	cout << "You now have " << score << " coins." << endl;
}

// This function calls opponent "simpleton", who starts with "Yes", but changes to the opposite of last choice if the player chose "No" in the last round. 
// The parameters are the variable "score" and the array "record". It changes the value of "score" and elements in record according to player's inputs of each round. 
void simpleton(int &score, int record[7][5][2]) {
	cout << "----------------------------------------------" << endl;
	cout << "Here comes a teenager." << endl;
	cout << "Who looks simple, but not easy to deal with." << endl;
	cout << "The principle of making decisions may be very simple for some people." << endl;
	for (int i=0; i<5; i++) {
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "You now have " << score << " coins." << endl;
		cout << "Type \"Yes\" if you would like to cooperate, else type \"No\"." << endl;
		cout << "You: ";
		string choice;
		cin >> choice;
		
		if (i==0) {
			cout << "Your rival: Yes" << endl;
			if (choice == "Yes" || choice == "yes") {
				judge(score, 1, 1);
				record[5][0][0] = 1;
				record[5][0][1] = 1;
			}
			else if (choice == "No" || choice == "no") {
				judge(score, 0, 1);
				record[5][0][0] = 0;
				record[5][0][1] = 1;
			}
			cout << "You now have " << score << " coins." << endl;
		}
		
		else {
			if (record[5][i-1][0] == 1) {
				record[5][i][1] = record[5][i-1][1];
				if (record[5][i][1]==1) {
						cout << "Your rival: Yes" << endl;
				}
				else {
						cout << "Your rival: No" << endl;
				}
				if (choice == "Yes" || choice == "yes") {
					judge(score, 1, record[5][i][1]);
				}
				else if (choice == "No" || choice == "no") {
					judge(score, 0, record[5][i][1]);
				}
				cout << "You now have " << score << " coins." << endl;
			}
			else {
				if (record[5][i-1][1]==0) {
					record[5][i][1] = 1;
					cout << "Your rival: Yes" << endl;
				}
				else {
					record[5][i][1] = 0;
					cout << "Your rival: No" << endl;
				}
				if (choice == "Yes" || choice =="yes") {
					judge(score, 1, record[5][i][1]);
				}
				else if (choice == "No" || choice == "no") {
					judge(score, 0, record[5][i][1]);
				}
				cout << "You now have " << score << " coins." << endl;
			}
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << "THE END OF ROUND" << endl;
	cout << "You now have " << score << " coins." << endl;
}

// This function calls certain opponent according to the random number generated.
// It changes the value of the dynamic variable "highscore" to store the highest score achievable. 
void call_opponent(int opponent, int &score, int record[7][5][2], int * highscore) {
	if (opponent==1) {
		girl(score, record);
		*highscore += 20;
	}
	else if (opponent==2) {
		black(score, record);
		*highscore += 0;
	}
	else if (opponent==3) {
		godfather(score, record);
		*highscore += 12;
	}
	else if (opponent==4) {
		copycat(score, record);
		*highscore += 12;
	}
	else if (opponent==5) {
		random(score, record);
		*highscore += 100;
	}
	else if (opponent==6) {
		simpleton(score, record);
		*highscore += 10;
	}
}

/*in this function, we will start the game,
and if the player wanna quit halfway,
it will return the number of rounds left*/
// This function calls opponents randomly for n times given by the variable "roundleft".
// It returns "roundleft" in the end. If roundleft > 0, we store the game status in a file as the player quit in the middle of the game. If roundleft = 0, we move to game end procedures.  
int gameplay(int& score, int record[7][5][2], int &roundleft, int *highscore) {
	cout << "Play with 5 players and you will detemine your destiny." << endl;
	srand(time(NULL));
	int opponent;
	int n = roundleft;
	
	// Now let's randomly call opponents!
	for (int j = 0; j < n; j++) {
		opponent = rand() % 6 + 1;
		call_opponent(opponent, score, record, highscore);
		roundleft -= 1;
		if (roundleft > 0) {
			cout << "Wanna quit? Type \"Yes\" else type \"No\" :";
			string c;
			cin >> c;
			if (c == "Yes" || c == "yes")
				break;
		}
	}
	return roundleft;
}

// This function evaluates the player's performance.
// It compares the player's score with the highest score achievable to give different comments. 
/*we will give an evaluation of the players' performance:
if score<40,fail;
if score>40, pass;
if score>highscore, the player is brilliant*/
void answer(int score, int* highscore) {
	cout << "----------------------------------------------" << endl;
	cout << "The end of the game, YOUNG MAN!" << endl;
	if (*highscore < 100) {
		cout << "The highest score that can be achieved by the most smart is: " << *highscore << endl;
	}
	else {
		while (*highscore > 100) {
			*highscore -= 100;
		}
		cout << "The highest score that can be achieved by the most smart is: " << *highscore <<"+"<< endl;
	}
	cout << "You now have " << score << " coins." << endl;
	if (score >= *highscore) {
		cout << "BRAVO! God cannot help but admire your wisdom." << endl;
		cout << "You are one of the smartest people ON EARTH!" << endl;
	}
	else if (score < 40) {
		cout << "You are never gonna leave this ark of crime. HAHAHAHAHAH..." << endl;
	}
	else {
		cout << "You are so lucky to get rid of that ark. Wish you life out there also lucky!" << endl;
	}
	cout << "----------------------------------------------" << endl;
}

int main() {
	string name;
	//We use players' name to create file to store their game status
	cout << "The young, What's your name: ";
	cin >> name;
	string fname = name + ".txt";
	

	print_background();
	int record[7][5][2];
	//use this 3-dimension array to store the record of the players' choices
	int score = 0;
	//use this item to calculate players' score
	int roundleft = 0;
	// use this item to record how many rounds are left
	int* highscore = new int(0);
	// use this dynamic management to record the highest score which is flexible and complicated

	//by opening the file created by name to judge whether it is a new player
	ifstream fin(fname.c_str());
	if (fin.fail()) {
		/*if failing to open the file, which means the game is new to the player,
		we will provide the player with the trial part to let them get familiar with the rule*/
		roundleft = 5;
		string start_game;
		bool play = false;
		trial();//to call the trial part
		while (!play) {
			cout << "Type \"Yes\" if you would like to proceed (you can try to type \"No\" if you want to quit):";
			//to let the player know the game truly starts from here.

			cin >> start_game;
			if (start_game == "Yes" || start_game == "yes") {
				play = true;
				roundleft = gameplay(score, record, roundleft, highscore);
			}
			if (start_game == "No" || start_game == "no") {
				cout << "If you don't play the game, you will be taken for human trials right away.  Think again!" << endl;
			}
			if (start_game != "Yes" && start_game != "No" && start_game != "yes" && start_game != "no") {
				cout << "Invalid Choice!" << endl;
			}
		}
	}
	/*if there is a file about the player, 
	we will skip the tiral part,
	and ask the play whether they would like to continue or not*/
	else {
		fin >> roundleft >> score >> *highscore;
		if (roundleft == 0) {
			score = 0;
			*highscore = 0;
			roundleft = 5;
			roundleft = gameplay(score, record, roundleft, highscore);
		}
		else {
			cout << "----------------------------------------------" << endl;

			fin.close();
			cout << "Wanna to continue your game of last time?" << endl;
			cout << "Type \"Yes\" if you would like to continue else type \"No\" :";
			string c;
			cin >> c;
			/*if they wanna continue, then contiue
			if they don't wanna continue, then we will start a new game for them*/
			if (c == "Yes" || c == "yes")
				roundleft = gameplay(score, record, roundleft, highscore);
			else {
				score = 0;
				*highscore = 0;
				roundleft = 5;
				roundleft = gameplay(score, record, roundleft, highscore);
			}
		}
	}
	/*when a play quit halfway, 
	we will store the record in a file named after the player's name
	so that he/she can continue it after typing their name*/
	if (roundleft > 0) {
		ofstream fout;
		fout.open(fname.c_str());

		if (fout.fail()) {
			cout << "Error in file opening!" << endl;
			exit(1);
		}

		fout << roundleft << " " << score << " "
			<< *highscore << endl;
		fout.close();
		cout << "Your game record has been stored."<<endl;
		cout << " You can type your name next time to continue your game." << endl;
		cout << "Thank you for playing our game!" << endl;
		exit(0);
	}

	/*when a whole 5 rounds are over, we will store the record in the file named after their name*/
	else {
		ofstream fout;
		fout.open(fname.c_str());

		if (fout.fail()) {
			cout << "Error in file opening!" << endl;
			exit(1);
		}

		fout << roundleft << " " << score << " "
			<< *highscore << endl;
		fout.close();
		answer(score, highscore);
	}

	/*if the player want to play again, we will provide with infinte times to play it again*/
	string playagain;
	cout << "Wanna play again to get the highest score human can get and be the smartest person?" << endl;
	cout << "Type \"Yes\" if you would like to continure else type \"No\" :";
	cin >> playagain;

	while (playagain == "Yes" || playagain == "yes") {
		score = 0;
		*highscore = 0;
		roundleft = 5;
		roundleft = gameplay(score, record, roundleft, highscore);

		if (roundleft > 0) {
			ofstream fout;
			fout.open(fname.c_str());

			if (fout.fail()) {
				cout << "Error in file opening!" << endl;
				exit(1);
			}

			fout << roundleft << " " << score << " "
				<< *highscore << endl;
			fout.close();
			cout << "Your game record has been stored.";
			cout << " You can type your name next time to continue your game." << endl;
			exit(0);
		}

		else {
			answer(score, highscore);
		}
		cout << "Wanna play again to get the highest score human can get and be the smartest person?" << endl;
		cout << "Type \"Yes\" if you would like to continue else type \"No\" :";
		cin >> playagain;
		
	}

	//finally clear the dynamic memory and end the game.
	delete highscore;
	cout << "Thank you for playing our game." << endl;
	cout << "THE END" << endl;

	return 0;
}
