
#define __OTYPER 0x04
#define __OSPEEDR 0x08
#define __PUPDR 0x0C
#define __IDR 0x10
#define __ODR 0x14
#define __BSRR 0x18
#define __LCKR 0x1C
#define __AFRL 0x20
#define __AFRH 0x24

#define __AHB1 0x40020000
#define __GPIOA (__AHB1)
#define __GPIOB (__AHB1 + 0x400)
#define __GPIOC (__AHB1 + 0x800)
#define __GPIOH (__AHB1 + 0x1C0)
#define __RCC (__AHB1 + 0x3800)

#define __GPIOA_MODER (__GPIOA)
#define __GPIOA_OTYPER (__GPIOA + __OTYPER)
#define __GPIOA_OSPEEDR (__GPIOA + __OSPEEDR)
#define __GPIOA_PUPDR __GPIOA + __PUPDR)
#define __GPIOA_IDR (__GPIOA + __IDR)
#define __GPIOA_ODR (__GPIOA + __ODR)
#define __GPIOA_BSRR (__GPIOA + __BSRR)
#define __GPIOA_LCKR (__GPIOA + __LCKR)
#define __GPIOA_AFRL (__GPIOA + __AFRL)
#define __GPIOA_AFRH (__GPIOA + __AFRH)

// #define __RCC_CR __RCC
#define __RCC_CFGR (__RCC + 8)
#define __RCC_PLLCFGR (__RCC + 4)
#define __RCC_BDCR (__RCC + 0x70)
#define __RCC_AHB1ENR (__RCC + 0x30)

typedef struct   {
volatile int CR; //0x00
volatile int PLLCFGR;//0x04
volatile int CFGR; //0x08
volatile int CIR; //0x0C
volatile int AHB1RSTR; //0x10
volatile int AHB2RSTR; //0x14
volatile int AHB3RSTR; //0x18
unsigned int reserved1; //0x1c
volatile int APB1RSTR; //0x20
volatile int APB2RSTR; //0x24
unsigned int reserved2; //0x28
unsigned int reserved3; //0x2c
volatile int AHB1ENR; //0x30
volatile int AHB2ENR; //0x34
volatile int AHB3ENR; //0x38
unsigned int reserved4; //0x3c
volatile int APB1ENR; //0x40
volatile int APB2ENR; //0x44
unsigned int reserved5; //0x48
unsigned int reserved6; //0x4C
volatile int AHB1LPENR; //0x50
volatile int AHB2LPENR; //0x54
volatile int AHB3LPENR; //0x58
unsigned int reserved7; //0x5C
volatile int APB1LPENR; //0x60
volatile int APB2LPENR; //0x64
unsigned int reserved8; //0x68
unsigned int reserved9; //0x6C
volatile int BDCR; //0x70
volatile int CSR; //0x74
unsigned int reserved10; //0x78
unsigned int reserved11; //0x7C
volatile int SSCGR; //0x80
volatile int PLLI2SCFGR; //0x84
volatile int PLLSAICFGR; //0x88
volatile int DCKCFGR; //0x8C
} _RCC_type;

typedef struct {
volatile int CR1; //0x00
volatile int CR2;//0x04
volatile int SMCR; //0x08
volatile int DIER; //0x0C
volatile int SR; //0x10
volatile int EGR; //0x14
volatile int CCMR1; //0x18
volatile int CCMR2; //0x1c
volatile int CCER; //0x20
volatile int CNT; //0x24
volatile int PSC; //0x28
volatile int ARR; //0x2c
unsigned int reserved1; //0x30
volatile int CCR1; //0x34
volatile int CCR2; //0x38
volatile int CCR3; //0x3c
volatile int CCR4; //0x40
unsigned int reserved2; //0x44
volatile int DCR; //0x48
volatile int DMAR; //0x4C
volatile int TIMx_OR; //0x50
} _TIM_type;

#define RCC_BASE (0x40023800)
#define TIM2_BASE (0x40010000)
#define RCC ((_RCC_type *)RCC_BASE)
#define TIM2 ((_TIM_type *)TIM2_BASE)
