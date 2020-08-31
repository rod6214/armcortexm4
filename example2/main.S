.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.include "constants.inc"

.section .text.main
.type main, %function
.weak main

main:
    ldr r0, =__RCC_AHB1ENR
    ldr r1, [r0]
    orr r1, 1
    str r1, [r0]
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
stop:
    b stop
