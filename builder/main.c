#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int main(int argc, char **argv) {

	char command[300];

	if (argc < 2) {
		char file;
		printf("Assembler file name: ");
		scanf("%s", &file);

		int libc;
		char **libs;
		printf("How many libs you want to plug? : ");
		scanf("%d", &libc);

		if (libc != 0) {
			int i;

			libs = malloc(libc * sizeof(*libs));

			for (i = 0; i < libc; i++)
			{
				libs[i] = malloc(30 * sizeof(char));
			}

			i = 0;
			while (i < libc) {
				printf("%d lib : ", i + 1);
				scanf("%s", libs[i]);
				i++;
			}

			sprintf(command, "ml64.exe %s /link /ENTRY:Main /SUBSYSTEM:WINDOWS", file);
			for (i = 0; i < libc; i++) {
				char part[50];
				sprintf(part, "/DEFAULTLIB: %s", libs[i]);
				strcat(command, part);
			}

			for (i = 0; i < libc; i++) {
				free(libs[i]);
			}
			free(libs);
		}
		system(command);
		return 0;
	}
	return 0;
}
