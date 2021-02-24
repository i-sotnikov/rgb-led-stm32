#ifndef _RGB_LED_H
#define _RGB_LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"

/* #define TIM2_FREQUENCY 8000000 */
/* #define TIM2_FREQUENCY 72000000 */

#ifndef TIM2_FREQUENCY
#error "Uncomment TIM2_FREQUENCY from rgb_led.h or define your own"
#endif

/* #define RCC_GPIO_RESET */    /*If defined, the function RGB_LED_Reset() disables the clocking of port A*/

void RGB_LED_Reset(void);
void RGB_LED_Init(void);
void RGB_LED_Stop(void);
void RGB_LED_Start(void);
void RGB_LED_Set(uint8_t red, uint8_t green, uint8_t blue);

#ifdef __cplusplus
}
#endif

#endif /* _RGB_LED_H */
