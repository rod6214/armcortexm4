.set __OTYPER, 0x04
.set __OSPEEDR, 0x08
.set __PUPDR, 0x0C
.set __IDR, 0x10
.set __ODR, 0x14
.set __BSRR, 0x18
.set __LCKR, 0x1C
.set __AFRL, 0x20
.set __AFRH, 0x24

.set __AHB1, 0x40020000
.set __GPIOA, __AHB1
.set __GPIOB, __AHB1 + 0x400
.set __GPIOC, __AHB1 + 0x800
.set __GPIOH, __AHB1 + 0x1C0
.set __RCC, __AHB1 + 0x3800

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
