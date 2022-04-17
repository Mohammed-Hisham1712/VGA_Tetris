#ifndef _RCC_H
#define _RCC_H


#define RCC_BASE 0X40021000

#define FLASH_ACR	((volatile uint32_t*) 0X40022000)

//RCC regisetrs

#define RCC_CR 		((volatile uint32_t *)(RCC_BASE + 0X00))
#define RCC_CFGR 	((volatile uint32_t*)(RCC_BASE + 0X04))
#define RCC_AHBENR	((volatile uint32_t*)(RCC_BASE + 0X14))
#define RCC_APB2ENR 	((volatile uint32_t*)(RCC_BASE + 0X18))
#define RCC_APB1ENR 	((volatile uint32_t*)(RCC_BASE + 0X1C))

//bit fields

//RCC_CR

#define HSION  	(1<<0)
#define HSIRDY	(1<<1)
#define HSEON	(1<<16)
#define HSERDY	(1<<17)
#define PLLON	(1<<24)
#define PLLRDY	(1<<25)

//RCC_CFGR

#define PLLSRC	(1<<16)
#define PLLXPRE	(1<<17)

//AHB PERIPHS
#define DMA1EN	(1<<0)

//APB2 PERIPHS
#define AFIOEN (1<<0)
#define IOPAEN (1<<2)
#define IOPBEN (1<<3)
#define IOPCEN (1<<4)

//APB1 PERIPHS

#define TIM2EN	(1<<0)
#define TIM3EN	(1<<1)
#define TIM4EN	(1<<2)
#define TIM5EN	(1<<3)
#define UART2EN (1<<17)
#define UART3EN (1<<18)

#endif
