#ifndef __INTERRUPTS_HD__
#define __INTERRUPTS_HD__

#include "registers.h"


#define TIMx_UIF 1
#define TIMx_CC1IF 2
#define TIMx_CC2IF 4
#define TIMx_CC3IF 8
#define TIMx_CC4IF 16
#define TIMx_TIF 64
#define TIMx_CC1OF 512
#define TIMx_CC2OF 1024
#define TIMx_CC3OF 2048
#define TIMx_CC4OF 4096

#define UIFBit 0
#define CC1IFBit 1
#define CC2IFBit 2
#define CC3IFBit 3
#define CC4IFBit 4
#define TIFBit 6
#define CC1OFBit 9
#define CC2OFBit 10
#define CC3OFBit 11
#define CC4OFBit 12

#define NFALSE 0
#define NTRUE 1

#define IS_TIM_IT_FLAG(__TIM_REF__, __TIM_FLAG__) ((__TIM_REF__)->SR & __TIM_FLAG__)  == __TIM_FLAG__
#define RESET_TIM_IT_FLAG(__TIM_REF__, __TIM_FLAG__) (__TIM_REF__)->SR &=  ~(__TIM_FLAG__)

#ifdef __cplusplus
extern "C" {
#endif

extern void TIM2_IRQHandler(void);
extern void TIM_RESET_flags(TIM_type* timx);

#ifdef __cplusplus
}
#endif

#endif /*__INTERRUPTS_HD__*/
