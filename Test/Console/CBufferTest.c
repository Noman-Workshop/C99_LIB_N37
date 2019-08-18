/**
# Created By: Noman^Alien#0637 
# Created On: 7/31/2019; 8:56 AM
*/

#include <Console/Buffer.h>

int main() {
	CBuffer *cBuffer = cbuffer_init(2, 2, 0, 0, 3, 3, 1, 0, NULL);
	cbuffer_write(cBuffer, (cbuffer_handle, "%d23456789abc", 1));
	printf("%s, %llu\n", cBuffer->buffer[0], strlen(cBuffer->buffer[0]));
//	cbuffer_write(cBuffer, (cbuffer_handle, "789ABC"));
//	printf("%s, %llu\n", cBuffer->buffer[0], strlen(cBuffer->buffer[0]));
//	cbuffer_write(cBuffer, (cbuffer_handle, "1234567891234567"));
//	printf("%s, %llu\n", cBuffer->buffer[0], strlen(cBuffer->buffer[0]));
	
	cbuffer_show(cBuffer);
	return 0;
}



