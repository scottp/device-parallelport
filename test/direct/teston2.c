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
	outb(4, 0x378);
	outb(11, 0x378 + 2);
	outb(10, 0x378 + 2);

	printf("Turning ON rellay\n");
	
	exit (0);
}
