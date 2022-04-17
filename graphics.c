#include "graphics.h"

Window newwin(uint16_t height, uint16_t width, uint16_t y_beg, uint16_t x_beg){

	Window win  = {
		.win_buff = (char*) malloc(height * width),
		.height = height,
		.width = width,
		.y_beg = y_beg,
		.x_beg = x_beg,
		.curs = 0
	};

	return win;
}

void wrefresh(Window *win){

	while(!in_backporch());

	uint16_t y_end = win->y_beg + win->height;
	uint16_t x_end = win->x_beg + win->width;
	uint16_t cnt = 0;

	for(uint16_t i = win->y_beg; i < y_end; i++){
	
		for(uint16_t j = win->x_beg; j < x_end; j++){

			vga_buff[i][j] = win->win_buff[cnt++];
		}
	}
}

void wmove(Window *win, uint16_t y, uint16_t x){

	if(y < win->height && x < win->width){
		win->curs = y * win->width + x;
	}

}

void wwrite_pixel(Window *win, enum Colors color){

	win->win_buff[win->curs++] = color;
	
	if(win->curs == win->width * win->height){
		win->curs = 0;
	}

}
	
void box(Window *win, uint8_t color, uint8_t thickness){

	uint16_t thresh = thickness * win->width;
	
	//upper border
	
	for(uint16_t i = 0; i < thresh; i++)
		win->win_buff[i] = color;

	thresh = win->width * win->height;

	//lower border
	
	for(uint16_t i = thresh - thickness * win->width; i < thresh; i++)
		win->win_buff[i] = color;

	thresh = (win->height - thickness) * win->width;

	//left border
	
	for(uint16_t j = 0; j < thickness; j++)
		for(uint16_t i = win->width * thickness; i < thresh; i += win->width)
			win->win_buff[i + j] = color;

	//right border
	for(uint16_t j = win->width-thickness; j < win->width; j++)
                for(uint16_t i = win->width * thickness; i < thresh; i += win->width)
                       win->win_buff[i+j] = color;
}

void wgetmaxyx(Window *win, uint16_t *y_max, uint16_t* x_max){

	if(y_max) 
		*y_max = win->height + win->y_beg - 1;

	if(x_max)
		*x_max = win->width + win->x_beg - 1;
}
