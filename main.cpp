#include "add-nbo.h"
#include <netinet/in.h>

void ex() {
	printf("syntax : add-nbo <file1> <file2> \n");
	printf("sample : add-nbo a.bin c.bin\n");
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		ex();
		return false;
	}

	FILE *f1, *f2;
	uint32_t n1, n2, h1, h2, res;
	

	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");
	
	fread(&n1, sizeof(uint32_t), 1, f1);
	fread(&n2, sizeof(uint32_t), 1, f2);
	
	h1 = my_ntoh(n1); 
	h2 = my_ntoh(n2);
	
	res = h1 + h2;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", h1, h1, h2, h2, res, res);

	fclose(f1);
	fclose(f2);

	return 0;
}
