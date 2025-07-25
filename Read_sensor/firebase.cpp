#include "firebase.h"
#include <FirebaseESP32.h> // library of firebaseESP32
#include <WiFi.h>
#include <pin.h>
#include <tft.h>

FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

const char* ssid = "Nha Tro Vui Ve";
const char* password = "66668888";

#define Firebase_Host  "fir-with-sensor-light-default-rtdb.firebaseio.com/"
#define Firebase_Auth  "Ol77jhIXlTxjaAjCjDP9fRlDUPAGs7E46iGnknGe"


// tham số nhận giá trị từ firebase
int data5base;

// valiable to firebase from esp32
const char* name_int = "/value_of_sensor_light";
const char* name_day = "/day";
const char* value_led = "test/control";
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
void firebase :: control_led()
 {
    Firebase.getInt(fbData, value_led);
    display::day(fbData.intData());
    display::clear();
    Serial.print("Gia tri trong firebase: ");
    Serial.println(fbData.intData() );
    digitalWrite(Led, fbData.intData());
    delay(1000);
 }

// đẩy data từ esp32 lên firebase
void firebase :: get_to_firebase_from_esp(const int& value)
{
   Firebase.setInt(fbData, name_int, value);
   if(value == 0) Firebase.setString(fbData,name_day, "Chao buoi sang!");
   else Firebase.setString(fbData,name_day, "Chao buoi toi!");
    
  Serial.println("Push data to /esp done !");
   delay(500);
 }
