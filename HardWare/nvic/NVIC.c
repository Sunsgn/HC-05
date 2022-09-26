#include "stm32f10x.h"                  // Device header
#include "NVIC.h"
#include "usart1.h"
#include "motor.h"
#include "hc.h"
#include "LED.h"
#include "delay.h"
#include "hc-sr501.h"
u8 INT_MARK;//中断标志位
void EXTI_INIT (void)
	{	 
	NVIC_InitTypeDef  NVIC_InitStruct;	//定义结构体变量
	EXTI_InitTypeDef  EXTI_InitStruct;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //启动GPIO时钟 （需要与复用时钟一同启动）     
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);//配置端口中断需要启用复用时钟
		
//第1个中断	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);  //定义 GPIO  中断
	
	EXTI_InitStruct.EXTI_Line=EXTI_Line5;  //定义中断线
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //中断使能
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //中断模式为 中断
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //上升沿触发
	
	EXTI_Init(& EXTI_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI9_5_IRQn;   //中断线     
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //使能中断
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //抢占优先级 2
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;     //子优先级  2
	NVIC_Init(& NVIC_InitStruct);
	
////第2个中断	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);  //定义  GPIO 中断
	
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;  //定义中断线
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //中断使能
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //中断模式为 中断
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //下降沿触发
	
	EXTI_Init(& EXTI_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;   //中断线
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //使能中断
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //抢占优先级 2
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;     //子优先级  2
	NVIC_Init(& NVIC_InitStruct);

////第3个中断	
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource6);  //定义  GPIO 中断
//	
//	EXTI_InitStruct.EXTI_Line=EXTI_Line6;  //定义中断线
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //中断使能
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //中断模式为 中断
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //下降沿触发
//	
//	EXTI_Init(& EXTI_InitStruct);
//	
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI9_5_IRQn;   //中断线
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //使能中断
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //抢占优先级 2
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;     //子优先级  2
//	NVIC_Init(& NVIC_InitStruct);

////第4个中断	
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource7);  //定义  GPIO 中断
//	
//	EXTI_InitStruct.EXTI_Line=EXTI_Line7;  //定义中断线
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //中断使能
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //中断模式为 中断
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //下降沿触发
//	
//	EXTI_Init(& EXTI_InitStruct);
//	
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI9_5_IRQn;   //中断线
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //使能中断
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //抢占优先级 2
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;     //子优先级  2
//	NVIC_Init(& NVIC_InitStruct);

}

//void EXTI9_5_IRQHandler(void)
//	{
//	  //float length;
//	if(EXTI_GetITStatus(EXTI_Line5)!=RESET){//判断某个线上的中断是否发生
//       if(PBin(5)==0){		
//        LED0=1;
//				 UsartPrintf(USART3, " 000");
//			 }
//			 else
//			 {
//			  LED0=0;
//				 UsartPrintf(USART3, " 111");
//			 }
//		//while(USART_GetFlagStatus(USART2, USART_FLAG_TC)==RESET);//检查发送中断标志位
//		EXTI_ClearITPendingBit(EXTI_Line5);   //清除 LINE 上的中断标志位
//	}     
//	
//}
//void  EXTI0_IRQHandler(void){
//	if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
//		{//判断某个线上的中断是否发生  
//		    //if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_0)==1)
//				//{
//				    //UsartPrintf(USART3,"这里有人");
//				//}	
//		   EXTI_ClearITPendingBit(EXTI_Line0);   //清除 LINE 上的中断标志位
//	}     
//	if(EXTI_GetITStatus(EXTI_Line6)!=RESET){//判断某个线上的中断是否发生 
//		INT_MARK=3;//标志位置1，表示有按键中断
//		EXTI_ClearITPendingBit(EXTI_Line6);   //清除 LINE 上的中断标志位
//	}     
//	if(EXTI_GetI TStatus(EXTI_Line7)!=RESET){//判断某个线上的中断是否发生 
//		INT_MARK=4;//标志位置1，表示有按键中断
//		EXTI_ClearITPendingBit(EXTI_Line7);   //清除 LINE 上的中断标志位
//	}     
//}





