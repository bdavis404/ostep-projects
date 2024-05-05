/* Brandon Davis  5/2/2024
 * wcat program ostep-projets*/


#include <stdio.h>
#include <stdlib.h>

// main
int
main(int argc, char *argv[]) {
	
	FILE *fp;
	char *s;
	char buffer[100];

	if (argc == 1) {
		exit(0);
	} else {
		for (int i = 1; i < argc; i++) {
			if ((fp = fopen(argv[i], "r")) == NULL) {
				printf("wcat: cannot open file\n");
				exit(1);
			}
			else {
				while((s = fgets(buffer, sizeof(buffer), fp)) != NULL) {
					printf("%s", buffer);
				}
				fclose(fp);
			}
		}
	}
	
	return 0;
}
