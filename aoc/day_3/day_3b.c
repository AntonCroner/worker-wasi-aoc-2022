#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int badge(char* elf_1, int n_1, char* elf_2, int n_2, char* elf_3, int n_3) {
	int result = 0;
	int priority = 0;
	char items[256];
	int itemCounter = 0;
	char item = 'U';
	char* test;
	bool found = false;
	for (int i = 0; i<n_1; i++){
		for (int j = 0; j<n_2; j++) {
	 		if (elf_1[i] == elf_2[j]) {
				items[itemCounter] = elf_1[i];
				itemCounter++;
			}
		}
	}
	for (int i = 0; i<itemCounter; i++){
		for (int k = 0; k<n_3; k++) {
			if (!found) {
				if (items[i] == elf_3[k]) {
					item = items[i];
					found = true;
					if (islower(item)) {
						result = (int)item - 96;
					}
					else {
						result = (int)item - 38;
					}
				}
			}
		}
	}
	return result; 
}

int main(int argc, char **argv) {
	int result = 0;
	int counter = 1;
	char line[256];
	char* bag_1;
	int n_1 = 0;
	char* bag_2;
	int n_2 = 0;
	char* bag_3;
	int n_3 = 0;

	while (fgets(line, 256, stdin) != NULL) {
		if (counter == 1) {
			n_1 = strlen(line) - 1;
			bag_1 = malloc(n_1*sizeof(char));
			for (int i = 0; i<n_1; i++) {
				bag_1[i] = line[i];
			}
			counter++;	
		}
		else if (counter == 2) {
			n_2 = strlen(line) - 1;
			bag_2 = malloc(n_2*sizeof(char));
			for (int i = 0; i<n_2; i++) {
				bag_2[i] = line[i];
			}
			counter++;	
		}
		else if (counter == 3) {
			n_3 = strlen(line) - 1;
			bag_3 = malloc(n_3*sizeof(char));
			for (int i = 0; i<n_3; i++) {
				bag_3[i] = line[i];
			}
			result += badge(bag_1, n_1, bag_2, n_2, bag_3, n_3);
			free(bag_1);
			free(bag_2);
			free(bag_3);
			counter = 1;
		}
	}
	printf("%d\n", result);
	return EXIT_SUCCESS;
}
