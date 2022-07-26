/* add-nbo.cpp */
#include "add-nbo.h"


uint32_t my_ntoh(uint32_t n){
	uint32_t b0, b1, b2, b3;

	b0 = (n & 0xff000000) >> 24;
	b1 = (n & 0x00ff0000) >> 8;
	b2 = (n & 0x0000ff00) << 8;
	b3 = (n & 0x000000ff) << 24;

	uint32_t res = b0 | b1 | b2 | b3;

	return res;
}

	
