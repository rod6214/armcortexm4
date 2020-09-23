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
#define FLASH_INTERFACE_BASE (0x40023C00)
#define SDRAM_Bank2_BASE (0xD0000000)
#define SDRAM_Bank1_BASE (0xC0000000)
#define FMC_BASE (0xA0000000)

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
#define FLASHI ((FLASHI_type *)FLASH_INTERFACE_BASE)
#define FMC ((FMC_Control_type *)FMC_BASE)
// #define SDRAM1 ((FMC_type *)SDRAM_Bank1_BASE)
// #define SDRAM2 ((FMC_type *)SDRAM_Bank2_BASE)
// SDRAM Controller
// FMC_SDCR1,2
#define FMC_SDCRx_RPIPE_2Bits 13
#define FMC_SDCRx_RBURST_Bit 12
#define FMC_SDCRx_SDCLK_2Bits 10
#define FMC_SDCRx_WP_Bit 9
#define FMC_SDCRx_CAS_2Bits 7
#define FMC_SDCRx_NB_Bit 6
#define FMC_SDCRx_MWID_2Bits 4
#define FMC_SDCRx_NR_2Bits 2
#define FMC_SDCRx_NC_2Bits 0
// FMC_SDTR1,2
#define FMC_SDTR_TRCD_4Bits 24
#define FMC_SDTR_TRP_4Bits 20
#define FMC_SDTR_TWR_4Bits 10
#define FMC_SDTR_TRC_4Bits 9
#define FMC_SDTR_TRAS_4Bits 7
#define FMC_SDTR_TXSR_4Bits 6
#define FMC_SDTR_TMRD_4Bits 4
// FMC_SDCMR
#define FMC_SDCMR_MRD_13Bits 9
#define FMC_SDCMR_NRFS_4Bits 5
#define FMC_SDCMR_CTB1_Bit 4
#define FMC_SDCMR_CTB2_Bit 3
#define FMC_SDCMR_MODE_4Bits 0
// FMC_SDRTR
#define FMC_SDRTR_REIE_Bit 14
#define FMC_SDRTR_COUNT_13Bits 1
#define FMC_SDRTR_CRE_Bit 0
// FMC_SDSR
#define FMC_SDRTR_BUSY_Bit 14
#define FMC_SDRTR_MODES2_2Bits 1
#define FMC_SDRTR_MODES1_2Bits 0
#define FMC_SDRTR_RE_Bit 0
// FMC_SDCR configs
#define FMC_SET_RPIPE_Delay(x) (x << FMC_SDCRx_RPIPE_2Bits)
#define FMC_SET_BURST_Delay(x) (x << FMC_SDCRx_RBURST_Bit)
#define FMC_SET_SDCLK_Delay(x) (x << FMC_SDCRx_SDCLK_2Bits)
#define FMC_SET_WP_Delay(x) (x << FMC_SDCRx_WP_Bit)
#define FMC_SET_CAS_Delay(x) (x << FMC_SDCRx_CAS_2Bits)
#define FMC_SET_NB_Delay(x) (x << FMC_SDCRx_NB_Bit)
#define FMC_SET_MWID_Delay(x) (x << FMC_SDCRx_MWID_2Bits)
#define FMC_SET_NR_Delay(x) (x << FMC_SDCRx_NR_2Bits)
#define FMC_SET_NC_Delay(x) (x << FMC_SDCRx_NC_2Bits)
// FMC_SDTR configs
#define FMC_SET_TRCD_Delay(x) ((x & 15UL) << FMC_SDTR_TRCD_4Bits)
#define FMC_SET_TRP_Delay(x) ((x & 15UL) << FMC_SDTR_TRP_4Bits)
#define FMC_SET_TWR_Delay(x) ((x & 15UL) << FMC_SDTR_TWR_4Bits)
#define FMC_SET_TRC_Delay(x) ((x & 15UL) << FMC_SDTR_TRC_4Bits)
#define FMC_SET_TRAS_Delay(x) ((x & 15UL) << FMC_SDTR_TRAS_4Bits)
#define FMC_SET_TXSR_Delay(x) ((x & 15UL) << FMC_SDTR_TXSR_4Bits)
#define FMC_SET_TMRD_Delay(x) ((x & 15UL) << FMC_SDTR_TMRD_4Bits)
// FMC_SDCMR configs
#define FMC_SET_MRD_Delay(x) ((x & 16383UL) << FMC_SDCMR_MRD_13Bits)
#define FMC_SET_NRFS_Delay(x) ((x & 15UL) << FMC_SDCMR_NRFS_4Bits)
#define FMC_SET_CTB1_Enabled (1UL << FMC_SDCMR_CTB1_Bit)
#define FMC_SET_CTB2_Enabled (1UL << FMC_SDCMR_CTB2_Bit)
#define FMC_SET_MODE_Delay(x) ((x & 15UL) << FMC_SDCMR_MODE_4Bits)
// FMC_SDRTR configs
#define FMC_SET_REIE_Delay(x) (x << FMC_SDRTR_REIE_Bit)
#define FMC_SET_COUNT_Delay(x) ((x & 15UL) << FMC_SDRTR_COUNT_13Bits)
#define FMC_SET_CRE_Enabled (1UL << FMC_SDRTR_CRE_Bit)
// FMC_SDSR status
#define FMC_IS_BUSY_Delay ((FMC->SDSR & (1UL << FMC_SDRTR_BUSY_Bit)) == (1UL << FMC_SDRTR_BUSY_Bit))
// Bank 2
#define FMC_IS_NORMAL_MODE_BANK2 (FMC->SDSR | (~(3UL << FMC_SDRTR_MODES1_2Bits))) == ~(3UL << FMC_SDRTR_MODES2_2Bits)
#define FMC_IS_SELFREFRESH_MODE_BANK2 (FMC->SDSR & (1UL << FMC_SDRTR_MODES2_2Bits)) == (1UL << FMC_SDRTR_MODES2_2Bits)
#define FMC_IS_POWERDOWN_MODE_BANK2 (FMC->SDSR & (2UL << FMC_SDRTR_MODES2_2Bits)) == (1UL << FMC_SDRTR_MODES2_2Bits)
// Bank 1
#define FMC_IS_NORMAL_MODE_BANK1 (FMC->SDSR | (~(3UL << FMC_SDRTR_MODES1_2Bits))) == ~(3UL << FMC_SDRTR_MODES1_2Bits)
#define FMC_IS_SELFREFRESH_MODE_BANK1 (FMC->SDSR & (1UL << FMC_SDRTR_MODES1_2Bits)) == (1UL << FMC_SDRTR_MODES1_2Bits)
#define FMC_IS_POWERDOWN_MODE_BANK1 (FMC->SDSR & (2UL << FMC_SDRTR_MODES1_2Bits)) == (1UL << FMC_SDRTR_MODES1_2Bits)
// #define FMC_IS_NORMAL_MODE_BANK2 (FMC->SDSR & (1UL << FMC_SDRTR_MODES2_2Bits)) == (1UL << FMC_SDRTR_MODES2_2Bits)
// #define FMC_IS_NORMAL_MODE_BANK1 (FMC->SDSR & (1UL << FMC_SDRTR_MODES1_2Bits)) == 
// #define FMC_GET_RE_Flag (1UL << FMC_SDRTR_RE_Bit)
// #define FMC_SET_CTB2_Enabled (1UL << FMC_SDCMR_CTB2_Bit)
// #define FMC_SET_MODE_Delay(x) ((x & 15UL) << FMC_SDCMR_MODE_4Bits)
// #define FMC_SET_TXSR_Delay(x) (x << FMC_SDTR_TXSR_4Bits)
// #define FMC_SET_TMRD_Delay(x) (x << FMC_SDTR_TMRD_4Bits)
// TIM register bits
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
// RCC_CR register bits
#define RCC_CR_PLLSAIRDY_Bit 29
#define RCC_CR_PLLSAION_Bit 28
#define RCC_CR_PLLI2SRDY_Bit 27
#define RCC_CR_PLLRDY_Bit 25
#define RCC_CR_PLLON_Bit 24
#define RCC_CR_CSSON_Bit 19
#define RCC_CR_HSEBYP_Bit 18
#define RCC_CR_HSERDY_Bit 17
#define RCC_CR_HSEON_Bit 16
#define RCC_CR_HSICAL_8Bits 8
#define RCC_CR_HSITRIM_5Bits 3
#define RCC_CR_HSIRDY_Bit 1
#define RCC_CR_HSION_Bit 0
// RCC_PLLCFGR register bits
#define RCC_PLLCFGR_PLLQ_4Bits 24
#define RCC_PLLCFGR_PLLSRC_Bit 22
#define RCC_PLLCFGR_PLLP_2Bits 16
#define RCC_PLLCFGR_PLLN_9Bits 6
#define RCC_PLLCFGR_PLLM_6Bits 0
// RCC_CFGR register bits
#define RCC_CFGR_MCO2_2Bits 30
#define RCC_CFGR_MCO2PRE_3Bits 29
#define RCC_CFGR_MCO1PRE_3Bits 26
#define RCC_CFGR_I2SSRC_2Bits 23
#define RCC_CFGR_MCO1_2Bits 21
#define RCC_CFGR_RTCPRE_5Bits 16
#define RCC_CFGR_PPRE2_3Bits 13
#define RCC_CFGR_PPRE1_3Bits 10
#define RCC_CFGR_HPRE_4Bits 4
#define RCC_CFGR_SWS_2Bits 2
#define RCC_CFGR_SW_2Bits 0
// RCC_CIR register bits
#define RCC_CIR_CSSC_Bit 23
#define RCC_CIR_PLLSAIRDYC_Bit 22
#define RCC_CIR_PLLI2SRDYC_Bit 21
#define RCC_CIR_PLLRDYC_Bit 20
#define RCC_CIR_HSERDYC_Bit 19
#define RCC_CIR_HSIRDYC_Bit 18
#define RCC_CIR_LSERDYC_Bit 17
#define RCC_CIR_LSIRDYC_Bit 16
#define RCC_CIR_PLLSAIRDYIE_Bit 14
#define RCC_CIR_PLLI2SRDYIE_Bit 13
#define RCC_CIR_PLLRDYIE_Bit 12
#define RCC_CIR_HSERDYIE_Bit 11
#define RCC_CIR_HSIRDYIE_Bit 10
#define RCC_CIR_LSERDYIE_Bit 9
#define RCC_CIR_LSIRDYIE_Bit 8
#define RCC_CIR_CSSF_Bit 7
#define RCC_CIR_PLLSAIRDYF_Bit 6
#define RCC_CIR_PLLI2SRDYF_Bit 5
#define RCC_CIR_PLLRDYF_Bit 4
#define RCC_CIR_HSERDYF_Bit 3
#define RCC_CIR_HSIRDYF_Bit 2
#define RCC_CIR_LSERDYF_Bit 1
#define RCC_CIR_LSIRDYF_Bit 0
// RCC AHB1 peripheral clock register (RCC_AHB1ENR)
#define RCC_AHB1ENR_DMA2EN_Bit 22
#define RCC_AHB1ENR_DMA1EN_Bit 21
#define RCC_AHB1ENR_BKPSRAMEN_Bit 18
#define RCC_AHB1ENR_CRCEN_Bit 12
#define RCC_AHB1ENR_GPIOKEN_Bit 10
#define RCC_AHB1ENR_GPIOJEN_Bit 20
#define RCC_AHB1ENR_GPIOIEN_Bit 9
#define RCC_AHB1ENR_GPIOHEN_Bit 8
#define RCC_AHB1ENR_GPIOGEN_Bit 7
#define RCC_AHB1ENR_GPIOFEN_Bit 6
#define RCC_AHB1ENR_GPIOEEN_Bit 5
#define RCC_AHB1ENR_GPIODEN_Bit 4
#define RCC_AHB1ENR_GPIOCEN_Bit 3
#define RCC_AHB1ENR_GPIOBEN_Bit 2
#define RCC_AHB1ENR_GPIOAEN_Bit 1
// RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define AHB2ENR_OTGFSEN_Bit 9
#define AHB2ENR_RNGEN_Bit 8
#define AHB2ENR_HASHEN_Bit 7
#define AHB2ENR_CRYPEN_Bit 6
#define AHB2ENR_DCMIEN_Bit 5
// RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
#define AHB3ENR_FMCEN_Bit 0
// RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define APB1ENR_UART8EN_Bit 31
#define APB1ENR_UART7EN_Bit 30
#define APB1ENR_DACEN_Bit 29
#define APB1ENR_PWREN_Bit 28
#define APB1ENR_CAN2EN_Bit 26
#define APB1ENR_CAN1EN_Bit 25
#define APB1ENR_I2C3EN_Bit 23
#define APB1ENR_I2C2EN_Bit 22
#define APB1ENR_I2C1EN_Bit 21
#define APB1ENR_UART5EN_Bit 20
#define APB1ENR_UART4EN_Bit 19
#define APB1ENR_USART3EN_Bit 18
#define APB1ENR_USART2EN_Bit 17
#define APB1ENR_SPI3EN_Bit 15
#define APB1ENR_SPI2EN_Bit 14
#define APB1ENR_WWDGEN_Bit 11
#define APB1ENR_TIM14EN_Bit 8
#define APB1ENR_TIM13EN_Bit 7
#define APB1ENR_TIM12EN_Bit 6
#define APB1ENR_TIM7EN_Bit 5
#define APB1ENR_TIM6EN_Bit 4
#define APB1ENR_TIM5EN_Bit 3
#define APB1ENR_TIM4EN_Bit 2
#define APB1ENR_TIM3EN_Bit 1
#define APB1ENR_TIM2EN_Bit 0
// RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define APB2ENR_LTDCEN_Bit 26
#define APB2ENR_SAI1EN_Bit 22
#define APB2ENR_SPI6EN_Bit 21
#define APB2ENR_SPI5EN_Bit 20
#define APB2ENR_TIM11EN_Bit 18
#define APB2ENR_TIM10EN_Bit 17
#define APB2ENR_TIM9EN_Bit 16
#define APB2ENR_SYSCFGEN_Bit 14
#define APB2ENR_SPI4EN_Bit 13
#define APB2ENR_SPI1EN_Bit 12
#define APB2ENR_SDIOEN_Bit 11
#define APB2ENR_ADC3EN_Bit 10
#define APB2ENR_ADC2EN_Bit 9
#define APB2ENR_ADC1EN_Bit 8
#define APB2ENR_USART6EN_Bit 5
#define APB2ENR_USART1EN_Bit 4
#define APB2ENR_TIM8EN_Bit 1
#define APB2ENR_TIM1EN_Bit 0
// RCC_PLLCFGR_PLLP Divisions
#define RCC_PLLCFGR_PLLP_div_by_2 0
#define RCC_PLLCFGR_PLLP_div_by_4 (1UL << RCC_PLLCFGR_PLLP_2Bits)
#define RCC_PLLCFGR_PLLP_div_by_6 (2UL << RCC_PLLCFGR_PLLP_2Bits)
#define RCC_PLLCFGR_PLLP_div_by_8 (3UL << RCC_PLLCFGR_PLLP_2Bits)
// RCC_PLLCFGR_PLLN Divisions
#define RCC_PLLCFGR_PLLN_mul_by_(x) (x << RCC_PLLCFGR_PLLN_9Bits)
// RCC_PLLCFGR_PLLM Divisions
#define RCC_PLLCFGR_PLLM_div_by_(x) (x << RCC_PLLCFGR_PLLM_6Bits)
// RCC_PLLCFGR_PLLSRC
#define RCC_PLLCFGR_HSE_AS_SOURCE_CLOCK (1UL << RCC_PLLCFGR_PLLSRC_Bit)
// RCC_PLLCFGR_PLLQ
#define RCC_PLLCFGR_PLLQ_div_by_(x) (x << RCC_PLLCFGR_PLLQ_4Bits)
#define RCC_PLLCFGR_HSE_IS_READY() (RCC->CR & (1UL << RCC_CR_HSERDY_Bit)) == (1UL << RCC_CR_HSERDY_Bit)
#define RCC_PLLCFGR_HSI_IS_READY() (RCC->CR & (1UL << RCC_CR_HSIRDY_Bit)) == (1UL << RCC_CR_HSIRDY_Bit)
#define RCC_PLLCFGR_PLL_IS_READY() (RCC->CR & (1UL << RCC_CR_PLLRDY_Bit)) == (1UL << RCC_CR_PLLRDY_Bit)
#define RCC_CFGR_SWS_IS_READY() ((RCC->CFGR & RCC_CFGR_SWS_PLL) == RCC_CFGR_SWS_PLL)
// RCC_CR_HSEON
#define RCC_CR_HSE_ON (1UL << RCC_CR_HSEON_Bit)
// RCC_CR_HSION
#define RCC_CR_HSI_ON (1UL << RCC_CR_HSION_Bit)
// RCC_CR_CSSON
#define RCC_CR_CSS_ON (1UL << RCC_CR_CSSON_Bit)
// RCC_CR_PLLON
#define RCC_CR_PLL_ON (1UL << RCC_CR_PLLON_Bit)
// FLASH_ACR
#define FLASH_ACR_LATENCY(x) x & 15UL
// PPRE2: APB high-speed prescaler (APB2)
#define RCC_CFGR_PPRE2_No_Div (3UL << RCC_CFGR_PPRE2_3Bits)
#define RCC_CFGR_PPRE2_Div_by_2 (4UL << RCC_CFGR_PPRE2_3Bits)
#define RCC_CFGR_PPRE2_Div_by_4 (5UL << RCC_CFGR_PPRE2_3Bits)
#define RCC_CFGR_PPRE2_Div_by_8 (6UL << RCC_CFGR_PPRE2_3Bits)
#define RCC_CFGR_PPRE2_Div_by_16 (7UL << RCC_CFGR_PPRE2_3Bits)
// PPRE1: APB Low speed prescaler (APB1)
#define RCC_CFGR_PPRE1_No_Div (3UL << RCC_CFGR_PPRE1_3Bits)
#define RCC_CFGR_PPRE1_Div_by_2 (4UL << RCC_CFGR_PPRE1_3Bits)
#define RCC_CFGR_PPRE1_Div_by_4 (5UL << RCC_CFGR_PPRE1_3Bits)
#define RCC_CFGR_PPRE1_Div_by_8 (6UL << RCC_CFGR_PPRE1_3Bits)
#define RCC_CFGR_PPRE1_Div_by_16 (7UL << RCC_CFGR_PPRE1_3Bits)
// HPRE: AHB prescaler
#define RCC_CFGR_HPRE_No_Div (7UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_2 (8UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_4 (9UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_8 (10UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_16 (11UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_64 (12UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_128 (13UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_256 (14UL << RCC_CFGR_HPRE_4Bits)
#define RCC_CFGR_HPRE_Div_by_512 (15UL << RCC_CFGR_HPRE_4Bits)
// SWS: System clock switch status
#define RCC_CFGR_SWS_HSI (0UL << RCC_CFGR_SWS_2Bits)
#define RCC_CFGR_SWS_HSE (1UL << RCC_CFGR_SWS_2Bits)
#define RCC_CFGR_SWS_PLL (2UL << RCC_CFGR_SWS_2Bits)
// SW: System clock switch
#define RCC_CFGR_SW_HSI (0UL << RCC_CFGR_SW_2Bits)
#define RCC_CFGR_SW_HSE (1UL << RCC_CFGR_SW_2Bits)
#define RCC_CFGR_SW_PLL (2UL << RCC_CFGR_SW_2Bits)

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

typedef struct   {
volatile int BCR1; //0x00
union {
    volatile int BTR1; //0x04
    volatile int BWTR1; //0x04
};
volatile int BCR2;//0x08
union {
    volatile int BTR2; //0x0C
    volatile int BWTR2; //0x0C
};
volatile int BCR3; //0x10
union {
    volatile int BTR3; //0x14
    volatile int BWTR3; //0x14
};
volatile int BCR4; //0x18
union {
    volatile int BTR4; //0x1C
    volatile int BWTR4; //0x1C
};
volatile int PCR2; // 0x60
volatile int SR2; // 0x64
volatile int PMEM2; // 0x68
volatile int PATT2; // 0x6C
unsigned int reserved1; // 0x70
volatile int ECCR2; // 0x74
unsigned int reserved2[2]; // 0x78 - 0x7C
volatile int PCR3; // 0x80
volatile int SR3; // 0x84
volatile int PMEM3; // 0x88
volatile int PATT3; // 0x8C
unsigned int reserved3; // 0x90
volatile int ECCR3; // 0x94
unsigned int reserved4[2]; // 0x98 - 0x9C
volatile int PCR4; // 0xA0
volatile int SR4; // 0xA4
volatile int PMEM4; // 0xA8
volatile int PATT4; // 0xAC
volatile int PIO4; // 0xB0
unsigned int reserved5[36]; // 0xB4 - 0x13C
volatile int SDCR_1; // 0x140
volatile int SDCR_2; // 0x144
volatile int SDTR1; // 0x148
volatile int SDTR2; // 0x14C
volatile int SDCMR; // 0x150
volatile int SDRTR; // 0x154
volatile int SDSR; // 0x158
} FMC_Control_type;

typedef struct {
volatile int ACR; //0x00
volatile int KEYR;//0x04
volatile int OPTKEYR; //0x08
volatile int SR; //0x0C
volatile int CR; //0x10
} FLASHI_type;

extern NVIC_type* NVIC_GetRegister();
extern void GPIO_TogglePin(GPIO_type* gpio, int pin);

#ifdef __cplusplus
}
#endif

#endif /*__REGISTERS__HD*/
