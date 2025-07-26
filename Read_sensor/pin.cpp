#include <pin.h>  
#include<Arduino.h>

int D0 = 21;
int Led = 26;

int TFT_CS = 5;
int TFT_RST = 4;
int TFT_DC = 2;

void pin :: init()
{
  pinMode(Led, OUTPUT);
  pinMode(D0, INPUT);
}