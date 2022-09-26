#include "stm32f10x.h"                  // Device header
#include "motor.h"
#include "timer1.h" 
void Car_Forward(void)      //绿色C
{
	TIM_SetCompare1(TIM1,200);
	TIM_SetCompare2(TIM1,900);
	TIM_SetCompare3(TIM1,300);
	TIM_SetCompare4(TIM1,900);
}
void Car_Backward(void)     //红色
{
	TIM_SetCompare1(TIM1,900);   //多
	TIM_SetCompare2(TIM1,300);
	TIM_SetCompare3(TIM1,900);    //单
	TIM_SetCompare4(TIM1,200);
}

void Car_Stopward(void)
{
	TIM_SetCompare1(TIM1,0);
	TIM_SetCompare2(TIM1,0);
	TIM_SetCompare3(TIM1,0);
	TIM_SetCompare4(TIM1,0);
	//TIM_CtrlPWMOutputs(TIM1,ENABLE);
}
void Car_Rightward(void)
{
	TIM_SetCompare1(TIM1,900);
	TIM_SetCompare2(TIM1,400);
	TIM_SetCompare3(TIM1,400);
	TIM_SetCompare4(TIM1,900);
	//TIM_CtrlPWMOutputs(TIM1,ENABLE); 
}
void Car_Liftward(void)
{
	TIM_SetCompare1(TIM1,400);
	TIM_SetCompare2(TIM1,900);
	TIM_SetCompare3(TIM1,900);
	TIM_SetCompare4(TIM1,400);
	//TIM_CtrlPWMOutputs(TIM1,ENABLE);
}
