/**
# Created By: Noman^Alien#0637 
# Created On: 7/31/2019; 5:19 AM
*/

#ifndef CONSOLE_BUFFER_H
#define CONSOLE_BUFFER_H

#include <stdInclude.h>
#include <Util/String/string.h>
#include <Util/String/snprintf.h>

typedef struct ConsoleBuffer {
	
	// Name of the Buffer
	char *name;
	
	// Where Buffer should be rendered in the screen
	unsigned short int *screenSize;
	unsigned short int *position;
	size_t cursorPos;
	
	// The Buffer Array and the no. of rows and columns in the buffer array
	size_t *bufferSize;
	char **buffer;
	unsigned char bufferOverflow;
	
	// Whether Scroll is Enabled or not in the Buffer container
	unsigned char scrollEnabled;
	long int *scroll;
	
	// The other buffers that this contains
	unsigned short int noOfContainedBuffers;
	struct ConsoleBuffer **containedBuffers;
	
} CBuffer;

/* ============================== Constructors ========================= */

/**
 * Constructs a Console Buffer with supplied parameters
 * @param name					Name of the Buffer
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
 * @param noOfContainedBuffers	Total number of buffers this contains,
 * 								The number changes automatically as you add more buffers
 * @param containedBuffers		?
 * @return 						a Console Buffer Instance
 */
CBuffer *cbuffer_init(const char *name,
                      unsigned short int screenSizeX, unsigned short int screenSizeY,
                      unsigned short int posX, unsigned short int posY,
                      size_t bufferRows, size_t bufferCols,
                      unsigned char scrollEnabled,
                      unsigned short int noOfContainedBuffers, CBuffer **containedBuffers);


/* ============================== Writing to Buffer ========================= */

extern char *_tempCBufferPntr;

// fixme: find a better name for the following variable
extern size_t _tempStringLen;

/**
 *	Provides a Handle to Check Length, Manipulate Buffer and Write new data
 */
#define cbuffer_handle _tempCBufferPntr, _tempStringLen

size_t _cbuffer_manageHandle(CBuffer *cBuffer, int strLength);

void _cbuffer_resetHandle(CBuffer *cBuffer);

/**
 *	Stores the formatted data into Console Buffer
 *	@param cBuffer The buffer to write onto
 *	@param args The formatted arguments
 */
 // fixme: fix the new snprintf and tempStrLen issues
#define cbuffer_write(cBuffer, args) _cbuffer_manageHandle(cBuffer, snprintf args); snprintf args; _cbuffer_resetHandle(cBuffer)

/* ============================== Printing/Rendering Buffer ========================= */

void _cbuffer_render(CBuffer *cBuffer);

void cbuffer_show(CBuffer *cBuffer);

void cbuffer_renderCommand(CBuffer *cBuffer, const char *command);

/* ============================== Live Render Commands/Actions ========================= */

void _cbuffer_focus(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

/**
 * Scrolls UP, DOWN, LEFT, RIGHT, HOME, END along with PAGEUP and PAGEDOWN
 * @param cBuffer 		The Main Console Buffer
 * @param activeCBuffer	The active Console Buffer to be scrolled
 * @param args			Automated Scroll Arguments passed from Live Command Renderer	<br>
 * 						[no_of_args, scroll_command, scroll_direction, scroll_count]
 * @example
 * 						ScrollArgs: 					<br>
 * 						&#9;["2", "scroll", "up", "5"] 	<br>
 */
void _cbuffer_scroll(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

void _cbuffer_resize(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

void _cbuffer_move(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

void _cbuffer_remove(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

void _cbuffer_show(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

void _cbuffer_hide(CBuffer *cBuffer, CBuffer *activeCBuffer, const char **args);

/* ============================== Utility Functions ========================= */
/**
 *
 * @param cBuffer 	The console buffer to operate on
 * @return			The max number of characters the console Buffer can hold with null '\0'
 */
size_t cbuffer_maxLen(CBuffer *cBuffer);

#endif
/* ============================== Experimental  API ========================= */

