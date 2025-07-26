#ifndef firebase_H
#define firebase_H
#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h> // library of firebaseESP32




// khởi tạo biến toàn cục cho firebase
extern FirebaseData fbData;
extern FirebaseAuth auth;
extern FirebaseConfig config;

// khởi tạo biến cho Wifi
extern const char* ssid;
extern const char* password;

// khởi tạo biến
extern String data5base;
extern int value_of_firebase;
extern int check1;
// biến thay đổi data
extern const char* name_int;
extern const char* name_day;
extern const char* value_led;
extern const char* state;

class firebase {
  public:
  static void wifi_connection(); // kết nối wifi
  static void connection_firebase(); // kết nối vơi firebase
  static void control_led(); // điều khiển led từ firebase
  static void get_to_firebase_from_esp(const int& value_of_thing); 
  static void read_firebase(); // hàm đọc data trên firebase
};


#endif 