/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 25.3.2022                                  **/
/*  Description  : UART driver 	                	          **/
/*  Version 	 : 1.0                                        **/
/***************************************************************/
#ifndef _UART_INT_H_
#define _UART_INT_H_

/*UARTCTL pins*/
#define UARTEN 0
#define TXE    8
#define RXE    9
/*UARTLCRH pins*/
#define FEN   4
#define WLEN0 5
#define WLEN1 6
/*UARTFR pins*/
#define RXFE 4
#define TXFF 5
#define RXFF 6
#define TXFE 7
/*UARTIM pins*/
#define RXIM 4

#define TERMINATE_STRING '\r'

void UART3_VoidInit();
void UART3_VoidSendChr(u8 copy_u8Chr);
u8 UART3_U8GetData(void);
void UART3_ReadString(u8* copy_u8str);
void UART3_VoidSendString(u8* copy_u8str);
void UART3_VoidSendNum(u32 copy_u32num);
void UART3_VoidEnRxInterrpt(void);
void UART3_VoidSetCallBackFunCom(void (*ptofun)(void));
void (*UART3_CallBackFunCom) (void) = NULL;

void UART4_VoidInit();
void UART4_VoidSendChr(u8 copy_u8Chr);
u8 UART4_U8GetData(void);
void UART4_ReadString(u8* copy_u8str);
void UART4_VoidSendString(u8* copy_u8str);
void UART4_VoidSendNum(u32 copy_u32num);
void UART4_VoidEnRxInterrpt(void);
void UART4_VoidSetCallBackFunCom(void (*ptofun)(void));
void (*UART4_CallBackFunCom) (void) = NULL;
#endif