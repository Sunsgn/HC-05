 /* 接线
 *  hc-sr501 ---PB0
 *  esp8266  ---PB2--RX,  PB3--TX;          Debage---PB10,11
 *  HC      ----PB1 TRIG ,PB4----ECHO      SG901-- -PA1   
 *  Bh107   ----PB5     LED继电器  ---PA4
 *   PWM    ----PA8,9,10,11
*/

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "timer1.h"   
#include "motor.h"
#include "USART1.h"             
#include "hc-sr501.h"

#include "led.h"
#include "hc.h"

#include "SG90.h"
#include "NVIC.h"

#include "sys.h"
#include <stdio.h>

u8 user_set_flag=0;


int main(void)
{ 

	int dis[3];//超声波距离
	TIM1_PWM_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_ms(1000);    //等待初始化
	LED_Init();             //LED 
	Hcsr04Init();           //超声波
	Bh1750_Init();          // 光敏
	SG901_Init();           //舵机
	Usart3_Init(9600);       //debug
	delay_ms(500);
	Hcsr04Init();     
	TIM_SetCompare2(TIM2, 1500);   //舵机初始化

	while (1)
	{ 
		dis[1] = Hcsr04GetLength();   //中间
		UsartPrintf(USART3,"%f",dis[1]);
		if(dis[1]>30)    //前进
	  {
		  Car_Forward();
	  }
		if(dis[1]<30)        //超声避障 
		 {
		     Car_Stopward();    
	 		 delay_ms(1000);
			 TIM_SetCompare2(TIM2, 2300);    //舵机左转
			 delay_ms(500);
			 dis[2] = Hcsr04GetLength();       //左间距离
			 delay_ms(500);
			 TIM_SetCompare2(TIM2, 1500);
			 delay_ms(500);
			 TIM_SetCompare2(TIM2, 700);
			 delay_ms(500);
			 TIM_SetCompare2(TIM2, 1500);
			 dis[0] = Hcsr04GetLength();      //右边距离
	 		 delay_ms(500);
		 
		  if(dis[2]<30&&dis[0]>30)
		 {
		     Car_Liftward();
			 delay_ms(800); 
		 }
		 
		 else if(dis[2]>30&&dis[0]<30)
		 {
		     Car_Rightward();
			 delay_ms(800); 
		 }
		 else if(dis[2]>30&&dis[0]>30)
		 {
		    Car_Rightward();
			 delay_ms(800); 
		 }
		 else if(dis[2]<30&&dis[0]<30)
		 {
		     Car_Backward();
			 delay_ms(2000); 
			 Car_Rightward();
			 delay_ms(800);
		 }
	 }

	} 
}	


 
void USART3_IRQHandler(void)  
{  
		u8 res;
    if(USART_GetITStatus(USART3,USART_IT_RXNE)!=RESET)  
		{	 
		  res= USART_ReceiveData(USART3);  // 串口3 接收
			if(res=='1')
			{
				Car_Forward();		
			}
			if(res=='2')
			{ 
				Car_Backward();
			}
			if(res=='3')
			{ 
			  Car_Stopward();
				LED0=0;
			}
			if(res=='4')
			{
				Car_Rightward();
				
			}
			if(res=='5')
			{
			  Car_Liftward();
			
			}
			if(res=='6')
			{
				LED0=1;
			//speed=speed+100;
			}
			if(res=='7')
			{
			  TIM_SetCompare2(TIM2, 2300);
			 
			}
			if(res=='8')
			{
	
			  TIM_SetCompare2(TIM2, 1500);
			}
			if(res=='9')
			{
	
			  TIM_SetCompare2(TIM2, 700);
			}

		USART_SendData(USART3,res);   // 串口3 发送
	}	
		USART_ClearFlag(USART3, USART_FLAG_RXNE);
} 
 

