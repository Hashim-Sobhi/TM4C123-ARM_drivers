/*	Header guard to avoid multiple definitions	*/
#ifndef SYSTICK_H_
#define SYSTICK_H_

void Systick_Init_With_Interrupt(u32 Relaod_Value);
void Systick_Start(void);
void Systick_Disable(void);
void Systick_Start_With_Polling(u32 Relaod_Value);
void Systick_WaitFlag(void);

/*	End of header guard	*/
#endif