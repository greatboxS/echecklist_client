# 1 "c:\\Users\\phuoc\\Desktop\\ECheckList_Client\\ECheckList_Client.ino"
// date : 27/2/2020
// name : Echecklist client
// Project: Echecklist
# 5 "c:\\Users\\phuoc\\Desktop\\ECheckList_Client\\ECheckList_Client.ino" 2
# 6 "c:\\Users\\phuoc\\Desktop\\ECheckList_Client\\ECheckList_Client.ino" 2
# 7 "c:\\Users\\phuoc\\Desktop\\ECheckList_Client\\ECheckList_Client.ino" 2
# 8 "c:\\Users\\phuoc\\Desktop\\ECheckList_Client\\ECheckList_Client.ino" 2
# 9 "c:\\Users\\phuoc\\Desktop\\ECheckList_Client\\ECheckList_Client.ino" 2

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
    Select_Person_Index = ECheckList_Client.ECheckStation.CheckPerson_Index;
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
                s.trim();
                memccpy(ECheckList_Client.ServerIp, s.c_str(), 0, sizeof(ECheckList_Client.ServerIp));
                ECheckList_Client.EEPROM_save_serverIp();
                __NVIC_SystemReset();
            }
            delay(20);
        }
    }

    if (func == API_SETTING_SERVER_PORT)
    {
        printf("Setting up your device now\r\n");
        while (Setting_TimeOut > 0)
        {
            Setting_TimeOut -= 20;
            if (Serial1.available() > 0)
            {
                String s = Serial1.readString();
                s.trim();

                ECheckList_Client.Port = (int)s.toInt();

                printf("%d\r\n", ECheckList_Client.Port);
                ECheckList_Client.EEPROM_save_serverPort();

                printf("Server Port: %d saved successfully", ECheckList_Client.Port);
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
