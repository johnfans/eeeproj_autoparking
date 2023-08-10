#include "motor.h"
#include "interface.h"
#include "stm32f10x.h"

//GPIO���ú���
void MotorGPIO_Configuration(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_F_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_Init(FRONT_LEFT_F_GPIO, &GPIO_InitStructure);    
	
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_B_PIN;	
	GPIO_Init(FRONT_LEFT_B_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_F_PIN;	
	GPIO_Init(FRONT_RIGHT_F_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_B_PIN;	
	GPIO_Init(FRONT_RIGHT_B_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_LEFT_F_PIN;	
	GPIO_Init(BEHIND_LEFT_F_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_LEFT_B_PIN;	
	GPIO_Init(BEHIND_LEFT_B_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_RIGHT_F_PIN;	
	GPIO_Init(BEHIND_RIGHT_F_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_RIGHT_B_PIN;	
	GPIO_Init(BEHIND_RIGHT_B_GPIO, &GPIO_InitStructure);  
	
}

//����ռ�ձ��������ת��
void CarMove(void)
{   
	
	 BEHIND_RIGHT_EN;
	
 /* //��ǰ��
	if(front_left_speed_duty > 0)//��ǰ
	{
		if(speed_count < front_left_speed_duty)
		{
			FRONT_LEFT_GO;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else if(front_left_speed_duty < 0)//���
	{
		if(speed_count < (-1)*front_left_speed_duty)
		{
			FRONT_LEFT_BACK;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else                //ֹͣ
	{
		FRONT_LEFT_STOP;
	}*/
	
		//��ǰ��
	if(front_right_speed_duty > 0)//��ǰ
	{
		if(speed_count < front_right_speed_duty)
		{
			FRONT_RIGHT_GO;
		}else                //ֹͣ
		{
			FRONT_RIGHT_STOP;
		}
	}
	else if(front_right_speed_duty < 0)//���
	{
		if(speed_count < (-1)*front_right_speed_duty)
		{
			FRONT_RIGHT_BACK;
		}else                //ֹͣ
		{
			FRONT_RIGHT_STOP;
		}
	}
	else                //ֹͣ
	{
		FRONT_RIGHT_STOP;
	}
	
	//�����
	if(behind_left_speed_duty > 0)//��ǰ
	{
		if(speed_count < behind_left_speed_duty)
		{
			BEHIND_LEFT_GO;
		}	else                //ֹͣ
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty < 0)//���
	{
		if(speed_count < (-1)*behind_left_speed_duty)
		{
			BEHIND_LEFT_BACK;
		}	else                //ֹͣ
		{
			BEHIND_LEFT_STOP;
		}
	}
	else                //ֹͣ
	{
		BEHIND_LEFT_STOP;
	}
	
/*		//�Һ���
	if(behind_right_speed_duty > 0)//��ǰ
	{
		if(speed_count < behind_right_speed_duty)
		{
			BEHIND_RIGHT_GO;
		}	else                //ֹͣ
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else if(behind_right_speed_duty < 0)//���
	{
		if(speed_count < (-1)*behind_right_speed_duty)
		{
			BEHIND_RIGHT_BACK;
		}	else                //ֹͣ
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else                //ֹͣ
	{
		BEHIND_RIGHT_STOP;
	}*/
}

//��ǰ
void CarGo(void)
{
	//front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=SPEED_DUTY; // ����
	behind_left_speed_duty=SPEED_DUTY; //�ҵ��
	//behind_right_speed_duty=SPEED_DUTY;
}

void CarGo2(void)
{
	//front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=SPEED_DUTY/2; // ����
	behind_left_speed_duty=SPEED_DUTY/2; //�ҵ��
	//behind_right_speed_duty=SPEED_DUTY;
}

//����
void CarBack(void)
{
	//front_left_speed_duty=-SPEED_DUTY;
	front_right_speed_duty=-SPEED_DUTY;
	behind_left_speed_duty=-SPEED_DUTY;
	//behind_right_speed_duty=-SPEED_DUTY;
}

//����
void CarRight(void)
{
	//front_left_speed_duty=-SPEED_DUTY;
	front_right_speed_duty=SPEED_DUTY;
	behind_left_speed_duty=-SPEED_DUTY;
	//behind_right_speed_duty=SPEED_DUTY;//���Ӻ���������
}

void CarRight1(void)
{
	//front_left_speed_duty=-SPEED_DUTY;
	front_right_speed_duty=SPEED_DUTY;
	behind_left_speed_duty=0;
	//behind_right_speed_duty=SPEED_DUTY;//���Ӻ���������
}
void CarRight2(void)
{
	//front_left_speed_duty=-SPEED_DUTY;
	front_right_speed_duty=SPEED_DUTY/2;
	behind_left_speed_duty=-SPEED_DUTY/2;
	//behind_right_speed_duty=SPEED_DUTY;//���Ӻ���������
}

void CarRight3(void)
{
	//front_left_speed_duty=-SPEED_DUTY;
	front_right_speed_duty=SPEED_DUTY/2;
	behind_left_speed_duty=0;
	//behind_right_speed_duty=SPEED_DUTY;//���Ӻ���������
}

//����
void CarLeft(void)
{
	//front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=-SPEED_DUTY;
	behind_left_speed_duty=SPEED_DUTY;//���Ӻ���������
	//behind_right_speed_duty=-SPEED_DUTY;
}
void CarLeft1(void)
{
	//front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=0;
	behind_left_speed_duty=SPEED_DUTY;//���Ӻ���������
	//behind_right_speed_duty=-SPEED_DUTY;
}

void CarLeft2(void)
{
	//front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=-SPEED_DUTY/2;
	behind_left_speed_duty=SPEED_DUTY/2;//���Ӻ���������
	//behind_right_speed_duty=-SPEED_DUTY;
}

void CarLeft3(void)
{
	//front_left_speed_duty=SPEED_DUTY;
	front_right_speed_duty=0;
	behind_left_speed_duty=SPEED_DUTY/2;//���Ӻ���������
	//behind_right_speed_duty=-SPEED_DUTY;
}
//ֹͣ
void CarStop(void)
{
	front_left_speed_duty=0;
	front_right_speed_duty=0;
	behind_left_speed_duty=0;
	behind_right_speed_duty=0;
}


void MotorInit(void)
{
	MotorGPIO_Configuration();
	CarStop();
}

