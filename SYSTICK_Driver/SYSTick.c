#include "Std_Types.h"
#include "Bit_Ops.h"
#include "TM4C123_Regs.h"
#include "SYSTick.h"

void Systick_Init_With_Interrupt(u32 Reload_Value){

	/* Disable Systick counter : ENABLE = 0 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) &= ~(1<<0);
	/* Disable Systick interrupt : INTEN = 0 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) &= ~(1<<1);
	/* STRELOAD Value Set */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_RELOAD_OFF) = Reload_Value -1;
	/* Clear STCURRENT */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CURRENT_OFF) = 0;
	/* Configure Clk source : CLK_SRC = 1 */
	/* Enable interrupt : INTEN = 1 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) |= 0x06;
}

void Systick_Start(void){
	/* Enable Systick counter : ENABLE = 1 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) |= (1<<0);
}

void Systick_Disable(void){
	/* STRELOAD Clear disables counter */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_RELOAD_OFF) = 0;
}

void Systick_Start_With_Polling(u32 Reload_Value){
	/* Disable Systick counter : ENABLE = 0 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) &= ~(1<<0);
	/* Disable Systick interrupt : INTEN = 0 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) &= ~(1<<1);
	/* STRELOAD Value Set */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_RELOAD_OFF) = Reload_Value -1;
	/* Clear STCURRENT */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CURRENT_OFF) = 0;
	/* Configure Clk source : CLK_SRC = 1 */
	/* Enable interrupt : INTEN = 1 */
	/* Enable Systick counter : ENABLE = 1 */
	*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) |= 0x05;
}
void Systick_WaitFlag(void)
{
	while(!(*(volatile u32*)((volatile u8*)(& SYSCTL_BASE_ADD) + SYSTICK_CTRL_OFF) & (1<<16)));
}