#ifndef __INTERFACE_H_
#define __INTERFACE_H_

#include "stm32f10x.h"

//user LED PG15
#define LED_PIN           GPIO_Pin_15
#define LED_GPIO        GPIOG
#define LED_SET         GPIO_SetBits(LED_GPIO , LED_PIN)
#define LED_RESET       GPIO_ResetBits(LED_GPIO , LED_PIN)


//����ң�� ���������������,�ⲿ�ж� PD10
#define IRIN_PIN         GPIO_Pin_10
#define IRIN_GPIO        GPIOD
#define IRIN_PORTSOURCE  GPIO_PortSourceGPIOD
#define IRIN_PINSOURCE   GPIO_PinSource10
#define IRIN_EXITLINE    EXTI_Line10
#define IRIN_IRQCH       EXTI15_10_IRQn
#define IRIN             GPIO_ReadInputDataBit(IRIN_GPIO, IRIN_PIN)


//���������� �ⲿ�жϷ��� PB14
#define Echo_PIN         GPIO_Pin_14
#define Echo_GPIO        GPIOB
#define Echo_PORTSOURCE  GPIO_PortSourceGPIOB
#define Echo_PINSOURCE   GPIO_PinSource14
#define Echo_EXITLINE    EXTI_Line14
#define Echo_IRQCH       EXTI15_10_IRQn
#define Echo             GPIO_ReadInputDataBit(Echo_GPIO, Echo_PIN)
//����IO PD8
#define Trig_PIN         GPIO_Pin_8
#define Trig_GPIO        GPIOD
#define Trig_RESET       GPIO_SetBits(Trig_GPIO , Trig_PIN)
#define Trig_SET         GPIO_ResetBits(Trig_GPIO , Trig_PIN)//5ת3.3����һ�η��� modfied by LC 2015.09.20 10:18


//�������IO PD12
#define Servo_PIN         GPIO_Pin_12
#define Servo_GPIO        GPIOD
#define Servo_SET         GPIO_SetBits(Servo_GPIO , Servo_PIN)
#define Servo_RESET       GPIO_ResetBits(Servo_GPIO , Servo_PIN)

//LCD1602 IO
//LCDRS PC13   
#define LCDRS_PIN         GPIO_Pin_13
#define LCDRS_GPIO        GPIOC
#define LCDRS_SET         GPIO_SetBits(LCDRS_GPIO , LCDRS_PIN)
#define LCDRS_RESET       GPIO_ResetBits(LCDRS_GPIO , LCDRS_PIN)

//LCDWR PC14   
#define LCDWR_PIN         GPIO_Pin_14
#define LCDWR_GPIO        GPIOC
#define LCDWR_SET         GPIO_SetBits(LCDWR_GPIO , LCDWR_PIN)
#define LCDWR_RESET       GPIO_ResetBits(LCDWR_GPIO , LCDWR_PIN)

//LCDEN PC15  
#define LCDEN_PIN         GPIO_Pin_15
#define LCDEN_GPIO        GPIOC
#define LCDEN_SET         GPIO_SetBits(LCDEN_GPIO , LCDEN_PIN)
#define LCDEN_RESET       GPIO_ResetBits(LCDEN_GPIO , LCDEN_PIN)

//LCDPORT PF0-PF7
#define LCD_PORT        0x00ff
#define LCD_GPIO        GPIOF
#define LCDWRITE_DATA(data)   LCD_GPIO->BSRR = 0x00ff0000;LCD_GPIO->BSRR = (data)     

//�������IO���� 
/* 
FRONT_LEFT_F_PIN	PG13	��ǰǰ��IO
FRONT_LEFT_B_PIN	PG11	��ǰ����IO

FRONT_RIGHT_F_PIN	PC11	��ǰǰ��IO
FRONT_RIGHT_B_PIN	PD0	  ��ǰ����IO

BEHIND_LEFT_F_PIN	PD6	    ���ǰ��IO
BEHIND_LEFT_B_PIN	PG9	    ������IO

�Һ�������������IO�����Ϊ��·ʹ��EN1��EN2���ߵ�ƽ��Ч
BEHIND_RIGHT_F_PIN	PD4	    �ҵ��ʹ��IO
BEHIND_RIGHT_B_PIN	PD2	    ����ʹ��IO
 */
#define FRONT_LEFT_F_PIN         GPIO_Pin_13
#define FRONT_LEFT_F_GPIO        GPIOG
#define FRONT_LEFT_F_SET         GPIO_SetBits(FRONT_LEFT_F_GPIO , FRONT_LEFT_F_PIN)
#define FRONT_LEFT_F_RESET       GPIO_ResetBits(FRONT_LEFT_F_GPIO , FRONT_LEFT_F_PIN)

#define FRONT_LEFT_B_PIN         GPIO_Pin_11
#define FRONT_LEFT_B_GPIO        GPIOG
#define FRONT_LEFT_B_SET         GPIO_SetBits(FRONT_LEFT_B_GPIO , FRONT_LEFT_B_PIN)
#define FRONT_LEFT_B_RESET       GPIO_ResetBits(FRONT_LEFT_B_GPIO , FRONT_LEFT_B_PIN)

#define FRONT_RIGHT_F_PIN         GPIO_Pin_11
#define FRONT_RIGHT_F_GPIO        GPIOC
#define FRONT_RIGHT_F_SET         GPIO_SetBits(FRONT_RIGHT_F_GPIO , FRONT_RIGHT_F_PIN)
#define FRONT_RIGHT_F_RESET       GPIO_ResetBits(FRONT_RIGHT_F_GPIO , FRONT_RIGHT_F_PIN)

#define FRONT_RIGHT_B_PIN         GPIO_Pin_0
#define FRONT_RIGHT_B_GPIO        GPIOD
#define FRONT_RIGHT_B_SET         GPIO_SetBits(FRONT_RIGHT_B_GPIO , FRONT_RIGHT_B_PIN)
#define FRONT_RIGHT_B_RESET       GPIO_ResetBits(FRONT_RIGHT_B_GPIO , FRONT_RIGHT_B_PIN)

#define BEHIND_LEFT_F_PIN         GPIO_Pin_6
#define BEHIND_LEFT_F_GPIO        GPIOD
#define BEHIND_LEFT_F_SET         GPIO_SetBits(BEHIND_LEFT_F_GPIO , BEHIND_LEFT_F_PIN)
#define BEHIND_LEFT_F_RESET       GPIO_ResetBits(BEHIND_LEFT_F_GPIO , BEHIND_LEFT_F_PIN)

#define BEHIND_LEFT_B_PIN         GPIO_Pin_9
#define BEHIND_LEFT_B_GPIO        GPIOG
#define BEHIND_LEFT_B_SET         GPIO_SetBits(BEHIND_LEFT_B_GPIO , BEHIND_LEFT_B_PIN)
#define BEHIND_LEFT_B_RESET       GPIO_ResetBits(BEHIND_LEFT_B_GPIO , BEHIND_LEFT_B_PIN)

#define BEHIND_RIGHT_F_PIN         GPIO_Pin_4
#define BEHIND_RIGHT_F_GPIO        GPIOD
#define BEHIND_RIGHT_F_SET         GPIO_SetBits(BEHIND_RIGHT_F_GPIO , BEHIND_RIGHT_F_PIN)
#define BEHIND_RIGHT_F_RESET       GPIO_ResetBits(BEHIND_RIGHT_F_GPIO , BEHIND_RIGHT_F_PIN)

#define BEHIND_RIGHT_B_PIN         GPIO_Pin_2
#define BEHIND_RIGHT_B_GPIO        GPIOD
#define BEHIND_RIGHT_B_SET         GPIO_SetBits(BEHIND_RIGHT_B_GPIO , BEHIND_RIGHT_B_PIN)
#define BEHIND_RIGHT_B_RESET       GPIO_ResetBits(BEHIND_RIGHT_B_GPIO , BEHIND_RIGHT_B_PIN)

//ѭ�����Թ�
/* 
��ѭ��	SEARCH_M_PIN	PG8
��ѭ��	SEARCH_R_PIN	PG6
��ѭ��	SEARCH_L_PIN	PG4
 */
#define SEARCH_M_PIN         GPIO_Pin_8
#define SEARCH_M_GPIO        GPIOG
#define SEARCH_M_IO          GPIO_ReadInputDataBit(SEARCH_M_GPIO, SEARCH_M_PIN)

#define SEARCH_R_PIN         GPIO_Pin_6
#define SEARCH_R_GPIO        GPIOG
#define SEARCH_R_IO          GPIO_ReadInputDataBit(SEARCH_R_GPIO, SEARCH_R_PIN)

#define SEARCH_L_PIN         GPIO_Pin_4
#define SEARCH_L_GPIO        GPIOG
#define SEARCH_L_IO          GPIO_ReadInputDataBit(SEARCH_L_GPIO, SEARCH_L_PIN)
#define BLACK_AREA 1
#define WHITE_AREA 0

#define PIN_openmv         GPIO_Pin_1
#define GPIO_openmv        GPIOF
#define openmv_IO          GPIO_ReadInputDataBit(GPIO_openmv, PIN_openmv)

//�������
/* 
�ұ���	VOID_R_PIN	PC7
�����	VOID_L_PIN	PG2
 */
#define VOID_R_PIN         GPIO_Pin_7
#define VOID_R_GPIO        GPIOC
#define VOID_R_IO          GPIO_ReadInputDataBit(VOID_R_GPIO, VOID_R_PIN)

#define VOID_L_PIN         GPIO_Pin_2
#define VOID_L_GPIO        GPIOG
#define VOID_L_IO          GPIO_ReadInputDataBit(VOID_L_GPIO, VOID_L_PIN)
#define BARRIER_Y 0 //���ϰ���
#define BARRIER_N 1  //���ϰ���

//����
/* 
�ٶ�������	FRONT_RIGHT_S_PIN	PA11
�ٶ�������	FRONT_LEFT_S_PIN	PA12
 */
#define FRONT_RIGHT_S_PIN         GPIO_Pin_11
#define FRONT_RIGHT_S_GPIO        GPIOA
#define FRONT_RIGHT_S_IO          GPIO_ReadInputDataBit(FRONT_RIGHT_S_GPIO, FRONT_RIGHT_S_PIN)

#define FRONT_LEFT_S_PIN         GPIO_Pin_12
#define FRONT_LEFT_S_GPIO        GPIOA
#define FRONT_LEFT_S_IO          GPIO_ReadInputDataBit(FRONT_LEFT_S_GPIO, FRONT_LEFT_S_PIN)

//��ǰ
#define FRONT_LEFT_GO    FRONT_LEFT_F_SET; FRONT_LEFT_B_RESET//ǰ��
#define FRONT_LEFT_BACK  FRONT_LEFT_F_RESET; FRONT_LEFT_B_SET//����
#define FRONT_LEFT_STOP  FRONT_LEFT_F_RESET; FRONT_LEFT_B_RESET//ֹͣ

//��ǰ
#define FRONT_RIGHT_GO     FRONT_RIGHT_F_SET;  FRONT_RIGHT_B_RESET
#define FRONT_RIGHT_BACK   FRONT_RIGHT_F_RESET;FRONT_RIGHT_B_SET
#define FRONT_RIGHT_STOP   FRONT_RIGHT_F_RESET;FRONT_RIGHT_B_RESET

//���
#define BEHIND_LEFT_GO     BEHIND_LEFT_F_SET;BEHIND_LEFT_B_RESET
#define BEHIND_LEFT_BACK   BEHIND_LEFT_F_RESET;BEHIND_LEFT_B_SET
#define BEHIND_LEFT_STOP   BEHIND_LEFT_F_RESET;BEHIND_LEFT_B_RESET

//�Һ�
#define BEHIND_RIGHT_GO    BEHIND_RIGHT_F_SET;BEHIND_RIGHT_B_RESET
#define BEHIND_RIGHT_BACK  BEHIND_RIGHT_F_RESET;BEHIND_RIGHT_B_SET
#define BEHIND_RIGHT_STOP  BEHIND_RIGHT_F_RESET;BEHIND_RIGHT_B_RESET
#define BEHIND_RIGHT_EN   BEHIND_RIGHT_F_SET;BEHIND_RIGHT_B_SET        
//С�������������߸���һ����������������������ֻ��Ҫ�����ƣ��ұߵ��ֻ����ǰ���ƣ����ｫ�Һ������ƽŵ����ʹ��

#define SPEED_DUTY 40//Ĭ��ռ�ձ� ��1ms��С�ֱ��� ����50ms����

//ָ���
#define COMM_STOP  'I'//ֹͣ
#define COMM_UP    'A'//ǰ��
#define COMM_DOWN  'B'//����
#define COMM_LEFT  'C'//��ת
#define COMM_RIGHT 'D'//��ת

extern unsigned int tick_5ms;//5ms����������Ϊ�������Ļ�������
extern unsigned char tick_1ms;//1ms����������Ϊ����Ļ���������
extern unsigned int speed_count;//ռ�ձȼ����� 50��һ����
extern unsigned char bt_rec_flag;//�������Ʊ�־λ

void delay_init(void);
void Delayms(u32 Nms);
void Delay_us(u32 Nus);
void LEDToggle(uint16_t Led);

void IRIN_Configuration(void);
void TIM2_Init(void);
void RedRayInit(void);
void ServoInit(void);
void GPIOCLKInit(void);
void UserLEDInit(void);
//void openmvInit(void);

#endif

