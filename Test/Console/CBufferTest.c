/**
# Created By: Noman^Alien#0637 
# Created On: 7/31/2019; 8:56 AM
*/

#include <Console/Buffer.h>

int main() {
	CBuffer *cBuffer = cbuffer_init(50, 50, 0, 0, 3, 3, 0, 1, NULL, 0, 0);
	cbuffer_sprintf(cBuffer, (cbuffer_handle, "%d23456", 1));
	cbuffer_sprintf(cBuffer, (cbuffer_handle, "789ABC"));
	cbuffer_sprintf(cBuffer, (cbuffer_handle, "1234567891234567"));
	printf("%s, %llu", cBuffer->buffer, strlen(cBuffer->buffer));
	return 0;
}



