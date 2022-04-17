#ifndef _GPIO_H
#define _GPIO_H

#define GPIOA_BASE 	0x40010800
#define GPIOB_BASE 	0x40010C00
#define GPIOC_BASE 	0x40011000
#define AFIO_BASE       0X40010000


//GPIOA registers

#define GPIOA_CRL 	((volatile uint32_t*)(GPIOA_BASE + 0X00))
#define GPIOA_CRH 	((volatile uint32_t*)(GPIOA_BASE + 0X04))
#define GPIOA_IDR 	((volatile uint32_t*)(GPIOA_BASE + 0X08))
#define GPIOA_ODR 	((volatile uint32_t*)(GPIOA_BASE + 0X0C))
#define GPIOA_BSRR 	((volatile uint32_t*)(GPIOA_BASE + 0X10))
#define GPIOA_BRR 	((volatile uint32_t*)(GPIOA_BASE + 0X14))

#define GPIOB_CRL 	((volatile uint32_t*)(GPIOB_BASE + 0X00))
#define GPIOB_CRH 	((volatile uint32_t*)(GPIOB_BASE + 0X04))
#define GPIOB_IDR 	((volatile uint32_t*)(GPIOB_BASE + 0X08))
#define GPIOB_ODR 	((volatile uint32_t*)(GPIOB_BASE + 0X0C))
#define GPIOB_BSRR 	((volatile uint32_t*)(GPIOB_BASE + 0X10))
#define GPIOB_BRR 	((volatile uint32_t*)(GPIOB_BASE + 0X14))

#define GPIOC_CRL 	((volatile uint32_t*)(GPIOC_BASE + 0X00))
#define GPIOC_CRH 	((volatile uint32_t*)(GPIOC_BASE + 0X04))
#define GPIOC_IDR 	((volatile uint32_t*)(GPIOC_BASE + 0X08))
#define GPIOC_ODR 	((volatile uint32_t*)(GPIOC_BASE + 0X0C))
#define GPIOC_BSRR 	((volatile uint32_t*)(GPIOC_BASE + 0X10))
#define GPIOC_BRR 	((volatile uint32_t*)(GPIOC_BASE + 0X14))

#define AFIO_MAPR       ((volatile uint32_t*)(AFIO_BASE + 0X04))


//bit fields

#define GPIO0 (1<<0)
#define GPIO1 (1<<1)
#define GPIO2 (1<<2)
#define GPIO3 (1<<3)
#define GPIO4 (1<<4)
#define GPIO5 (1<<5)
#define GPIO6 (1<<6)
#define GPIO7 (1<<7)
#define GPIO8 (1<<8)
#define GPIO9 (1<<9)
#define GPIO10 (1<<10)
#define GPIO11 (1<<11)
#define GPIO12 (1<<12)
#define GPIO13 (1<<13)
#define GPIO14 (1<<14)
#define GPIO15 (1<<15)

#endif
