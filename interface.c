#include "interface.h"

void delay_init(void)
{
   SysTick->CTRL&=0xfffffffb;//���ƼĴ�����ѡ���ⲿʱ�Ӽ�ϵͳʱ�ӵİ˷�֮һ��HCLK/8��72M/8=9M��
}


//1us ��ʱ����
void Delay_us(u32 Nus)   
{   
SysTick->LOAD=Nus*9;          //ʱ�����    72M��Ƶ     
SysTick->CTRL|=0x01;             //��ʼ����      
while(!(SysTick->CTRL&(1<<16))); //�ȴ�ʱ�䵽��   
SysTick->CTRL=0X00000000;        //�رռ�����   
SysTick->VAL=0X00000000;         //��ռ�����        
} 

void Delayms(u32 Nms)
{
	while(Nms--)
	{
		Delay_us(1000);
	}
}

//ʹ������GPIOʱ��
void GPIOCLKInit(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG , ENABLE);
}

void UserLEDInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(LED_GPIO , &GPIO_InitStructure);
	
	LED_SET;	
}

/*void openmvInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = PIN_openmv;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIO_openmv , &GPIO_InitStructure);
}
*/
void ServoInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = Servo_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(Servo_GPIO , &GPIO_InitStructure);
	
	Servo_SET;//Ĭ�ϸ��ߵ�λmodfied by LC 2015.09.20 12:00
}

/**-------------------------------------------------------
  * @������ NVIC_TIM5Configuration
  * @����   ����TIM5�ж�������������
  * @����   ��
  * @����ֵ ��
***------------------------------------------------------*/
static void NVIC_TIM2Configuration(void)
{ 
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Set the Vector Table base address at 0x08000000 */
    //NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0000);

    /* Enable the TIM5 gloabal Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}


void TIM2_Init(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    /* TIM2 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    /* Time base configuration */
    //��������Զ�װ�صļ���ֵ�����ڼ����Ǵ�0��ʼ�ģ�����Ϊ100us
    TIM_TimeBaseStructure.TIM_Period = (100 - 1);//10kHz
    // �������Ԥ��Ƶϵ����������Ϊ0ʱ��ʾ����Ƶ����Ҫ��1
    TIM_TimeBaseStructure.TIM_Prescaler = (72 - 1);//1MHz
    // �߼�Ӧ�ñ��β��漰�������ڶ�ʱ��ʱ��(CK_INT)Ƶ���������˲���(ETR,TIx)
    // ʹ�õĲ���Ƶ��֮��ķ�Ƶ����
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    //���ϼ���
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    //��ʼ����ʱ��5
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    /* Clear TIM5 update pending flag[���TIM5����жϱ�־] */
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

    /* TIM IT enable */ //������ж�
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    /* TIM5 enable counter */
    TIM_Cmd(TIM2, ENABLE);  //������ʹ�ܣ���ʼ����

    /* �жϲ������� */
    NVIC_TIM2Configuration();
}

void LEDToggle(uint16_t Led)
{
    /* ָ���ܽ������� 1��ʵ�ֶ�Ӧ��LEDָʾ��״̬ȡ��Ŀ�� */
	LED_GPIO->ODR ^= Led;
	//��Ҫ���Ч�ʣ�����ֱ�ӵ��� LEDnOBB = !LEDnOBB;
}


