/**
# Created By: Noman^Alien#0637
# Created On: 7/31/2019; 5:19 AM
*/

#include <Console/Buffer.h>

/* ============================== Constructors ========================= */

CBuffer *cbuffer_init(unsigned short int screenSizeX,
                      unsigned short int screenSizeY, unsigned short int posX,
                      unsigned short int posY, unsigned int bufferRows,
                      unsigned int bufferCols, unsigned char scrollEnabled,
                      unsigned char isMain, CBuffer *containerBuffer,
                      unsigned short int noOfContainedBuffers,
                      CBuffer **containedBuffers) {

    CBuffer *cBuffer = (CBuffer *)malloc(sizeof(CBuffer));

    cBuffer->screenSize = calloc(2, sizeof(unsigned short int));
    cBuffer->screenSize[0] = screenSizeX;
    cBuffer->screenSize[1] = screenSizeY;

    cBuffer->position = calloc(2, sizeof(unsigned short int));

    cBuffer->bufferSize = calloc(2, sizeof(unsigned short int));
    cBuffer->bufferSize[0] = bufferRows;
    cBuffer->bufferSize[1] = bufferCols;

    cBuffer->cursorPos = 0;
    cBuffer->bufferOverflow = 0;

	cBuffer->buffer = calloc(bufferRows * bufferCols, sizeof(char));

    cBuffer->containerBuffer = containerBuffer;
    cBuffer->noOfContainedBuffers = noOfContainedBuffers;
    cBuffer->containedBuffers = containedBuffers;

    cBuffer->scrollEnabled =
        (scrollEnabled == 'N' || scrollEnabled == 0) ? 0 : 1;
    cBuffer->isMain = (isMain == 'N' || isMain == 0) ? 0 : 1;

    if (cBuffer->isMain) {
        cBuffer->position[0] = 0;
        cBuffer->position[1] = 0;
    } else {
        cBuffer->position[0] = posX;
        cBuffer->position[1] = posY;
    }

    return cBuffer;
}

/* ============================== Writing To Buffers =========================
 */

char *_tempCBufferPntr = NULL;

unsigned int _tempStringLen = 0;
/**
 * Handles Buffer 	Overwriting and Detects Buffer Overflow
 * @param cBuffer 	The Console Buffer Instance in which Data will be
 * written
 * @param strLength	Length of the new formatted data
 * @return			Total Number of Characters it will write into
 * cBuffer
 */
unsigned int _cbuffer_manageHandle(CBuffer *cBuffer, int strLength) {
    unsigned int i;

    unsigned int len = cbuffer_maxLen(cBuffer);
    unsigned int cursorPos = cBuffer->cursorPos;
    unsigned int spaceAvailable = len - cursorPos;
    unsigned int shiftLeft = strLength - spaceAvailable;
    _tempStringLen = len;

    if (spaceAvailable >= strLength) {
        /* Appending Buffer */
        _tempCBufferPntr = &(cBuffer->buffer[cursorPos]);

        cBuffer->cursorPos += strLength;
    } else if (strLength <= len) {
        /* Overwriting Buffer */
        for (i = 0; i < shiftLeft; i++) {
            cBuffer->buffer[i] = cBuffer->buffer[i + shiftLeft];
        }

        _tempCBufferPntr = &(cBuffer->buffer[len - strLength]);

        /* At the end of overwriting and new data entry the cursor will be at
         * the end too */
        cBuffer->cursorPos = len;
    } else {
        cBuffer->bufferOverflow = 1;
        _tempCBufferPntr = (char *)calloc(strLength, sizeof(char));
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
        free(cBuffer->buffer);
        /* fixme: possible memory leak */
        cBuffer->buffer =
            &(_tempCBufferPntr[_tempStringLen - cbuffer_maxLen(cBuffer) + 1]);
        cBuffer->cursorPos = cbuffer_maxLen(cBuffer);
    }
    _tempCBufferPntr = NULL;
    _tempStringLen = 0;
}
/* ============================== Buffer: Utility ========================= */

unsigned int cbuffer_maxLen(CBuffer *cBuffer) {
    return cBuffer->bufferSize[0] * cBuffer->bufferSize[1];
}
