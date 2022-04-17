#ifndef _SCREEN_H
#define _SCREEN_H

#include <stdint.h>
#include "vga.h"
#include "graphics.h"
#include "pieces.h"


#define PCOLORS	8

void show_piece(Window*, Piece*);
void rem_piece(Window*, Piece*);
int8_t show_new_piece(Window*, Piece*);
void clear_board(Window*);
void move_piece_down(Window*, Piece*);
void move_piece_right(Window*, Piece*);
void move_piece_left(Window*, Piece*);
void rotate_piece(Window*, Piece*);
int8_t try_move_down(Window*, Piece*);
int8_t try_move_right(Window*, Piece*);
int8_t try_move_left(Window*, Piece*);
int8_t try_rotate_piece(Window*, Piece*);
void rem_complete_rows(Window*);
void show_title(void);

#endif
