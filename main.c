
#define __OTYPER 0x04
#define __OSPEEDR 0x08
#define __PUPDR 0x0C
#define __IDR 0x10
#define __ODR 0x14
#define __BSRR 0x18
#define __LCKR 0x1C
#define __AFRL 0x20
#define __AFRH 0x24

#define __AHB1 0x40020000
#define __GPIOA (__AHB1)
#define __GPIOB (__AHB1 + 0x400)
#define __GPIOC (__AHB1 + 0x800)
#define __GPIOH (__AHB1 + 0x1C0)
#define __RCC (__AHB1 + 0x3800)

#define __GPIOA_MODER (__GPIOA)
#define __GPIOA_OTYPER (__GPIOA + __OTYPER)
#define __GPIOA_OSPEEDR (__GPIOA + __OSPEEDR)
#define __GPIOA_PUPDR __GPIOA + __PUPDR)
#define __GPIOA_IDR (__GPIOA + __IDR)
#define __GPIOA_ODR (__GPIOA + __ODR)
#define __GPIOA_BSRR (__GPIOA + __BSRR)
#define __GPIOA_LCKR (__GPIOA + __LCKR)
#define __GPIOA_AFRL (__GPIOA + __AFRL)
#define __GPIOA_AFRH (__GPIOA + __AFRH)

// #define __RCC_CR __RCC
#define __RCC_CFGR (__RCC + 8)
#define __RCC_PLLCFGR (__RCC + 4)
#define __RCC_BDCR (__RCC + 0x70)
#define __RCC_AHB1ENR (__RCC + 0x30)

int main() {
    int* __ahb1en = ((int*)__RCC_AHB1ENR);
    int* __gpiomoder = ((int*)__GPIOA_MODER);
    int* __gpioddr = ((int*)__GPIOA_ODR);

    *__ahb1en |= 1;
    *__gpiomoder |= 1 << 18;
    *__gpioddr |= 512;

    return 0;
}