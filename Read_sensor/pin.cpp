#include <pin.h>  
#include<Arduino.h>

int D0 = 21;
int Led = 26;

void pin :: init()
{
  pinMode(Led, OUTPUT);
  pinMode(D0, INPUT);
}