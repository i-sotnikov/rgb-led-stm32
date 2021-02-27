# Описание библиотеки RGB LED STM32
## Назначение
Данная маленькая библиотека предназначена для упрощённой работы с RGB-светодиодами.
## Совместимость
Библиотека написана для микроконтроллера **STM32F103C8T6**, но должна работать для
микроконтроллеров **STM32F103Cxxx**.
## Описание функций библиотеки
В состав библиотеки входит пять функций:
```c
void RGB_LED_Reset(void);
void RGB_LED_Init(void);
void RGB_LED_Stop(void);
void RGB_LED_Start(void);
void RGB_LED_Set(uint8_t red, uint8_t green, uint8_t blue);
```
Рассмотрим предназначение каждой из них:

1. `RGB_LED_Reset()`<br>
    Данная функция ... <br>
    Также функция может отключать тактирование
    используемого порта GPIOA при раскомментировании
    соответствующей строки: 
    ```c
    /* #define RCC_GPIO_RESET */
    ...
    #ifdef RCC_GPIO_RESET
    /* GPIO port A clock disable */
    CLEAR_BIT(RCC->ABP2ENR, RCC_APB2ENR_IOPAEN);
    #endif
    ```

2. `RGB_LED_Init()`<br>
    Данная функция ...<br>
    Для работы функции необходимо раскомментировать строку
    с нужной частотой тактирования таймера:
    ```c
    /* #define TIM2_FREQUENCY 8000000 */
    /* #define TIM2_FREQUENCY 72000000 */
    ```
3. `RGB_LED_Stop()`<br>
    Данная функция ...

4. `RGB_LED_Start()`<br>
    Данная функция ...

5. `RGB_LED_Set(red, green, blue)`<br>
    Данная функция ...
