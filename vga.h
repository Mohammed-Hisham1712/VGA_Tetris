#ifndef _VGA_H
#define _VGA_H

#define H_PIXELS	206
#define H_COLS		103
#define VISIBLE_COLS	100
#define V_LINES		150
#define VGA_BUFF_SIZE	(H_COLS * V_LINES)


extern char vga_buff[V_LINES][H_COLS];
void initscr(void);
char in_backporch(void);
void test_colors(void);

#endif
