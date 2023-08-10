#ifndef __SPEEDCTROL_H_
#define __SPEEDCTROL_H_

#define FOSC 48000000L //�������ã�ʹ��24M Hz 6T˫�ٱ�ģʽ

//�ٶȷ���IO�ڶ���
//sbit FRONT_LEFT_S_IO =  P1^3; //��ǰǰ��IO
//sbit FRONT_RIGHT_S_IO =  P1^2; //��ǰǰ��IO

extern unsigned char front_left_speed;
extern unsigned char front_right_speed;

void MeasureSpeed(void);
void MeasureInit(void);
int plus_judge(void);
void delay_degree(int grids);
void delay_degree_R(int grids);
#endif
