#include "LCD1602.h"
#include "interface.h"
#include "stm32f10x.h"
#include <stdio.h>

//ȫ�ֱ�������


/*******************************************************************************
* �� �� �� ��LcdBusy
* �������� �����LCDæ״̬,LcdBusy Ϊ1ʱ��æ���ȴ���lcd-busyΪ0ʱ,�У���дָ��������
* ��    �� ����
* ��    �� ��״̬
*******************************************************************************/
//bit LcdBusy()
// {                          
//    bit result;
//    LCDRS_RESET;
//    LCDWR_SET;
//    LCDEN_SET;
//    Delay_us(1);
//    result = (bit)(P0&0x80);
//    LCDEN_RESET;
//    return(result); 
//}
 
/*******************************************************************************
* �� �� �� ��write_com
* �������� ��LCD1602 дָ��
* ��    �� ����
* ��    �� ����
*******************************************************************************/
void LcdWriteCom(unsigned char com)
{
	//while(LcdBusy());
	Delay_us(20);
	LCDWRITE_DATA(com);
	LCDRS_RESET;
	LCDWR_RESET;
	LCDEN_RESET;
	Delay_us(10);
	LCDEN_SET;
	Delay_us(10);
	LCDEN_RESET;
	Delay_us(10);
}

/*******************************************************************************
* �� �� �� ��write_com
* �������� ��LCD1602 д����
* ��    �� ����
* ��    �� ����
*******************************************************************************/
void LcdWriteDate(unsigned char date)
{
	//while(LcdBusy());
	Delay_us(20);
	LCDWRITE_DATA(date);
	LCDRS_SET;
	LCDWR_RESET;
	LCDEN_RESET;
	Delay_us(10);
	LCDEN_SET;
	Delay_us(10);
	LCDEN_RESET; 
	Delay_us(10);	
}

void LCD1602PortInit()
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = LCDRS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(LCDRS_GPIO , &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = LCDWR_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(LCDWR_GPIO , &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = LCDEN_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(LCDEN_GPIO , &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin = LCD_PORT;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(LCD_GPIO , &GPIO_InitStructure);		
}

/*******************************************************************************
* �� �� �� ��LCD1602Init
* �������� ��LCD1602��ʼ��
* ��    �� ����
* ��    �� ����
*******************************************************************************/
void LCD1602Init()
{
	char index=0;
	LCD1602PortInit();
	Delayms(100);
	LcdWriteCom(0x38);  //����16*2��ʾ��8λ���ݽӿ�
	LcdWriteCom(0x0c); //����ʾ����ʾ�������˸
	LcdWriteCom(0x06);//дһ��ָ���Զ���һ
	LcdWriteCom(0x01);//����  
	Delayms(100);//��ʱһ��ʱ��ʱ�䣬�ȴ�LCD1602�ȶ�	
	
	LcdWriteCom(0x80);//���õ�һ�� ���ݵ�ַָ��
}

/*******************************************************************************
* �� �� �� ��LCD1602WriteCommand
* �������� ����ʾָ���Ļ U D L R S 
* ��    �� ��comm �ַ���ʽ
* ��    �� ����
*******************************************************************************/
void LCD1602WriteCommand(unsigned char const table[])
{	char index=0;
	LcdWriteCom(0x80);//���õ�һ�� ���ݵ�ַָ��
	for(index=0;index<16;index++)
	{
		LcdWriteDate(table[index]);  //д������             
	}
	
	LcdWriteCom(0xc0);//���õڶ��� ���ݵ�ַָ��
	for(index=0;index<16;index++)
	{
		LcdWriteDate(table[index]);  //д������             
	}
}  


void LCD1602WriteSpeed(unsigned char fl,unsigned char fr)
{
	char data_buf[4];
	int index=0;
	
	data_buf[3] = 0;
	sprintf(data_buf,"%03d",(int)fl);
	LcdWriteCom(0x80+3);//���õ�һ�� ���ݵ�ַָ��
	for(index=0;index<3;index++)
	{
		LcdWriteDate(data_buf[index]);  //д������             
	}
	
	sprintf(data_buf,"%03d",(int)fr);
	LcdWriteCom(0xc0+3);//���õ�һ�� ���ݵ�ַָ��
	for(index=0;index<3;index++)
	{
		LcdWriteDate(data_buf[index]);  //д������             
	}
}
