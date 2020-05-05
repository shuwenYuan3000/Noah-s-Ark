#ifndef JUDGE_H 
#define JUDGE_H 

void judge(int& score, int you, int npc) {
	if (you == 1 && npc == 1)
		score += 2;
	else if (you == 0 && npc == 1)
		score += 4;
	else if (you == 1 && npc == 0)
		score += 0;
	else if (you == 0 && npc == 0)
		score -= 1;
}

#endif 
