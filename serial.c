#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "uart.h"
#include "serial.h"

//USART3
//TX: PB10
//RX: PB11


void serial_set_baudrate(uint32_t baudrate){
	//This function requires APB1CLK to be defined
	
	uint32_t div = 36000000 / (16 * baudrate);

	uint32_t mantissa = (uint32_t) div;
	uint32_t fraction = (uint32_t) ((div - mantissa) * 16);

	*UART3_BRR = (mantissa << 4) | fraction;
}

void serial_word_length(char len){

	if(len == 8){
		*UART3_CR1 &= ~UART_M; //Clear M bit
	}
	else{
		*UART3_CR1 |= UART_M; //Set M bit
	}
}

void serial_set_parity(uint32_t parity){

	/*
	 * PARITY
	 * 1-PARITY_ODD
	 * 2-PARITY_EVEN
	 * 3-PARITY_NONE
	 */

	if(parity == PARITY_ODD){
		*UART3_CR1 |= UART_PCE;	//ON
		*UART3_CR1 |= UART_PS;	//ODD
	}
	else if(parity == PARITY_EVEN){
		*UART3_CR1 |= UART_PCE;	//ON
		*UART3_CR1 &= ~UART_PS;	//EVEN
	}
	else{
		*UART3_CR1 &= ~UART_PCE;
	}
}

void serial_set_mode(uint32_t mode){

	/*
	 * Modes
	 * 1- MODE_TX
	 * 2- MODE_RX
	 * 3- MODE_TX_RX
	 */

	if(mode == MODE_TX){
		*UART3_CR1 |= UART_TE;
		*UART3_CR1 &= ~UART_RE;
	}
	else if(mode == MODE_RX){
		*UART3_CR1 &= ~UART_TE;
		*UART3_CR1 |= UART_RE;
	}
	else{
		*UART3_CR1 |= UART_TE | UART_RE;
	}
}


void serial_begin(uint32_t baudrate){

	*RCC_APB1ENR |= UART3EN; 
	*RCC_APB2ENR |= IOPBEN; //GPIOB Enable

	//Configure TX pin(RB10)
	*GPIOB_CRH |= (1<<8); 
	*GPIOB_CRH &= ~(1<<9); //OUTPUT_10_MHZ
	*GPIOB_CRH &= ~(1<<10);
	*GPIOB_CRH |= (1<<11); //ALTFN_PUSHPULL

	//configure RX pin(RB11)
	*GPIOB_CRH &= ~(1<<12);
	*GPIOB_CRH &= ~(1<<13);//INPUT_MODE
	*GPIOB_CRH |= (1<<14);
	*GPIOB_CRH &= ~(1<<15);	//INPUT_FLOAT

	*UART3_CR1 |= UART_UE;
	serial_set_baudrate(baudrate);
	serial_word_length(8);
	serial_set_parity(PARITY_NONE);
	serial_set_mode(MODE_TX_RX);

}

void serial_send_byte(char byte){
	while(!(*UART3_SR & UART_TXE)); //Wait for TDR to be empty
	*UART3_DR = byte;
}

void serial_send_str(const char* str){

	while(*str){
		while(!(*UART3_SR & UART_TXE)); //Wait for TDR to be empty
		*UART3_DR = *str++;
	}
	
	while(!(*UART3_SR & UART_TC)); //Wait for last byte transmission complete
	*UART3_SR &= ~UART_TC; //Transmission Complete

}

void serial_send_word(uint32_t word){

	char word_ch[9];

	for(uint32_t i = 0; i < 8; i++){

		word_ch[7 - i] = word % 10 + '0';
		word /= 10;
	}
	word_ch[8] = 0;

	serial_send_str(word_ch);
}

char serial_read_blocking(void){

	while(!(*UART3_SR & UART_RXNE));
	return *UART3_DR;
}

char serial_read_byte(void){

	if(*UART3_SR & UART_RXNE){
		return *UART3_DR;
	}
	
	return -1;
}
