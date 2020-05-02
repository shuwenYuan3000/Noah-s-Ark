#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
	cout << "Those who finally win more than 40 coins can get off the board." << endl;
	cout << "\"So if in all rounds we choose Cooperate then we all can get off the board!\", the smart said."<< endl;
	cout << endl;
	cout << "But for the rest of the coins other than 40, each one coin can change into a million dollars in the real world." << endl;
}

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
	if (choice == "Yes") {
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
	if (choice == "Yes") {
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

void judge(int &score, int you, int npc) {
	if (you == 1 && npc == 1)
		score += 2;
	else if (you == 0 && npc == 1)
		score += 4;
	else if (you == 1 && npc == 0)
		score += 0;
	else if (you == 0 && npc == 0)
	    score -= 1;
}

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

void call_opponent(int opponent, int &score, int record[7][5][2]) {
	if (opponent==1) {
		girl(score, record);
	}
	else if (opponent==2) {
		black(score, record);
	}
	else if (opponent==3) {
		godfather(score, record);
	}
	else if (opponent==4) {
		copycat(score, record);
	}
	else if (opponent==5) {
		random(score, record);
	}
	else if (opponent==6) {
		simpleton(score, record);
	}
}
void gameplay(int &score, int record[7][5][2]){
	cout << "Play with 5 players and you will detemine your destiny." << endl;
	srand(time(NULL));
	int opponent;
	
	// Now let's randomly call five opponents!
	for (int j=0; j<5; j++) {
		opponent = rand() % 6 + 1;                 
		call_opponent(opponent, score, record);
	}
}

int main() {
	string name;
	cout << "The young, What's your name: ";
	cin >> name;
	//读取文件的那部分还没写哦
	int score = 0;
	int record[7][5][2];
	print_background();
	string start_game;
	bool play = false;
	trial();
	while (!play) {
		cout << "Type \"Yes\" if you would like to proceed:";//可能造成一点点误解，要不加个print“no”就quit这样？
		cin >> start_game;
		if (start_game == "Yes" || start_game == "yes") {
			play = true;
			gameplay(score, record);
		}
		if (start_game == "No" || start_game == "no") {
			cout << "If you don't play the game, you will be taken for human trials right away.  Think again!" << endl;
		}
		if (start_game != "Yes" && start_game != "No" && start_game != "yes" && start_game != "no") {
			cout << "Invalid Choice!" << endl;
		}
	}
	//evaluate();
	//file的那部分还没写哦

	return 0;
}
