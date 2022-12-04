#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	int result = 0;
	int size = 0;
	char item = 'U';
	int priority = 0;
	char line[256];
	bool found = false;

	while (fgets(line, 256, stdin) != NULL) {
		found = false;
		size = strlen(line) - 1;
		char compartment_1[size/2];
		char compartment_2[size/2];
		for (int i = 0; i<size/2; i++) {
			compartment_1[i] = line[i];
			compartment_2[i] = line[size/2+i];
		}
		for (int i = 0; i<size/2; i++) {
			for (int j = 0; j<size/2; j++) {
				if (!found){
					if (compartment_1[i] == compartment_2[j]) {
						item = compartment_1[i];
						found = true;
						if (islower(item)) {
							priority = (int)item - 96;
						}
						else {
							priority = (int)item - 38;
						}
						result += priority;
					}
				}
			}
		}
	}
	printf("%d\n", result);
	return EXIT_SUCCESS;
}
