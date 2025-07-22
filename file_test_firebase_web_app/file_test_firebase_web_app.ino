#include<firebase.h>

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  firebase :: wifi_connection();
  firebase :: connection_firebase();
}
void loop()
{
 // firebase:: get_to_firebase_from_esp(); 
 firebase :: control_led();
}