#ifndef _PIECES_H
#define _PIECES_H

#include <stdint.h>

#define NUM_OF_PIECES 	7
#define ROTATIONS	4
#define PROWS		12
#define PCOLS		10

typedef const char (piece_t)[PCOLS];

extern const char tetris[NUM_OF_PIECES][ROTATIONS][PROWS][PCOLS];

enum Pieces{
	PIECE_T,
	PIECE_L,
	PIECE_LM,
	PIECE_I,
	PIECE_N,
	PIECE_NM,
	PIECE_O
};

enum Rotations{
	ROTATION_NORMAL,
	ROTATION_CWISE,
	ROTATION_FLIPPED,
	ROTATION_ANTI_CWISE
};

typedef struct __piece{
	enum Pieces piece;
	enum Rotations rotation;
	uint16_t y_start;
	uint16_t x_start;
}Piece;


Piece get_rand_piece(void);

#endif
