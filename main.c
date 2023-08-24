#include <stm32f4xx.h>

int ADC_val;
void ADC_init()
{
	RCC -> AHB1ENR |= (1U<<0);
	GPIOA -> MODER |= (1U<<0);
	RCC -> APB2ENR |= (1<<8);
	ADC1 -> CR1 |= (1U<<24);
	//ADC1 -> CR2 &= ~(1U<<0);
	//ADC1 -> SQR3 |= (1U<<0);
	ADC1 -> CR2 |= (1U<<0);
}

void ADC_conversion()
{
	ADC1 -> CR2 |= (1U<<30);
}

unsigned int ADC_read()
{
	while(!(ADC1 -> SR & (1U<<1)));
	return (ADC1 -> DR);
}


int main()
{
	ADC_init();

	while(1)
	{
		ADC_conversion();
		ADC_val = ADC_read();
	}
}
