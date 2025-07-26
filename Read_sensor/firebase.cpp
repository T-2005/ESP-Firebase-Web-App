#include "firebase.h"
#include <FirebaseESP32.h> // library of firebaseESP32
#include <WiFi.h>
#include <pin.h>
#include <tft.h>
#include <light.h>

FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

const char* ssid = "Nha Tro Vui Ve";
const char* password = "66668888";

#define Firebase_Host  "fir-with-sensor-light-default-rtdb.firebaseio.com/"
#define Firebase_Auth  "Ol77jhIXlTxjaAjCjDP9fRlDUPAGs7E46iGnknGe"


// tham số nhận giá trị từ firebase
String data5base;
int value_of_firebase;
int check1 = 0;
// valiable to firebase from esp32
const char* name_int = "/value_of_sensor_light";
const char* name_day = "/day";
const char* value_led = "test/control";
const char* state = "test/state";
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
void firebase :: read_firebase()
{
    Firebase.getInt(fbData, value_led);
    value_of_firebase = fbData.intData();
   
    Firebase.getString(fbData, state);
    data5base = fbData.stringData(); // lấy trạng thái của firebase
     
}

void firebase :: control_led()
 {
   light :: check_and_clear_oled(value_of_firebase, check1); // hàm xóa kí tự trên oled
   display::state_of_device(value_of_firebase); // hiển thị lên oled  
    Serial.print("Gia tri trong firebase: ");
    Serial.println(value_of_firebase );
    digitalWrite(Led, value_of_firebase);
    //delay(1000);
 }

// đẩy data từ esp32 lên firebase
void firebase :: get_to_firebase_from_esp(const int& value_of_thing)
{
   Firebase.setInt(fbData, name_int, value_of_thing); // // đẩy dữ liệu từ esp32 lên firebase dạng số nguyên lấy từ biến "value_of_thing"
   if(value_of_thing == 0) Firebase.setString(fbData,name_day, "Chao buoi sang!");
   else Firebase.setString(fbData,name_day, "Chao buoi toi!");
    
  Serial.println("Push data to /esp done !");
   delay(500);
 }
