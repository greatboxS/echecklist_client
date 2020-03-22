#ifndef _SLAVERCONFIG_h
#define _SLAVERCONFIG_h
#include <Arduino.h>
#include "SysConfig.h"
#include "EClient.h"
#include <HardwareSerial.h>

#define MASTER_ID	0x80

#define	SLAVE_AREA	ROOM_31 // 3.1
// #define	SLAVE_AREA	ROOM_32 // 3.2
// #define	SLAVE_AREA	POWER_ROOM_T3 // phong T3
// #define	SLAVE_AREA	POWER_ROOM_T1 // phong T1
// #define	SLAVE_AREA	GENERATOR	// phong may phat
// #define	SLAVE_AREA	L_H_VOLTAGE_TRANSFORMER	// phong bien ap
// #define	SLAVE_AREA	LAB_ROOM // phong lab


volatile int CheckingTimerCounter = 0; //int = 32bit
bool ReceivingData = false;
TIM_HandleTypeDef  Timer1, Timer2;
HardwareTimer* FlashLedTimer, * CheckingTimer;


void CheckingTimerCallback(HardwareTimer* xTimer);
void FlashLedTimerCallback(HardwareTimer* xTimer);

void IO_init();
void Timer_Init();
void System_Starup();

//////////////////////////////////////////////////////////////////////////////////////////
// System start up function
void System_Starup()
{
	IO_init();
	Timer_Init();
}

//////////////////////////////////////////////////////////////////////////////////////////

void CheckingTimerCallback(HardwareTimer* xTimer)
{
	//printf("Timer 2 callback\r\n");
}
//
void FlashLedTimerCallback(HardwareTimer* xTimer)
{
	//function_log();
	FlashLed(!FlashLedVal());
}

void Timer_Init()
{
	printf("Timer init\r\n");
	Timer1.Instance = TIM1;
	Timer2.Instance = TIM2;

	FlashLedTimer = new HardwareTimer(Timer1.Instance);
	CheckingTimer = new HardwareTimer(Timer2.Instance);

	// set timer overflow value
	FlashLedTimer->setOverflow(50000, MICROSEC_FORMAT);
	CheckingTimer->setOverflow(10000000, MICROSEC_FORMAT);

	// attach interrupt timer
	FlashLedTimer->attachInterrupt(FlashLedTimerCallback);
	CheckingTimer->attachInterrupt(CheckingTimerCallback);

	FlashLedTimer->resume();
	CheckingTimer->resume();
}
#endif // !_SLAVERCONFIG_h

