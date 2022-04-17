#ifndef _DMA_H
#define _DMA_H

#define DMA1_BASE	0X40020000

#define DMA_ISR		((volatile uint32_t*)(DMA1_BASE + 0X00))
#define DMA_IFCR	((volatile uint32_t*)(DMA1_BASE + 0X04))

#define DMA_CCR(X)	((volatile uint32_t*)(DMA1_BASE + 0X08 + 20*(X - 1)))
#define DMA_CNDTR(X)	((volatile uint32_t*)(DMA1_BASE + 0X0C + 20*(X - 1)))
#define DMA_CPAR(X)	((volatile uint32_t*)(DMA1_BASE + 0X10 + 20*(X - 1)))
#define DMA_CMAR(X)	((volatile uint32_t*)(DMA1_BASE + 0X14 + 20*(X - 1)))


//DMA_ISR

#define GIF1	(1<<0)
#define TCIF1	(1<<1)
#define GIF2    (1<<4)
#define TCIF2   (1<<5)
#define GIF3    (1<<8)
#define TCIF3   (1<<9)
#define GIF4    (1<<12)
#define TCIF4   (1<<13)
#define GIF5    (1<<16)
#define TCIF5   (1<<17)
#define GIF6    (1<<20)
#define TCIF6   (1<<21)
#define GIF7    (1<<24)
#define TCIF7   (1<<25)

//DMA_IFCR

#define CGIF1    (1<<0)
#define CTCIF1   (1<<1)
#define CGIF2    (1<<4)
#define CTCIF2   (1<<5)
#define CGIF3    (1<<8)
#define CTCIF3   (1<<9)
#define CGIF4    (1<<12)
#define CTCIF4   (1<<13)
#define CGIF5    (1<<16)
#define CTCIF5   (1<<17)
#define CGIF6    (1<<20)
#define CTCIF6   (1<<21)
#define CGIF7    (1<<24)
#define CTCIF7   (1<<25)

//DMA_CCR

#define DMA_EN		(1<<0)
#define DMA_TCIE	(1<<1)
#define DMA_DIR		(1<<4)
#define DMA_CIRC	(1<<5)
#define DMA_PINC	(1<<6)
#define DMA_MINC	(1<<7)


#endif
