#include <stdio.h>
#include <stdlib.h>

#include "stm32f10x.h"

#include "bsp_SysTick.h"
#include "bsp_usart1.h"

#include "MY_ow.h"
#include "MDC04_driver.h"

int main(void)
{ 
	float Cmin=0, Cmax=30;

	USART1_Config();
	SysTick_Init();
	
	OW_Init();
	
	/********************读取MDC04_ROM_ID*******************************/
		MY_Read_ROM();
	
	/********************电容配置流程***********************************/
	MY_Range(Cmin,11); 		//Cmax-Cmin<31pF，配置最大最小电容值，确定量程范围
	MY_F(MDC04_REPEATABILITY_HIGH,MDC04_MPS_SINGLE);		//配置高重复性，单次测量
	MY_Channel(0x07);
	while(1)
	{
		/********************单独测温*************************************/
		MY_T();
		/********************温度及1通道电容测量**************************/
//		MY_TC1();
		/********************4通道电容测量********************************/
		MY_C();
		//ow_Delay_ms(100);
		
//		ow_Delay_ms(1000000);     
	}
}

