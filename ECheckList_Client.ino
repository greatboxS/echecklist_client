// date : 27/2/2020
// name : Echecklist client
// Project: Echecklist
#include <Arduino.h>
#include "SysConfig.h"
#include "SlaverConfig.h"
#include "TestApi.h"
#include <HardwareSerial.h>

EClient ECheckList_Client;

int Select_Item_Index = -1;
int Select_Person_Index = -1;
int Select_Note_Index = -1;

int Setting_TimeOut = 0;
int NewId = 0;

void setup()
{

    Serial.setTimeout(100);
    Serial.begin(115200);
    while (!Serial)
        ;

    IO_init();
    Timer_Init();
    ECheckList_Client.station_init();
}

void loop()
{
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_ENABLE_CHECKING_PIN))
    {
        while (!BUT_VAL(BUT_ENABLE_CHECKING_PIN))
            ;
        printf("BUT_ENABLE_CHECKING_PIN\r\n");

        ECheckList_Client.station_enable_select_check_item(true);
    }
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_ENABLE_SELECT_PEOPLE_PIN))
    {
        while (!BUT_VAL(BUT_ENABLE_SELECT_PEOPLE_PIN))
            ;
        printf("BUT_ENABLE_SELECT_PEOPLE_PIN\r\n");

        ECheckList_Client.station_enable_select_check_person(true);
    }
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_SUBMIT_PIN))
    {
        while (!BUT_VAL(BUT_SUBMIT_PIN))
            ;
        printf("BUT_SUBMIT_PIN");

        ECheckList_Client.station_submit();
    }
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_OK_PIN))
    {
        while (!BUT_VAL(BUT_OK_PIN))
            ;
        printf("BUT_OK_PIN\r\n");

        ECheckList_Client.station_set_check_item_state(OK);
        ECheckList_Client.station_pick_current_notes(Select_Item_Index, Select_Note_Index);
    }
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_NOK_PIN))
    {
        printf("BUT_NOK_PIN\r\n");
        ECheckList_Client.station_set_check_item_state(NOT_OK);
    }
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_DOW_PIN))
    {
        while (!BUT_VAL(BUT_DOW_PIN))
            ;
        printf("BUT_DOW_PIN\r\n");

        ECheckList_Client.station_select_new_check_item(false, Select_Item_Index);
        ECheckList_Client.station_select_new_person(false, Select_Person_Index);
        ECheckList_Client.station_select_check_item_notes(false, Select_Note_Index);
    }
    //---------------------------------------------------------
    if (!BUT_VAL(BUT_UP_PIN))
    {
        while (!BUT_VAL(BUT_UP_PIN))
            ;
        printf("BUT_UP_PIN\r\n");

        ECheckList_Client.station_select_new_check_item(true, Select_Item_Index);
        ECheckList_Client.station_select_new_person(true, Select_Person_Index);
        ECheckList_Client.station_select_check_item_notes(true, Select_Note_Index);
    }

    ECheckList_Client.ethernet_running();

    debug_port_receiving_data();

    ECheckList_Client.ethernet_checking_module();

    Setting_TimeOut = 1000 * 60 * 5;
    NewId = 0;
    switch (Api_request())
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
        ECheckList_Client.station_pick_current_notes(Select_Item_Index, Select_Note_Index);
        break;
    case API_BUT_NOK: // but nok
        ECheckList_Client.station_set_check_item_state(NOT_OK);
        break;

    case API_SET_AREA_ID: // set client id
        printf("Setting up your device now\r\n");
        while (Setting_TimeOut > 0)
        {
            Setting_TimeOut -= 20;
            if (Serial.available() > 0)
            {
                String s = Serial.readString();

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
                    NVIC_SystemReset();
                    break;
                }
            }
            delay(20);
        }
        break;

    case API_RESTART_DEVICE: // but nok
        NVIC_SystemReset();
        break;
    }

    delay(2);
}