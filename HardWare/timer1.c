#include "stm32f10x.h"                  // Device header

void TIM1_GPIO_Config(void)
{  
      GPIO_InitTypeDef GPIO_InitStructure;  
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);   
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);     
 
      GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 | GPIO_Pin_9| GPIO_Pin_10 | GPIO_Pin_11;   
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                    // 复用推挽输出  
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
      GPIO_Init(GPIOA, &GPIO_InitStructure);
  }
void TIM1_Mode_Config(void)
{        
      TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;        
      TIM_OCInitTypeDef  TIM_OCInitStructure;       
      u16 CCR1_Val = 90;                
      u16 CCR2_Val = 90;       
      u16 CCR3_Val = 90;        
      u16 CCR4_Val = 90; 
  
     TIM_TimeBaseStructure.TIM_Period = 999;       //当定时器从0计数到999，即为1000次，为一个定时周期  
     TIM_TimeBaseStructure.TIM_Prescaler =99;             
     TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;        //设置时钟分频系数：不分频           
 
     TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式  
	   TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
     TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);                   
 
     TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;            //配置为PWM模式1   
     TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;               
     TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;         
     TIM_OCInitStructure.TIM_Pulse = CCR1_Val;           //设置跳变值，当计数器计数到这个值时，电平发生跳变 
     TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR1_Val时为高电平  
     TIM_OC1Init(TIM1, &TIM_OCInitStructure);         //使能通道1  
     TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  
 
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   
    TIM_OCInitStructure.TIM_Pulse = CCR2_Val;          //设置通道2的电平跳变值，输出另外一个占空比的PWM   
    TIM_OC2Init(TIM1, &TIM_OCInitStructure);          //使能通道2 
    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);          
 
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   
    TIM_OCInitStructure.TIM_Pulse = CCR3_Val;        //设置通道3的电平跳变值，输出另外一个占空比的PWM   
    TIM_OC3Init(TIM1, &TIM_OCInitStructure);         //使能通道3   
    TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);    
 
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
    TIM_OCInitStructure.TIM_Pulse = CCR4_Val;        //设置通道4的电平跳变值，输出另外一个占空比的PWM  
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);        //使能通道4 
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  
 
    TIM_ARRPreloadConfig(TIM1, ENABLE);                         // 使能TIM1重载寄存器ARR    
	TIM_CtrlPWMOutputs(TIM1, ENABLE); 
	TIM_Cmd(TIM1, ENABLE);  
} 
void TIM1_PWM_Init(void)
{       
     TIM1_GPIO_Config();     
     TIM1_Mode_Config();      
}

void Timer3_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 65535 - 1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM3, ENABLE);
}

