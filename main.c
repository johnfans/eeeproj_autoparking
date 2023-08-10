#include "stm32f10x.h"
#include "interface.h"
#include "LCD1602.h"
#include "IRCtrol.h"
#include "motor.h"
#include "SpeedCtrol.h"
unsigned char const table1[]="MISSION COMPLETE";
unsigned char const table2[]="----------------";
unsigned char const table3[]="V  ID MATCHED   ";
unsigned char const table4[]="X  ID MISMACHED ";
unsigned char const table5[]="    WAITING     ";
unsigned char const table6[]="    ID FOUND    ";
unsigned char const table7[]="     RUNNING    ";

//全局变量定义
unsigned int speed_count=0;//占空比计数器 50次一周期
char front_left_speed_duty=SPEED_DUTY;
char front_right_speed_duty=SPEED_DUTY;
char behind_left_speed_duty=SPEED_DUTY;
char behind_right_speed_duty=SPEED_DUTY;

unsigned int tick_5ms = 0;//5ms计数器，作为主函数的基本周期
unsigned char tick_1ms = 0;//1ms计数器，作为电机的基本计数器
unsigned char tick_200ms = 0;//刷新显示
unsigned int ts;
int gridcount=0;

char ctrl_comm = COMM_STOP;//控制指令
unsigned char continue_time=0;

void parking()
	{	
	LCD1602WriteCommand(table3);
	CarRight3();
	Delayms(800);
	
	while(1){
		CarRight3();
		if(SEARCH_M_IO == BLACK_AREA || SEARCH_L_IO == BLACK_AREA || SEARCH_R_IO == BLACK_AREA)
			break;}
	
	CarStop();
	Delayms(500);
	CarStop();
	
	CarGo2();
	Delayms(10);
	
			
	tick_5ms=0;
	while(1){
	if(tick_5ms>=550) {CarStop();break;}
	if(SEARCH_M_IO == BLACK_AREA && SEARCH_L_IO == BLACK_AREA && SEARCH_R_IO == BLACK_AREA)
	{
		CarStop();
		break;
	}
	
	else if(SEARCH_L_IO == BLACK_AREA)//右
	{
		CarRight1();
	}
	else if(SEARCH_R_IO == BLACK_AREA)//左
	{
		CarLeft1();
	}
	else if(SEARCH_M_IO == BLACK_AREA)//中
	{
		CarGo();
	}
	else
	{
		CarGo();
	}
	Delayms(10);
	}
	
	
			
	
	LCD1602WriteCommand(table1);
	while(1){};
	
		
}


int main(void)
{
	delay_init();
	GPIOCLKInit();
	UserLEDInit();
	//openmvInit();
	LCD1602Init();
	IRCtrolInit();
	TIM2_Init();
	MotorInit();
	ServoInit();
	MeasureInit();
	
	Delayms(1500);

	LCD1602WriteCommand(table7);
	CarGo();
	delay_degree(120);
	
	CarStop();
	Delayms(500);
	CarStop();
	
	CarRight1();
	delay_degree_R(41);
	
	CarStop();
	Delayms(500);
	CarStop();
	
	CarGo();
	delay_degree(35);
		
	CarStop();
	Delayms(200);
	CarStop();
	LCD1602WriteCommand(table5);
	
	while(1){
		if(VOID_L_IO==1) break;}
	
	LCD1602WriteCommand(table6);
	CarBack();
	delay_degree(55);
	
	CarStop();
	Delayms(500);
	CarStop();
	
	CarLeft2();
	Delayms(600);
	
	//wait until online
	while(1){
		CarLeft2();
		Delayms(10);
		if(SEARCH_M_IO == BLACK_AREA || SEARCH_L_IO == BLACK_AREA || SEARCH_R_IO == BLACK_AREA)
			break;}
	
	CarStop();
	Delayms(500);
	CarStop();
	LCD1602WriteCommand(table7);
	
	//start routing in time
	gridcount=0;
	while(1){
	if(gridcount>=280) {CarStop();break;}
	gridcount += plus_judge();
	if(SEARCH_M_IO == BLACK_AREA && SEARCH_L_IO == BLACK_AREA && SEARCH_R_IO == BLACK_AREA)
	{
		CarGo();
	}
	
	else if(SEARCH_L_IO == BLACK_AREA)//右
	{
		CarRight1();
	}
	else if(SEARCH_R_IO == BLACK_AREA)//左
	{
		CarLeft1();
	}
	else if(SEARCH_M_IO == BLACK_AREA)//中
	{
		CarGo();
	}
	else
	{
		CarGo();
	}
	Delayms(1);
	gridcount += plus_judge();
	Delayms(1);
	}
	Delayms(300);
	CarStop();
	LCD1602WriteCommand(table5);
	while(1){
		if(VOID_L_IO==1)
		{	
			if(VOID_R_IO==1)
				parking();
			else if(VOID_R_IO==0)
				break;}
	}
	LCD1602WriteCommand(table4);
	
	gridcount=0;
	while(1){
	if(gridcount>=55) {CarStop();break;}
	gridcount+=plus_judge();
	if(SEARCH_M_IO == BLACK_AREA && SEARCH_L_IO == BLACK_AREA && SEARCH_R_IO == BLACK_AREA)
	{
		CarGo2();
	}
	
	else if(SEARCH_L_IO == BLACK_AREA)//右
	{
		CarRight3();
	}
	else if(SEARCH_R_IO == BLACK_AREA)//左
	{
		CarLeft3();
	}
	else if(SEARCH_M_IO == BLACK_AREA)//中
	{
		CarGo2();
	}
	else
	{
		CarGo2();
	}
	Delayms(2);
	}
	Delayms(300);
	CarStop();
	LCD1602WriteCommand(table5);
	while(1){
		if(VOID_L_IO==1)
		{
			if(VOID_R_IO==1)
				parking();
			if(VOID_R_IO==0)
				break;}
		}
	LCD1602WriteCommand(table4);
	gridcount=0;
	while(1){
	if(gridcount>=55) {CarStop();break;}
	gridcount+=plus_judge();
	if(SEARCH_M_IO == BLACK_AREA && SEARCH_L_IO == BLACK_AREA && SEARCH_R_IO == BLACK_AREA)
	{
		CarGo2();
		
	}
	
	else if(SEARCH_L_IO == BLACK_AREA)//右
	{
		CarRight3();
	}
	else if(SEARCH_R_IO == BLACK_AREA)//左
	{
		CarLeft3();
	}
	else if(SEARCH_M_IO == BLACK_AREA)//中
	{
		CarGo2();
	}
	else
	{
		CarGo2();
	}
	Delayms(2);
	}
	Delayms(300);
	CarStop();
LCD1602WriteCommand(table5);
	while(1){
		if(VOID_L_IO==1)
		{	
			if(VOID_R_IO==1)
			{	LCD1602WriteCommand(table3);
				CarRight3();
				tick_5ms=0;
				Delayms(500);
				while(tick_5ms<=1250)
				{	
					if(SEARCH_M_IO == BLACK_AREA)
						break;
					Delayms(10);
				}
				CarStop();
				Delayms(500);
				CarStop();
				CarGo2();
				Delayms(1200);
				CarStop();
				LCD1602WriteCommand(table1);
				while(1){};
			}
			if(VOID_R_IO==0)
				break;}
			}
	LCD1602WriteCommand(table4);
	CarGo();
	delay_degree(60);
	CarStop();
	
	
			
	
	LCD1602WriteCommand(table1);
	while(1){};
	
		
}

