/* USER CODE BEGIN FirstSection */
/* can be used to modify / undefine following code or add new definitions */
/* USER CODE END FirstSection */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_gpio.h"
#include  <stdio.h>

#include "main.h"

#define  GPIO_LED1          GPIO_PIN_14
#define  GPIO_LED2          GPIO_PIN_13
#define  GPIO_LED3          GPIO_PIN_12

#define  PORT_LED1          GPIOB
#define  PORT_LED2          GPIOB
#define  PORT_LED3          GPIOB

#define  LED1_ON            HAL_GPIO_WritePin(PORT_LED1, GPIO_LED1, GPIO_PIN_RESET);          
#define  LED1_OFF           HAL_GPIO_WritePin(PORT_LED1, GPIO_LED1, GPIO_PIN_SET); 

#define  LED2_ON            HAL_GPIO_WritePin(PORT_LED2, GPIO_LED2, GPIO_PIN_RESET);          
#define  LED2_OFF           HAL_GPIO_WritePin(PORT_LED2, GPIO_LED2, GPIO_PIN_SET); 

#define  LED3_ON            HAL_GPIO_WritePin(PORT_LED3, GPIO_LED3, GPIO_PIN_RESET);          
#define  LED3_OFF           HAL_GPIO_WritePin(PORT_LED3, GPIO_LED3, GPIO_PIN_SET); 

#define  LED1_TOGGLE        HAL_GPIO_TogglePin(PORT_LED1, GPIO_LED1);
#define  LED2_TOGGLE        HAL_GPIO_TogglePin(PORT_LED2, GPIO_LED2);
#define  LED3_TOGGLE        HAL_GPIO_TogglePin(PORT_LED3, GPIO_LED3);

/* Extern variables ---------------------------------------------------------*/ 
  

/*
*********************************************************************************************************
*                                             BSP_LED_Init()
*
* Description : Initialize the I/O for the LEDs
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : BSP_Init().
*
* Note(s)     : none.
*********************************************************************************************************
*/

//void BSP_LED_Init (void)
//{
//  GPIO_InitTypeDef GPIO_InitStruct;

//  // GPIO Ports Clock Enable  
//  __HAL_RCC_GPIOD_CLK_ENABLE();

//  // Configure GPIO pin Output Level  
//  HAL_GPIO_WritePin(GPIOD, BSP_GPIOD_LED1 | BSP_GPIOD_LED2 | BSP_GPIOD_LED3, GPIO_PIN_RESET);

//  // Configure GPIO pins 
//  GPIO_InitStruct.Pin = BSP_GPIOD_LED1 | BSP_GPIOD_LED2 | BSP_GPIOD_LED3;
//  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
//}


/*
*********************************************************************************************************
*                                             BSP_LED_OnOff()
*
* Description : Turn ON any or all the LEDs on of the board.
*
* Argument(s) : led     The ID of the LED to control:
*
*                       0    OnOff ALL the LEDs
*                       1    OnOff user LED1  on the board
*                       2    OnOff user LED2  on the board
*                       3    OnOff user LED3  on the board
*
*               State   The is LED State
*                       GPIO_PIN_RESET: to clear the port pin
*                       GPIO_PIN_SET:   to set the port pin
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void BSP_LED_OnOff (uint16_t led, GPIO_PinState State)
{
    switch (led) {
        case 0:
             if( State == GPIO_PIN_RESET)
						 {
							 LED1_ON;
							 LED2_ON;
							 LED3_ON;
						 }
						 else 
             {
							 LED1_OFF;
							 LED2_OFF;
							 LED3_OFF;
             }							 
             break;

        case 1:
             if( State == GPIO_PIN_RESET)
						 {
							 LED1_ON;
						 }
						 else 
             {
							 LED1_OFF;
             }	
             break;
				
        case 2:
             if( State == GPIO_PIN_RESET)
						 {
							 LED2_ON;
						 }
						 else 
             {
							 LED2_OFF;
             }	
             break;
				
        case 3:
             if( State == GPIO_PIN_RESET)
						 {
							 LED3_ON;
						 }
						 else 
             {
							 LED3_OFF;
             }	
             break;

        default:
             break;
    }
}



/*
*********************************************************************************************************
*                                            BSP_LED_Toggle()
*
* Description : TOGGLE any or all the LEDs on the board.
*
* Argument(s) : led     The ID of the LED to control:
*
*                       0    TOGGLE ALL the LEDs
*                       1    TOGGLE user LED1  on the board
*                       2    TOGGLE user LED2  on the board
*                       3    TOGGLE user LED3  on the board
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void BSP_LED_Toggle (uint16_t led)
{
    switch (led) {
        case 0:
             LED1_TOGGLE;
				     LED2_TOGGLE;
				     LED3_TOGGLE;
             break;

        case 1:
             LED1_TOGGLE;
             break;

        case 2:
             LED2_TOGGLE;
             break;
				
        case 3:
             LED3_TOGGLE;
             break;

        default:
             break;
    }
}



/* USER CODE END AdditionalCode */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
