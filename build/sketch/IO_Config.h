#ifndef _IO_CONFIG_h
#define _IO_CONFIG_h

#define BUT_ENABLE_CHECKING_PIN PB3		 // Nu?t nh�?n cho phe?p Checking
#define BUT_UP_PIN PB4					 // Nu?t nh�?n l�n
#define BUT_DOW_PIN PB5					 // Nu?t nh�?n xu�?ng
#define BUT_OK_PIN PB6					 // Nu?t nh�?n tra?ng tha?i OK
#define BUT_NOK_PIN PB7					 // Nu?t nh�?n tra?ng tha?i NOK
#define BUT_ENABLE_SELECT_PEOPLE_PIN PB8 // Nu?t nh�?n cho phe?p thay ?�?i th�ng tin ng???i tr??c
#define BUT_SUBMIT_PIN PB9				 // L?u th�ng tin v??a checking

#define BUT_NOTE_OK_PIN PA8 // L?u th�ng tin v??a checking

// #define LAMP_ENABLE_CHECKING_PIN PB0
// #define LAMP_SUBMIT_SUCCESS_PIN PB1
// #define LAMP_ENABLE_SELECT_PEOPLE_PIN PB10

#define ETHERNET_CS_PIN PA4
#define ETHERNET_RST_PIN PA3

//
#define ON HIGH
#define OFF LOW
//
#define FlashLed(x) digitalWrite(LED_BUILTIN, x)
#define FlashLedVal() digitalRead(LED_BUILTIN)

#define BUT_VAL(x) digitalRead(x)
#define LAMP_VAL(x, y) digitalWrite(x, y)
#define OutPut_Pin(x, y) digitalWrite(x, y)

// define 74HC595 for Check Item
#define HC595_1_SDI_PIN PC13		   //15
#define HC595_1_SCK_PIN PC15		   //11
#define HC595_1_OUTPUT_ENABLE_PIN PC14 //12

//define 74HC595 pin for Checking person Index
#define HC595_2_SDI_PIN PA0
#define HC595_2_SCK_PIN PA2
#define HC595_2_OUTPUT_ENABLE_PIN PA1

//define 74HC595 pin for check item status  OK , NOT OK
#define HC595_3_SDI_PIN PB12
#define HC595_3_SCK_PIN PB14
#define HC595_3_OUTPUT_ENABLE_PIN PB13

//define 74HC595 pin for check item Notes
#define HC595_4_SDI_PIN PA11
#define HC595_4_SCK_PIN PA15
#define HC595_4_OUTPUT_ENABLE_PIN PA12

//define 74HC595 pin for ENABLE ALARM
#define HC595_5_SDI_PIN PB0
#define HC595_5_SCK_PIN PB11
#define HC595_5_OUTPUT_ENABLE_PIN PB10

// EEPROM STORE ADDRESS
#define EEPROM_AREA_ID 0
#define EEPROM_PERSON_ID 1
#define EEPROM_MAC_ID 2
#define EEPROM_SERVER_IP (EEPROM_MAC_ID + 6)
#define EEPROM_ITEM_STATE_ID (EEPROM_SERVER_IP + 20) //begin of check item

#define HC595_LAMP_1_ON 0x01
#define HC595_LAMP_2_ON 0x02
#define HC595_LAMP_3_ON 0x04
#define HC595_LAMP_4_ON 0x08
#define HC595_LAMP_5_ON 0x10
#define HC595_LAMP_6_ON 0x20
#define HC595_LAMP_7_ON 0x40
#define HC595_LAMP_8_ON 0x80
#define HC595_LAMP_9_ON 0x0100
#define HC595_LAMP_10_ON 0x0200
#define HC595_ALL_LAMP_OFF 0x00

#define IHC595_LAMP_1_ON 0xFFFE
#define IHC595_LAMP_2_ON 0xFFFD
#define IHC595_LAMP_3_ON 0xFFFB
#define IHC595_LAMP_4_ON 0xFFF7
#define IHC595_LAMP_5_ON 0xFFEF
#define IHC595_LAMP_6_ON 0xFFDF
#define IHC595_LAMP_7_ON 0xFFBF
#define IHC595_LAMP_8_ON 0xFF7F
#define IHC595_LAMP_9_ON 0xFEFF
#define IHC595_LAMP_10_ON 0xFDFF
#define IHC595_ALL_LAMP_OFF 0xFFFF

const uint16_t LAMP_STATE[] = {
	HC595_LAMP_1_ON,
	HC595_LAMP_2_ON,
	HC595_LAMP_3_ON,
	HC595_LAMP_4_ON,
	HC595_LAMP_5_ON,
	HC595_LAMP_6_ON,
	HC595_LAMP_7_ON,
	HC595_LAMP_8_ON,
	HC595_LAMP_9_ON,
	HC595_LAMP_10_ON,
	HC595_ALL_LAMP_OFF,
};

const uint16_t ILAMP_STATE[] = {
	IHC595_LAMP_1_ON,
	IHC595_LAMP_2_ON,
	IHC595_LAMP_3_ON,
	IHC595_LAMP_4_ON,
	IHC595_LAMP_5_ON,
	IHC595_LAMP_6_ON,
	IHC595_LAMP_7_ON,
	IHC595_LAMP_8_ON,
	IHC595_LAMP_9_ON,
	IHC595_LAMP_10_ON,
	IHC595_ALL_LAMP_OFF,
	IHC595_ALL_LAMP_OFF,
	IHC595_ALL_LAMP_OFF,
	IHC595_ALL_LAMP_OFF,
};
// Defile All IO IN ECHECKING SYSTEM
#include <HardwareSerial.h>

////////////////////////////////////////////////////////////////////////////////////////
const uint8_t HC595_SDI_PIN[] = {
	HC595_1_SDI_PIN,
	HC595_2_SDI_PIN,
	HC595_3_SDI_PIN,
	HC595_4_SDI_PIN,
	HC595_5_SDI_PIN,
};
//
const uint8_t HC595_SCK_PIN[] = {
	HC595_1_SCK_PIN,
	HC595_2_SCK_PIN,
	HC595_3_SCK_PIN,
	HC595_4_SCK_PIN,
	HC595_5_SCK_PIN,
};
//
const uint8_t HC595_OUTPUT_ENABLE_PIN[] = {
	HC595_1_OUTPUT_ENABLE_PIN,
	HC595_2_OUTPUT_ENABLE_PIN,
	HC595_3_OUTPUT_ENABLE_PIN,
	HC595_4_OUTPUT_ENABLE_PIN,
	HC595_5_OUTPUT_ENABLE_PIN,
};

typedef enum HC595_typedef
{
	CHECK_ITEM_INDEX,
	CHECK_PERSON_INDEX,
	CHECK_ITEM_STATUS,
	CHECK_ITEM_NOTE_INDEX,
	CHECK_ENABLE,
};

////////////////////////////////////////////////////////////////////////////////////////
void HC595_hold(uint8_t type)
{
	OutPut_Pin(HC595_OUTPUT_ENABLE_PIN[type], HIGH);
	OutPut_Pin(HC595_OUTPUT_ENABLE_PIN[type], LOW);
}

void HC595_shift(uint8_t shift_reg, uint8_t type)
{
	char count_ = 0;
	for (count_ = 0; count_ < 8; count_++)
	{
		(shift_reg & 0x80) > 0 ? OutPut_Pin(HC595_SDI_PIN[type], HIGH) : OutPut_Pin(HC595_SDI_PIN[type], LOW);

		OutPut_Pin(HC595_SCK_PIN[type], HIGH);
		OutPut_Pin(HC595_SCK_PIN[type], LOW);
		shift_reg = shift_reg << 1;
	}
}

void HC595_shiftByte(uint8_t shift_reg, uint8_t type)
{
	OutPut_Pin(HC595_OUTPUT_ENABLE_PIN[type], LOW);
	OutPut_Pin(HC595_SCK_PIN[type], LOW);

	for (int i = 0; i < 8; i++)
	{
		(shift_reg & 0x80) > 0 ? OutPut_Pin(HC595_SDI_PIN[type], HIGH) : OutPut_Pin(HC595_SDI_PIN[type], LOW);

		OutPut_Pin(HC595_SCK_PIN[type], HIGH);
		OutPut_Pin(HC595_SCK_PIN[type], LOW);
		shift_reg = shift_reg << 1;
	}
	OutPut_Pin(HC595_OUTPUT_ENABLE_PIN[type], HIGH);
	OutPut_Pin(HC595_OUTPUT_ENABLE_PIN[type], LOW);
}

void HC595_writeBytes(uint8_t *buf, size_t len, uint8_t type)
{
	HC595_hold(type);
	OutPut_Pin(HC595_SCK_PIN[type], LOW);
	for (size_t i = 0; i < len; i++)
	{
		if (buf == NULL)
			break;

		HC595_shift(*buf, type);
		buf++;
	}
	HC595_hold(type);
}

void IO_init()
{
	printf("IO init\r\n");
	pinMode(BUT_ENABLE_CHECKING_PIN, INPUT_PULLUP);
	pinMode(BUT_ENABLE_SELECT_PEOPLE_PIN, INPUT_PULLUP);
	pinMode(BUT_DOW_PIN, INPUT_PULLUP);
	pinMode(BUT_UP_PIN, INPUT_PULLUP);
	pinMode(BUT_OK_PIN, INPUT_PULLUP);
	pinMode(BUT_NOK_PIN, INPUT_PULLUP);
	pinMode(BUT_SUBMIT_PIN, INPUT_PULLUP);
	pinMode(BUT_NOTE_OK_PIN, INPUT_PULLUP);

	pinMode(HC595_1_SDI_PIN, OUTPUT);
	pinMode(HC595_1_SCK_PIN, OUTPUT);
	pinMode(HC595_1_OUTPUT_ENABLE_PIN, OUTPUT);

	pinMode(HC595_2_SDI_PIN, OUTPUT);
	pinMode(HC595_2_SCK_PIN, OUTPUT);
	pinMode(HC595_2_OUTPUT_ENABLE_PIN, OUTPUT);

	pinMode(HC595_3_SDI_PIN, OUTPUT);
	pinMode(HC595_3_SCK_PIN, OUTPUT);
	pinMode(HC595_3_OUTPUT_ENABLE_PIN, OUTPUT);

	pinMode(HC595_4_SDI_PIN, OUTPUT);
	pinMode(HC595_4_SCK_PIN, OUTPUT);
	pinMode(HC595_4_OUTPUT_ENABLE_PIN, OUTPUT);

	pinMode(HC595_5_SDI_PIN, OUTPUT);
	pinMode(HC595_5_SCK_PIN, OUTPUT);
	pinMode(HC595_5_OUTPUT_ENABLE_PIN, OUTPUT);

	digitalWrite(HC595_1_SDI_PIN, LOW);
	digitalWrite(HC595_1_SCK_PIN, LOW);
	digitalWrite(HC595_1_OUTPUT_ENABLE_PIN, LOW);

	digitalWrite(HC595_2_SDI_PIN, LOW);
	digitalWrite(HC595_2_SCK_PIN, LOW);
	digitalWrite(HC595_2_OUTPUT_ENABLE_PIN, LOW);

	digitalWrite(HC595_3_SDI_PIN, LOW);
	digitalWrite(HC595_3_SCK_PIN, LOW);
	digitalWrite(HC595_3_OUTPUT_ENABLE_PIN, LOW);

	digitalWrite(HC595_4_SDI_PIN, LOW);
	digitalWrite(HC595_4_SCK_PIN, LOW);
	digitalWrite(HC595_4_OUTPUT_ENABLE_PIN, LOW);

	digitalWrite(HC595_5_SDI_PIN, LOW);
	digitalWrite(HC595_5_SCK_PIN, LOW);
	digitalWrite(HC595_5_OUTPUT_ENABLE_PIN, LOW);

	pinMode(ETHERNET_CS_PIN, OUTPUT);
	pinMode(ETHERNET_RST_PIN, OUTPUT);

	digitalWrite(ETHERNET_CS_PIN, HIGH);
	digitalWrite(ETHERNET_RST_PIN, HIGH);

	pinMode(LED_BUILTIN, OUTPUT);
	FlashLed(OFF);
}

#endif // !_IO_CONFIG_h
