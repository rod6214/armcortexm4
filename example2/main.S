.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

@ .set PLLCFGR_CONFIG, 0x402A04
@ .set CFGR_CONFIG, 0x900A
.set CFGR_CONFIG, 0xB405
.set PORT_ENABLE, 0x85
.set ARR1_CONFIG, 200
.set TIM1_CR1_CONFIG, 1
@ .set ARR8_CONFIG, 500
@ .set TIM8_PSC_CONFIG, 65535
.set TIM1_PSC_CONFIG, 15
.set TIM1_DIER_CONFIG, 1 @ UIE
.set TIM1_EGR, 1
.set RCC_APB2ENR_CONFIG, 1 

.include "constants.inc"

.section .text.main
.weak main
.type main, %function

main:
    bl enable_ports
    bl clock_config
    bl port_config
    bl timer_config
    @ bl enable_timer_irq
    @ bl set_porta9
    bl clear_porta9
stop:
    b stop
.section .text.enable_ports, "a"
.weak enable_ports
.type enable_ports, %function
enable_ports:
    push {lr}
    ldr r0, =__RCC_AHB1ENR
    ldr r1, [r0]
    orr r1, r1, PORT_ENABLE
    str r1, [r0]
    pop {lr}
    blx lr
clock_config:
@ System Clock configuration: 8Mhz/M * N/P
@ 8Mhz/4 * 168/2 = 168Mhz (M = 4, N = 168, P = 2)
@ APB2 and APB1 clock = AHB clock divided by 2 (84Mhz)
@ AHB clock = system clock not divided (HSE selected) (168Mhz)
    push {lr}
    @ ldr r0, =__RCC_PLLCFGR
    @ ldr r1, [r0]
    @ ldr r2, =PLLCFGR_CONFIG
    @ orr r1, r1, r2
    @ str r1, [r0]
    ldr r0, =__RCC_CFGR
    ldr r1, [r0]
    ldr r2, =CFGR_CONFIG
    orr r1, r1, r2
    str r1, [r0]
    pop {lr}
    blx lr
port_config:
    push {lr}
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
    bl clear_porta9
    pop {lr}
    blx lr
set_porta9:
    push {lr}
    ldr r0, =__GPIOA_ODR
    ldr r1, =512
    str r1, [r0]
    pop {lr}
    blx lr
clear_porta9:
    push {lr}
    ldr r0, =__GPIOA_ODR
    ldr r1, =0
    str r1, [r0]
    pop {lr}
    blx lr
timer_config:
    push {lr}
    @ TIM1 configuration
    @ ldr r0, =__TIM2_SR
    @ ldr r2, =0
    @ str r2, [r0]
    ldr r0, =__RCC_APB2ENR
    ldr r2, =RCC_APB2ENR_CONFIG @ Configure TIM1EN
    str r2, [r0]

    @ mov r0, 28
    @ and r1, r0, 0x1f
    @ mov r2, 1
    @ lsl r2, r2, r1
    @ and r1, r0, 0xe0

    @ lsr r1, r1, 3

    @ ldr r0, =__NVIC_ISER0

    @ str r2, [r0, r1]
    @ ldr r0, =__NVIC_ISER0
    @ ldr r1, =0x10000000
    @ str r1, [r0]

    ldr r0, =__NVIC_ISER0
    ldr r1, [r0]
    orr r1, r1, 0x10000000
    str r1, [r0]
    
    @ ldr r0, =0xE000ED08
    @ ldr r1, =isr_Vectors
    @ str r1, [r0]
    @ mov r3, 1
    @ msr control, r3
    @ str r1, [r0]
    @ mov r3, 0
    @ msr control, r3

    @ ldr r0, =0xE000E280
    @ ldr r2, =0
    @ str r2, [r0]

    ldr r0, =__TIM2_PSC
    ldr r2, =TIM1_PSC_CONFIG @ Configuring for 84Mhz/65535 = 1.281Khz
    str r2, [r0]

    ldr r0, =__TIM2_ARR
    ldr r2, =ARR1_CONFIG @ Configuring for 1.281Khz/500 = 2.562
    str r2, [r0]

    ldr r0, =__TIM2_CR1
    ldr r2, =TIM1_CR1_CONFIG @ Configure ARPE | URS | CEN
    str r2, [r0]
    @ ldr r0, =__TIM2_EGR               /* update event to apply prescaler*/
    @ ldr r1, [r0]
    @ orr r1, 1
    @ str r1, [r0]

    @ movw r6, 5
    @ ldr r0, =__TIM1_CNT 
    @ ldr r2, =0
    @ str r2, [r0]
    ldr r0, =__TIM2_DIER
    ldr r2, =TIM1_DIER_CONFIG @ Update Interrupt Enabled
    str r2, [r0]

    

    @ ldr r0, =__TIM1_EGR 
    @ ldr r2, =TIM1_EGR @ Configuring for 1.281Khz/500 = 2.562
    @ str r2, [r0]

    pop {lr}
    blx lr
enable_timer_irq:
    push {lr}
    ldr r0, =__NVIC_ISER0
    ldr r1, [r0]
    orr r1, r1, 0x10000000
    str r1, [r0]
    @ ldr r0, =__TIM1_DIER
    @ ldr r2, =TIM1_DIER_CONFIG @ Update Interrupt Enabled
    @ str r2, [r0]
    pop {lr}
    blx lr
tim1_irq:
    push {lr}
    bl set_porta9
    movw r6, 0xffff
    @ ldr r0, =__TIM1_SR 
    @ ldr r2, =0
    @ str r2, [r0]
    pop {lr}
    blx lr
