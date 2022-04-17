#ifndef  _NVIC_H
#define _NVIC_H

#define SYS_IRQS 16
#define PERIPH_IRQS 64
#define ISR_VEC_SIZE (SYS_IRQS + PERIPH_IRQS)


#define IRQ_POS(X) (SYS_IRQS + X)

//NVIC Registers

#define NVIC_ISER_BASE	0XE000E100

#define NVIC_ISER1	((volatile uint32_t*)(NVIC_ISER_BASE + 0X00))
#define NVIC_ISER2	((volatile uint32_t*)(NVIC_ISER_BASE + 0X04))

#define NVIC_ICER_BASE	0XE000E180

#define NVIC_ICER1	((volatile uint32_t*)(NVIC_ICER_BASE + 0X00))
#define NVIC_ICER2	((volatile uint32_t*)(NVIC_ICER_BASE + 0X04))


#define EXTI0_IRQ 	6
#define EXTI1_IRQ 	7
#define EXTI2_IRQ 	8
#define EXTI3_IRQ 	9
#define EXTI4_IRQ 	10
#define EXTI9_5_IRQ 	23
#define EXTI15_10_IRQ 	40

#define ADC1_2_IRQ	18

#define TIM2_IRQ	28
#define TIM3_IRQ	29
#define TIM4_IRQ	30

#define USART1_IRQ	37
#define USART2_IRQ	38
#define USART3_IRQ	39


//System handlers

void systick_isr(void) __attribute__((weak));

//ISRs

void exti0_isr(void) __attribute__((weak));
void exti1_isr(void) __attribute__((weak));
void exti2_isr(void) __attribute__((weak));
void exti3_isr(void) __attribute__((weak));
void exti4_isr(void) __attribute__((weak));
void exti9_5_isr(void) __attribute__((weak));
void exti15_10_isr(void) __attribute__((weak));

void adc1_2_isr(void) __attribute__((weak));

void tim2_isr(void) __attribute__((weak));
void tim3_isr(void) __attribute__((weak));
void tim4_isr(void) __attribute__((weak));

void usart1_isr(void) __attribute__((weak));
void usart2_isr(void) __attribute__((weak));
void usart3_isr(void) __attribute__((weak));


#endif
