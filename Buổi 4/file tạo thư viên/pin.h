#ifndef pin_H
#define pin_H

#include<Arduino.h>

extern int D0;
extern int Led;
extern int TFT_CS = 5;
extern int TFT_RST = 4;
extern int TFT_DC = 2;

class pin {
  public:
  static void init(); // hàm khởi tạo các chân kêt nối
};

#endif