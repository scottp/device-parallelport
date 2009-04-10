#include <stdlib.h>
#include <stdio.h>
#include <asm/unistd.h>
#include <asm/io.h>

int main() {

	printf("Getting ioperm for 0x378\n");

	if (ioperm(0x378, 3, 1)) {
		printf("Failed to get ioperm\n");
		exit (1);
	}

	printf("Setting up rellays\n");
	outb(0, 0x378);
	outb(11, 0x37a);
	outb(10, 0x37a);

	printf("Turning OFF rellay\n");
	
	exit (0);
}
