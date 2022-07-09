/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 2.7.2022                                     **/
/*  Description  : PWM driver 	                	            **/
/*  Version 	 : 1.0                                          **/
/***************************************************************/
#include "Std_Types.h"
#include "Bit_Ops.h"
#include "TM4C123_Regs.h"
#include "PWM.h"
#include "Delay.h"


// m0pwm0
void PWM0_VoidInit(void)
{
	//enable module 0 pwm
	SET_BIT(RCGCPWM ,0);
	Delay_ms(1);
	
	// enable AF to bit 6 port B
	SET_BIT(GPIO_PORTB_AFSEL_R ,6);
	
	// enable m0pwm0 signal
	SET_BIT(GPIO_PORTB_PCTL_R,26);
	
	// enable clock divider
	SET_BIT(RCC,20);
	
	// count down mode and starting from load value
	// set predivide pwm /64
	SET_BIT(RCC,17);
	SET_BIT(RCC,18);
	SET_BIT(RCC,19);
	
	// enable clocking
	SET_BIT(PWM0CTL,0);
	Delay_ms(1);
	
	// set at load and clr at compA 
	SET_BIT(PWM0GENA,2);
	SET_BIT(PWM0GENA,3);
	SET_BIT(PWM0GENA,7);
	
	//  set 50 hz
	PWM0LOAD = 5000;
	PWM0CMPA = 4999;    minimum value
	
	// enable output
	SET_BIT(PWMENABLE,0);
	Delay_ms(1);
}


void duty_cycle_0 (unsigned long p)
{
	unsigned long d = (p*5000)/100;
	d = 5000 - d -1;
	PWM0CMPA = d;
}



// m0pwm2
void PWM2_VoidInit(void)
{
	//enable module 0 pwm
	SET_BIT(RCGCPWM ,0);
	Delay_ms(1);
	
	// enable AF to bit 4 port b
	SET_BIT(GPIO_PORTB_AFSEL_R ,4);
	
	// enable m0pwm2 signal
	SET_BIT(GPIO_PORTB_PCTL_R,18);
	
	// enable clock divider
	SET_BIT(RCC,20);
	
	// count down mode and starting from load value
	// set predivide pwm /64
	SET_BIT(RCC,17);
	SET_BIT(RCC,18);
	SET_BIT(RCC,19);
	
	// enable clocking
	SET_BIT(PWM1CTL,0);
	Delay_ms(1);
	
	// set at load and clr at compA
	SET_BIT(PWM1GENA,2);
	SET_BIT(PWM1GENA,3);
	SET_BIT(PWM1GENA,7);
	
	//  set 50 hz
	PWM1LOAD = 5000;
	PWM1CMPA = 4999; // minimum value
	
	
	// enable output
	SET_BIT(PWMENABLE,2);
	Delay_ms(1);
}


void duty_cycle_2 (unsigned long p)
{
	unsigned long d = (p*5000)/100;
	d = 5000 - d;
	PWM1CMPA = d;
}