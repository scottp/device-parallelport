#include <stdlib.h>
#include <stdio.h>
#include <asm/unistd.h>
#include <asm/io.h>

int main(int argc, char * argv[]) {
	int byte;

	if (argc != 2) {
		printf("Must supply a number\n");
		exit(1);
	}

	byte = atoi(argv[1]);
	if (byte < 0 || byte > 255) {
		printf("Byte must be 0 to 255\n");
		exit(1);
	}

	if (ioperm(0x378, 3, 1)) {
		printf("Failed to get ioperm\n");
		exit (1);
	}

	printf("Setting up rellays\n");

	// Byte from input (0-255)
	outb(byte, 0x378);

	// Flash
	outb(11, 0x378 + 2);
	outb(10, 0x378 + 2);

	exit (0);
}
