
.set __IDR, 0x10
.set __ODR, 0x14
.set __BSRR, 0x18
.set __LCKR, 0x1C
.set __AFRL, 0x20
.set __AFRH, 0x24

.set __AHB1, 0x4002
.set __GPIOA, 0
.set __GPIOA_MODER, __GPIOA
.set __GPIOA_OTYPER, __GPIOA + 4
.set __GPIOA_OSPEEDR, __GPIOA + 8
.set __GPIOA_PUPDR, __GPIOA + 0x0C
.set __GPIOA_IDR, __GPIOA + __IDR
.set __GPIOA_ODR, __GPIOA + __ODR
.set __GPIOA_BSRR, __GPIOA + __BSRR
.set __GPIOA_LCKR, __GPIOA + __LCKR
.set __GPIOA_AFRL, __GPIOA + __AFRL
.set __GPIOx_AFRH, __GPIOA + __AFRH

.set __GPIOB, 0x400
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

.set __SYSCFG, 0x4001
.set __SYSCFG_MEMRMP, 0x3000

.set __OPTION_BYTES_BANK1, 0x1FFF
.set __OPTION_BYTES_BANK2, 0x1FFE

.set __SCB_REG, 0xE000
.set __AIRCR, 0xED00 + 0x0C

.globl _start

.section .VectorTable, "a"
.word 0x20030000
.word _Reset_Handler

.data
var:
    .word 0x11111111

.text

values:
.word 0

_Reset_Handler:
    b _Reset_Handler
_start:
    
_stop:
    b _stop
