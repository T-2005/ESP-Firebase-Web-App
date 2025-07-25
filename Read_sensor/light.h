#ifndef light_H
#define light_H 

#include<Arduino.h>

extern int check;
extern int value_of_sensor;
class light {
  public:
 static void read_light_sensor();
  static void start_led(const int& value_of_sensor,  int& check);
  static void firebase_sensor();
};

#endif