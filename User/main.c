#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	/*开�?时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//开启GPIOA的时�?
															//使用各个外�?�前必须开�?时钟，否则�?��?��?�的操作无效
	
	/*GPIO初�?�化*/
	GPIO_InitTypeDef GPIO_InitStructure;					//定义结构体变�?
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//GPIO模式，赋值为推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				//GPIO引脚，赋值为�?0号引�?
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO速度，赋值为50MHz
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);					//将赋值后的构体变量传递给GPIO_Init函数
															//函数内部会自动根�?结构体的参数配置相应寄存�?
															//实现GPIOA的初始化
	
	/*主循�?，循�?体内的代码会一直循�?执�??*/
	while (1)
	{
		/*设置PA0引脚的高低电平，实现LED�?烁，下面展示3种方�?*/
		
		/*方法1：GPIO_ResetBits设置低电平，GPIO_SetBits设置高电�?*/
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);					//将PA0引脚设置为低电平
		Delay_ms(500);										//延时500ms
		GPIO_SetBits(GPIOA, GPIO_Pin_1);					//将PA0引脚设置为高电平
		Delay_ms(500);										//延时500ms
		
		/*方法2：GPIO_WriteBit设置�?/高电平，由Bit_RESET/Bit_SET指定*/
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_RESET);		//将PA0引脚设置为低电平
		Delay_ms(500);										//延时500ms
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, Bit_SET);			//将PA0引脚设置为高电平
		Delay_ms(500);										//延时500ms
		
		/*方法3：GPIO_WriteBit设置�?/高电平，由数�?0/1指定，数�?需要强�?为BitAction类型*/
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)0);		//将PA0引脚设置为低电平
		Delay_ms(500);										//延时500ms
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)1);		//将PA0引脚设置为高电平
		Delay_ms(500);										//延时500ms
		GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)0);		//将PA0引脚设置为高电平
		Delay_ms(100);										//延时500ms
	}
}
