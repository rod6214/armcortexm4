#include "registers.h"

int main() {
    // int* __ahb1en = ((int*)__RCC_AHB1ENR);
    // int* __gpiomoder = ((int*)__GPIOA_MODER);
    // int* __gpioddr = ((int*)__GPIOA_ODR);
    // int* __tim2 = ((int*)0x40010000);
    // _RCC* __rcc = ((_RCC*)0x40023800);
    // volatile int* __rcc2 = ((int*)0x40023800);
    // __rcc2[0] = 1;
    // RCC_APB2ENR
    RCC->APB2ENR = 1;
    // TIM2_PSC
    TIM2->PSC = 15;
    // TIM2_ARR
    TIM2->ARR = 200;
    // TIM2_CR1
    TIM2->CR1 = 1;
    // TIM2_DIER
    TIM2->DIER = 1;

    // *__ahb1en |= 1;
    // *__gpiomoder |= 1 << 18;
    // *__gpioddr |= 512;

    while(1) {

    }

    return 0;
}