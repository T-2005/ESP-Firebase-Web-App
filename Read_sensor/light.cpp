#include "light.h"
#include "pin.h"
#include "tft.h"
int value_of_sensor = 0;
int check = 0;
void light :: read_light_sensor()
{
  value_of_sensor = digitalRead(D0);
  Serial.println(value_of_sensor);
  delay(300);
  digitalWrite(Led, value_of_sensor);
}

void light:: start_led()
{
  if(value_of_sensor == 1) // kiem tra neu button bat thi doi 20ms
     {
       delay(20);      
         if(value_of_sensor == 1) // neu button bat thi kiem tra bien check
         {
             if(check == 0) // neu check = 0 -> gan bien check = 1 va den sang
             {
               check = 1;   
                     display::clear();      
               }       
             
         } 
         }
       while(value_of_sensor == 1); // vong lap vo han cho den khi nut nhan dc nhan 1 lan nua

    if(value_of_sensor == 0) // kiem tra neu button bat thi doi 20ms
     {
       delay(20);      
         if(value_of_sensor == 0) // neu button bat thi kiem tra bien check
         {
             if(check == 1) // neu check = 0 -> gan bien check = 1 va den sang
             {
               check = 0;  
                 display::clear();             
               }       
             
         } 
         }
       while(value_of_sensor == 0); // vong lap vo han cho den khi nut nhan dc nhan 1 lan nua
}
