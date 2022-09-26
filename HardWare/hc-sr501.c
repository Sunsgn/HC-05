#include "stm32f10x.h"                  // Device header

void hcsr501_Init(void)
{    //人体红外
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			// GPIOB时钟使能	
	// Elude-- 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	// Elude--
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 					// 上拉输入
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// 输入模式不需要设端口速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);							// 初始化	
}

void Bh1750_Init(void)
{    //光敏
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			// GPIOB时钟使能	
	// Elude-- 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	// Elude--
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 					// 上拉输入
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// 输入模式不需要设端口速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);							// 初始化	
}

void MIC_Init(void)
{    //声音
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			// GPIOB时钟使能	
	// Elude-- 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	// Elude--
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 					// 上拉输入
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				// 输入模式不需要设端口速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);							// 初始化	
}
