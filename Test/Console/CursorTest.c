/**
# Created By: anonyman637
# Created On: 1/15/19; 10:13 AM
*/

#include <Console/ctrlFuncCodedCharSet.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int i;
	printf(SGR(1;3;46));
	for (i = 0; i <= 100; i += 10) {
		printf("Loading %d%% | ", i);
		int j;
		for (j = 0; j < 10; j++) {
			printf(SGR(41));
			printf(CUB(14));
			printf(" ");
			fflush(stdout);
			sleep(1);
			printf(SGR(1;3;46));
		}
		printf(CR);
		fflush(stdout);
	}

	printf(_SGR_);
	printf(LF "Done" LF);

	return 0;
}
