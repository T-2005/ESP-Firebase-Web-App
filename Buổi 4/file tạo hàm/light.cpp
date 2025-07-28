/*
    File: Đọc cảm biến ánh sáng, điều khiển led bằng tín hiệu từ cảm biến ánh sáng và kiểm tra trạng thái của led
    Mục đích: Quản lý các hàm liên quan đến cảm biến ánh sáng và led
    Chú ý: Khi lập trình thì khởi tạo hàm này trong file "function_main.ino"
*/

#include "light.h"
#include "pin.h"
#include "tft.h"
#include "firebase.h"

int value_of_sensor = 0;
int check = 0;


void light :: led_sensor()
{
  light :: read_light_sensor();
  light :: on_off_led();
  light :: check_and_clear_oled(value_of_sensor, check);
  display::state_of_device(check); // hiển thị trên màn oled
}

void light :: read_light_sensor() // đọc cảm biến ánh sáng
{
  value_of_sensor = digitalRead(D0);
  Serial.print("Gia tri của cam bien: ");
  Serial.println(value_of_sensor);
  delay(300);
}

void light :: on_off_led(const int& value_of_sesor) // bật tắt led
{
    digitalWrite(Led, value_of_sensor);
}


void light:: check_and_clear_oled(const int& value_of_sensor,  int& check)
{
  if(value_of_sensor == 1) // kiem tra neu sensor bat thi doi 20ms
     {
       delay(20);      
         if(value_of_sensor == 1) // neu sensor bat thi kiem tra bien check
         {
             if(check == 0) // neu check = 0 -> gan bien check = 1 va den sang
             {
              check = 1;   
                display::clear();      
               }       
             
         } 
      }
    while(value_of_sensor == 1); // vòng lặp vô hạn cho đến khi sensor nhận được tín hiệu mới

    if(value_of_sensor == 0) // kiem tra neu sensor bat thi doi 20ms
     {
       delay(20);      
         if(value_of_sensor == 0) // neu sensor bat thi kiem tra bien check
         {
             if(check == 1) // neu check = 0 -> gan bien check = 1 va den sang
             {
               check = 0;  
                 display::clear();             
               }       
             
            } 
         }
       while(value_of_sensor == 0); // vòng lặp vô hạn cho đến khi sensor nhận được tín hiệu mới
}
