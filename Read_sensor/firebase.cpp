#include "firebase.h"
#include <FirebaseESP32.h> // library of firebaseESP32
#include <WiFi.h>


FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

const char* ssid = "Nha Tro Vui Ve";
const char* password = "66668888";

#define Firebase_Host  "esp32-with-light-default-rtdb.firebaseio.com/"
#define Firebase_Auth  "ex4GKoswbBLYjc0rtc4bWe5iZ5DZb9JBqkhI3F8Q"



int data5base;
const char* name_int = "/value_of_sensor_light";
const char* name_day = "/day";

// kết nối Wifi
void firebase :: wifi_connection() // setup
{
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi connected!");
}

// kết nối đến firebase
void firebase :: connection_firebase() // setup
{
  config.host = Firebase_Host ;
  config.signer.tokens.legacy_token = Firebase_Auth;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

// lấy dữ liệu từ Firebase về Esp32
// void firebase :: get_to_esp_from_firebase() // loop
// {
//    // lấy giá trị kiểu int ở trường esp32
//    Firebase.getInt(fbData, "/esp32");
//    // hứng giá trị
//    data5base = fbData.intData();
//    {
//      Serial.println("data in /esp32 is: ");
//      Serial.println(data5base);
//      delay(1000);
//    }
//    Firebase.setString(fbData, truongthaydoi, "tuan");
//    Serial.println("set data done !");
//    delay(500);
//  }

// đẩy data từ esp32 lên firebase
void firebase :: get_to_firebase_from_esp(const int& value)
{
   Firebase.setInt(fbData, name_int, value);
   if(value == 0) Firebase.setString(fbData,name_day, "Chao buoi sang!");
   else Firebase.setString(fbData,name_day, "Chao buoi toi!");
    
  Serial.println("Push data to /esp done !");
   delay(500);
 }
