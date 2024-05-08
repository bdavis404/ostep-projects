/* Brandon Davis  5/2/2024
 * wgrep program ostep-projets
	link: https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-utilities
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


FILE *fp;
char *line;
char *sub;
size_t len = 0; 
ssize_t nread;

void grep(char *search_term);

int main(int argc, char *argv[]) {
	char *search_term = argv[1];
	
	if (argc == 1){
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	} else if (argc == 2) {
		fp = stdin;
		grep(search_term);
	} else {
		// point iterator to argv location of file names
		for(int i = 2; i < argc; i++) {
			if ((fp = fopen(argv[i], "r")) == NULL){
				printf("wgrep: cannot open file\n");
				exit(1);
			} else {
				grep(search_term);
			}
		}
	}

	free(line);
	fclose(fp);

	return 0;
}

void grep(char *search_term) {
	while((nread = getline(&line, &len, fp)) != -1) {
		if((sub = strstr(line, search_term)) != NULL) {
			fwrite(line, nread, 1, stdout);
		} 
	}
}

