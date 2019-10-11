#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	unsigned long page;
	unsigned long offset;
	unsigned long address;

	int pageSize = 32;
	int pageNum = 8;
	int max = pow(pageSize*pageNum, 0.5);

	char str[max];
	printf("Enter logical memory address: ");
	gets(str);

	address = atoll(str);
	/* Page Number=quotient of address/page size and offset=remainder */

	int noOfBits = (int) pow(pageSize, 0.5);
	page = address >> noOfBits;
	if(page >= pageNum) {
		printf("Out of pages\n");
		exit(1);
	}
	/* Since page size=32B --> 5 bits holding the virtual address */
	offset = address & 0x1f;

	printf("The address %lu contains: \n", address);
	printf("page number = %lu\n", page);
	printf("offset = %lu\n", offset);

	return 0;
}