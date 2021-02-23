#include "rgb_led.h"

void RGB_LED_Init(void)
{
        /* RCC initialization */
        /* GPIO port A clock enable */
        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);

        /* TIM2 timer clock enable */
        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);

        /* GPIO initialization */
        /* Pins A1-3, alternate function output Push-Pull, 2 MHz */
        MODIFY_REG(GPIOA->CRL,
                   GPIO_CRL_MODE1   | GPIO_CRL_CNF1   |
                   GPIO_CRL_MODE2   | GPIO_CRL_CNF2   |
                   GPIO_CRL_MODE3   | GPIO_CRL_CNF3,
                   GPIO_CRL_MODE1_1 | GPIO_CRL_CNF1_1 |
                   GPIO_CRL_MODE2_1 | GPIO_CRL_CNF2_1 |
                   GPIO_CRL_MODE3_1 | GPIO_CRL_CNF3_1);

        /* TIM2 initialization, channels 2, 3, 4 */
        /* Enable compare */
        SET_BIT(TIM2->CCER, TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E);

        /* Output compare PWM mode 1 */
        SET_BIT(TIM2->CCMR1, TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);
        SET_BIT(TIM2->CCMR2,
                             TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 |
                             TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2);
        
        /* Prescaler */
        WRITE_REG(TIM2->PSC, TIM2_FREQUENCY / 5000000);

        /* Auto-reload register */
        WRITE_REG(TIM2->ARR, 255);
}

void RGB_LED_Stop(void)
{
        /* Disable counter */           
        CLEAR_BIT(TIM2->CR1, TIM_CR1_CEN);

        /* Re-initialize the counter */
        SET_BIT(TIM2->EGR, TIM_EGR_UG);
}

void RGB_LED_Start(void)
{
        /* Re-initialize the counter */
        SET_BIT(TIM2->EGR, TIM_EGR_UG);

        /* Enable counter */           
        SET_BIT(TIM2->CR1, TIM_CR1_CEN);
}
