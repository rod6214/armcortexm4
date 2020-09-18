#include "registers.h"
#include "interrupts.h"

int main() {
    NVIC_type* _nvic = NVIC_GetRegister();

    RCC->APB1ENR |= 1;
    RCC->AHB1ENR |= 1;
    _nvic->ISER[0] = (1UL << 28);
    GPIOA->MODER |= (1UL << 18);
    GPIOA->PUPDR |= (2UL << 18);
    TIM_RESET_flags_ALL(TIM2);
    TIM2->PSC = 15;
    TIM2->ARR = 200;
    TIM2->CR1 = 1;
    TIM2->DIER = 1;
    
    while(1);

    return 0;
}

int count = 0;

void TIM2_IRQHandler() {
    TIM2->CR1 = 0;
    if (count > 2000) {
        GPIO_TogglePin(GPIOA, 9);
        count = 0;
    }
    count++;
    TIM_RESET_flags(TIM2);
    TIM2->CR1 = 1;
}
