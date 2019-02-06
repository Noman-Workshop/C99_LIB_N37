/**
# Created By: anonyman637
# Created On: 2/3/19; 8:10 PM
*/

#ifndef CONSOLE_CTRL_FUNC_H
#define CONSOLE_CTRL_FUNC_H

#include <stdInclude.h>
#include "ctrlFuncCodedCharSet.h"

#ifdef WINDOWS


int EnableVTMode();


#endif


/* ============================= Cursor Control Functions ============================= */

void moveTo(int px, int py);


void _moveTo_();


void moveToX(int px);


void _moveToX_();


void moveToY(int py);


void _moveToY_();


void moveBy_CharHorz(int n);


void moveBy_CharVert(int n);


void moveBy_Line(int n);


void moveBy_Tab(int n);


typedef enum {
	chr,
	line,
	allChr,
	allLine,
	allChrAtLine
} TabStop;


void set_TabStop(TabStop type);


void clear_TabStop(TabStop type);


#endif
