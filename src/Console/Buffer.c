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
                      unsigned short int noOfContainedBuffers,
                      CBuffer **containedBuffers) {
	
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
	
	cBuffer->scroll = (size_t *) calloc(2, sizeof(size_t));
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
 * @return			Total Number of Characters it will write into
 * cBuffer
 */
size_t _cbuffer_manageHandle(CBuffer *cBuffer, int strLength) {
	/*	size_t i; */
	
	size_t len = cbuffer_maxLen(cBuffer);
	size_t cursorPos = cBuffer->cursorPos;
	size_t spaceAvailable = len - cursorPos;
	size_t shiftLeft = strLength - spaceAvailable;
	_tempStringLen = len;
	
	if (spaceAvailable >= strLength) {
		// Appending Buffer
		_tempCBufferPntr = cBuffer->buffer[0] + cursorPos;
		
		cBuffer->cursorPos += strLength;
	} else if (strLength <= len) {
		// Overwriting Buffer
		
		/* Alternative Buffer Overwriting to String Copy */
		/*
			for (i = 0; i < shiftLeft; i++) {
				cBuffer->buffer[0][i] = cBuffer->buffer[0][i + shiftLeft];
			}
		*/
		
		strcpy(cBuffer->buffer[0], cBuffer->buffer[0] + shiftLeft + 1);
		_tempCBufferPntr = cBuffer->buffer[0] + (len - strLength - 1);
		
		// At the end of overwriting and new data entry the cursor will be at the end too
		cBuffer->cursorPos = len;
	} else {
		cBuffer->bufferOverflow = 1;
		_tempCBufferPntr = (char *) calloc(strLength, sizeof(char));
		_tempStringLen = strLength;
	}
	
	return strLength <= len ? strLength : len;
}

/**
 * Resets the temporary buffers and handles Buffer Overflows
 * @param cBuffer Console buffer to work on
 */
void _cbuffer_resetHandle(CBuffer *cBuffer) {
	if (cBuffer->bufferOverflow) {
		size_t len = cbuffer_maxLen(cBuffer);
		strcpy(cBuffer->buffer[0], _tempCBufferPntr + (_tempStringLen - len + 1));
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
}

void cbuffer_show(CBuffer *cBuffer) {
	_cbuffer_render(cBuffer);
	size_t rows = (cBuffer->screenSize[0] < cBuffer->bufferSize[0]) ?
	              cBuffer->screenSize[0] : cBuffer->bufferSize[0];
	size_t cols = (cBuffer->screenSize[1] < cBuffer->bufferSize[1]) ?
	              cBuffer->screenSize[1] : cBuffer->bufferSize[1];
	
	// fixme: Will newlines \n create an awkward situation here?
	for (size_t i = cBuffer->scroll[0]; i < rows; i++) {
		for (size_t j = cBuffer->scroll[1]; j < cols; j++) {
			printf("%c", cBuffer->buffer[i][j]);
		}
		printf("\n");
	}
	
	char *liveRenderCommand = calloc(100, sizeof(char));
	printf(">>> ");
	scanf("%[^\n]%*c", liveRenderCommand);
	cbuffer_renderCommand(cBuffer, liveRenderCommand);
	if (strncmp(liveRenderCommand, "quit", 4) != 0) {
		cbuffer_show(cBuffer);
	}
}


void cbuffer_renderCommand(CBuffer *cBuffer, const char *command) {
	/* toKnow: All the live render operations are done in the active buffer
	 * toKnow: Active Buffer can be changed by focus command */
	CBuffer *activeCBuffer = cBuffer;
	const char **commandTokens = str_split(command, " ");
	
	// todo: implement string to function pointer dictionary to render commands
}

/* ============================== Live Render Commands ========================= */
void _cbuffer_scroll(CBuffer *cBuffer, const char **scrollArgs) {
	short int noOfArgs;
	char scrollDir;
	long int scrollCount = 1;
	if (scrollArgs != NULL) {
		noOfArgs = (short int) strtol(scrollArgs[0], NULL, 10);
		scrollDir = scrollArgs[2][0];
		// p for pageup and q for pagedown
		if (scrollDir == 'p' && scrollArgs[2][2] == 'd') scrollDir = 'q';
		if (noOfArgs > 2) scrollCount = strtol(scrollArgs[3], NULL, 10);
		
		switch (scrollDir) {
			case 'u':
				cBuffer->scroll[0] += -1 * scrollCount;
				break;
			
			case 'd':
				cBuffer->scroll[0] += 1 * scrollCount;
				break;
			
			case 'l':
				cBuffer->scroll[1] += -1 * scrollCount;
				break;
			
			case 'r':
				cBuffer->scroll[1] += 1 * scrollCount;
				break;
			
			case 'h':
				cBuffer->scroll[0] = cBuffer->scroll[1] = 0;
				break;
			
			case 'e':
				cBuffer->scroll[0] = cBuffer->bufferSize[0];
				cBuffer->scroll[1] = cBuffer->bufferSize[1];
				break;
			
			case 'p':
				cBuffer->scroll[0] += cBuffer->screenSize[0];
				break;
			
			case 'q':
				cBuffer->scroll[0] -= cBuffer->screenSize[0];
				break;
			
			default:
				break;
		}
	}
	// scroll can't be less than [0,0]
	if (cBuffer->scroll[0] < 0) cBuffer->scroll[0] = 0;
	if (cBuffer->scroll[1] < 0) cBuffer->scroll[1] = 0;
	
	// scroll can't be greater than [rows, cols]
	if (cBuffer->scroll[0] > cBuffer->bufferSize[0])
		cBuffer->scroll[0] = cBuffer->bufferSize[0];
	if (cBuffer->scroll[1] > cBuffer->bufferSize[1])
		cBuffer->scroll[1] = cBuffer->bufferSize[1];
	
}

/* ============================== Buffer: Utility ========================= */

size_t cbuffer_maxLen(CBuffer *cBuffer) {
	return cBuffer->bufferSize[0] * cBuffer->bufferSize[1];
}
