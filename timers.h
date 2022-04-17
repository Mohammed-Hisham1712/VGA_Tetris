#ifndef _TIMERS_H
#define _TIMERS_H

#define TIM2_BASE 	0X40000000
#define TIM3_BASE	0X40000400
#define TIM4_BASE	0X40000800

#define TIM2_CR1 	((volatile uint32_t*)(TIM2_BASE + 0X00))
#define TIM2_CR2 	((volatile uint32_t*)(TIM2_BASE + 0X04))
#define TIM2_SMCR	((volatile uint32_t*)(TIM2_BASE + 0X08))
#define TIM2_DIER 	((volatile uint32_t*)(TIM2_BASE + 0X0C))
#define TIM2_SR 	((volatile uint32_t*)(TIM2_BASE + 0X10))
#define TIM2_EGR 	((volatile uint32_t*)(TIM2_BASE + 0X14))
#define TIM2_CCMR1	((volatile uint32_t*)(TIM2_BASE + 0X18))
#define TIM2_CCER	((volatile uint32_t*)(TIM2_BASE + 0X20))
#define TIM2_CNT 	((volatile uint32_t*)(TIM2_BASE + 0X24))
#define TIM2_PSC 	((volatile uint32_t*)(TIM2_BASE + 0X28))
#define TIM2_ARR 	((volatile uint32_t*)(TIM2_BASE + 0X2C))
#define TIM2_CCR1	((volatile uint32_t*)(TIM2_BASE + 0X34))
#define TIM2_CCR2	((volatile uint32_t*)(TIM2_BASE + 0X38))

#define TIM3_CR1        ((volatile uint32_t*)(TIM3_BASE + 0X00))
#define TIM3_CR2        ((volatile uint32_t*)(TIM3_BASE + 0X04))
#define TIM3_SMCR       ((volatile uint32_t*)(TIM3_BASE + 0X08))
#define TIM3_DIER       ((volatile uint32_t*)(TIM3_BASE + 0X0C))
#define TIM3_SR         ((volatile uint32_t*)(TIM3_BASE + 0X10))
#define TIM3_EGR        ((volatile uint32_t*)(TIM3_BASE + 0X14))
#define TIM3_CCMR1      ((volatile uint32_t*)(TIM3_BASE + 0X18))
#define TIM3_CCER       ((volatile uint32_t*)(TIM3_BASE + 0X20))
#define TIM3_CNT        ((volatile uint32_t*)(TIM3_BASE + 0X24))
#define TIM3_PSC        ((volatile uint32_t*)(TIM3_BASE + 0X28))
#define TIM3_ARR        ((volatile uint32_t*)(TIM3_BASE + 0X2C))
#define TIM3_CCR1       ((volatile uint32_t*)(TIM3_BASE + 0X34))
#define TIM3_CCR2	((volatile uint32_t*)(TIM3_BASE + 0X38))

#define TIM4_CR1        ((volatile uint32_t*)(TIM4_BASE + 0X00))
#define TIM4_CR2        ((volatile uint32_t*)(TIM4_BASE + 0X04))
#define TIM4_SMCR       ((volatile uint32_t*)(TIM4_BASE + 0X08))
#define TIM4_DIER       ((volatile uint32_t*)(TIM4_BASE + 0X0C))
#define TIM4_SR         ((volatile uint32_t*)(TIM4_BASE + 0X10))
#define TIM4_EGR        ((volatile uint32_t*)(TIM4_BASE + 0X14))
#define TIM4_CCMR1      ((volatile uint32_t*)(TIM4_BASE + 0X18))
#define TIM4_CCMR2	((volatile uint32_t*)(TIM4_BASE + 0X1C))
#define TIM4_CCER       ((volatile uint32_t*)(TIM4_BASE + 0X20))
#define TIM4_CNT        ((volatile uint32_t*)(TIM4_BASE + 0X24))
#define TIM4_PSC        ((volatile uint32_t*)(TIM4_BASE + 0X28))
#define TIM4_ARR        ((volatile uint32_t*)(TIM4_BASE + 0X2C))
#define TIM4_CCR1       ((volatile uint32_t*)(TIM4_BASE + 0X34))
#define TIM4_CCR2       ((volatile uint32_t*)(TIM4_BASE + 0X38))
#define TIM4_CCR3	((volatile uint32_t*)(TIM4_BASE + 0X3C))
#define TIM4_CCR4	((volatile uint32_t*)(TIM4_BASE + 0X40))


//bit fields
//TIMx_CR1
#define CEN	(1<<0)
#define UDIS	(1<<1)
#define URS	(1<<2)
#define OPM	(1<<3)
#define ARPE	(1<<7)

//TIMx_DIER
#define UIE	(1<<0)
#define CC1IE	(1<<1)
#define CC2IE	(1<<2)
#define UDE	(1<<8)

//TIMx_SR
#define UIF	(0X00000001)
#define CC1IF	(0X00000002)
#define CC2IF	(0X00000004)


//TIMx_EGR
#define UG	(0X00000001)

#endif
