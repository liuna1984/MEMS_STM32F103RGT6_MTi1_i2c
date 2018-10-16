/**
  ******************************************************************************
  * @file    BMP280.h
  * @author  Waveshare Team
  * @version V1.0
  * @date    12-12-2014
  * @brief   Header file for BMP280.c module.
  ******************************************************************************
  */


extern void BMP280_Read_Calibration_i2c();
#ifndef __BSP_BMP280_SPI_H
#define __BSP_BMP280_SPI_H

#include "stm32f1xx_hal.h"
#include "main.h"

#define BMP280_RET_OK   0
#define BMP280_RET_NG   1

/* 
 *  BMP280 I2c address
 */
#define BMP280_ADDR        BMP280_AD0_LOW     // default I2C address  
#define BMP280_AD0_LOW     0xEC //address pin low (GND)
#define BMP280_AD0_HIGH    0xEE //address pin high (VCC)

/* 
 *  BMP280 register address
 */
#define BMP280_REGISTER_DIG_T1      0x88
#define BMP280_REGISTER_DIG_T2      0x8A
#define BMP280_REGISTER_DIG_T3      0x8C

#define BMP280_REGISTER_DIG_P1      0x8E
#define BMP280_REGISTER_DIG_P2      0x90
#define BMP280_REGISTER_DIG_P3      0x92
#define BMP280_REGISTER_DIG_P4      0x94
#define BMP280_REGISTER_DIG_P5      0x96
#define BMP280_REGISTER_DIG_P6      0x98
#define BMP280_REGISTER_DIG_P7      0x9A
#define BMP280_REGISTER_DIG_P8      0x9C
#define BMP280_REGISTER_DIG_P9      0x9E 

#define BMP280_REGISTER_CHIPID      0xD0
#define BMP280_REGISTER_VERSION     0xD1
#define BMP280_REGISTER_SOFTRESET   0xE0
#define BMP280_REGISTER_STATUS      0xF3
#define BMP280_REGISTER_CONTROL     0xF4
#define BMP280_REGISTER_CONFIG      0xF5

#define BMP280_TEMP_XLSB_REG        0xFC	    /*Temperature XLSB Register */
#define BMP280_TEMP_LSB_REG         0xFB        /*Temperature LSB Register  */ 
#define BMP280_TEMP_MSB_REG         0xFA        /*Temperature LSB Register  */  
#define BMP280_PRESS_XLSB_REG       0xF9		/*Pressure XLSB  Register   */
#define BMP280_PRESS_LSB_REG        0xF8		/*Pressure LSB Register     */
#define BMP280_PRESS_MSB_REG        0xF7		/*Pressure MSB Register     */	

/*calibration parameters */  
#define BMP280_DIG_T1_LSB_REG       0x88  
#define BMP280_DIG_T1_MSB_REG       0x89  
#define BMP280_DIG_T2_LSB_REG       0x8A  
#define BMP280_DIG_T2_MSB_REG       0x8B  
#define BMP280_DIG_T3_LSB_REG       0x8C  
#define BMP280_DIG_T3_MSB_REG       0x8D  
#define BMP280_DIG_P1_LSB_REG       0x8E  
#define BMP280_DIG_P1_MSB_REG       0x8F  
#define BMP280_DIG_P2_LSB_REG       0x90  
#define BMP280_DIG_P2_MSB_REG       0x91  
#define BMP280_DIG_P3_LSB_REG       0x92  
#define BMP280_DIG_P3_MSB_REG       0x93  
#define BMP280_DIG_P4_LSB_REG       0x94  
#define BMP280_DIG_P4_MSB_REG       0x95  
#define BMP280_DIG_P5_LSB_REG       0x96  
#define BMP280_DIG_P5_MSB_REG       0x97  
#define BMP280_DIG_P6_LSB_REG       0x98  
#define BMP280_DIG_P6_MSB_REG       0x99  
#define BMP280_DIG_P7_LSB_REG       0x9A  
#define BMP280_DIG_P7_MSB_REG       0x9B  
#define BMP280_DIG_P8_LSB_REG       0x9C  
#define BMP280_DIG_P8_MSB_REG       0x9D  
#define BMP280_DIG_P9_LSB_REG       0x9E  
#define BMP280_DIG_P9_MSB_REG       0x9F

//typedef struct {	 
//	uint16_t T1; 		/*<calibration T1 data*/
//	int16_t T2;  	 	/*<calibration T2 data*/
//	int16_t T3;  		/*<calibration T3 data*/
//	uint16_t P1;  	    /*<calibration P1 data*/
//	int16_t P2;  		/*<calibration P2 data*/
//	int16_t P3;  		/*<calibration P3 data*/
//	int16_t P4;  		/*<calibration P4 data*/
//	int16_t P5;  		/*<calibration P5 data*/
//	int16_t P6;  		/*<calibration P6 data*/
//	int16_t P7;  		/*<calibration P7 data*/
//	int16_t P8;  		/*<calibration P8 data*/
//	int16_t P9;			/*<calibration P9 data*/
//	int32_t T_fine;	/*<calibration t_fine data*/
//}BMP280_HandleTypeDef;

typedef struct
{
	uint8_t Index;
	int32_t AvgBuffer[8];
}BMP280_AvgTypeDef;

#define MSLP     101325          // Mean Sea Level Pressure = 1013.25 hPA (1hPa = 100Pa = 1mbar)

extern I2C_HandleTypeDef hi2c1;

extern int32_t PressureVal, TemperatureVal, AltitudeVal;

extern uint16_t dig_T1;  
extern int16_t dig_T2; 
extern int16_t dig_T3;  
extern uint16_t dig_P1; 
extern int16_t dig_P2;  
extern int16_t dig_P3; 
extern int16_t dig_P4; 
extern int16_t dig_P5; 
extern int16_t dig_P6; 
extern int16_t dig_P7; 
extern int16_t dig_P8; 
extern int16_t dig_P9; 
extern int32_t t_fine; 

//BMP280_HandleTypeDef bmp280;
extern int32_t gs32Pressure0; 
extern int16_t AC1, AC2, AC3, B1, B2, MB, MC, MD, _oss;  
extern uint16_t AC4, AC5, AC6;
extern int32_t B5, UT, UP, Pressure0; 
extern int32_t PressureVal, TemperatureVal, AltitudeVal;
extern int BMP280_COUNTER;
extern double PRESSURE_FILTER[8];

/* 
 *  extern interface
 */
#ifdef BUS_IO
#include "I2C_IO.h"

extern uint8_t BMP280_Initl_io(void);
extern void BMP280_CalTemperatureAndPressureAndAltitude_io(int32_t *temperature, int32_t *pressure, int32_t *Altitude);

#endif
 
#ifdef BUS_I2C

#include "i2c.h"

extern uint8_t BMP280_Initl_i2c(void);
extern void BMP280_CalTemperatureAndPressureAndAltitude_i2c(int32_t *temperature, int32_t *pressure, int32_t *Altitude);

#endif

#ifdef BUS_SPI

#include "spi.h"

#define BMP280_READ          0x80      // SPI Address format, bit7 - > Read (1) or Write (0) operation ;
#define BMP280_WRITE         0x7F      // SPI Address format, bit7 - > Read (1) or Write (0) operation ;

#define GPIO_CS280           GPIO_PIN_4
#define PORT_CS280           GPIOC

#define CS280_LOW            HAL_GPIO_WritePin(PORT_CS280, GPIO_CS280, GPIO_PIN_RESET);          
#define CS280_HIGH           HAL_GPIO_WritePin(PORT_CS280, GPIO_CS280, GPIO_PIN_SET); 

extern uint8_t BMP280_Initl_spi(void);
extern void BMP280_CalTemperatureAndPressureAndAltitude_spi(int32_t *temperature, int32_t *pressure, int32_t *Altitude);

#endif
#endif /* __BMP280_H */

/******************* (C) COPYRIGHT 2016 Waveshare *****END OF FILE*******************/
