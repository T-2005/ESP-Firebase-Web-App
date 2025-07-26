#include "light.h"
#include "pin.h"
#include "tft.h"
#include "Arduino.h"
#include "firebase.h"
void setup() {
  Serial.begin(9600);
   pin::init();
  display::hien_thi();
  firebase::wifi_connection();
  firebase::connection_firebase();
}

void loop() {
 firebase :: read_firebase();
   if(String(data5base) == "On")
  {
    Serial.println(data5base);
     firebase::control_led(); // hàm điều khiển led bằng firebase
   
 }
   else if(String(data5base) == "Off")
   {
    Serial.println(data5base);
    light::led_sensor(); // hàm điều khiển led bằng cảm biến ánh sáng
    firebase::get_to_firebase_from_esp(value_of_sensor); //hàm đọc giá trị từ esp lên firebase
 }
   
}
