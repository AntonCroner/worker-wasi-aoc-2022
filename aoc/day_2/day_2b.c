#include <stdlib.h>
#include <stdio.h>
//A rock 1
//B paper 2
//C scissor 3
//X lose 
//Y draw 
//Z win

int win(char opponent) {
	int result = 0;
	if (opponent == 'A') {
		result = 2;
	}
	if (opponent == 'B') {
		result = 3;
	}
	if (opponent == 'C') {
		result = 1;
	}
	return result + 6;
}
int draw(char opponent) {
	int result = 0;
	if (opponent == 'A') {
		result = 1;
	}
	if (opponent == 'B') {
		result = 2;
	}
	if (opponent == 'C') {
		result = 3;
	}
	return result + 3;
}
int lose(char opponent) {
	int result = 0;
	if (opponent == 'A') {
		result = 3;
	}
	if (opponent == 'B') {
		result = 1;
	}
	if (opponent == 'C') {
		result = 2;
	}
	return result;
}

int rock_paper_scissor(char opponent, char outcome) {
	int result = 0;
	char tool = 'U';
	if (outcome == 'Z') {
		result = win(opponent);
	}
	if (outcome == 'Y') {
		result = draw(opponent);
	}
	if (outcome == 'X') {
		result = lose(opponent);
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
