#include <nds.h>
#include <stdio.h>

int main(void) {
	consoleDemoInit();
	iprintf("Hello World!");
	for (;;) {
		swiWaitForVBlank();
		scanKeys();
		int pressed = keysDown();
		if (pressed & KEY_START)
			break;
	}
}
