#include "stm32f10x.h"                  // Device header

void hcsr501_Init(void)
{    //�������
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			// GPIOBʱ��ʹ��	
	// Elude-- 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	// Elude--
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 					// ��������
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// ����ģʽ����Ҫ��˿��ٶ�
	GPIO_Init(GPIOB, &GPIO_InitStructure);							// ��ʼ��	
}

void Bh1750_Init(void)
{    //����
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			// GPIOBʱ��ʹ��	
	// Elude-- 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	// Elude--
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 					// ��������
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// ����ģʽ����Ҫ��˿��ٶ�
	GPIO_Init(GPIOB, &GPIO_InitStructure);							// ��ʼ��	
}

void MIC_Init(void)
{    //����
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			// GPIOBʱ��ʹ��	
	// Elude-- 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	// Elude--
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 					// ��������
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// ����ģʽ����Ҫ��˿��ٶ�
	GPIO_Init(GPIOB, &GPIO_InitStructure);							// ��ʼ��	
}
