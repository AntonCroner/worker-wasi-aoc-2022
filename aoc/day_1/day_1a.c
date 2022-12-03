#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
	int result;
	int size = 0;
	int calories = 0;
	int mostCalories = 0;
	int food = 0;
	char line[256];
	while (fgets(line, 256, stdin) != NULL) {
		if(*line == '\n'){
		 	mostCalories = calories > mostCalories ? calories : mostCalories;
		 	calories = 0;
		 }
		 else {
			food = atoi(line);
		 	calories += food;
		 }
	}
	printf("%d\n", mostCalories);
	result = EXIT_SUCCESS;
	return result;
}
