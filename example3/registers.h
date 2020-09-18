#ifndef __REGISTERS__HD
#define __REGISTERS__HD

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

// #define SET_BITPAIR_HIGH_REGISTER(__register__, bit, option, offset) (__register__) |= (option << (bit*2 + offset))
// #define SET_BITPAIR_LOW_REGISTER(__register__, bit, option) (__register__) |= (option << bit)
// #define RESET_BITPAIR_HIGH_REGISTER(__register__, bit, option, offset) (__register__) &= ~(option << (bit*2 + offset))
// #define RESET_BITPAIR_LOW_REGISTER(__register__, bit, option) (__register__) &= ~(option << bit)

#define SET_BIT_HIGH_REGISTER(__register__, bit) (__register__) |= ((1UL << (bit + 16)) & ~0x0FFFFUL)
#define SET_BIT_LOW_REGISTER(__register__, bit) (__register__) |= ((1UL << bit) & 0x0FFFFUL)
#define RESET_BIT_HIGH_REGISTER(__register__, bit) (__register__) &= (~(1UL << (bit + 16)) & ~0x0FFFFUL)
#define RESET_BIT_LOW_REGISTER(__register__, bit) (__register__) &= ((~(1UL << bit)) & 0x0FFFFUL)

// #define GET_BITPAIR_HIGH_REGISTER(__register__, bit, option) ((__register__) & (option << bit*2)) == (option << bit*2)
// #define GET_BITPAIR_LOW_REGISTER(__register__, bit, option) ((__register__) & (option << bit)) == (option << bit)
// #define GET_BIT_HIGH_REGISTER(__register__, bit) ((__register__) & (option << bit*2)) == (option << (bit + 16))
// #define GET_BIT_LOW_REGISTER(__register__, bit) ((__register__) & (option << bit)) == (option << bit)
#define COMPARE_BITS(__register__, pos, width) ((__register__) & (width << pos)) == (width << pos)
#define GET_BIT_REGISTER(__register__, bit) COMPARE_BITS(__register__, bit, 1UL)

#define RCC_BASE (0x40023800)
#define TIM2_BASE (0x40000000)
#define NVIC_BASE (0xE000E000)
#define GPIOA_BASE (0x40020000)
#define NVIC_ISER_BASE (NVIC_BASE + 0x100)
#define NVIC_ICER_BASE (NVIC_BASE + 0x180)
#define NVIC_ISPR_BASE (NVIC_BASE + 0x200)
#define NVIC_ICPR_BASE (NVIC_BASE + 0x280)
#define NVIC_IABR_BASE (NVIC_BASE + 0x300)
#define NVIC_IPR_BASE (NVIC_BASE + 0x400)
#define NVIC_STIR_BASE (NVIC_BASE + 0xE00)
#define RCC ((RCC_type *)RCC_BASE)
#define TIM2 ((TIM_type *)TIM2_BASE)
#define GPIOA ((GPIO_type *)GPIOA_BASE)

#define TIM_SR_UIF_Bit 0
#define TIM_SR_CC1IF_Bit 1
#define TIM_SR_CC2IF_Bit 2
#define TIM_SR_CC3IF_Bit 3
#define TIM_SR_CC4IF_Bit 4
#define TIM_SR_TIF_Bit 6
#define TIM_SR_CC1OF_Bit 9
#define TIM_SR_CC2OF_Bit 10
#define TIM_SR_CC3OF_Bit 11
#define TIM_SR_CC4OF_Bit 12

#ifdef __cplusplus
extern "C" {
#endif

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
} RCC_type;

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
} TIM_type;

typedef struct {
unsigned int* ISER;
unsigned int* ICER;
unsigned int* ISPR;
unsigned int* ICPR;
unsigned int* IABR;
unsigned int* IPR;
unsigned int* STIR;
} NVIC_type;

typedef struct {
volatile int MODER; //0x00
volatile int OTYPER;//0x04
volatile int OSPEEDER; //0x08
volatile int PUPDR; //0x0C
volatile int IDR; //0x10
volatile int ODR; //0x14
volatile int BSRR; //0x18
volatile int LCKR; //0x1c
volatile int AFRL; //0x20
volatile int AFRH; //0x24
} GPIO_type;

extern NVIC_type* NVIC_GetRegister();
extern void GPIO_TogglePin(GPIO_type* gpio, int pin);

#ifdef __cplusplus
}
#endif

#endif /*__REGISTERS__HD*/
