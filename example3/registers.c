#include "registers.h"
#include "interrupts.h"

NVIC_type __NVIC;

NVIC_type* NVIC_GetRegister() {
    __NVIC.ISER = ((unsigned int*)NVIC_ISER_BASE);
    __NVIC.ICER = ((unsigned int*)NVIC_ICER_BASE);
    __NVIC.ICPR = ((unsigned int*)NVIC_ICPR_BASE);
    __NVIC.ISPR = ((unsigned int*)NVIC_ISPR_BASE);
    __NVIC.IPR = ((unsigned int*)NVIC_IPR_BASE);
    __NVIC.IABR = ((unsigned int*)NVIC_IABR_BASE);
    __NVIC.STIR = ((unsigned int*)NVIC_STIR_BASE);
    return &__NVIC;
}

void TIM_RESET_flags(TIM_type* timx) {
    if (IS_TIM_IT_FLAG(timx, TIMx_UIF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_UIF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC1IF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC1IF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC2IF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC2IF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC3IF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC3IF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC4IF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC4IF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_TIF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_TIF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC1OF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC1OF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC2OF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC2OF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC3OF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC3OF);
    }
    if (IS_TIM_IT_FLAG(timx, TIMx_CC4OF) != NFALSE) {
        RESET_TIM_IT_FLAG(timx, TIMx_CC4OF);
    }
}

void GPIO_TogglePin(GPIO_type* gpio, int pin) {
    static int counter = 0;
    if (GET_BIT_REGISTER(gpio->ODR, pin)) {
        SET_BIT_HIGH_REGISTER(gpio->BSRR, pin); // Reset
    }
    else {
        SET_BIT_LOW_REGISTER(gpio->BSRR, pin);
    } 
}
