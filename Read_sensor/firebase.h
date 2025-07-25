#ifndef firebase_H
#define firebase_H
#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h> // library of firebaseESP32




// creat valiable
extern FirebaseData fbData;
extern FirebaseAuth auth;
extern FirebaseConfig config;

// Wifi
extern const char* ssid;
extern const char* password;
// Firebase declare
// extern const char* Firebase_Host;
// extern const char* Firebase_Auth;
// biến hứng
extern int data5base;
// biến thay đổi data
extern const char* name_int;
extern const char* name_day;
extern const char* value_led;
class firebase {
  public:
  static void wifi_connection();
  static void connection_firebase();
   static void control_led();
  static void get_to_firebase_from_esp(const int& value); 
};


#endif 