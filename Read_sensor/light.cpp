#include "light.h"
#include "pin.h"
#include "tft.h"
#include "firebase.h"

int value_of_sensor = 0;
int check = 0;
void light :: read_light_sensor()
{
  value_of_sensor = digitalRead(D0);
  Serial.println(value_of_sensor);
  delay(300);
  digitalWrite(Led, value_of_sensor);
  light :: start_led(value_of_sensor, check); // hàm xóa chữ trong màn oled
  display::day(check); // hiển thị trên màn oled
}


void light:: start_led(const int& value_of_sensor,  int& check)
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
