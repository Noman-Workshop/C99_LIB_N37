/**
# Created By: Noman^Alien#0637 
# Created On: 7/31/2019; 5:19 AM
*/

#ifndef CONSOLE_BUFFER_H
#define CONSOLE_BUFFER_H

#include <stdInclude.h>

typedef struct ConsoleBuffer {
	
	// Where Buffer should be rendered in the screen
	unsigned short int *screenSize;
	unsigned short int *position;
	unsigned int cursorPos;
	
	// The Buffer Array and the no. of rows and columns in the buffer array
	unsigned int *bufferSize;
	char **buffer;
	unsigned char bufferOverflow;
	
	// Whether Scroll is Enabled or not in the Buffer container
	unsigned char scrollEnabled;
	
	// The buffer in which this buffer is contained
	struct ConsoleBuffer *containerBuffer;
	
	// The other buffers that this contains
	unsigned short int noOfContainedBuffers;
	struct ConsoleBuffer **containedBuffers;
	
	// Whether this buffer is on the top of the hierarchy
	unsigned char isMain;
	
	
} CBuffer;

/* ============================== Constructors ========================= */

/**
 * Constructs a Console Buffer with supplied parameters
 * @param screenSizeX 			Length of the display size of the buffer
 * @param screenSizeY 			Breadth of the display size of the buffer
 * @param posX					The X position of buffer relative to container
 * 								For Main Container Buffers it is always set to 0
 * @param posY					The Y position of buffer relative to container
 * 								For Main Container Buffers it is always set to 0
 * @param bufferRows 			Number of Rows in Buffer
 * 								Number of Rows and Columns determines the size of the Buffer
 * @param bufferCols			Number of Columns in Buffer
 * 								Number of Rows and Columns determines the size of the Buffer
 * @param scrollEnabled			If Enabled, the buffer can be viewed entirely with scroll,
 * 								ignoring its screen size with scroll command
 * @param isMain				Whether this buffer is the Main Buffer
 * @param containerBuffer		?
 * @param noOfContainedBuffers	Total number of buffers this contains,
 * 								The number changes automatically as you add more buffers
 * @param containedBuffers		?
 * @return 						a Console Buffer Instance
 */
CBuffer *cbuffer_init(unsigned short int screenSizeX, unsigned short int screenSizeY,
                      unsigned short int posX, unsigned short int posY,
                      unsigned int bufferRows, unsigned int bufferCols,
                      unsigned char scrollEnabled, unsigned char isMain,
                      CBuffer *containerBuffer,
                      unsigned short int noOfContainedBuffers, CBuffer **containedBuffers);


/* ============================== Writing to Buffer ========================= */

extern char *_tempCBufferPntr;

// fixme: find a better name for the following variable
extern unsigned int _tempStringLen;

/**
 *	Provides a Handle to Check Length, Manipulate Buffer and Write new data
 */
#define cbuffer_handle _tempCBufferPntr, _tempStringLen

unsigned int _cbuffer_manageHandle(CBuffer *cBuffer, int strLength);

void _cbuffer_resetHandle(CBuffer *cBuffer);

/**
 *	Stores the formatted data into Console Buffer
 *	@param cBuffer The buffer to write onto
 *	@param args The formatted arguments
 */
#define cbuffer_write(cBuffer, args) _cbuffer_manageHandle(cBuffer, snprintf args); snprintf args; _cbuffer_resetHandle(cBuffer)

/* ============================== Printing/Rendering Buffer ========================= */


/* ============================== Utility Functions ========================= */
/**
 *
 * @param cBuffer 	The console buffer to operate on
 * @return			The max number of characters the console Buffer can hold with null '\0'
 */
unsigned int cbuffer_maxLen(CBuffer *cBuffer);

#endif
