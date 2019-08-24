/**
# Created By: Noman^Alien#0637 
# Created On: 7/31/2019; 8:56 AM
*/

#include <Console/Buffer.h>

int main() {
	CBuffer *cBuffer = cbuffer_init("main", 2, 2, 0, 0, 4, 3, 1, 0, NULL);
	cbuffer_write(cBuffer, (cbuffer_handle, "%d2345", 1));
	cbuffer_write(cBuffer, (cbuffer_handle, "%d789abcdef", 6));
	cbuffer_write(cBuffer, (cbuffer_handle, "jkl"));
	
	cbuffer_write(cBuffer, (cbuffer_handle, "tuvwxyz0-=//llp"));
//	cbuffer_write_exp(cBuffer, "%d23456789abc", 1);
//	cbuffer_renderCommand(cBuffer, "scroll down 1");
//	cbuffer_renderCommand(cBuffer, "scroll down 1");
//	cbuffer_write(cBuffer, (cbuffer_handle, "789ABC"));
//	cbuffer_write(cBuffer, (cbuffer_handle, "1234567891234567"));
	printf("%s, %d\n", cBuffer->buffer[0], (int) strlen(cBuffer->buffer[0]));
	cbuffer_renderCommand(cBuffer, "scroll up 1000");
	cbuffer_show(cBuffer);
	return 0;
}



