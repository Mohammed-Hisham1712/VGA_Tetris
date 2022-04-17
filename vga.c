#include <stdint.h>
#include "rcc.h"
#include "gpio.h"
#include "timers.h"
#include "dma.h"
#include "nvic.h"
#include "vga.h"


char vga_buff[V_LINES][H_COLS];

void tim3_isr(void){
	*TIM3_SR = 0;
	*DMA_CCR(7) &= ~DMA_EN;
	*DMA_CMAR(7) = (uint32_t)vga_buff;
	*DMA_CNDTR(7) = H_COLS;
	*DMA_CCR(7) |= DMA_EN;
	*TIM2_DIER |= UIE;
}
void tim2_isr(void){
	*TIM2_SR = 0;
	static uint8_t counter = 0;
	static uint8_t line = 0;
	if (++counter == 4)
	{
		counter = 0;
		*DMA_CCR(7) &= ~DMA_EN;
		*DMA_CMAR(7) = (*DMA_CMAR(7)) + H_PIXELS/2;
		*DMA_CNDTR(7) = H_COLS;
		if (++line == 150)
		{
			*GPIOB_ODR=0;
			counter = 0;
			line = 0;
			*TIM2_DIER &= ~UIE;
			return;
		}
		*DMA_CCR(7) |= DMA_EN;
	}
}

static void tim2_start(void){
	
	*TIM2_ARR = 2047; //28.4444uS period, 2047
	*TIM2_CCR1 = 144; //2uS High Time, 144  //h_sync
	*TIM2_CCR2 = 400; //2 + 3.5556 uS, 400  //h_sync + back porch
	*TIM2_PSC = 0;

	*TIM2_CR1 |= ARPE;
	*TIM2_CR1 |= URS;

	*TIM2_CR2 |= (1<<5); //MASTER MODE TRGO = 1 EACH UEV

	*TIM2_CCMR1 |= (1<<3); //OC1PE
	*TIM2_CCMR1 |= (3<<5); //PWM MODE1

	*TIM2_CCMR1 |= (1<<11); //OC2PE
	*TIM2_CCMR1 |= (3<<13); //PWM MODE1

	*TIM2_CCER |= 3; //OC1 ACTIVE LOW AND ENABLED
	*TIM2_CCER |= (3<<4); //OC2 ACTIVE LOW AND ENABLED
	
	*NVIC_ISER1 |= (1<<TIM2_IRQ);
	*TIM2_EGR |= UG; //LOAD REGISTERS

	*TIM2_CR1 |= CEN; //ENABLE COUNTER
}

static void tim3_start(void){

	*TIM3_ARR = 624;	//625 lines, while fram = 17.7776 mS
	*TIM3_CCR1 = 2;		//v_sync = 0.056mS
	*TIM3_CCR2 = 24;	//v_sync + back porch = 682uS
	*TIM3_PSC = 0;

	*TIM3_CR1 |= ARPE;
	*TIM3_CR1 |= URS;

	*TIM3_SMCR |= 7; //EXTERNAL MODE 1
	*TIM3_SMCR |= (1<<4);	//TIM2 MASTER, TIM3 SLAVE

	*TIM3_CCMR1 |= (1<<3); //OC1PE
	*TIM3_CCMR1 |= (3<<5);	//PWM MODE1

	*TIM3_CCMR1 |= (1<<11);	//OC2PE
	*TIM3_CCMR1 |= (3<<13);	//PWM MODE1

	*TIM3_CCER |= 3; 	//OC1 ACTIVE LOW AND ENABLED
	*TIM3_CCER |= (3<<4);	//OC2 ACTIVE LOW AND ENABLED

	*TIM3_DIER |= CC2IE;
	*NVIC_ISER1 |= (1<<TIM3_IRQ);

	*TIM3_EGR |= UG;

	*TIM3_CR1 |= CEN; //ENABLE COUNTER
}

static void tim4_start(void){
	
	*TIM4_ARR = 15; //Fuev = 4.5Mhz 15
	*TIM4_CCR3 = 8;  //8
	*TIM4_PSC = 0;

	*TIM4_CR1 |= ARPE;
	*TIM4_CR1 |= URS;

	*TIM4_DIER |= UDE;

	*TIM4_SMCR |= (5<<4); //TS = 101, TI1FP1
	*TIM4_SMCR |= (5<<0); //SMS = 101, GATED MODE

	*TIM4_CCMR2 |= (1<<3);	//OC3PE
	*TIM4_CCMR2 |= (3<<5);	//PWM MODE1

	*TIM4_CCER |= (3<<8);	//OC3 ACTIVE LOW AND ENABLED

	*TIM4_EGR |= UG;

	*TIM4_CR1 |= CEN;
}

static void vga_sync(void){

	*RCC_APB2ENR |= IOPAEN;
	*RCC_APB2ENR |= IOPBEN;
        *RCC_APB1ENR |= TIM2EN;
	*RCC_APB1ENR |= TIM3EN;
	*RCC_APB1ENR |= TIM4EN;

	//PA0	TIM2_CH1
        *GPIOA_CRL |= 1; //OUTPUT 10Mhz
        *GPIOA_CRL &= ~(1<<2);
        *GPIOA_CRL |= (1<<3);//ALTFN PUSHPULL

	//PA1	TIM2_CH2
	*GPIOA_CRL |= (1<<4);
	*GPIOA_CRL &= ~(1<<6);
	*GPIOA_CRL |= (1<<7);

	//PA6	TIM3_CH1
	*GPIOA_CRL |= (1<<24);
	*GPIOA_CRL &= ~(1<<26);
	*GPIOA_CRL |= (1<<27);

	//PA7	TIM3_CH2
	*GPIOA_CRL |= (1<<28);
	*GPIOA_CRL &= ~(1<<30);
	*GPIOA_CRL |= (1<<31);

	//PB6 TIM4_CH1
	*GPIOB_CRL &= ~(3<<24); //INPUT MODE
	*GPIOB_CRL |= (1<<26);
	*GPIOB_CRL &= ~(1<<27);

	//PB8	TIM4_CH3
	*GPIOB_CRH |= (1<<0);
	*GPIOB_CRH &= ~(1<<2);
	*GPIOB_CRH |= (1<<3);

	tim4_start();
	tim3_start();
	tim2_start();
}

static void dma_setup(void){

	*RCC_AHBENR |= DMA1EN;

	//CONFIGURE DMA1 CHANNEL 7
	*DMA_CCR(7) |= (3<<12); //VERY HIGH PRIORITY
	*DMA_CCR(7) |= DMA_MINC;
	*DMA_CCR(7) |= DMA_DIR;
	*DMA_CCR(7) |= DMA_CIRC;//enable circular mode

	*DMA_CNDTR(7) = H_COLS;

	*DMA_CPAR(7) = (uint32_t) GPIOB_ODR;
	*DMA_CMAR(7) = (uint32_t) vga_buff;
	
}



void initscr(void){

        *RCC_APB2ENR |= AFIOEN;
        *AFIO_MAPR |= (1<<25);

        dma_setup();

        vga_sync();

        *GPIOB_CRL |= (3<<0) | (3<<4) | (3<<12) | (3<<16) | (3<<20) | (3<<28);
        *GPIOB_CRL &= ~(1<<2) & ~(1<<6) & ~(1<<14) & ~(3<<18) & ~(1<<22) & ~(1<<30);

}

char in_backporch(void){
	return *TIM3_CNT < 24;
}

void test_colors(void){

	for(uint16_t i = 0; i < V_LINES; i++){

		for(uint16_t j = 0; j < VISIBLE_COLS; j++){

			if(i < 49){
				vga_buff[i][j] = 0x11;
			}
			else if(i < 99){
				vga_buff[i][j] = 0x22;
			}
			else if(i < 149){
				vga_buff[i][j] = 0x88;
			}
			else{
				vga_buff[i][j] = 0x00;
			}
		}
	}
}
