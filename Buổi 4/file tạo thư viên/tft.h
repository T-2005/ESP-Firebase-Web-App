#ifndef tft_H
#define tft_H

#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_ST7796S.h>
#include <Adafruit_ST77xx.h>



class display{
  public:
  static void hien_thi(); // hàm setup màu và kiểu hiện thị trên oled
  static void state_of_device(const int& value); // hàm hiển thị trạng thái của module
  static void clear(); // hàm xóa kí tự
};
#endif