#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <stdint.h>
#include <stdlib.h>
#include "vga.h"

enum Colors{
	COLOR_BLACK = 0X00,
	COLOR_RED = 0X11,
	COLOR_GREEN = 0X22,
	COLOR_BLUE = 0X88,
	COLOR_YELLOW = 0X33,	//RED AND GREEN
	COLOR_CYAN = 0XAA,	//GREEN AND BLUE
	COLOR_MAGENTA = 0X99,	//RED AND BLUE
	COLOR_WHITE = 0XFF	//RED, GREEN AND BLUE
};

typedef struct __window{
	char *win_buff;
	uint16_t height;
	uint16_t width;
	uint16_t y_beg;
	uint16_t x_beg;
	uint16_t curs;
}Window;


Window newwin(uint16_t, uint16_t, uint16_t, uint16_t);
void wrefresh(Window*);
void wmove(Window*, uint16_t, uint16_t);
void wwrite_pixel(Window*, enum Colors);
void box(Window*, uint8_t, uint8_t);
void wgetmaxyx(Window*, uint16_t*, uint16_t*);

#endif
