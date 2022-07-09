/*	Header guard to avoid multiple definitions	*/
#ifndef TM4C123_REGS_H_
#define TM4C123_REGS_H_

/*	Base Address		*/
#define RCGCUART 			*((volatile u32*)0x400FE618)
#define SYSCTL_BASE_ADD		*((volatile u32*) 0xE000E000)
#define RCGCGPIO            *((volatile u32*) 0x400FE608) //clock enable port 
#define RCGCPWM  			*((volatile u32*) 0x400FE640)  
#define RCC  				*((volatile u32*) 0x400FE060) 
// data registers
#define GPIO_PORTA_DATA_R *((volatile u32*)0x400043FC)
#define GPIO_PORTB_DATA_R *((volatile u32*)0x400053FC)
#define GPIO_PORTC_DATA_R *((volatile u32*)0x400063FC)
#define GPIO_PORTD_DATA_R *((volatile u32*)0x400073FC)
#define GPIO_PORTE_DATA_R *((volatile u32*)0x400243FC)
#define GPIO_PORTF_DATA_R *((volatile u32*)0x400253FC)
// direction register
#define GPIO_PORTA_DIR_R *((volatile u32*)0x40004400)
#define GPIO_PORTB_DIR_R *((volatile u32*)0x40005400)
#define GPIO_PORTC_DIR_R *((volatile u32*)0x40006400)
#define GPIO_PORTD_DIR_R *((volatile u32*)0x40007400)
#define GPIO_PORTE_DIR_R *((volatile u32*)0x40024400)
#define GPIO_PORTF_DIR_R *((volatile u32*)0x40025400)
// alternative function selection
#define GPIO_PORTA_AFSEL_R *((volatile u32*)0x40004420)
#define GPIO_PORTB_AFSEL_R *((volatile u32*)0x40005420)
#define GPIO_PORTC_AFSEL_R *((volatile u32*)0x40006420)
#define GPIO_PORTD_AFSEL_R *((volatile u32*)0x40007420)
#define GPIO_PORTE_AFSEL_R *((volatile u32*)0x40024420)
#define GPIO_PORTF_AFSEL_R *((volatile u32*)0x40025420)
// pull up enable
#define GPIO_PORTA_PUR_R *((volatile u32*)0x40004510)
#define GPIO_PORTB_PUR_R *((volatile u32*)0x40005510)
#define GPIO_PORTC_PUR_R *((volatile u32*)0x40006510)
#define GPIO_PORTD_PUR_R *((volatile u32*)0x40007510)
#define GPIO_PORTE_PUR_R *((volatile u32*)0x40024510)
#define GPIO_PORTF_PUR_R *((volatile u32*)0x40025510)
// digital pins enable
#define GPIO_PORTA_DEN_R *((volatile u32*)0x4000451C)
#define GPIO_PORTB_DEN_R *((volatile u32*)0x4000551C)
#define GPIO_PORTC_DEN_R *((volatile u32*)0x4000651C)
#define GPIO_PORTD_DEN_R *((volatile u32*)0x4000751C)
#define GPIO_PORTE_DEN_R *((volatile u32*)0x4002451C)
#define GPIO_PORTF_DEN_R *((volatile u32*)0x4002551C)
// write 0x4C4F434B to unlock 
#define GPIO_PORTA_LOCK_R *((volatile u32*)0x40004520)
#define GPIO_PORTB_LOCK_R *((volatile u32*)0x40005520)
#define GPIO_PORTC_LOCK_R *((volatile u32*)0x40006520)
#define GPIO_PORTD_LOCK_R *((volatile u32*)0x40007520)
#define GPIO_PORTE_LOCK_R *((volatile u32*)0x40024520)
#define GPIO_PORTF_LOCK_R *((volatile u32*)0x40025520)
// commit register
#define GPIO_PORTA_CR_R *((volatile u32*)0x40004524)
#define GPIO_PORTB_CR_R *((volatile u32*)0x40005524)
#define GPIO_PORTC_CR_R *((volatile u32*)0x40006524)
#define GPIO_PORTD_CR_R *((volatile u32*)0x40007524)
#define GPIO_PORTE_CR_R *((volatile u32*)0x40024524)
#define GPIO_PORTF_CR_R *((volatile u32*)0x40025524)
// analog mode enable
#define GPIO_PORTA_AMSEL_R *((volatile u32*)0x40004528)
#define GPIO_PORTB_AMSEL_R *((volatile u32*)0x40005528)
#define GPIO_PORTC_AMSEL_R *((volatile u32*)0x40006528)
#define GPIO_PORTD_AMSEL_R *((volatile u32*)0x40007528)
#define GPIO_PORTE_AMSEL_R *((volatile u32*)0x40024528)
#define GPIO_PORTF_AMSEL_R *((volatile u32*)0x40025528)
// port control register
#define GPIO_PORTA_PCTL_R *((volatile u32*)0x4000452C)
#define GPIO_PORTB_PCTL_R *((volatile u32*)0x4000552C)
#define GPIO_PORTC_PCTL_R *((volatile u32*)0x4000652C)
#define GPIO_PORTD_PCTL_R *((volatile u32*)0x4000752C)
#define GPIO_PORTE_PCTL_R *((volatile u32*)0x4002452C)
#define GPIO_PORTF_PCTL_R *((volatile u32*)0x4002552C)
// ADC control register
#define GPIO_PORTA_ADCCTL_R *((volatile u32*)0x40004530)
#define GPIO_PORTB_ADCCTL_R *((volatile u32*)0x40005530)
#define GPIO_PORTC_ADCCTL_R *((volatile u32*)0x40006530)
#define GPIO_PORTD_ADCCTL_R *((volatile u32*)0x40007530)
#define GPIO_PORTE_ADCCTL_R *((volatile u32*)0x40024530)
#define GPIO_PORTF_ADCCTL_R *((volatile u32*)0x40025530)

/****************************     UART3 & UART4    ****************************/

// data register
#define UARTDR3 *((volatile u32*)0x4000F000)
// Flag register
#define UARTFR3 *((volatile u32*)0x4000F018)
// baud rate integer 
#define UARTIBRD3 *((volatile u32*)0x4000F024)
// baud rate fraction
#define UARTFBRD3 *((volatile u32*)0x4000F028)
// uart line control
#define UARTLCRH3 *((volatile u32*)0x4000F02C)
// uart control
#define UARTCTL3 *((volatile u32*)0x4000F030)
// interrupt mask
#define UARTIM3  *((volatile u32*)0x4000F038)
// UART3 Interrupt Clear
#define UARTICR3 *((volatile u32*)0x4000F044)


// data register
#define UARTDR4 *((volatile u32*)0x40010000)
// Flag register
#define UARTFR4 *((volatile u32*)0x40010018)
// baud rate integer 
#define UARTIBRD4 *((volatile u32*)0x40010024)
// baud rate fraction
#define UARTFBRD4 *((volatile u32*)0x40010028)
// uart line control
#define UARTLCRH4 *((volatile u32*)0x4001002C)
// uart control
#define UARTCTL4 *((volatile u32*)0x40010030)
// interrupt mask
#define UARTIM4 *((volatile u32*)0x40010038)
// UART3 Interrupt Clear
#define UARTICR4 *((volatile u32*)0x40010044)

// data register
#define UARTDR5 *((volatile u32*)0x40011000)
// Flag register
#define UARTFR5 *((volatile u32*)0x40011018)
// baud rate integer 
#define UARTIBRD5 *((volatile u32*)0x40011024)
// baud rate fraction
#define UARTFBRD5 *((volatile u32*)0x40011028)
// uart line control
#define UARTLCRH5 *((volatile u32*)0x4001102C)
// uart control
#define UARTCTL5 *((volatile u32*)0x40011030)
// interrupt mask
#define UARTIM5 *((volatile u32*)0x40011038)
//clock congif
#define UARTCC5 *((volatile u32*)0x40011FC8)

/*************************         NVIC      *************************/
#define NVIC_EN1 *((volatile u32*)0xE000E104)


/*	SYSTICK Offsets		*/
#define SYSTICK_CTRL_OFF	 0x010
/*
	16 --> Count Bit ( turns 1 at time-out )  //READ ONLY
	2 --> CLK_SRC ( 0 internal oscillator /4 , 1 system clock )
	1 --> INTEN ( 0 interrupt_disabled , 1 interrupt_enabled )
	0 --> ENABLE (0 disabled , 1 enabled )
*/
#define SYSTICK_RELOAD_OFF	 0x014
#define SYSTICK_CURRENT_OFF	 0x018


/*************************         PWM      *************************/
#define PWM0GENA  *((volatile u32*)0x40028060)
#define PWM1GENA  *((volatile u32*)0x400280A0)

#define PWM0LOAD  *((volatile u32*)0x40028050)
#define PWM1LOAD  *((volatile u32*)0x40028090)

#define PWM0CMPA  *((volatile u32*)0x40028058)
#define PWM1CMPA  *((volatile u32*)0x40028098)

#define PWM0CTL   *((volatile u32*)0x40028040)
#define PWM1CTL   *((volatile u32*)0x40028080)

#define PWMENABLE *((volatile u32*)0x40028008)

/*	End of header guard	*/
#endif