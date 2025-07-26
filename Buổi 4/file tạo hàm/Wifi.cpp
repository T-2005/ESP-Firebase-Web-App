/*
	File:  Kết nối Esp32 với Wifi
*/
#include<Arduino.h>
#include <Wifi.h>

const char* ssid = "Wifi_name";
const char* password = "wifi_password";

void wifi_connection() // Nằm trong hàm setup
{
  WiFi.begin(ssid, password);
  // Chờ cho đến khi kết nối wifi thành công
  Serial.print("Connecting to Wifi");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi connected!");
}
