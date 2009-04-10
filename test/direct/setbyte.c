#include <stdlib.h>
#include <stdio.h>
#include <asm/unistd.h>
#include <asm/io.h>

int main(int argc, char * argv[]) {
	int byte;
	int offset;

	if (argc != 3) {
		printf("Must supply a number and an offset\n");
		exit(1);
	}

	byte = atoi(argv[1]);
	if (byte < 0 || byte > 255) {
		printf("Byte must be 0 to 255\n");
		exit(1);
	}

	offset = atoi(argv[2]);
	if (offset < 0 || offset > 2) {
		printf("Offset must be 0 to 2\n");
		exit(1);
	}

	if (ioperm(0x378, 3, 1)) {
		printf("Failed to get ioperm\n");
		exit (1);
	}

	// Byte from input (0-255)
	outb(byte, 0x378 + offset);

	exit (0);
}
