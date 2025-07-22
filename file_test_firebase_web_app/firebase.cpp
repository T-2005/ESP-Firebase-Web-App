#include "firebase.h"
#include <FirebaseESP32.h> // library of firebaseESP32
#include <WiFi.h>


FirebaseData fbData;
FirebaseAuth auth;
FirebaseConfig config;

const char* ssid = "Nha Tro Vui Ve";
const char* password = "66668888";

#define Firebase_Host  "fir-with-sensor-light-default-rtdb.firebaseio.com/"
#define Firebase_Auth  "Ol77jhIXlTxjaAjCjDP9fRlDUPAGs7E46iGnknGe"


// tham sá»‘ nháº­n giĂ¡ trá»‹ tá»« firebase
int data5base ;
int led = 26;
// valiable to firebase from esp32
const char* name_int = "test/int";
const char* name_string = "test/string";
const char* name_float = "test/float";
const char* value_led = "test/control";
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 1000; // 10 seconds in milliseconds
// káº¿t ná»‘i Wifi
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

// káº¿t ná»‘i Ä‘áº¿n firebase
void firebase :: connection_firebase() // setup
{
  config.host = Firebase_Host ;
  config.signer.tokens.legacy_token = Firebase_Auth;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}


void firebase :: get_to_firebase_from_esp()
{
  
  unsigned long currentTime = millis();
    if (currentTime - lastSendTime >= sendInterval){
      // Update the last send time
      lastSendTime = currentTime;
    }
  
    Firebase.setInt(fbData, name_int, lastSendTime);
    Firebase.setString(fbData, name_string, "Hello");
   
    Firebase.setFloat(fbData, name_float, lastSendTime / 1000);
    
    
  Serial.println("Push data to /esp done !");
   delay(500);
 }
 void firebase :: control_led()
 {
   Firebase.getInt(fbData, value_led);
   
    Serial.print("Gia tri trong firebase: ");
    Serial.println(fbData.intData() );
    digitalWrite(led, fbData.intData());
    delay(1000);
 }