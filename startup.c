#include "nvic.h"

#define FLASH_BASE 0X08000000
#define SRAM_BASE 0X20000000
#define PERIPH_BASE 0X40000000

#define SRAM_SIZE 1024*20
#define SRAM_END (SRAM_BASE + SRAM_SIZE)


void _start(void);
void main(void);


typedef unsigned long uint32_t;
typedef void (*handler)(void);

__attribute__((section(".isr_vector")))
handler vector_table[ISR_VEC_SIZE] = {
	(void*)SRAM_END,
	_start,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	systick_isr,
	//Periph
	0,
	0,
	0,
	0,
	0,
	0,
	exti0_isr,
	exti1_isr,
	exti2_isr,
	exti3_isr,
	exti4_isr,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	exti9_5_isr,
	0,
	0,
	0,
	0,
	tim2_isr,
	tim3_isr
};


//symbols defined in the linker script
extern uint32_t _sidata[];
extern uint32_t _sdata[];
extern uint32_t _edata[];

extern uint32_t _sbss[];
extern uint32_t _ebss[];


//init the .data section in SRAM
void __init_data(uint32_t* flash_begin, uint32_t* data_begin, uint32_t* data_end){
	uint32_t* ptr = data_begin;
	while(ptr < data_end){
		*ptr = *flash_begin;
		++ptr;
	       	++flash_begin;
	}
}

//init the .bss section in SRAM
void __init_bss(uint32_t* bss_begin, uint32_t* bss_end){
	uint32_t* ptr = bss_begin;
	while(ptr < bss_end){
		*ptr++ = 0;
	}
}

void* malloc(uint32_t bytes){

	extern uint32_t _sheap;
	extern uint32_t _eheap;

	static uint32_t *alloc_ptr;
	uint32_t *ret_ptr;

	if(!alloc_ptr){
		alloc_ptr = &_sheap;
	}

	uint32_t inc = (bytes + 0x03)>>2;

	if(alloc_ptr + inc > &_eheap){
		return 0;
	}

	ret_ptr = alloc_ptr;
	alloc_ptr += inc;

	for(uint32_t i = 0; i < inc; i++){
		*(ret_ptr + i) = 0x00;
	}	

	return ret_ptr;
}

//Reset handler definition
void __attribute__((noreturn))
_start(void){
	__init_data(_sidata, _sdata, _edata);
	__init_bss(_sbss, _ebss);
	main();
	for(;;);
}


