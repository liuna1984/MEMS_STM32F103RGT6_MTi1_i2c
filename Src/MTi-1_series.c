#include "gpio.h"
//#include "spi.h"
#include "MTi-1_series.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "i2c.h"
typedef union   
{  
    struct   
    {  
        unsigned char low_byte;  
        unsigned char mlow_byte;  
        unsigned char mhigh_byte;  
        unsigned char high_byte;  
     }float_byte;  
            
     float  value;  
}FLAOT_UNION; 
FLAOT_UNION Rateofrun[3],Acceleration[3],Magneticm[3];
uint8_t version;
uint8_t DRDYstate;
uint8_t recbuffer[100]={0};
uint16_t m_notificationMessageSize;
uint16_t m_measurementMessageSize;

#define DEVICE_ADDR (0x1d<<1)
uint8_t version;
uint8_t DRDYstate;
uint8_t i2c1_rxbuf[100]={0};
uint16_t m_notificationMessageSize;
uint16_t m_measurementMessageSize;
void mydelay(uint16_t delaytime);
void Init_MTi_i2C(void)
{
	uint8_t i2c1_txbuf[10];
  //uint8_t i2c1_rxbuf[10];
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
	//mydelay(1000);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);
	//mydelay(1000);
 
	HAL_GPIO_WritePin(PSEL0_MTi1_GPIO_Port, PSEL0_MTi1_Pin, GPIO_PIN_SET);
	//HAL_Delay(4000);
	i2c1_txbuf[0]=ProtocolInfo;
	//HAL_I2C_Mem_Write(&hi2c1, DEVICE_ADDR,(uint16_t)0x00, I2C_MEMADD_SIZE_8BIT, &i2c1_txbuf[0], 1, 100);
	HAL_I2C_Master_Transmit(&hi2c1, DEVICE_ADDR, (uint8_t*)&i2c1_txbuf[0], 1,100);
	HAL_I2C_Master_Receive(&hi2c1, DEVICE_ADDR, (uint8_t*)&i2c1_rxbuf[0], 2,100);
	//HAL_I2C_Mem_Read(&hi2c1, DEVICE_ADDR, (uint16_t)0x00, I2C_MEMADD_SIZE_8BIT, &i2c1_rxbuf[0], 4, 100);
  version=i2c1_rxbuf[0];
	DRDYstate=i2c1_rxbuf[1];
//	HAL_Delay(1);
	i2c1_txbuf[0]=PipeStatus;
	HAL_I2C_Master_Transmit(&hi2c1, DEVICE_ADDR, (uint8_t*)&i2c1_txbuf[0], 1,100);
	HAL_I2C_Master_Receive(&hi2c1, DEVICE_ADDR, (uint8_t*)&i2c1_rxbuf[0], 4,100);
	m_notificationMessageSize=i2c1_rxbuf[0]|i2c1_rxbuf[1]<<8;
  m_measurementMessageSize=i2c1_rxbuf[2]|i2c1_rxbuf[3]<<8;
	
	
}
void mydelay(uint16_t delaytime)
{
	int i,j;
	for(i=0;i<delaytime;i++)
	for(j=0;j<delaytime;j++)
	{;}
}

void MTiRead(void)
{
//   uint8_t sentbuffer[100];
//	 sentbuffer[0]=MeasurementPipe;
//	 HAL_GPIO_WritePin(GPIOC, CS_MTi1_Pin, GPIO_PIN_SET);
//	 HAL_GPIO_WritePin(GPIOC, CS_MTi1_Pin, GPIO_PIN_RESET);
//	 HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&sentbuffer[0], (uint8_t*)&recbuffer[0],(m_measurementMessageSize+4),100);
//	 HAL_GPIO_WritePin(GPIOC, CS_MTi1_Pin, GPIO_PIN_SET);
	uint8_t i2c1_txbuf[10];
//  uint8_t i2c1_rxbuf[10];
	//i2c1_txbuf[0]=PipeStatus;
	
	i2c1_txbuf[0]=MeasurementPipe;
	HAL_I2C_Master_Transmit(&hi2c1, DEVICE_ADDR, (uint8_t*)&i2c1_txbuf[0], 1,100);
	HAL_I2C_Master_Receive(&hi2c1, DEVICE_ADDR, (uint8_t*)&i2c1_rxbuf[0],(m_measurementMessageSize+4),100);
}

void MTidatadeal(void)
{
	int i,j;
		for(j=0;j<4;j++)
		{
			Rateofrun[j].float_byte.high_byte=i2c1_rxbuf[10+j*4];
			Rateofrun[j].float_byte.mlow_byte=i2c1_rxbuf[12+j*4];
			Rateofrun[j].float_byte.low_byte=i2c1_rxbuf[13+j*4];
		}
//		Orientationq[j].float_byte.low_byte=recbuffer[9+j*4];
//		Orientationq[j].float_byte.mlow_byte=recbuffer[10+j*4];
//		Orientationq[j].float_byte.mhigh_byte=recbuffer[11+j*4];
//		Orientationq[j].float_byte.high_byte=recbuffer[12+j*4];
		for(j=0;j<3;j++)
		{
			Acceleration[j].float_byte.high_byte=i2c1_rxbuf[25+j*4];
			Acceleration[j].float_byte.mhigh_byte=i2c1_rxbuf[26+j*4];
			Acceleration[j].float_byte.mlow_byte=i2c1_rxbuf[27+j*4];
			Acceleration[j].float_byte.low_byte=i2c1_rxbuf[28+j*4];
		}
		for(j=0;j<3;j++)
		{
			Magneticm[j].float_byte.high_byte=i2c1_rxbuf[40+j*4];
			Magneticm[j].float_byte.mhigh_byte=i2c1_rxbuf[41+j*4];
			Magneticm[j].float_byte.mlow_byte=i2c1_rxbuf[42+j*4];
			Magneticm[j].float_byte.low_byte=i2c1_rxbuf[43+j*4];
		}
	 printf("%f %f %f %f %f %f %f %f %f\n",Rateofrun[0].value,Rateofrun[1].value,Rateofrun[2].value,Acceleration[0].value,Acceleration[1].value,Acceleration[2].value,Magneticm[0].value,Magneticm[1].value,Magneticm[2].value);
}