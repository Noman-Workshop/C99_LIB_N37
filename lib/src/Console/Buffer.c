/**
# Created By: Noman^Alien#0637
# Created On: 7/31/2019; 5:19 AM
*/

#include <Console/Buffer.h>

/* ============================== Constructors ========================= */

CBuffer *cbuffer_init(const char *name,
                      unsigned short int screenSizeX, unsigned short int screenSizeY,
                      unsigned short int posX, unsigned short int posY,
                      size_t bufferRows, size_t bufferCols,
                      unsigned char scrollEnabled,
                      unsigned short int noOfContainedBuffers, CBuffer **containedBuffers) {
	CBuffer *cBuffer = (CBuffer *) malloc(sizeof(CBuffer));
	
	cBuffer->name = calloc(strlen(name) + 1, sizeof(char));
	snprintf(cBuffer->name, strlen(name) + 1, "%s", name);
	
	cBuffer->screenSize = calloc(2, sizeof(unsigned short int));
	cBuffer->screenSize[0] = screenSizeX;
	cBuffer->screenSize[1] = screenSizeY;
	
	cBuffer->position = calloc(2, sizeof(unsigned short int));
	
	cBuffer->bufferSize = calloc(2, sizeof(unsigned short int));
	cBuffer->bufferSize[0] = bufferRows;
	cBuffer->bufferSize[1] = bufferCols;
	
	cBuffer->cursorPos = 0;
	cBuffer->bufferOverflow = 0;
	
	// Allocating a 2D array with continuous block of memory
	cBuffer->buffer = (char **) calloc(bufferRows, sizeof(char *));
	cBuffer->buffer[0] = (char *) calloc(bufferRows * bufferCols, sizeof(char));
	for (; bufferRows > 0; bufferRows--) {
		cBuffer->buffer[bufferRows] = cBuffer->buffer[0] + bufferRows * bufferCols;
	}
	
	cBuffer->noOfContainedBuffers = noOfContainedBuffers;
	cBuffer->containedBuffers = containedBuffers;
	
	cBuffer->scrollEnabled = (scrollEnabled == 'N' || scrollEnabled == 0) ? 0 : 1;
	
	cBuffer->scroll = (long *) calloc(2, sizeof(long));
	cBuffer->scroll[0] = cBuffer->scroll[1] = 0;
	
	cBuffer->position[0] = posX;
	cBuffer->position[1] = posY;
	
	return cBuffer;
}

/* ============================== Writing To Buffers ========================= */

char *_tempCBufferPntr = NULL;
size_t _tempStringLen = 0;

/**
 * Handles Buffer 	Overwriting and Detects Buffer Overflow
 * @param cBuffer 	The Console Buffer Instance in which Data will be
 * written
 * @param strLength	Length of the new formatted data
 * @return			Total Number of Characters it will write into cBuffer
 */
size_t _cbuffer_manageHandle(CBuffer *cBuffer, int strLength) {
	size_t len = cbuffer_maxLen(cBuffer) - 1;
	size_t cursorPos = cBuffer->cursorPos;
	size_t spaceAvailable = (long) (len - cursorPos) < 0 ? 0 : len - cursorPos;
	size_t shiftLeft = 0;
	_tempStringLen = len + 1;
	
	if (spaceAvailable >= strLength) {
		// Appending Buffer
		_tempCBufferPntr = cBuffer->buffer[0] + cursorPos;
		cBuffer->cursorPos += strLength;
	} else if (strLength <= len) {
		// Overwriting Buffer
		shiftLeft = strLength - spaceAvailable;
		/* Alternative Buffer Overwriting to String Copy */
//		/*
		for (size_t i = 0; i + shiftLeft < cursorPos; i++) {
			cBuffer->buffer[0][i] = cBuffer->buffer[0][i + shiftLeft];
		}
//		*/
		
		// toKnow: strcpy produces restrict warnings
//		strcpy(cBuffer->buffer[0], cBuffer->buffer[0] + shiftLeft + 1);
		_tempCBufferPntr = cBuffer->buffer[0] + (len - strLength);
		
		// At the end of overwriting and new data entry the cursor will be at the end too
		cBuffer->cursorPos = len + 1;
	} else {
		cBuffer->bufferOverflow = 1;
		_tempCBufferPntr = (char *) calloc(strLength, sizeof(char));
		_tempStringLen = strLength + 1;
	}
	
	return strLength <= len ? strLength : len;
}

/**
 * Resets the temporary buffers and handles Buffer Overflows
 * @param cBuffer Console buffer to work on
 */
void _cbuffer_resetHandle(CBuffer *cBuffer) {
	if (cBuffer->bufferOverflow) {
		size_t len = cbuffer_maxLen(cBuffer) - 1;
//		strcpy(cBuffer->buffer[0], _tempCBufferPntr + (_tempStringLen - len + 1));
		snprintf(cBuffer->buffer[0], len + 1, "%s", _tempCBufferPntr + (_tempStringLen - len - 1));
		cBuffer->cursorPos = len;
		free(_tempCBufferPntr);
	}
	_tempCBufferPntr = NULL;
	_tempStringLen = 0;
}

/* ============================== Rendering/Printing Buffer ========================= */

void _cbuffer_render(CBuffer *cBuffer) {
	if (cBuffer->noOfContainedBuffers) {
		// todo: render the container buffers here
	}
	//fixme: Better and Cross-platform solution to clear the screen
	system("@cls||clear");
	
	printf("\n");
	for (size_t bi = cBuffer->scroll[0], si = 0; si < cBuffer->screenSize[0]; bi++, si++) {
		for (size_t bj = cBuffer->scroll[1], sj = 0; sj < cBuffer->screenSize[1]; bj++, sj++) {
			// new lines and buffers messes up with your head
			if ((bj < cBuffer->bufferSize[1])) {
				printf("%c", cBuffer->buffer[bi][bj]);
				// fixme: find a simple solution to fix this newline issue
				if (cBuffer->buffer[bi][bj] == '\n') {
					// when you hit a new line ...
//					si++;
					// ... you forget where you was in the previous line
//					sj = -1;
				}
				
			} else {
				// sometimes the buffer size can be less than screen size
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

char commandStr[7][15] = {
		"focus",
		"scroll",
		"resize",
		"move",
		"remove",
		"show",
		"hide",
};

void (*action[7])(CBuffer *cBuffer, CBuffer *activeBuffer, const char **args) = {
		_cbuffer_focus,
		_cbuffer_scroll,
		_cbuffer_resize,
		_cbuffer_move,
		_cbuffer_remove,
		_cbuffer_show,
		_cbuffer_hide,
};

void cbuffer_renderCommand(CBuffer *cBuffer, const char *command) {
	/*
	 * toKnow: All the live render operations are done in the active buffer
	 * toKnow: Active Buffer can be changed by focus action
	 **/
	CBuffer *activeCBuffer = cBuffer;
	const char **commandTokens = (const char **) str_split(command, " ");
	
	for (int i = 0; i < 7; i++) {
		if (!strncmp(commandTokens[1], commandStr[i], strlen(commandTokens[1]))) {
			action[i](cBuffer, activeCBuffer, commandTokens);
			break;
		}
		
	}
	
}

void cbuffer_show(CBuffer *cBuffer) {
	char *liveRenderCommand = calloc(100, sizeof(char));
	do {
		_cbuffer_render(cBuffer);
		printf(">>> ");
		scanf("%[^\n]%*c", liveRenderCommand);
		if (!strncmp(liveRenderCommand, "quit", 4)) {
			break;
		}
		cbuffer_renderCommand(cBuffer, liveRenderCommand);
	} while (1);
}

/* ============================== Live Render Commands ========================= */

void _cbuffer_focus(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {}

void _cbuffer_scroll(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {
	short int noOfArgs;
	char scrollDir;
	long int scrollCount = 1;
	if (args != NULL) {
		noOfArgs = (short int) strtol(args[0], NULL, 10);
		scrollDir = args[2][0];
		// p for pageup and q for pagedown
		if (scrollDir == 'p' && args[2][2] == 'd') scrollDir = 'q';
		if (noOfArgs > 2) scrollCount = strtol(args[3], NULL, 10);
		
		switch (scrollDir) {
			case 'u':
				activeCBuffer->scroll[0] -= scrollCount;
				break;
			
			case 'd':
				activeCBuffer->scroll[0] += scrollCount;
				break;
			
			case 'l':
				activeCBuffer->scroll[1] -= scrollCount;
				break;
			
			case 'r':
				activeCBuffer->scroll[1] += scrollCount;
				break;
			
			case 'h':
				activeCBuffer->scroll[0] = activeCBuffer->scroll[1] = 0;
				break;
			
			case 'e':
				activeCBuffer->scroll[0] = (long) activeCBuffer->bufferSize[0] - 1;
				activeCBuffer->scroll[1] = (long) activeCBuffer->bufferSize[1] - activeCBuffer->screenSize[1];
				break;
			
			case 'p':
				activeCBuffer->scroll[0] -= activeCBuffer->screenSize[0];
				break;
			
			case 'q':
				activeCBuffer->scroll[0] += activeCBuffer->screenSize[0];
				break;
			
			default:
				break;
		}
	}
	
	// scroll can't be greater than [rows, cols] and also can't roll down to bottom past the screen
	if (activeCBuffer->scroll[0] + activeCBuffer->screenSize[0] > (long) activeCBuffer->bufferSize[0] - 1)
		activeCBuffer->scroll[0] = (long) activeCBuffer->bufferSize[0] - activeCBuffer->screenSize[0];
	if (activeCBuffer->scroll[1] + activeCBuffer->screenSize[1] > (long) activeCBuffer->bufferSize[1] - 1)
		activeCBuffer->scroll[1] = (long) activeCBuffer->bufferSize[1] - activeCBuffer->screenSize[1];
	
	// scroll can't be less than [0,0]
	if (activeCBuffer->scroll[0] < 0) activeCBuffer->scroll[0] = 0;
	if (activeCBuffer->scroll[1] < 0) activeCBuffer->scroll[1] = 0;
}


void _cbuffer_resize(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {}

void _cbuffer_move(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {}

void _cbuffer_remove(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {}

void _cbuffer_show(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {}

void _cbuffer_hide(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args) {}

/* ============================== Buffer: Utility ========================= */

size_t cbuffer_maxLen(CBuffer *cBuffer) { return cBuffer->bufferSize[0] * cBuffer->bufferSize[1]; }

/* ============================== Experimental  API ========================= */

