#ifndef firebase_H
#define firebase_H
#include <Arduino.h>





// creat valiable


// Wifi
extern const char* ssid;
extern const char* password;
// Firebase declare
// extern const char* Firebase_Host;
// extern const char* Firebase_Auth;
// biáº¿n há»©ng
extern int data5base;
// biáº¿n thay Ä‘á»•i data
extern const char* name_int;
extern const char* name_string;
extern const char* name_float;
extern const char* value_led;
extern unsigned long lastSendTime;
extern int led;
extern const unsigned long sendInterval;
class firebase {
  public:
  static void wifi_connection();
  static void connection_firebase();
   static void get_to_firebase_from_esp();
  static void control_led();
};

#endif 