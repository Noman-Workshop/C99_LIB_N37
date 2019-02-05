/**
# Created By: anonyman637
# Created On: 2/3/19; 9:20 PM
*/

#include <Console/ctrlFunc.h>

/* ============================= Cursor Control Functions ============================= */

void moveTo(int px, int py) {
	printf(CUP(py, px));
}


void _moveTo_() {
	printf(_CUP_);
}


void moveToX(int px) {
	printf(CHA(px));
}


void _moveToX_() {
	printf(_CHA_);
}


void moveToY(int py);


void _moveToY_();


void moveBy_CharHorz(int n) {
	if (n > 0) {
		printf(CUF(n));
	} else {
		printf(CUB(-n));
	}

}


void moveBy_CharVert(int n) {
	if (n > 0) {
		printf(CUD(n));
	} else {
		printf(CUU(-n));
	}

}


void moveBy_Line(int n) {
	if (n > 0) {
		printf(CNL(n));
	} else {
		printf(CPL(-n));
	}

}


void moveBy_Tab(int n) {
	if (n > 0) {
		printf(CHT(n));
	} else {
		printf(CBT(-n));
	}

}


void set_TabStop(TabStop type) {
	switch (type) {

		case chr:
			printf(CTC("0"));

			break;
		case line:
			printf(CTC("1"));

			break;

		default:
			/* TODO: Error Handle for set_TabStop */
			break;

	}
}


void clear_TabStop(TabStop type) {
	switch (type) {

		case chr:
			printf(CTC("2"));

			break;

		case line:
			printf(CTC("3"));

			break;

		case allChr:
			printf(CTC("5"));

			break;

		case allLine:
			printf(CTC("6"));

			break;

		case allChrAtLine:
			printf(CTC("4"));

			break;

		default:

			break;

	}
}
