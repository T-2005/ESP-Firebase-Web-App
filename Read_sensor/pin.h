#ifndef pin_H
#define pin_H

#include<Arduino.h>

extern int D0;
extern int Led;

extern int TFT_CS;
extern int TFT_RST;
extern int TFT_DC;

class pin {
  public:
  static void init();
};

#endif