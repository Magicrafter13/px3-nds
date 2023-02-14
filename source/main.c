#include <nds.h>
#include <stdio.h>

// Images
#include "menu.h"

int main(void) {
	// Init video
	videoSetMode(MODE_5_2D);
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	consoleDemoInit();

	iprintf("Hello World!");

	int bg = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	dmaCopy(menuBitmap, bgGetGfxPtr(bg), 256 * 256);
	dmaCopy(menuPal, BG_PALETTE, 256 * 2);

	for (;;) {
		swiWaitForVBlank();
		scanKeys();
		int pressed = keysDown();
		if (pressed & KEY_START)
			break;
	}
}
