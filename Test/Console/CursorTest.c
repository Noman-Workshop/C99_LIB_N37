/**
# Created By: anonyman637
# Created On: 1/15/19; 10:13 AM
*/

#include <stdio.h>
#include <Console/ctrlFunc.h>
#include <unistd.h>


void flushNSleep(unsigned int waitTime) {
	fflush(stdout);
	sleep(waitTime);
}

void printScale(int length, int scale) {
	int i, j;
	for (i = 0; i < (length < 10 ? 1: length / 10); i++) {
		printf("|");
		for (j = 1; j < (length < 10 ? length: scale); j++) {
			printf("%d", j);
		}
	}

	printf("\n");
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcomment"

int main(int argc, char *argv[]) {
	int i;

#ifdef WINDOWS
	EnableVTMode();
#endif

	/* Test: BS */
/*
	printf("This is a test TEXT");
	printf(SIMD(1));
	for (i = 0; i < 10; i++) {
		printf(BS);
		flushNSleep(1);
	}
	printf("After Execution of function\n");
/**/

	/* Test: CR */
/*
	printf("This is a test TEXT\n");
	printf(SIMD(1));
	for (i = 0; i <= 10; i++) {
		printf(CR);
		flushNSleep(2);
		printf("Loading %d0%%", i);
		flushNSleep(2);
	}
	printf("\nAfter Execution of function\n");
/**/

	/* Test: FF */
/*
	printf("First TEXT");
	flushNSleep(3);
	printf(FF);
	flushNSleep(3);

	printf("\f");
	flushNSleep(3);

	printf("Second TEXT");
	flushNSleep(3);
	printf(FF);
	flushNSleep(3);

	printf("Third TEXT");
	flushNSleep(3);
	printf(FF);
	flushNSleep(2);

	printf("After Execution of function\n");
/**/

	/* Test: HPA */
/*
	printf("Test TEXT");
	flushNSleep(2);
	
	printf(HPA(18));
	flushNSleep(2);

	printf("x pos should be 18");
	flushNSleep(2);

	printf(_HPA_);
	flushNSleep(2);

	printf("Default HPA");
	flushNSleep(2);

	printf(HPA(1000));
	flushNSleep(2);
	printf("After moving to position 1000");
	flushNSleep(2);

	printf(HPA(10));
	flushNSleep(2);
	printf("x pos should be 10, but on which line");

	printf("Thank You\n");
/**/

	/* Test: HPB, HPR */
/**/
	printf("This might not be a very long text.");
	flushNSleep(2);
	printf(HPB(8));
	flushNSleep(2);
	printf("8 chars back");
	flushNSleep(2);
	printf(HPR(10));
	printf("10 chars forward");
	flushNSleep(2);

	printf("Thank You\n");
/**/

	/* Test: HT */
/*
	printScale(170, 8);
	for (i = 0; i <= 15; i++) {
		printf(HT);
		printf("T");
	}

	printf("\n0123456");
	printf(HT);
	printf("T");
	printf("\nThis is a long text, lets see where next tab stop is?");
	printf(HT);
	printf("T");
	printf(" So it moves to next multiple of 8" HT "T");
	printf("\nTest Complete\n");
/**/

	/* Test: HTJ */
/**/


/**/

	/* Test: HTS */
/*
	printScale(120, 5);
	printf(SM("18"));
	for (i = 5; i < 60; i += 5) {
		printf(HPA(i));
		printf(HTS "_");
		flushNSleep(1);
	}

	printf(_HPA_);
	flushNSleep(10);

	for (i = 1; i < 10; i++) {
		printf(HT "T");
		flushNSleep(2);
	}

	printScale(120, 8);
	for (i = 1; i < 10; i++) {
		printf(HT "T");
		flushNSleep(2);
	}

	printf("\nTest Complete\n");

/**/
	return 0;

}

#pragma GCC diagnostic pop


