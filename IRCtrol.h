#ifndef __IRCTROL_H_
#define __IRCTROL_H_

#include "stm32f10x.h"

extern unsigned char ir_rec_flag;//�������ݱ�־λ 1 �������� 0 û��
extern char ctrl_comm;//����ָ��
extern unsigned char continue_time;
void IRCtrolInit(void);
void IRIntIsr(void);

#endif
