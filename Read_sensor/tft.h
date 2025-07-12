#ifndef tft_H
#define tft_H

#include<Arduino.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_ST7796S.h>
#include <Adafruit_ST77xx.h>

extern int TFT_CS;
extern int TFT_RST;
extern int TFT_DC;

class display{
  public:
  static void hien_thi();
  static void day();
  static void clear();
};
#endif