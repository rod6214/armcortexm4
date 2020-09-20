#include "registers.h"
#include "interrupts.h"

void Config_SystemClock();

int main() {
    NVIC_type* _nvic = NVIC_GetRegister();

    Config_SystemClock();

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
    if (count >= 200) {
        GPIO_TogglePin(GPIOA, 9);
        count = 0;
    }
    count++;
    TIM_RESET_flags(TIM2);
    TIM2->CR1 = 1;
}

void Config_SystemClock() {

    // Configuration: 8Mhz/4*168/6 = 56Mhz
    RCC->PLLCFGR = RCC_PLLCFGR_PLLP_div_by_6
    | RCC_PLLCFGR_PLLN_mul_by_(168UL)
    | RCC_PLLCFGR_PLLM_div_by_(4UL)
    | RCC_PLLCFGR_HSE_AS_SOURCE_CLOCK;

    RCC->CR = RCC_CR_HSE_ON | RCC_CR_CSS_ON | RCC_CR_PLL_ON;

    while(!RCC_PLLCFGR_HSE_IS_READY());
    while(!RCC_PLLCFGR_PLL_IS_READY());
    // Set latency for cpu
    FLASHI->ACR = FLASH_ACR_LATENCY(2);
    // Configure buffer's speed
    // APBx: 16Mhz/4 = 4Mhz
    // APBx (timer): 4Mhz * 2 = 8Mhz
    // AHBx: 10.5Mhz
    RCC->CFGR = RCC_CFGR_PPRE2_Div_by_4
    | RCC_CFGR_PPRE1_Div_by_4
    | RCC_CFGR_HPRE_No_Div
    | RCC_CFGR_SW_PLL;

    // RCC->CR |= RCC_CR_PLL_ON;

    while ((RCC->CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL);
}
