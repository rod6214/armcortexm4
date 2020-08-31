.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.set PLLCFGR_CONFIG, 0x402A04
.set CFGR_CONFIG, 0x900A
.set PORT_ENABLE, 0x85

.include "constants.inc"

.section .text.main
.weak main
.type main, %function

main:
    bl enable_ports
    bl clock_config
    bl port_config
stop:
    b stop
.section .text.enable_ports, "a"
.weak enable_ports
.type enable_ports, %function
enable_ports:
    ldr r0, =__RCC_AHB1ENR
    ldr r1, [r0]
    orr r1, r1, PORT_ENABLE
    str r1, [r0]
    blx lr
clock_config:
    ldr r0, =__RCC_PLLCFGR
    ldr r1, [r0]
    ldr r2, =PLLCFGR_CONFIG
    orr r1, r1, r2
    str r1, [r0]
    ldr r0, =__RCC_CFGR
    ldr r1, [r0]
    ldr r2, =CFGR_CONFIG
    orr r1, r1, r2
    str r1, [r0]
    blx lr
port_config:
    ldr r0, =__GPIOA_MODER
    ldr r1, [r0]
    mov r2, 1
    orr r1, r1, r2, lsl 18
    str r1, [r0]
    ldr r0, =__GPIOA_PUPDR
    ldr r1, [r0]
    mov r2, 2
    orr r1, r1, r2, lsl 18
    str r1, [r0]
    ldr r0, =__GPIOA_ODR
    ldr r1, [r0]
    orr r1, r1, 512
    str r1, [r0]
    blx lr
