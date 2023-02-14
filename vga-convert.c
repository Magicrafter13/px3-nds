#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// Default VGA palette
/*uint8_t R_LUT[256] = {
		0,   0,   0,   0, 170, 170, 170, 170,  85,  85,  85,  85, 255, 255, 255, 255,
		0,  20,  32,  44,  56,  69,  81,  97, 113, 130, 146, 162, 182, 203, 227, 255,
		0,  65, 125, 190, 255, 255, 255, 255, 255, 255, 255, 255, 255, 190, 125,  65,
		0,   0,   0,   0,   0,   0,   0,   0, 125, 158, 190, 223, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 223, 190, 158, 125, 125, 125, 125, 125, 125, 125, 125,
	182, 199, 219, 235, 255, 255, 255, 255, 255, 255, 255, 255, 255, 235, 219, 199,
	182, 182, 182, 182, 182, 182, 182, 182,   0,  28,  56,  85, 113, 113, 113, 113,
	113, 113, 113, 113, 113,  85,  56,  28,   0,   0,   0,   0,   0,   0,   0,   0,
	 56,  69,  85,  97, 113, 113, 113, 113, 113, 113, 113, 113, 113,  97,  85,  69,
	 56,  56,  56,  56,  56,  56,  56,  56,  81,  89,  97, 105, 113, 113, 113, 113,
	113, 113, 113, 113, 113, 105,  97,  89,  81,  81,  81,  81,  81,  81,  81,  81,
		0,  16,  32,  48,  65,  65,  65,  65,  65,  65,  65,  65,  65,  48,  32,  16,
		0,   0,   0,   0,   0,   0,   0,   0,  32,  40,  48,  56,  65,  65,  65,  65,
	 65,  65,  65,  65,  65,  56,  48,  40,  32,  32,  32,  32,  32,  32,  32,  32,
	 44,  48,  52,  60,  65,  65,  65,  65,  65,  65,  65,  65,  65,  60,  52,  48,
	 44,  44,  44,  44,  44,  44,  44,  44,   0,   0,   0,   0,   0,   0,   0,   0
};

uint8_t G_LUT[256] = {
		0,   0, 170, 170,   0,   0,  85, 170,  85,  85, 255, 255,  85,  85, 255, 255,
		0,  20,  32,  44,  56,  69,  81,  97, 113, 130, 146, 162, 182, 203, 227, 255,
		0,   0,   0,   0,   0,   0,   0,   0,   0,  65, 125, 190, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 190, 125,  65, 125, 125, 125, 125, 125, 125, 125, 125,
	125, 158, 190, 223, 255, 255, 255, 255, 255, 255, 255, 255, 255, 223, 190, 158,
	182, 182, 182, 182, 182, 182, 182, 182, 182, 199, 219, 235, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 235, 219, 199,   0,   0,   0,   0,   0,   0,   0,   0,
		0,  28,  56,  85, 113, 113, 113, 113, 113, 113, 113, 113, 113,  85,  56,  28,
	 56,  56,  56,  56,  56,  56,  56,  56,  56,  69,  85,  97, 113, 113, 113, 113,
	113, 113, 113, 113, 113,  97,  85,  69,  81,  81,  81,  81,  81,  81,  81,  81,
	 81,  89,  97, 105, 113, 113, 113, 113, 113, 113, 113, 113, 113, 105,  97,  89,
		0,   0,   0,   0,   0,   0,   0,   0,   0,  16,  32,  48,  65,  65,  65,  65,
	 65,  65,  65,  65,  65,  48,  32,  16,  32,  32,  32,  32,  32,  32,  32,  32,
	 32,  40,  48,  56,  65,  65,  65,  65,  65,  65,  65,  65,  65,  56,  48,  40,
	 44,  44,  44,  44,  44,  44,  44,  44,  44,  48,  52,  60,  65,  65,  65,  65,
	 65,  65,  65,  65,  65,  60,  52,  48,   0,   0,   0,   0,   0,   0,   0,   0
};

uint8_t B_LUT[256] = {
		0, 170,   0, 170,   0, 170,   0, 170,  85, 255,  85, 255,  85, 255,  85, 255,
		0,  20,  32,  44,  56,  69,  81,  97, 113, 130, 146, 162, 182, 203, 227, 255,
	255, 255, 255, 255, 255, 190, 125,  65,   0,   0,   0,   0,   0,   0,   0,   0,
		0,  65, 125, 190, 255, 255, 255, 255, 255, 255, 255, 255, 255, 223, 190, 158,
	125, 125, 125, 125, 125, 125, 125, 125, 125, 158, 190, 223, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 235, 219, 199, 182, 182, 182, 182, 182, 182, 182, 182,
	182, 199, 219, 235, 255, 255, 255, 255, 113, 113, 113, 113, 113,  85,  56,  28,
		0,   0,   0,   0,   0,   0,   0,   0,   0,  28,  56,  85, 113, 113, 113, 113,
	113, 113, 113, 113, 113,  97,  85,  69,  56,  56,  56,  56,  56,  56,  56,  56,
	 56,  69,  85,  97, 113, 113, 113, 113, 113, 113, 113, 113, 113, 105,  97,  89,
	 81,  81,  81,  81,  81,  81,  81,  81,  81,  89,  97, 105, 113, 113, 113, 113,
	 65,  65,  65,  65,  65,  48,  32,  16,   0,   0,   0,   0,   0,   0,   0,   0,
		0,  16,  32,  48,  65,  65,  65,  65,  65,  65,  65,  65,  65,  56,  48,  40,
	 32,  32,  32,  32,  32,  32,  32,  32,  32,  40,  48,  56,  65,  65,  65,  65,
	 65,  65,  65,  65,  65,  60,  52,  48,  44,  44,  44,  44,  44,  44,  44,  44,
	 44,  48,  52,  60,  65,  65,  65,  65,   0,   0,   0,   0,   0,   0,   0,   0
};*/

// Planet X3 Palette (from src/video/palsluts.s)
uint8_t R_LUT[256] = {
		0, 170, 170,   0,   0,   0, 170, 170,  85, 255, 255,  85,  85,  85,   0, 255,
	 79, 144, 207, 208, 218, 218, 220, 220, 217, 219, 236, 246, 254, 251, 251, 255,
	 82, 122, 147, 178, 201, 244, 248, 252, 255, 255, 254, 253, 252, 255, 255, 255,
	 52,  79,  89, 141, 185, 202, 210, 220, 244, 203, 179, 145, 134, 120,  98,  75,
	 39,  67,  98, 126, 157, 185, 202, 210, 220, 206, 189, 155, 135,  93,  54,  22,
	 91, 113, 151, 172, 176, 138,  99,  87,  68,  72,  75,  91, 142, 182, 181, 128,
	255, 255, 255, 255, 171, 130, 130, 130, 130, 130, 130, 130, 124, 116, 107,  97,
	226, 205, 205, 205, 121,  80,  80,  56,  57,  59,  67,  75,  72,  66,  57,  47,
	160, 160, 160, 160,  87,  58,  58,  44,  47,  49,  52,  56,  53,  48,  41,  34,
	117, 117, 117, 117,  63,  42,  42,  47,  46,  46,  45,  44,  40,  36,  31,  24,
	 87,  87,  87,  87,  47,  31,  31,  91,  81,  75,  67,  61,  51,  44,  36,  21,
	 39,  51,  76, 100, 137, 160, 178, 196, 209, 231, 231, 247, 249, 232, 234, 252,
	 18,  19,  19,  25,  58,  91,  97, 134, 150, 164, 174, 180, 183, 182, 183, 191,
	 11,  15,  20,  21,  22,  25,  20,  50,  58,  58,  59, 104, 182, 225, 232, 232,
	 17,  17,  16,  15,  14,  13,  14,  14,  17,  16,  16,  17,  20,  21,  36,  53,
	 31,  54,  79, 102, 127, 149, 168, 181, 197, 191, 182, 166, 154, 135, 117,  92
};

uint8_t G_LUT[256] = {
		0,   0,  85, 170, 170,   0,   0, 170,  85,  85, 255, 255, 255,  85,   0, 255,
		0,   0,  35,  83, 101, 141, 185, 216, 223, 226, 243, 251, 255, 253, 255, 226,
	 48,  66,  81, 107, 131, 141, 143, 146, 155, 175, 199, 217, 231, 188, 155, 122,
	 52,  30,  58,  78,  87, 109, 132, 158, 170, 148, 135, 117, 117, 110,  93,  73,
	 32,  55,  81, 104, 130, 152, 171, 184, 199, 184, 165, 146, 125,  90, 109, 110,
	 40,  55,  91, 117, 143, 166, 183, 196, 209, 223, 231, 240, 249, 230, 194, 128,
	153, 190, 223, 255, 255, 255, 255, 255, 237, 223, 206, 190, 175, 158, 137, 113,
	111, 140, 173, 205, 205, 205, 205, 227, 203, 182, 158, 140, 125, 108,  87,  63,
	 58, 101, 128, 160, 160, 160, 160, 173, 149, 131, 114, 101,  90,  78,  63,  45,
	 42,  73,  92, 117, 117, 117, 117, 115, 100,  89,  78,  70,  61,  53,  42,  30,
	 31,  54,  68,  87,  87,  87,  87,  82,  73,  68,  58,  52,  43,  37,  29,  19,
	 48,  59,  75,  85,  94,  99, 103, 106, 108, 143, 179, 184, 208, 224, 231, 241,
	 25,  27,  42,  48,  55,  50,  60,  62,  73,  93, 118, 137, 145, 167, 174, 190,
	 15,  21,  30,  34,  43,  53,  59,  75, 104, 121, 138, 159, 167, 195, 211, 224,
	 33,  37,  42,  46,  52,  60,  72,  86, 111, 134, 155, 176, 192, 204, 220, 231,
	 26,  46,  67,  87, 108, 126, 146, 163, 182, 178, 171, 161, 153, 142, 133, 117
};

uint8_t B_LUT[256] = {
		0,   0,   0,   0, 170, 170, 170, 170,  85,  85,  85,  85, 255, 255,   0, 255,
	 23,  28,  16,   7,   5,   0,   3,  41,  92, 133, 154, 185, 184, 135,  38,  33,
	 35,  40,  42,  55,  72,  54,  85, 122, 155, 175, 163, 153, 146, 177, 155, 154,
	 59,  91, 112,  78,  55,  78, 106, 137, 144, 173, 189, 213, 175, 144, 110,  79,
	 12,  20,  29,  38,  47,  55,  78, 106, 137, 151, 168, 186, 209, 249, 163,  70,
	 39,  51,  75,  85,  92, 101, 113, 127, 136, 160, 210, 211, 229, 232, 196, 128,
	130, 130, 130, 130, 130, 158, 208, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	101,  80,  80,  80,  80, 108, 158, 228, 227, 225, 218, 210, 207, 205, 205, 205,
	 58,  58,  58,  58,  58,  78, 117, 173, 171, 168, 165, 162, 160, 160, 160, 160,
	 42,  42,  42,  42,  42,  56,  85, 115, 113, 112, 110, 109, 107, 106, 104, 102,
	 31,  31,  31,  31,  31,  42,  63,  83,  77,  73,  67,  63,  55,  47,  38,  22,
	 91, 113, 151, 172, 177, 143, 113,  87,  68,  74,  75, 103, 142, 182, 201, 224,
	 43,  49,  74,  86,  76,  64,  61,  48,  47,  49,  59,  74, 103, 126, 156, 193,
	 23,  35,  55,  62,  78,  96, 123, 115, 103,  90,  77,  91, 126, 144, 168, 182,
	 58,  57,  56,  53,  51,  49,  46,  46,  54,  60,  62,  66,  70,  75,  85, 113,
	 19,  33,  48,  62,  77,  90, 112, 134, 159, 166, 174, 175, 182, 203, 182, 140
};

int main(int argc, char *argv[]) {
	if (argc != 3)
		return 2;
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	printf("P3 %d %d 255\n", width, height);
	uint8_t buffer[width];
	size_t bytes_read = 0;
	while (bytes_read = fread(buffer, sizeof (uint8_t), width, stdin), bytes_read > 0) {
		for (size_t i = 0; i < bytes_read; ++i)
			printf("%"PRIu8" %"PRIu8" %"PRIu8" ", R_LUT[buffer[i]], G_LUT[buffer[i]], B_LUT[buffer[i]]);
		putc('\n', stdout);
	}
}