#include <stdlib.h>
#include <stdio.h>
//A X rock
//B Y paper
//C Z scissor

char outcome_f(char opponent, char me) {
	char result = 'U';
	if (opponent == 'A') {
		if (me == 'X') {
			result = 'D';
		}
		if (me == 'Y') {
			result = 'W';
		}
		if (me == 'Z') {
			result = 'L';
		}	
	}
	if (opponent == 'B') {
		if (me == 'X') {
			result = 'L';
		}
		if (me == 'Y') {
			result = 'D';
		}
		if (me == 'Z') {
			result = 'W';
		}
	}
	if (opponent == 'C') {
		if (me == 'X') {
			result = 'W';
		}
		if (me == 'Y') {
			result = 'L';
		}
		if (me == 'Z') {
			result = 'D';
		}
	}
	return result;
}

int rock_paper_scissor(char opponent, char me) {
	int result = 0;
	int win = 6;
	int draw = 3;
	int loss = 0;
	int bonus = 0;
	if (me == 'X') {
		bonus = 1;
	}
	if (me == 'Y') {
		bonus = 2;
	}
	if (me == 'Z') {
		bonus = 3;
	}
	char outcome = outcome_f(opponent, me); 
	if (outcome == 'W') {
		result = win + bonus;
	}
	if (outcome == 'D') {
		result = draw + bonus;
	}
	if (outcome == 'L') {
		result = loss + bonus;
	}
	return result;
}

int main(int argc, char **argv) {
	int result = 0;
	int size = 0;
	char line[10];
	while (fgets(line, 10, stdin) != NULL) {
		result += rock_paper_scissor(line[0], line[2]);
	}
	printf("%d\n", result);
	return EXIT_SUCCESS;
}
