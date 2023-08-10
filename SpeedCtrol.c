#include "SpeedCtrol.h"
#include "interface.h"

//����ֱ��66mm��������̳���Ϊ20�������ܳ� 207mm = 20.7cm 
//��������жϸߵ͵�ƽ�仯����������Ҳ����˵����תһ�ܼ�������Ϊ40
//һ�������仯��ʾ�����ܹ��ľ���Ϊ 20.7/40 = 0.5175cm

unsigned char front_left_speed=0;
unsigned char front_right_speed=0;

unsigned char front_left_speed_temp=0;
unsigned char front_right_speed_temp=0;

static unsigned char front_left_io=0;
static unsigned char front_right_io=0;
static unsigned char count_5ms=0;

void MeasureInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_S_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(FRONT_RIGHT_S_GPIO , &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_S_PIN;//����ʹ��GPIO�ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(FRONT_LEFT_S_GPIO , &GPIO_InitStructure); 
}

/*******************************************************************************
* �� �� �� ��MeasureSpeed
* �������� ���ٶȲ���������IO�仯�������ú�������ÿ5ms����һ��
* ��    �� ����
* ��    �� ����
*******************************************************************************/
void MeasureSpeed(void)
{
	count_5ms++;
	if(FRONT_LEFT_S_IO != front_left_io)//������ƽ�仯
	{
		front_left_speed_temp++;
		front_left_io = FRONT_LEFT_S_IO;
	}
	
	if(FRONT_RIGHT_S_IO != front_right_io)//������ƽ�仯
	{
		front_right_speed_temp++;
		front_right_io = FRONT_RIGHT_S_IO;
	}
	
	if(count_5ms == 100)//ÿ500ms��ȡһ���ٶ�
	{
		count_5ms = 0;
		front_left_speed = front_left_speed_temp *2;//��ȡ1s�ĸߵ͵�ƽ�仯����
		front_right_speed = front_right_speed_temp*2;
		front_left_speed_temp = 0;
		front_right_speed_temp = 0;
		
		front_left_speed = (unsigned char)(0.5175 * (double)front_left_speed + 0.5);//�����ٶ� cm/s ��������
		front_right_speed = (unsigned char)(0.5175 * (double)front_right_speed + 0.5);//�����ٶ� cm/s ��������
	}
}

int plus_judge(void)
{	if(FRONT_LEFT_S_IO != front_left_io)//������ƽ�仯
	{
		front_left_io = FRONT_LEFT_S_IO;
		return 1;
	}
	return 0;
	
}

void delay_degree_R(int grids)
{	int temp=0;
	while(1)
	{		if(FRONT_RIGHT_S_IO != front_right_io)//������ƽ�仯
		{
			temp++;
			front_right_io = FRONT_RIGHT_S_IO;
				if(temp>=grids)
					break;
		
		}
		
	}
}

void delay_degree(int grids)
{	int temp=0;
	while(1)
	{		if(FRONT_LEFT_S_IO != front_left_io)//������ƽ�仯
		{
			temp++;
			front_left_io = FRONT_LEFT_S_IO;
				if(temp>=grids)
					break;
		
		}
	}
}

/*******************************************************************************
* �� �� �� ��ClearMeasure
* �������� ��������������¿�ʼ����
* ��    �� ����
* ��    �� ����
*******************************************************************************/
void ClearMeasure(void)
{
	count_5ms = 0;
	front_left_speed_temp = 0;
	front_right_speed_temp = 0;
}


