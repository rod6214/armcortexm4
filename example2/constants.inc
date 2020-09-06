.set __OTYPER, 0x04
.set __OSPEEDR, 0x08
.set __PUPDR, 0x0C
.set __IDR, 0x10
.set __ODR, 0x14
.set __BSRR, 0x18
.set __LCKR, 0x1C
.set __AFRL, 0x20
.set __AFRH, 0x24

.set __APB1, 0x40000000
.set __APB2, 0x40010000
.set __AHB1, 0x40020000

.set __GPIOA, __AHB1
.set __GPIOB, __AHB1 + 0x400
.set __GPIOC, __AHB1 + 0x800
.set __GPIOH, __AHB1 + 0x1C0
.set __RCC, __AHB1 + 0x3800
.set __RTC, __APB1 + 0x2800
.set __TIM1, __APB2 + 0x0000
.set __TIM8, __APB2 + 0x0400

.set __GPIOA_MODER, __GPIOA
.set __GPIOA_OTYPER, __GPIOA + __OTYPER
.set __GPIOA_OSPEEDR, __GPIOA + __OSPEEDR
.set __GPIOA_PUPDR, __GPIOA + __PUPDR
.set __GPIOA_IDR, __GPIOA + __IDR
.set __GPIOA_ODR, __GPIOA + __ODR
.set __GPIOA_BSRR, __GPIOA + __BSRR
.set __GPIOA_LCKR, __GPIOA + __LCKR
.set __GPIOA_AFRL, __GPIOA + __AFRL
.set __GPIOA_AFRH, __GPIOA + __AFRH

.set __GPIOB_MODER, __GPIOB
.set __GPIOB_OTYPER, __GPIOB + 4
.set __GPIOB_OSPEEDR, __GPIOB + 8
.set __GPIOB_PUPDR, __GPIOB + 0x0C
.set __GPIOB_IDR, __GPIOB + 0x10
.set __GPIOB_ODR, __GPIOA + 0x14
.set __GPIOB_BSRR, __GPIOA + 0x18
.set __GPIOB_LCKR, __GPIOA + 0x1C
.set __GPIOB_AFRL, __GPIOA + 0x20
.set __GPIOB_AFRH, __GPIOA + 0x24

.set __RTC_TR, __RTC + 0x00
.set __RTC_DR, __RTC + 0x04
.set __RTC_CR, __RTC + 0x08
.set __RTC_ISR, __RTC + 0x0C
.set __RTC_PRER, __RTC + 0x10
.set __RTC_WUTR, __RTC + 0x14
.set __RTC_CALIBR, __RTC + 0x18
.set __RTC_ALRMAR, __RTC + 0x1C
.set __RTC_ALRMBR, __RTC + 0x20
.set __RTC_WPR, __RTC + 0x24
.set __RTC_SSR, __RTC + 0x28
.set __RTC_SHIFTR, __RTC + 0x2C
.set __RTC_TSTR, __RTC + 0x30
.set __RTC_TSSSR, __RTC + 0x38
.set __RTC_CALR, __RTC + 0x3C
.set __RTC_TAFCR, __RTC + 0x40
.set __RTC_ALRMASSR, __RTC + 0x44
.set __RTC_ALRMBSSR, __RTC + 0x48
.set __RTC_BKP0R, __RTC + 0x50
.set __RTC_BKP19R, __RTC + 0x9C

.set __TIM1_CR1, __TIM1 + 0x00
.set __TIM1_CR2, __TIM1 + 0x04
.set __TIM1_SMCR, __TIM1 + 0x08
.set __TIM1_DIER, __TIM1 + 0x0C
.set __TIM1_SR, __TIM1 + 0x10
.set __TIM1_EGR, __TIM1 + 0x14
.set __TIM1_CCMR1, __TIM1 + 0x18
.set __TIM1_CCMR1, __TIM1 + 0x18
.set __TIM1_CCMR2, __TIM1 + 0x1C
.set __TIM1_CCMR2, __TIM1 + 0x1C
.set __TIM1_CCER, __TIM1 + 0x20
.set __TIM1_CNT, __TIM1 + 0x24
.set __TIM1_PSC, __TIM1 + 0x28
.set __TIM1_ARR, __TIM1 + 0x2C
.set __TIM1_RCR, __TIM1 + 0x30
.set __TIM1_CCR1, __TIM1 + 0x34
.set __TIM1_CCR2, __TIM1 + 0x38
.set __TIM1_CCR3, __TIM1 + 0x3C
.set __TIM1_CCR4, __TIM1 + 0x40
.set __TIM1_BDTR, __TIM1 + 0x44
.set __TIM1_DCR, __TIM1 + 0x48
.set __TIM1_DMAR, __TIM1 + 0x4C

.set __TIM8_CR1, __TIM8 + 0x00
.set __TIM8_CR2, __TIM8 + 0x04
.set __TIM8_SMCR, __TIM8 + 0x08
.set __TIM8_DIER, __TIM8 + 0x0C
.set __TIM8_SR, __TIM8 + 0x10
.set __TIM8_EGR, __TIM8 + 0x14
.set __TIM8_CCMR1, __TIM8 + 0x18
.set __TIM8_CCMR1, __TIM8 + 0x18
.set __TIM8_CCMR2, __TIM8 + 0x1C
.set __TIM8_CCMR2, __TIM8 + 0x1C
.set __TIM8_CCER, __TIM8 + 0x20
.set __TIM8_CNT, __TIM8 + 0x24
.set __TIM8_PSC, __TIM8 + 0x28
.set __TIM8_ARR, __TIM8 + 0x2C
.set __TIM8_RCR, __TIM8 + 0x30
.set __TIM8_CCR1, __TIM8 + 0x34
.set __TIM8_CCR2, __TIM8 + 0x38
.set __TIM8_CCR3, __TIM8 + 0x3C
.set __TIM8_CCR4, __TIM8 + 0x40
.set __TIM8_BDTR, __TIM8 + 0x44
.set __TIM8_DCR, __TIM8 + 0x48
.set __TIM8_DMAR, __TIM8 + 0x4C

.set __FMC_CONTROLLER, 0xA000
.set __FMC_SDCR1, 0x140

.set __RCC_CR, __RCC
.set __RCC_CFGR, __RCC + 8
.set __RCC_PLLCFGR, __RCC + 4
.set __RCC_BDCR, __RCC + 0x70
.set __RCC_AHB1ENR, __RCC + 0x30

.set __SYSCFG, 0x4001
.set __SYSCFG_MEMRMP, 0x3000

.set __OPTION_BYTES_BANK1, 0x1FFF
.set __OPTION_BYTES_BANK2, 0x1FFE

.set __SCB_REG, 0xE000
.set __AIRCR, 0xED00 + 0x0C
