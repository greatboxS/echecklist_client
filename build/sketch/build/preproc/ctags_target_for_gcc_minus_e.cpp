# 1 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h"
/*

 Name:		ECheckLib.h

 Created:	12/10/2019 9:47:39 PM

 Author:	Dell-PC

 Editor:	http://www.visualmicro.com

*/
# 10 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h"
# 11 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h" 2
# 12 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h" 2
# 13 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h" 2
# 14 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h" 2
# 15 "e:\\Visual Code\\EcheckList_Stm32\\ECheckLib.h" 2

typedef enum ECheckItem_Def
{
 UAC_DC_SWITCH_STATUS, //Tr?ng th�i c?a c�c thi?t b? ?�ng c?t t?i c�c t? ph�n ph?i UAC, DC
 TRNFORMER_SKIN, //B? m?t s?n m�y bi?n �p
 UAC_CABINET_DURABILITY, //?? v?ng ch?c c?a c�c t? ph�n ph?i ngu?n UAC (HK103EP1 ??n HK103EP2)
 ACCU_OUTSIZE, //H�nh d?ng b�n ngo�i c?a Accu
 AC_OPERATING_ROOM_TEMP, //Ho?t ??ng c?a ?i?u h�a, nhi?t ?? trong ph�ng
 OPERATION_OF_SYNCHRONOUS_SYSTEM, //Ho?t ??ng c?a h? th?ng h�a ??ng b?
 OPERATION_OF_TVSS_SYSTEM, //Ho?t ??ng c?a h? th?ng TVSS
 OPERATION_OF_TVSS_SYSTEM_AT_UAC_DC, //Ho?t ??ng c?a TVSS t?i c�c t? ph�n ph?i UAC, DC
 COMPENSATION_CABINET, //Ki?m tra h? th?ng t? b�
 PCCC, //Ki?m tra PCCC
 FUEL_LEAKS_FUEL_LEVEL, //Ki?m tra r� r? nhi�n li?u v� m?c nhi�n li?u
 BREAKER_NOISE, //Ki?m tra ti?ng ?n m�y c?t
 TRNSFORMER_FUEL_LEAKS, //S? r� r? d?u m�y bi?n �p
 ACCU_STATUS, //T�nh tr?ng c?a accu
 UPS_OPERATING_STATUS, //T�nh tr?ng ho?t ??ng h? th?ng UPS
 DC_POWER_OPERATING_STATUS, //T�nh tr?ng ho?t ??ng t? ngu?n DC
 GENERATOR_ACB_OUTPUT_STATUS, //Tr?ng th�i c?a ACB ??u ra m�y ph�t ?i?n
 SEPAM_RELAY_STATUS, //Tr?ng th�i c?a b? b?o v? relay Sepam
 GENERATOR_CONTROLLER_STATUS, //Tr?ng th�i c?a b? ?i?u khi?n m�y ph�t ?i?n
 L_H_BREAKER_LAMP_STATUS, //Tr?ng th�i ?�n b�o pha v� ?�n b�o tr?ng th�i m�y c?t t? h? th?/trung th?
 AC_CABINET_PHASE_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha c?a c�c t? ph�n ph?i AC
 AC_UAC_CABINET_PHASE_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha c?a c�c t? ph�n ph?i AC, UAC
 ME_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha, ?�n c?nh b�o c?a c�c thi?t b? c? ?i?n
 L_H_VOTLTAGE_TRANSFORMER_ROOM_ENVIRONMENT, //V? sinh khu v?c ph�ng h? th?/trung th?/ m�y bi?n �p
 LAB_ACCU_ROOM_ENVIROMENT, //V? sinh khu v?c ph�ng Lab v� ph�ng accu
 MACHINE_AREA_ENVIROMENT, //V? sinh khu v?c ph�ng m�y
 POWER_AREA_ENVIROMENT, //V? sinh khu v?c ph�ng ngu?n
 POWER_ACCU_ROOM_ENVIROMENT, //V? sinh khu v?c ph�ng ngu?n v� ph�ng accu
 GENERATOR_AREA_ENVIROMENT, //V? sinh xung quanh khu v?c m�y ph�t ?i?n
};

typedef enum ECheckNote_Def
{
 DURTY=1,
 HIGH_TEMPERERTURE,
 _1,
 _2,
 _3,
 _4,
 _5,
 _6,
 _7,
 _81,
 _9,
 _10,
};

typedef enum ECheckArea_Def
{
 ROOM_31 = 1, //Ph�ng m�y 3.1/3.2

 ROOM_32, //Ph�ng m�y 3.1/3.2

 POWER_ROOM_T3, //Ph�ng Ngu?n T3

 POWER_ROOM_T1, //Ph�ng Ngu?n T1

 GENERATOR, //M�y ph�t ?i?n

 L_H_VOLTAGE_TRANSFORMER, //Ph�ng trung th? + H? th? + MBA

 LAB_ROOM //Ph�ng LAB

};

typedef enum ECheckPerson_Def
{
 DAU_VAN_AN = 1, //??u V?n An
 NGUYEN_THE_ANH, //Nguy?n Th? Anh
 HO_VAN_KHOA, //H? V?n Khoa
 NGUYEN_VAN_NAM, //Nguy?n V?n Nam
 VO_TAN_HAU, //V� T?n H?u
 VU_THANH_SON, //V? Thanh S?n
 NGUYEN_DINH_HUU, //Nguy?n ?�nh H?u
 NGUYEN_TRI_TINH, //Nguy?n Tri T�nh
};

const ECheckItem_Def Room_31_32[]{
 UAC_DC_SWITCH_STATUS, //Tr?ng th�i c?a c�c thi?t b? ?�ng c?t t?i c�c t? ph�n ph?i UAC, DC
 AC_OPERATING_ROOM_TEMP, //Ho?t ??ng c?a ?i?u h�a, nhi?t ?? trong ph�ng
 ME_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha, ?�n c?nh b�o c?a c�c thi?t b? c? ?i?n
 PCCC, //Ki?m tra PCCC
 OPERATION_OF_TVSS_SYSTEM_AT_UAC_DC, //Ho?t ??ng c?a TVSS t?i c�c t? ph�n ph?i UAC, DC
 UAC_CABINET_DURABILITY, //?? v?ng ch?c c?a c�c t? ph�n ph?i ngu?n UAC (HK103EP1 ??n HK103EP2)
 MACHINE_AREA_ENVIROMENT, //V? sinh khu v?c ph�ng m�y
};

const ECheckItem_Def PowerRoomT3[]{
 AC_UAC_CABINET_PHASE_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha c?a c�c t? ph�n ph?i AC, UAC
 DC_POWER_OPERATING_STATUS, //T�nh tr?ng ho?t ??ng t? ngu?n DC
 UPS_OPERATING_STATUS, //T�nh tr?ng ho?t ??ng h? th?ng UPS
 ACCU_OUTSIZE, //H�nh d?ng b�n ngo�i c?a Accu
 AC_OPERATING_ROOM_TEMP, //Ho?t ??ng c?a ?i?u h�a, nhi?t ?? trong ph�ng
 PCCC, //Ki?m tra PCCC
 POWER_ACCU_ROOM_ENVIROMENT, //V? sinh khu v?c ph�ng ngu?n v� ph�ng accu
};

const ECheckItem_Def PowerRoomT1[]{
 AC_CABINET_PHASE_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha c?a c�c t? ph�n ph?i AC
 OPERATION_OF_SYNCHRONOUS_SYSTEM, //Ho?t ??ng c?a h? th?ng h�a ??ng b?
 OPERATION_OF_TVSS_SYSTEM, //Ho?t ??ng c?a h? th?ng TVSS
 PCCC, //Ki?m tra PCCC
 COMPENSATION_CABINET, //Ki?m tra h? th?ng t? b�
 POWER_AREA_ENVIROMENT, //V? sinh khu v?c ph�ng ngu?n

};

const ECheckItem_Def Generator[]{
 GENERATOR_CONTROLLER_STATUS, //Tr?ng th�i c?a b? ?i?u khi?n m�y ph�t ?i?n
 FUEL_LEAKS_FUEL_LEVEL, //Ki?m tra r� r? nhi�n li?u v� m?c nhi�n li?u
 GENERATOR_ACB_OUTPUT_STATUS, //Tr?ng th�i c?a ACB ??u ra m�y ph�t ?i?n
 ACCU_STATUS, //T�nh tr?ng c?a accu
 PCCC, //Ki?m tra PCCC
 GENERATOR_AREA_ENVIROMENT //V? sinh xung quanh khu v?c m�y ph�t ?i?n
};

const ECheckItem_Def LHVoltage[]{
 TRNSFORMER_FUEL_LEAKS, //S? r� r? d?u m�y bi?n �p
 TRNFORMER_SKIN, //B? m?t s?n m�y bi?n �p
 SEPAM_RELAY_STATUS, //Tr?ng th�i c?a b? b?o v? relay Sepam
 L_H_BREAKER_LAMP_STATUS, //Tr?ng th�i ?�n b�o pha v� ?�n b�o tr?ng th�i m�y c?t t? h? th?/trung th?
 BREAKER_NOISE, //Ki?m tra ti?ng ?n m�y c?t
 PCCC, //Ki?m tra PCCC
 L_H_VOTLTAGE_TRANSFORMER_ROOM_ENVIRONMENT, //V? sinh khu v?c ph�ng h? th?/trung th?/ m�y bi?n �p
};

const ECheckItem_Def LabRoom[]{
 AC_UAC_CABINET_PHASE_LAMP_STATUS, //Tr?ng th�i ?�n hi?n th? pha c?a c�c t? ph�n ph?i AC, UAC
 DC_POWER_OPERATING_STATUS, //T�nh tr?ng ho?t ??ng t? ngu?n DC
 UPS_OPERATING_STATUS, //T�nh tr?ng ho?t ??ng h? th?ng UPS
 ACCU_OUTSIZE, //H�nh d?ng b�n ngo�i c?a Accu
 AC_OPERATING_ROOM_TEMP, //Ho?t ??ng c?a ?i?u h�a, nhi?t ?? trong ph�ng
 OPERATION_OF_TVSS_SYSTEM_AT_UAC_DC, //Ho?t ??ng c?a TVSS t?i c�c t? ph�n ph?i UAC, DC
 PCCC, //Ki?m tra PCCC
 LAB_ACCU_ROOM_ENVIROMENT, //V? sinh khu v?c ph�ng Lab v� ph�ng accu
};

typedef const ECheckItem_Def *CheckingAreasItems[8];

const uint8_t ECheckNoteArray[]{
 DURTY,
 HIGH_TEMPERERTURE,
 _1,
 _2,
 _3,
 _4,
 _5,
 _6,
 _7,
 _81,
};

const ECheckArea_Def ECheckAreaArray[]{
 ROOM_31, //Ph�ng m�y 3.1/3.2
 ROOM_32, //Ph�ng m�y 3.1/3.2
 POWER_ROOM_T3, //Ph�ng Ngu?n T3
 POWER_ROOM_T1, //Ph�ng Ngu?n T1
 GENERATOR, //M�y ph�t ?i?n
 L_H_VOLTAGE_TRANSFORMER, //Ph�ng trung th? + H? th? + MBA
 LAB_ROOM //Ph�ng LAB
};

const ECheckPerson_Def CheckPersonList[]{
 DAU_VAN_AN, //??u V?n An
 NGUYEN_THE_ANH, //Nguy?n Th? Anh
 HO_VAN_KHOA, //H? V?n Khoa
 NGUYEN_VAN_NAM, //Nguy?n V?n Nam
 VO_TAN_HAU, //V� T?n H?u
 VU_THANH_SON, //V? Thanh S?n
 NGUYEN_DINH_HUU, //Nguy?n ?�nh H?u
 NGUYEN_TRI_TINH, //Nguy?n Tri T�nh
};

typedef enum ECheckState_Def
{
 OK = 0xFF,
 NOT_OK = 0x00,
};







typedef struct ECheckItem_t
{
 uint8_t Item;
 uint8_t Status; //0 false, 0xFF true
 uint8_t Note;
};

const uint8_t CheckList_size[]{
 0,
 sizeof(Room_31_32),
 sizeof(Room_31_32),
 sizeof(PowerRoomT3),
 sizeof(PowerRoomT1),
 sizeof(Generator),
 sizeof(LHVoltage),
 sizeof(LabRoom),
};

typedef struct ECheckStation_t
{
 uint8_t AreaId = 1;
 uint8_t CheckPerson_Index = 0; // index in CheckPersonList[]
 uint8_t CheckItem_Index = 0; // index in ECheckItem_def[area_id][index] or ECheckItems[index]
 uint8_t CheckNote_Index = 0;
 const ECheckItem_Def *ECheckItem_def[8]{
  {},
  Room_31_32,
  Room_31_32,
  PowerRoomT3,
  PowerRoomT1,
  Generator,
  LHVoltage,
  LabRoom,
 };

 std::vector<ECheckItem_t> ECheckItems;

 void seting_up(int area_id)
 {
  printf("Set devie id: %d\r\n", area_id);
  ECheckItems.clear();
  AreaId = area_id;
  int size = CheckList_size[area_id];

  printf("Total check list %d\r\n", size);
  printf("Setting up deivce Id: %d\r\n", area_id);

  for (size_t i = 0; i < size; i++)
  {
   ECheckItem_t New_Item;

   New_Item.Item = ECheckItem_def[area_id][i];
   New_Item.Status = NOT_OK;
   New_Item.Note = 0;

   ECheckItems.push_back(New_Item);
  }
 }

 bool set_current_item_state(uint8_t state)
 {
  if (ECheckItems.size() < CheckItem_Index || CheckItem_Index < 0)
   return false;

  printf("Current Item index %d\r\n", CheckItem_Index);
  printf("Current State %d\r\n", state);
  ECheckItems[CheckItem_Index].Status = state;
  return true;
 }

 bool set_current_item_note()
 {
  if (ECheckItems.size() < CheckItem_Index || CheckItem_Index < 0)
   return false;

  if (CheckNote_Index > sizeof(ECheckNoteArray))
   return false;

  printf("Current Item index %d\r\n", CheckItem_Index);
  printf("Current Note index %d\r\n", CheckNote_Index);
  ECheckItems[CheckItem_Index].Note = ECheckNoteArray[CheckNote_Index];
  return true;
 }

 uint8_t get_current_note_index()
 {
  return ECheckItems[CheckItem_Index].Note;
 }

 ECheckPerson_Def get_check_person_id()
 {
  return CheckPersonList[CheckPerson_Index];
 }

 void set_device_area_id(uint8_t id)
 {
  AreaId = id;
  EEPROM_save_area_id();
  seting_up(id);
 }

 void reset_all_check_items()
 {
  printf("Reset all items\r\n");
  for (size_t i = 0; i < ECheckItems.size(); i++)
  {
    ECheckItems[i].Status = OK;
    CheckNote_Index=0;
  }

 }

 void EEPROM_save_area_id()
 {
  printf("Save devie id to EEPROM\r\n");
  EEPROM.begin();
  printf("EEPROM wirte area id: %d\r\n", AreaId);
  EEPROM.write(0, AreaId);
  EEPROM.end();
 }

 void EEPROM_save_person_id()
 {
  printf("Save person id to EEPROM\r\n");
  EEPROM.begin();
  EEPROM.write(1, CheckPerson_Index);
  EEPROM.end();
 }

 void EEPROM_save_last_check_state()
 {
  printf("Save check item state to EEPROM\r\n");
  EEPROM.begin();
  for (size_t i = 0; i < ECheckItems.size(); i++)
  {
   EEPROM.write(((2 + 6) + 20) /*begin of check item*/ + i, ECheckItems[i].Status);
  }
  EEPROM.end();
 }

 void EEPROM_read_local_data()
 {
  printf("Read EcheckStation information\r\n");
  EEPROM.begin();
  uint8_t area_id = EEPROM.read(0);
  uint8_t person_id = EEPROM.read(1);

  printf("EEPROM read area id: %d\r\n", area_id);
  printf("EEPROM read person id: %d\r\n", person_id);

  if (area_id == 0 || area_id > 10)
  {
   area_id = 1;
   EEPROM.write(0, area_id);
  }

  if (person_id > 10)
  {
   person_id = 1;
   EEPROM.write(1, person_id);
  }

  AreaId = area_id;
  CheckPerson_Index = person_id;

  seting_up(AreaId);

  for (size_t i = 0; i < ECheckItems.size(); i++)
  {
   ECheckItems[i].Status = EEPROM.read(((2 + 6) + 20) /*begin of check item*/ + i);
  }

  EEPROM.end();
 }
};

uint8_t SelectItemLampVal[8]{
 0x01,
 0x02,
 0x04,
 0x08,
 0x10,
 0x20,
 0x40,
 0x80,
};




/* Table of CRC values for high-order byte */



static const uint8_t table_crc_hi[] = {

 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40};

/* Table of CRC values for low-order byte */




static const uint8_t table_crc_lo[] = {

 0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
 0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
 0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
 0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
 0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
 0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
 0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
 0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
 0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
 0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
 0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
 0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
 0x43, 0x83, 0x41, 0x81, 0x80, 0x40};

static uint16_t crc16(uint8_t *buffer, uint16_t buffer_length)
{
 uint8_t crc_hi = 0xFF; /* high CRC byte initialized */
 uint8_t crc_lo = 0xFF; /* low CRC byte initialized */
 unsigned int i; /* will index into CRC lookup */

 /* pass through message buffer */
 while (buffer_length--)
 {
  i = crc_hi ^ *buffer++; /* calculate the CRC  */




  crc_hi = crc_lo ^ table_crc_hi[i];
  crc_lo = table_crc_lo[i];

 }

 return (crc_hi << 8 | crc_lo);
}
# 1 "e:\\Visual Code\\EcheckList_Stm32\\ECheckList_Client.ino"
// date : 27/2/2020
// name : Echecklist client
// Project: Echecklist
# 5 "e:\\Visual Code\\EcheckList_Stm32\\ECheckList_Client.ino" 2
# 6 "e:\\Visual Code\\EcheckList_Stm32\\ECheckList_Client.ino" 2
# 7 "e:\\Visual Code\\EcheckList_Stm32\\ECheckList_Client.ino" 2
# 8 "e:\\Visual Code\\EcheckList_Stm32\\ECheckList_Client.ino" 2
# 9 "e:\\Visual Code\\EcheckList_Stm32\\ECheckList_Client.ino" 2

EClient ECheckList_Client;

int Select_Item_Index = -1;
int Select_Person_Index = -1;
int Select_Note_Index = -1;

int Setting_TimeOut = 0;
int NewId = 0;
int tick = 0;

uint8_t hex_to_int(char c);
uint8_t get_mac_from_string(const char *buf);

void setup()
{

    Serial1.setTimeout(100);
    Serial1.begin(115200);
    while (!Serial1)
        ;

    IO_init();
    Timer_Init();
    ECheckList_Client.station_init();
}

void loop()
{
    if (millis() - tick > 500)
    {
        tick = millis();
        ECheckList_Client.alarm_check_item_status();
    }
    //---------------------------------------------------------
    if (!digitalRead(6 /* Nu?t nh�?n cho phe?p Checking*/))
    {
        while (!digitalRead(6 /* Nu?t nh�?n cho phe?p Checking*/))
            ;
        printf("BUT_ENABLE_CHECKING_PIN\r\n");

        ECheckList_Client.station_enable_select_check_item(true);
    }
    //---------------------------------------------------------
    if (!digitalRead(1 /* Nu?t nh�?n cho phe?p thay ?�?i th�ng tin ng???i tr??c*/))
    {
        while (!digitalRead(1 /* Nu?t nh�?n cho phe?p thay ?�?i th�ng tin ng???i tr??c*/))
            ;
        printf("BUT_ENABLE_SELECT_PEOPLE_PIN\r\n");

        ECheckList_Client.station_enable_select_check_person(true);
    }
    //---------------------------------------------------------
    if (!digitalRead(0 /* L?u th�ng tin v??a checking*/))
    {
        while (!digitalRead(0 /* L?u th�ng tin v??a checking*/))
            ;
        printf("BUT_SUBMIT_PIN");

        ECheckList_Client.station_submit();
    }
    //---------------------------------------------------------
    if (!digitalRead(3 /* Nu?t nh�?n tra?ng tha?i OK*/))
    {
        while (!digitalRead(3 /* Nu?t nh�?n tra?ng tha?i OK*/))
            ;
        printf("BUT_OK_PIN\r\n");

        ECheckList_Client.station_set_check_item_state(OK);
    }
    //---------------------------------------------------------
    if (!digitalRead(2 /* Nu?t nh�?n tra?ng tha?i NOK*/))
    {
        printf("BUT_NOK_PIN\r\n");
        ECheckList_Client.station_set_check_item_state(NOT_OK);
    }
    //---------------------------------------------------------
    if (!digitalRead(4 /* Nu?t nh�?n xu�?ng*/))
    {
        while (!digitalRead(4 /* Nu?t nh�?n xu�?ng*/))
            ;
        printf("BUT_DOW_PIN\r\n");

        ECheckList_Client.station_select_new_check_item(false, Select_Item_Index);
        ECheckList_Client.station_select_new_person(false, Select_Person_Index);
        ECheckList_Client.station_select_check_item_notes(false, Select_Note_Index);
    }
    //---------------------------------------------------------
    if (!digitalRead(5 /* Nu?t nh�?n l�n*/))
    {
        while (!digitalRead(5 /* Nu?t nh�?n l�n*/))
            ;
        printf("BUT_UP_PIN\r\n");

        ECheckList_Client.station_select_new_check_item(true, Select_Item_Index);
        ECheckList_Client.station_select_new_person(true, Select_Person_Index);
        ECheckList_Client.station_select_check_item_notes(true, Select_Note_Index);
    }

    //---------------------------------------------------------
    if (!digitalRead(12 /* L?u th�ng tin v??a checking*/))
    {
        while (!digitalRead(12 /* L?u th�ng tin v??a checking*/))
            ;
        printf("BUT_NOTE_OK_PIN\r\n");

        ECheckList_Client.station_pick_current_notes(Select_Item_Index, Select_Note_Index);
    }

    ECheckList_Client.ethernet_running();

    debug_port_receiving_data();

    ECheckList_Client.ethernet_checking_module();

    Setting_TimeOut = 1000 * 60 * 5;
    NewId = 0;
    API_Function_t func = Api_request();
    if (func == API_SETTING_MAC)
    {
        printf("Setting up your device now\r\n");
        while (Setting_TimeOut > 0)
        {
            Setting_TimeOut -= 20;
            if (Serial1.available() > 0)
            {
                String s = Serial1.readString();
                uint8_t MAC[6];
                uint8_t *temp = MAC;
                int begin_mac_element = 0;
                for (size_t i = 0; i < s.length(); i++)
                {
                    if (s.charAt(i) == ':' || s.charAt(i) == '-' || s.charAt(i) == ' ')
                    {
                        String element = s.substring(begin_mac_element, i);
                        begin_mac_element = i + 1;
                        *(temp++) = get_mac_from_string(element.c_str());
                        printf("%X\r\n", *(temp - 1));
                    }
                }

                String last = s.substring(begin_mac_element, s.length());
                *(temp) = get_mac_from_string(last.c_str());

                memccpy(ECheckList_Client.mac, MAC, 0, sizeof(ECheckList_Client.mac));
                ECheckList_Client.EEPROM_save_mac();
                __NVIC_SystemReset();
            }
            delay(20);
        }
    }

    if (func == API_SETTING_SERVER_IP)
    {
        printf("Setting up your device now\r\n");
        while (Setting_TimeOut > 0)
        {
            Setting_TimeOut -= 20;
            if (Serial1.available() > 0)
            {
                String s = Serial1.readString();
                memccpy(ECheckList_Client.ServerIp, s.c_str(), 0, sizeof(ECheckList_Client.ServerIp));
                ECheckList_Client.EEPROM_save_serverIp();
                __NVIC_SystemReset();
            }
            delay(20);
        }
    }

    switch (func)
    {
    case API_ENABLE_CHECK: // but enable check
        ECheckList_Client.station_enable_select_check_item(true);
        break;
    case API_ENABLE_PERSON: // but enablle
        ECheckList_Client.station_enable_select_check_person(true);
        break;
    case API_BUT_SUBMIT: // but submit checking result
        ECheckList_Client.station_submit();
        break;
    case API_BUT_DOWN: // but down
        ECheckList_Client.station_select_new_check_item(false, Select_Item_Index);
        ECheckList_Client.station_select_new_person(false, Select_Person_Index);
        ECheckList_Client.station_select_check_item_notes(false, Select_Note_Index);
        break;
    case API_BUT_UP: // but up
        ECheckList_Client.station_select_new_check_item(true, Select_Item_Index);
        ECheckList_Client.station_select_new_person(true, Select_Person_Index);
        ECheckList_Client.station_select_check_item_notes(true, Select_Note_Index);
        break;
    case API_BUT_OK: // but ok
        ECheckList_Client.station_set_check_item_state(OK);
        break;
    case API_BUT_NOK: // but nok
        ECheckList_Client.station_set_check_item_state(NOT_OK);
        break;

    case API_NOTE_OK:
        ECheckList_Client.station_pick_current_notes(Select_Item_Index, Select_Note_Index);
        break;

    case API_SET_AREA_ID: // set client id
        printf("Setting up your device now\r\n");
        while (Setting_TimeOut > 0)
        {
            Setting_TimeOut -= 20;
            if (Serial1.available() > 0)
            {
                String s = Serial1.readString();

                NewId = s.toInt();
                if (NewId == 0 || NewId > 10)
                {
                    printf("Invalid device id\r\nPlease input the device Id: ");
                }
                else
                {
                    printf("%d", NewId);
                    ECheckList_Client.ECheckStation.set_device_area_id(NewId);
                    printf("Set up done\r\n");
                    __NVIC_SystemReset();
                    break;
                }
            }
            delay(20);
        }
        break;

    case API_RESTART_DEVICE: // but nok
        __NVIC_SystemReset();
        break;
    }

    delay(2);
}

uint8_t hex_to_int(char c)
{
    if (c == 'A' || c == 'a')
        return 10;
    if (c == 'B' || c == 'b')
        return 11;
    if (c == 'C' || c == 'c')
        return 12;
    if (c == 'D' || c == 'd')
        return 13;
    if (c == 'E' || c == 'e')
        return 14;
    if (c == 'F' || c == 'f')
        return 15;

    if ((uint8_t)c >= 48 && (uint8_t)c < 48 + 9)
        return (uint8_t)c - 48;
}

uint8_t get_mac_from_string(const char *buf)
{
    printf("hex to int: %s\r\n", buf);
    uint8_t first_digit = hex_to_int(buf[0]);
    uint8_t second_digit = hex_to_int(buf[1]);
    return first_digit * 16 + second_digit;
}
