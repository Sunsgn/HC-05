#include "stm32f10x.h"                  // Device header
#include "NVIC.h"
#include "usart1.h"
#include "motor.h"
#include "hc.h"
#include "LED.h"
#include "delay.h"
#include "hc-sr501.h"
u8 INT_MARK;//�жϱ�־λ
void EXTI_INIT (void)
	{	 
	NVIC_InitTypeDef  NVIC_InitStruct;	//����ṹ�����
	EXTI_InitTypeDef  EXTI_InitStruct;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //����GPIOʱ�� ����Ҫ�븴��ʱ��һͬ������     
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);//���ö˿��ж���Ҫ���ø���ʱ��
		
//��1���ж�	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);  //���� GPIO  �ж�
	
	EXTI_InitStruct.EXTI_Line=EXTI_Line5;  //�����ж���
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //�ж�ʹ��
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //�ж�ģʽΪ �ж�
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //�����ش���
	
	EXTI_Init(& EXTI_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI9_5_IRQn;   //�ж���     
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //ʹ���ж�
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //��ռ���ȼ� 2
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;     //�����ȼ�  2
	NVIC_Init(& NVIC_InitStruct);
	
////��2���ж�	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);  //����  GPIO �ж�
	
	EXTI_InitStruct.EXTI_Line=EXTI_Line0;  //�����ж���
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //�ж�ʹ��
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //�ж�ģʽΪ �ж�
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //�½��ش���
	
	EXTI_Init(& EXTI_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel=EXTI0_IRQn;   //�ж���
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //ʹ���ж�
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //��ռ���ȼ� 2
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;     //�����ȼ�  2
	NVIC_Init(& NVIC_InitStruct);

////��3���ж�	
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource6);  //����  GPIO �ж�
//	
//	EXTI_InitStruct.EXTI_Line=EXTI_Line6;  //�����ж���
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //�ж�ʹ��
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //�ж�ģʽΪ �ж�
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //�½��ش���
//	
//	EXTI_Init(& EXTI_InitStruct);
//	
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI9_5_IRQn;   //�ж���
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //ʹ���ж�
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //��ռ���ȼ� 2
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;     //�����ȼ�  2
//	NVIC_Init(& NVIC_InitStruct);

////��4���ж�	
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource7);  //����  GPIO �ж�
//	
//	EXTI_InitStruct.EXTI_Line=EXTI_Line7;  //�����ж���
//	EXTI_InitStruct.EXTI_LineCmd=ENABLE;              //�ж�ʹ��
//	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;     //�ж�ģʽΪ �ж�
//	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;   //�½��ش���
//	
//	EXTI_Init(& EXTI_InitStruct);
//	
//	NVIC_InitStruct.NVIC_IRQChannel=EXTI9_5_IRQn;   //�ж���
//	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;  //ʹ���ж�
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;  //��ռ���ȼ� 2
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority=2;     //�����ȼ�  2
//	NVIC_Init(& NVIC_InitStruct);

}

//void EXTI9_5_IRQHandler(void)
//	{
//	  //float length;
//	if(EXTI_GetITStatus(EXTI_Line5)!=RESET){//�ж�ĳ�����ϵ��ж��Ƿ���
//       if(PBin(5)==0){		
//        LED0=1;
//				 UsartPrintf(USART3, " 000");
//			 }
//			 else
//			 {
//			  LED0=0;
//				 UsartPrintf(USART3, " 111");
//			 }
//		//while(USART_GetFlagStatus(USART2, USART_FLAG_TC)==RESET);//��鷢���жϱ�־λ
//		EXTI_ClearITPendingBit(EXTI_Line5);   //��� LINE �ϵ��жϱ�־λ
//	}     
//	
//}
//void  EXTI0_IRQHandler(void){
//	if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
//		{//�ж�ĳ�����ϵ��ж��Ƿ���  
//		    //if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_0)==1)
//				//{
//				    //UsartPrintf(USART3,"��������");
//				//}	
//		   EXTI_ClearITPendingBit(EXTI_Line0);   //��� LINE �ϵ��жϱ�־λ
//	}     
//	if(EXTI_GetITStatus(EXTI_Line6)!=RESET){//�ж�ĳ�����ϵ��ж��Ƿ��� 
//		INT_MARK=3;//��־λ��1����ʾ�а����ж�
//		EXTI_ClearITPendingBit(EXTI_Line6);   //��� LINE �ϵ��жϱ�־λ
//	}     
//	if(EXTI_GetI TStatus(EXTI_Line7)!=RESET){//�ж�ĳ�����ϵ��ж��Ƿ��� 
//		INT_MARK=4;//��־λ��1����ʾ�а����ж�
//		EXTI_ClearITPendingBit(EXTI_Line7);   //��� LINE �ϵ��жϱ�־λ
//	}     
//}





