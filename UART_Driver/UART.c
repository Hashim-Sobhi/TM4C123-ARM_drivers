/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 25.3.2022                                  **/
/*  Description  : UART3 driver 	              	          **/
/*  Version 	 : 1.0                                        **/
/***************************************************************/
#include "Std_Types.h"
#include "Bit_Ops.h"
#include "TM4C123_Regs.h"
#include "UART.h"
#include "Delay.h"


/*
	UART 3 Pins : PC6 RX
				PC7 TX

	UART 4 Pins : PC4 RX
				PC5 TX
*/



void UART3_VoidInit()
{
	f32 temp;
	// enable UART3 clock
	SET_BIT(RCGCUART ,3);
	Delay(2);
	// enable AF bit0,1 
	SET_BIT(GPIO_PORTC_AFSEL_R ,6);	
	SET_BIT(GPIO_PORTC_AFSEL_R ,7);
	// assign uart signal to bits0,1
	SET_BIT(GPIO_PORTC_PCTL_R,24);
	SET_BIT(GPIO_PORTC_PCTL_R,28);
	//disable uart
	CLR_BIT(UARTCTL3,UARTEN);
	// baud rate 
	//temp = (F_CLK / (f32)(16*copy_u8baudRate)) - (u32)(F_CLK / (16*copy_u8baudRate));
	UARTIBRD3 = 104;
	UARTFBRD3 = 11;
	// set data 8 bits
	SET_BIT(UARTLCRH3,WLEN0);
	SET_BIT(UARTLCRH3,WLEN1);
	// clear FIFO
	CLR_BIT(UARTLCRH3,FEN);
	//rx enable 
	SET_BIT(UARTCTL3,RXE);
	//tx enable 
	SET_BIT(UARTCTL3,TXE);
	//enable uart
	SET_BIT(UARTCTL3,UARTEN);
	UART3_VoidEnRxInterrpt();
}

void UART3_VoidSendChr(u8 copy_u8Chr)
{
	while (GET_BIT(UARTFR3,TXFF)); //wait until tx buffer not full
	UARTDR3 = copy_u8Chr;
}
void UART3_VoidSendString(u8* copy_u8str)
{
	u16 loc_u8counter = 0;
	while (copy_u8str[loc_u8counter]!='\0')
	{
		UART3_VoidSendChr(copy_u8str[loc_u8counter]);
		loc_u8counter++;
	}
}
u8 UART3_U8GetData(void)
{
	while (GET_BIT(UARTFR3,RXFE)); //wait data to receive
	return ((u8)(UARTDR3&0xFF));
}

void UART3_ReadString(u8* copy_u8str)
{
	u8 c =1;
	u32 i = 0;
	while(c != (u8)TERMINATE_STRING)
	{
		c = UART3_U8GetData();
		copy_u8str[i++] = c;
	}
	copy_u8str[i] = 0 ;
}
void UART3_VoidSendNum(u32 copy_u32num)
{
	if (copy_u32num == 0)
	{
		UART3_VoidSendChr('0');
	}
	else
	{
		u8 local_u8num = 0;
		u32 local_u32rev = 1;
		while (copy_u32num != 0)
		{
			local_u32rev = (local_u32rev*10)+(copy_u32num%10);
			copy_u32num /= 10;
		}
		while (local_u32rev != 1)
		{
			local_u8num = local_u32rev%10;
			local_u32rev /= 10;
			UART3_VoidSendChr(local_u8num+48);
		} 	
	}	
}
void UART3_VoidEnRxInterrpt(void)
{
	// enable interrupt
	SET_BIT(UARTIM3,RXIM);
	SET_BIT(NVIC_EN1,27);
}

void UART3_VoidSetCallBackFunCom(void (*ptofun)(void))
{
	UART3_CallBackFunCom = ptofun;
}
void UART3_Handler( void )
	{
		SET_BIT(UARTICR3,4);
		UART3_CallBackFunCom();
	}

/***************************************************uart4********************************/
void UART4_VoidInit()
{
	f32 temp;
	// enable UART3 clock
	SET_BIT(RCGCUART ,4);
	// enable AF bit 4,5 
	SET_BIT(GPIO_PORTC_AFSEL_R ,4);	
	SET_BIT(GPIO_PORTC_AFSEL_R ,5);

	// assign uart signal to bits 4,5
	SET_BIT(GPIO_PORTC_PCTL_R,16);
	SET_BIT(GPIO_PORTC_PCTL_R,20);
	//disable uart
	CLR_BIT(UARTCTL4,UARTEN);
	// baud rate 
	//temp = (F_CLK / (f32)(16*copy_u8baudRate)) - (u32)(F_CLK / (16*copy_u8baudRate));
	UARTIBRD4 = 104;
	UARTFBRD4 = 11;
	// set data 8 bits
	SET_BIT(UARTLCRH4,WLEN0);
	SET_BIT(UARTLCRH4,WLEN1);
	// clear FIFO
	CLR_BIT(UARTLCRH4,FEN);
	//rx enable 
	SET_BIT(UARTCTL4,RXE);
	//tx enable 
	SET_BIT(UARTCTL4,TXE);
	//enable uart
	SET_BIT(UARTCTL4,UARTEN);
	UART4_VoidEnRxInterrpt();
}

void UART4_VoidSendChr(u8 copy_u8Chr)
{
	while (GET_BIT(UARTFR4,TXFF)); //wait until tx buffer not full
	UARTDR4 = copy_u8Chr;
}
void UART4_VoidSendString(u8* copy_u8str)
{
	u16 loc_u8counter = 0;
	while (copy_u8str[loc_u8counter]!='\0')
	{
		UART4_VoidSendChr(copy_u8str[loc_u8counter]);
		loc_u8counter++;
	}
}
u8 UART4_U8GetData(void)
{
	while (GET_BIT(UARTFR4,RXFE)); //wait data to receive
	return ((u8)(UARTDR4&0xFF));
}

void UART4_ReadString(u8* copy_u8str)
{
	u8 c =1;
	u32 i = 0;
	while(c != (u8)TERMINATE_STRING)
	{
		c = UART4_U8GetData();
		copy_u8str[i++] = c;
	}
	copy_u8str[i] = 0 ;
}
void UART4_VoidSendNum(u32 copy_u32num)
{
	if (copy_u32num == 0)
	{
		UART4_VoidSendChr('0');
	}
	else
	{
		u8 local_u8num = 0;
		u32 local_u32rev = 1;
		while (copy_u32num != 0)
		{
			local_u32rev = (local_u32rev*10)+(copy_u32num%10);
			copy_u32num /= 10;
		}
		while (local_u32rev != 1)
		{
			local_u8num = local_u32rev%10;
			local_u32rev /= 10;
			UART4_VoidSendChr(local_u8num+48);
		} 	
	}	
}
void UART4_VoidEnRxInterrpt(void)
{
	// enable interrupt
	SET_BIT(UARTIM4,RXIM);
	SET_BIT(NVIC_EN1,28);
}

void UART4_VoidSetCallBackFunCom(void (*ptofun)(void))
{
	UART4_CallBackFunCom = ptofun;
}
void UART4_Handler( void )
	{
		SET_BIT(UARTICR4,4);
		UART4_CallBackFunCom();
	}