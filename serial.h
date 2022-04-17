#ifndef _SERIAL_H
#define _SERIAL_H

typedef unsigned long uint32_t;
#define PARITY_ODD 0
#define PARITY_EVEN 1
#define PARITY_NONE 2

#define MODE_TX 0
#define MODE_RX 1
#define MODE_TX_RX 2

uint32_t apb1_clock;

void serial_set_baudrate(uint32_t);
void serial_word_length(char);
void serial_set_parity(uint32_t);
void serial_set_mode(uint32_t);

void serial_begin(uint32_t);
void serial_send_byt(char);
void serial_send_str(const char*);
void serial_send_word(uint32_t);
char serial_read_blocking(void);
char serial_read_byte(void);

#endif
