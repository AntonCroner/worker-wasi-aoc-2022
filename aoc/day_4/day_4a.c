#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv) {
	int result = 0;
	char line[256];
	char* elf_1;
	int elf_1_s;
	int elf_1_e;
	char* elf_2;
	int elf_2_s;
	int elf_2_e;

	while (fgets(line, 256, stdin) != NULL) {
		elf_1 = strtok(line, ",");
		elf_2 = strtok(NULL, ",");
		elf_1_s = atoi(strtok(elf_1, "-"));
		elf_1_e = atoi(strtok(NULL, "-"));
		elf_2_s = atoi(strtok(elf_2, "-"));
		elf_2_e = atoi(strtok(NULL, "-"));
		if (elf_1_s <= elf_2_s && elf_1_e >= elf_2_e) {
			result++;
		}
		else if (elf_2_s <= elf_1_s && elf_2_e >= elf_1_e) {
			result++;
		}
	}
	printf("%d\n", result);
	return EXIT_SUCCESS;
}
