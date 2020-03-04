#ifndef EClient_h
#define EClient_h

#include "SysConfig.h"
#include <HardwareSerial.h>
#include <EthernetClient.h>

class EClient
{
private:
    uint8_t ENABLE_ALARM_VAL = 0x00; // 1 enable check, 0x02 person, 0x04 notes
public:
    uint8_t mac[6] = {0xF6, 0x6C, 0x08, 0x62, 0x05, 0x0F};
    //const char *Host = "Host: 10.10.10.1:32768";
    //const char *ServerIp = "10.10.10.1";
    //const int Port = 32768;

    const char *ServerIp = "10.4.3.41";
    const char *Host = "Host: 10.4.3.41:32760";
    int Port = 32760;

    // const char *ServerIp = "192.168.0.1";
    // const char *Host = "Host: 192.168.0.1:32760";
    // int Port = 32760;

    const char *Post = "POST /echecklist/post HTTP/1.1";
    const char *ContentType = "Content-Type: application/json";
    const char *Connection = "Connection: keep-alive";
    const char *CashControl = "Cache-Control: max-age=0";
    const char *UpgradeInsecure = "Upgrade-Insecure-Requests: 1";
    const char *UserAgent = "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.122 Safari/537.36";

    String Url = "";
    char RX_Buffer[1024];

    bool cable_connected = false;
    bool module_connected = false;
    bool ip_initialized = false;
    ECheckStation_t ECheckStation;
    EthernetClient client;

    bool Enable_Check = false;
    bool Enable_Select_Person = false;
    bool Enable_Select_Note = false;
    bool reset_module_now = false;

    void alarm_check_item_index(int index);      // LED selected item //on when enable and off after submit
    void alarm_check_person_index(int index);    // LED selected person
    void alarm_check_item_note_index(int index); // LED slected notes

    void alarm_enable_select_check_item(bool state);   // LED enable select check item
    void alarm_enable_select_check_person(bool state); // LED enable select check person
    void alarm_enable_select_note();                   // LED enable select note, blink led two times

    void alarm_but_submit_click();
    void alarm_submit_success(bool status);
    void alarm_check_item_status();   // LED item ok or not ok
    void alarm_current_note_status(); // LED enable select check item notes

    void station_enable_select_check_item(bool status);               // for button enable select check item
    void station_select_new_person(bool direction, int &index);       // for butoon updown select check person
    void station_select_new_check_item(bool direction, int &index);   // for button updown select check item
    void station_enable_select_check_person(bool status);             // for button enable select check person
    void station_set_check_item_state(uint8_t state);                 // for buton Ok and Not Ok
    void station_select_check_item_notes(bool direction, int &index); // for button up down select notes
    void station_pick_current_notes(int &item_index, int &note_index);
    void station_enable_select_check_item_note(bool state = false);

    void station_submit();
    void station_init();

    bool start_connect_to_server(uint32_t timeout = 20000);

    int ethernet_init();                  // get ethernet module Ip
    void ethernet_checking_module();      // call this function to check ethernet module all the tim
    uint8_t get_ethernet_module_status(); // get ethernet status
    void serialize_local_data();          // serial data to json string
    bool ethernet_post_data();            // post ethernet data
    void ethernet_running();
};

void EClient::alarm_but_submit_click()
{
    printf("Alarm submit\r\n");
    ENABLE_ALARM_VAL = 0x00;
    HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);
}

void EClient::alarm_submit_success(bool status)
{
    printf("Alarm submit status %s\r\n", status ? "successfull" : "fail");
    if (status)
    {
        for (size_t i = 0; i < 5; i++)
        {
            ENABLE_ALARM_VAL = 0x06;
            HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);
            delay(20);
            ENABLE_ALARM_VAL = 0x00;
            HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);
            delay(20);
        }
    }
    else
    {
        ENABLE_ALARM_VAL = 0xFF;
        HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);
    }
}

void EClient::ethernet_running()
{
    if (client.available() > 0)
    {
        int receivedBytes = client.available();
        memset(RX_Buffer, 0, sizeof(RX_Buffer));
        client.readBytesUntil('\r\n', RX_Buffer, receivedBytes);
        printf("%s\r\n", RX_Buffer);

        if (strstr(RX_Buffer, "{") != nullptr)
        {
            printf("new data is comming\r\n");
            DynamicJsonDocument json_doc = DynamicJsonDocument(1024 * 1);
            DeserializationError JsonErr = deserializeJson(json_doc, RX_Buffer);
            printf("parse json object coed: %s\r\n", JsonErr.c_str());

            if (!JsonErr)
            {
                bool success = json_doc.getMember("Success").as<bool>();
                if (success)
                {
                    alarm_submit_success(true);
                }
                else
                {
                    alarm_submit_success(false);
                }
            }
        }
    }
}

void EClient::ethernet_checking_module()
{
    get_ethernet_module_status();

    if (reset_module_now)
    {
        reset_module_now = false;
        ethernet_init();
    }
}

uint8_t EClient::get_ethernet_module_status()
{
    if (Ethernet.hardwareStatus() == EthernetNoHardware)
    {
        printf("Ethernet shield was not found.  Sorry, can't run without hardware\r\n");
        cable_connected = false;
        module_connected = false;
        return 0; // no hardware
    }

    if (Ethernet.linkStatus() == LinkOFF)
    {
        //printf("Ethernet cable is not connected\r\n");
        cable_connected = false;
        module_connected = true;
        return 2; // no cable
    }
    module_connected = true;
    if (!cable_connected)
    {
        reset_module_now = true;
    }

    cable_connected = true;
    ip_initialized = true;
    return 1; // cable connect ok
}

int EClient::ethernet_init()
{
    Ethernet.init(ETHERNET_CS_PIN);
    printf("Ethernet configurating module\r\n");
    Serial.println(Ethernet.localIP());

    // IPAddress debug_ip(192, 168, 0, 2);
    // Ethernet.begin(mac, debug_ip);
    // return 1;
    int exception = Ethernet.begin(mac, 20000);

    if (exception == 0)
    {
        printf("Failed to configure Ethernet using DHCP\r\n");
        // Check for Ethernet hardware present
        if (Ethernet.hardwareStatus() == EthernetNoHardware)
        {
            printf("Ethernet shield was not found.  Sorry, can't run without hardware.\r\n");
            cable_connected = false;
            module_connected = false;
        }
        if (Ethernet.linkStatus() == LinkOFF)
        {
            printf("Ethernet cable is not connected.\r\n");
            cable_connected = false;
            module_connected = true;
        }
    }
    else
    {
        module_connected = true;
        cable_connected = true;
        ip_initialized = true;
        printf("Ethernet module get Ip successfull\r\n");
        Serial.println(Ethernet.localIP());
    }

    return exception;
}

void EClient::serialize_local_data()
{
    int Total_CheckItem = ECheckStation.ECheckItems.size();
    DynamicJsonDocument json_doc = DynamicJsonDocument(1024 * 2);

    memset(RX_Buffer, 0, sizeof(RX_Buffer));

    json_doc["Area_Id"] = ECheckStation.AreaId;
    json_doc["CheckPerson_Id"] = (uint8_t)ECheckStation.get_check_person_id();

    JsonArray CheckItems = json_doc.createNestedArray("CheckItems");

    printf("Create CheckItems successed\r\n");
    printf("Local CheckItems size %d\r\n", Total_CheckItem);

    for (size_t i = 0; i < Total_CheckItem; i++)
    {
        JsonObject item = CheckItems.createNestedObject();
        item["Item"] = ECheckStation.ECheckItems[i].Item;
        item["Status"] = ECheckStation.ECheckItems[i].Status;
        item["Note"] = ECheckStation.ECheckItems[i].Note;

        printf("Create Item [%d]: success\r\n", i);
    }

    serializeJson(json_doc, RX_Buffer);
    printf("Serialize submit data: success\r\n");
    printf("%s\r\n", RX_Buffer);
}

bool EClient::ethernet_post_data()
{
    if (!client.connected())
    {
        if (!start_connect_to_server())
        {
            printf("Connect: failed\r\n");
            return false;
        }
        printf("Connect: successed\r\n");
    }

    int data_length = strlen(RX_Buffer);
    char ContentLength[64]{0};
    snprintf(ContentLength, sizeof(ContentLength), "Content-Length: %d", data_length);

    client.println(Post);
    client.println(Host);
    client.println(Connection);
    client.println(CashControl);
    client.println(UpgradeInsecure);
    client.println(UserAgent);
    client.println(ContentType);
    client.println(ContentLength);
    client.println();
    client.println(RX_Buffer);
    return true;
}

void EClient::station_init()
{
    printf("Initializing local parameter\r\n");
    ECheckStation.EEPROM_read_local_data();
    ethernet_init();
}

bool EClient::start_connect_to_server(uint32_t timeout)
{
    if (client.connected())
        return true;

    client.connect(ServerIp, Port);
    char temp[64];
    snprintf(temp, sizeof(temp), "Start connect to server : %s:%d\r\n", ServerIp, Port);
    printf(temp);
    int count = timeout / 100;
    int i = 0;
    while (!client.connected() && i < count)
    {
        i++;
        delay(100);
        printf(".\r\n");
    }
    if (client.connected())
    {
        printf("Connected to server %s:%d: successfull\r\n", ServerIp, Port);
    }
    else
    {
        printf("Connected to server %s:%d: fail\r\n", ServerIp, Port);
    }
    return client.connected();
}

void EClient::station_submit()
{
    printf("Station submit last check result\r\n");
    if (!Enable_Check)
        return;

    alarm_but_submit_click();
    serialize_local_data();
    if (ethernet_post_data())
    {
        ECheckStation.EEPROM_save_last_check_state();

        Enable_Check = false;
        Enable_Select_Note = false;
        Enable_Select_Person = false;
    }
    else
    {
        alarm_submit_success(false);
    }
}

//-------------------------------------------ALARM ENABLE------------------------------------------------
void EClient::alarm_enable_select_check_item(bool state)
{
    printf("Alarm enable select check item %d\r\n", state);
    if (state)
        ENABLE_ALARM_VAL = 0x01;
    else
        ENABLE_ALARM_VAL &= 0xFE;
    HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);
}

void EClient::alarm_enable_select_check_person(bool state)
{
    printf("Alarm enable select person %d\r\n", state);
    if (state)
        ENABLE_ALARM_VAL = 0x02;
    else
        ENABLE_ALARM_VAL &= 0xFD;

    HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);
}

void EClient::alarm_enable_select_note()
{
    printf("Alarm enable select notes\r\n");
    //74hc595 5 for note list display

    ENABLE_ALARM_VAL = 0x04;
    HC595_shiftByte(ENABLE_ALARM_VAL, CHECK_ENABLE);

    byte notes[2] = {0xFF, 0xFF};
    HC595_writeBytes(notes, 2, CHECK_ITEM_NOTE_INDEX);
    delay(50);
    notes[0] = 0x00;
    notes[1] = 0x00;
    HC595_writeBytes(notes, 2, CHECK_ITEM_NOTE_INDEX);
    delay(50);
    int begin_index = -1;
    station_select_check_item_notes(true, begin_index);
}

//-------------------------------------------ALARM UP DOWN------------------------------------------------
void EClient::alarm_check_item_index(int index) // LED selected item //on when enable and off after submit
{
    printf("Alarm check item index %d\r\n", index);
    uint8_t high_byte = uint8_t(LAMP_STATE[index] >> 8);
    uint8_t low_byte = uint8_t(LAMP_STATE[index] & 0xFFFF);
    HC595_shiftByte(high_byte, CHECK_ITEM_INDEX);
    HC595_shiftByte(low_byte, CHECK_ITEM_INDEX);
}

void EClient::alarm_check_person_index(int index) // LED selected person
{
    printf("Alarm check person index %d\r\n", index);
    uint8_t high_byte = uint8_t(LAMP_STATE[index] >> 8);
    uint8_t low_byte = uint8_t(LAMP_STATE[index] & 0xFFFF);
    HC595_shiftByte(high_byte, CHECK_PERSON_INDEX);
    HC595_shiftByte(low_byte, CHECK_PERSON_INDEX);
}

void EClient::alarm_check_item_note_index(int index) // LED slected notes
{
    printf("Alarm check note index %d\r\n", index);
    uint8_t high_byte = uint8_t(LAMP_STATE[index] >> 8);
    uint8_t low_byte = uint8_t(LAMP_STATE[index] & 0xFFFF);
    HC595_shiftByte(high_byte, CHECK_ITEM_NOTE_INDEX);
    HC595_shiftByte(low_byte, CHECK_ITEM_NOTE_INDEX);
}

//-------------------------------------------ALARM STATUS------------------------------------------------
void EClient::alarm_check_item_status()
{
    printf("Alarm check item status\r\n");
    uint16_t check_item_status = 0xFFFF;

    printf("Items status value: \r\n");
    for (size_t i = 0; i < ECheckStation.ECheckItems.size(); i++)
    {

        if (ECheckStation.ECheckItems[i].Status == OK)
        {
            check_item_status &= LAMP_STATE[i];
            printf("%d", 1);
        }
        else
        {
            printf("%d", 0);
        }
        printf("\r\n");
    }

    uint8_t high_byte = uint8_t(check_item_status >> 8);
    uint8_t low_byte = uint8_t(check_item_status);
    HC595_shiftByte(high_byte, CHECK_ITEM_STATUS);
    HC595_shiftByte(low_byte, CHECK_ITEM_STATUS);
}

void EClient::alarm_current_note_status()
{
    printf("Alarm selected item note status\r\n");
    uint8_t currentNote = ECheckStation.get_current_note_index();
    uint8_t high_byte = uint8_t(LAMP_STATE[currentNote] >> 8);
    uint8_t low_byte = uint8_t(LAMP_STATE[currentNote] & 0xFFFF);
    HC595_shiftByte(high_byte, CHECK_ITEM_NOTE_INDEX);
    HC595_shiftByte(low_byte, CHECK_ITEM_NOTE_INDEX);
}

//-----------------------------------------BUTTON ENABLE-------------------------------------------------
void EClient::station_enable_select_check_item(bool status)
{
    bool state = false;
    int begin_index = -1;
    if (status && !Enable_Check)
    {
        ECheckStation.reset_all_check_items();
        station_enable_select_check_person(false);
        state = true;
        station_select_new_check_item(true, begin_index);
        Enable_Select_Note = false;
    }

    if (Enable_Check)
        state = false;

    Enable_Check = state;
    alarm_enable_select_check_item(state);
}

void EClient::station_enable_select_check_person(bool status)
{
    bool state = false;
    int begin_index = -1;
    if (status && !Enable_Select_Person)
    {
        state = true;
        station_enable_select_check_item(false);
        station_select_new_person(true, begin_index);
        Enable_Select_Note = false;
    }

    if (Enable_Select_Person)
        state = false;

    ECheckStation.EEPROM_save_person_id();
    Enable_Select_Person = state;
    alarm_enable_select_check_person(state);
}

void EClient::station_enable_select_check_item_note(bool state)
{
    printf("Station select notes\r\n");
    Enable_Select_Note = true;
    station_enable_select_check_item(false);
    station_enable_select_check_person(false);
    alarm_enable_select_note();

    int begin_index = -1;
    station_select_check_item_notes(true, begin_index);
}
//-------------------------------------------BUTTON UP DOWN-----------------------------------------------
void EClient::station_select_new_check_item(bool direction, int &index)
{
    if (!Enable_Check)
        return;

    printf("Select item button: %s, index: %d\r\n", direction ? "Up" : "Down", index);
    if (direction) // up
    {
        index++;
        if (index >= ECheckStation.ECheckItems.size())
            index = 0;
    }
    else // down
    {
        index--;
        if (index < 0)
            index += ECheckStation.ECheckItems.size();
    }

    ECheckStation.CheckItem_Index = index;
    alarm_check_item_index(index);
}

void EClient::station_select_new_person(bool direction, int &index)
{
    if (!Enable_Select_Person)
        return;

    printf("Select person button: %s, index: %d\r\n", direction ? "Up" : "Down", index);
    if (direction) // up
    {
        index++;
        if (index >= sizeof(CheckPersonList))
            index = 0;
    }
    else // down
    {
        index--;
        if (index < 0)
            index += sizeof(CheckPersonList);
    }

    ECheckStation.CheckPerson_Index = index;
    ECheckStation.EEPROM_save_person_id();
    alarm_check_person_index(index);
}

void EClient::station_select_check_item_notes(bool direction, int &index)
{
    if (!Enable_Select_Note)
        return;
    printf("Select notes button: %s, index: %d\r\n", direction ? "Up" : "Down", index);
    if (direction) // up
    {
        index++;
        if (index >= sizeof(ECheckNoteArray))
            index = 0;
    }
    else // down
    {
        index--;
        if (index < 0)
            index += sizeof(ECheckNoteArray);
    }

    ECheckStation.CheckNote_Index = index;
    alarm_check_item_note_index(index);
}

//-------------------------------------------BUTTON OK----------------------------------------------------
void EClient::station_set_check_item_state(uint8_t state)
{
    if (!Enable_Check)
        return;

    printf("Station check current item state: %s\r\n", state == 0 ? "NOT OK" : "OK");

    if (ECheckStation.set_current_item_state(state))
        printf("Set current item successfull\r\n");
    else
        printf("Set current item fail\r\n");

    alarm_check_item_status();

    if (state == 0) //select not ok
    {
        station_enable_select_check_item_note(true);
        alarm_enable_select_note();
    }
}

void EClient::station_pick_current_notes(int &item_index, int &note_index)
{
    if (!Enable_Select_Note)
        return;

    printf("Station select note\r\n");
    if (ECheckStation.set_current_item_note())
    {
        printf("Set Note successfull\r\n");

        printf("Select next item to check\r\n");
        station_enable_select_check_person(false);
        station_select_new_check_item(true, item_index);
        Enable_Check = true;
        Enable_Select_Note = false;
        Enable_Select_Person = false;
        alarm_enable_select_check_item(true);
    }
    else
        printf("Set Note fail\r\n");
}
#endif