#ifndef TestAPI_h
#define TestAPI_h

#include "SysConfig.h"
#include <HardwareSerial.h>
#include <Arduino.h>

typedef enum API_Function_t
{
    API_NULL,
    API_ENABLE_CHECK,
    API_ENABLE_PERSON,
    API_BUT_DOWN,
    API_BUT_UP,
    API_BUT_SUBMIT,
    API_BUT_OK,
    API_BUT_NOK,
    API_SET_AREA_ID,
    API_RESTART_DEVICE,
    API_NOTE_OK,
    API_SETTING_MAC,
    API_SETTING_SERVER_IP,
    API_SETTING_SERVER_PORT,

};

API_Function_t API_Code;

void debug_port_receiving_data()
{
    //printf("Checking serial port\r\n");
    if (Serial.available() > 0)
    {
        String s = Serial.readString();
        s.toLowerCase();

        printf("%s\r\n", s.c_str());

        if (s.indexOf("enable-check") > -1)
        {
            printf("API-Enable Check\r\n");
            API_Code = API_ENABLE_CHECK;
        }

        if (s.indexOf("enable-person") > -1)
        {
            printf("API-Enable Select People\r\n");
            API_Code = API_ENABLE_PERSON;
        }

        if (s.indexOf("but-submit") > -1)
        {
            printf("API-Enable Check\r\n");
            API_Code = API_BUT_SUBMIT;
        }

        if (s.indexOf("but-down") > -1)
        {
            printf("API-But Down\r\n");
            API_Code = API_BUT_DOWN;
        }

        if (s.indexOf("but-up") > -1)
        {
            printf("API-But Up\r\n");
            API_Code = API_BUT_UP;
        }

        if (s.indexOf("but-ok") > -1)
        {
            printf("API-But OK\r\n");
            API_Code = API_BUT_OK;
        }

        if (s.indexOf("but-nok") > -1)
        {
            printf("API-But Not\r\n");
            API_Code = API_BUT_NOK;
        }

        if (s.indexOf("device-setting") > -1)
        {
            printf("API-Set Local Id\r\n");
            API_Code = API_SET_AREA_ID;
        }

        if (s.indexOf("device-restart") > -1)
        {
            printf("API-Restart Device\r\n");
            API_Code = API_RESTART_DEVICE;
        }

        if(s.indexOf("but-note-ok")>-1)
        {
            printf("API-But set note ok\r\n");
            API_Code = API_NOTE_OK;
        }

         if(s.indexOf("setting-mac")>-1)
        {
            printf("API-Setting mac id\r\n");
            API_Code = API_SETTING_MAC;
        }

        if(s.indexOf("setting-ip")>-1)
        {
            printf("API-Setting server ip\r\n");
            API_Code = API_SETTING_SERVER_IP;
        }

        if(s.indexOf("setting-port")>-1)
        {
            printf("API-Setting server port\r\n");
            API_Code = API_SETTING_SERVER_PORT;
        }
    }
}

API_Function_t Api_request()
{
    API_Function_t api = API_Code;
    API_Code = API_NULL;
    return api;
}
#endif
