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
	
	/********************��ȡMDC04_ROM_ID*******************************/
		MY_Read_ROM();
	
	/********************������������***********************************/
	MY_Range(Cmin,11); 		//Cmax-Cmin<31pF�����������С����ֵ��ȷ�����̷�Χ
	MY_F(MDC04_REPEATABILITY_HIGH,MDC04_MPS_SINGLE);		//���ø��ظ��ԣ����β���
	MY_Channel(0x07);
	while(1)
	{
		/********************��������*************************************/
		MY_T();
		/********************�¶ȼ�1ͨ�����ݲ���**************************/
//		MY_TC1();
		/********************4ͨ�����ݲ���********************************/
		MY_C();
		//ow_Delay_ms(100);
		
//		ow_Delay_ms(1000000);     
	}
}

