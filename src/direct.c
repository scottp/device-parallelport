#include <stdlib.h>
#include <stdio.h>
#include <asm/unistd.h>
#include <asm/io.h>

int init() {
	// XXX: How much support here for locations
	// Since we are running as root what does it hurt?
	// How many bytes?
	if (ioperm(0x378, 3, 1)) {
		return (1);
	}
	return (0);
}

void set_bit(int bit, int state) {
	// XXX: inb first, then turn on bit, then output
	// bit = 0 to 23
	// state = 0 or 1
	outb(1, 0x378);
}

int get_bit(int bit) {
	// XXX: inb then just return 0/1 for bit
	// bit = 0 to 23
	outb(11, 0x378 + 2);
	outb(10, 0x378 + 2);
	return(1);
}

void set_byte(int byte, char state) {
	// byte = 0 to 2
	// state = actual state of the byte
}

char get_byte(int byte) {
	// byte = 0 to 2
}


