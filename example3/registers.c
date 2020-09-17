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
}
