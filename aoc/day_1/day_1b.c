#include <stdlib.h>
#include <stdio.h>

void update(int* mostCalories, int calories) {
	int temp1;
	int temp2;
	if (calories >= mostCalories[0]) {
		temp1 = mostCalories[0];
		temp2 = mostCalories[1];
		mostCalories[1] = temp1;
		mostCalories[2] = temp2;
		mostCalories[0] = calories;
	}
	else if (calories >= mostCalories[1]) {
		temp2 = mostCalories[1];
		mostCalories[1] = calories;
		mostCalories[2] = temp2;

	}
	else if (calories > mostCalories[2]) {
		mostCalories[2] = calories;
	}
	else {
		return;
	}
}


int main(int argc, char **argv) {
	int result;
	int size = 0;
	int calories = 0;
	int mostCalories[3] = {0, 0, 0};
	int food = 0;
	char line[256];

	while (fgets(line, 256, stdin) != NULL) {
		if(*line == '\n'){
			update(mostCalories, calories);
		 	calories = 0;
		 }
		 else {
			food = atoi(line);
		 	calories += food;
		 }
	}
	update(mostCalories, calories);
	calories = mostCalories[0] + mostCalories[1] + mostCalories[2];
	printf("%d\n", calories);
	result = EXIT_SUCCESS;
	return result;
}
